#include <stdio.h>
#include <stdlib.h>

int main()
{
	int lever;   //杠杆
	int zhang;   //开仓张数 ，bitget平台1张为0.1ETH 
	int direction;  //方向，多还是空 
	float pr[6];   //记录盈亏10%、20%、30%、40%、50%、60%时的金额 
	float po[6];   //记录盈亏10%、20%、30%、40%、50%、60%时的平仓价格
	float principal;  //全仓本金 
	float position;  // 保证金；保证金 = （成交均价 * 张数 * 每张价格）/ 杠杆 
	float position_1,position_2;   //分别为开仓和平仓价格 ；手续费 = 当前价格 * 张数 * 十万分之4 
	                               //平仓手续费目前为十万分之6 
//持仓成本＝（第一次买入价格×持仓数量＋加仓时价格×加仓的数量）／（第一次持仓数量＋加仓数量）

	printf("本程序用来计算止损点位\n\n");
	printf("请输入方向(1为多，0为空) ：");
	scanf("%d",&direction);
	printf("请输入杠杆：");
	scanf("%d",&lever); 
	printf("请输入开仓价格 ：");
	scanf("%f",&position_1);
	printf("请输入张数：");
	scanf("%d",&zhang);
	printf("请输入本金：");
	scanf("%f",&principal);
	
    if (direction == 1) //多头 
	{
		pr[0] = -principal * 0.1;  //盈亏为本金的10%时的金额 
	    pr[1] = -principal * 0.2;
        pr[2] = -principal * 0.3;
	    pr[3] = -principal * 0.4;
	    pr[4] = -principal * 0.5;
	    pr[5] = -principal * 0.6;
	}
	
	if (direction == 0) //空头 
	{
		pr[0] = principal * 0.1;  //盈亏为本金的10%时的金额 
	    pr[1] = principal * 0.2;
        pr[2] = principal * 0.3;
	    pr[3] = principal * 0.4;
	    pr[4] = principal * 0.5;
	    pr[5] = principal * 0.6;
	}	
		
	po[0] = pr[0] / (zhang * 0.1) + position_1; //盈亏为本金的10%时的平仓价格 
	po[1] = pr[1] / (zhang * 0.1) + position_1;
	po[2] = pr[2] / (zhang * 0.1) + position_1;
	po[3] = pr[3] / (zhang * 0.1) + position_1;
	po[4] = pr[4] / (zhang * 0.1) + position_1;
	po[5] = pr[5] / (zhang * 0.1) + position_1; 
	//源公式为：盈亏 = （全平价 - 开仓价）* 张数 * 每张价 

    position = (position_1 * zhang * 0.1) / lever; 

    int i;
    printf("\n");
    printf("当前保证金为：%0.8f\n",position);
	if (direction == 1)
	{	
		for (i=0;i<6;i++)
		  printf("当亏损本金的%d0%%时，平仓价格为：%7.2f，此时盈亏：%12.8f，收益率：%7.2f%%\n",i+1,po[i],pr[i],(pr[i] / position) * 100);
	}
	if (direction == 0)
	{
		for (i=0;i<6;i++)
	 	  printf("当亏损本金的%d0%%时，平仓价格为：%7.2f，此时盈亏：%12.8f，收益率：%7.2f%%\n",i+1,po[i],-pr[i],(-pr[i] / position) * 100);
	}
	 
    printf("\n风险务必控制在30%%以内！！\n\n");
	system("pause");
	return 0; 
}
