#include <stdio.h>
#include <stdlib.h>

int main()
{
	int zhang;       //加仓后总张数 
	int zhang_1,zhang_2;   //张数  
    float position,position_1,position_2;
    
	printf("本程序用来计算何处加仓到达目标点位\n\n");
	printf("请输入目前成本价格 ：");
	scanf("%f",&position_1);
	printf("请输入目前持仓数量 ：");
	scanf("%d",&zhang_1);
	printf("请输入目标成本价格 ：");
	scanf("%f",&position_2);
	printf("请输入目标加仓数量 ：");
	scanf("%d",&zhang_2);
	
	zhang = zhang_1 + zhang_2;
	position = (position_2 * zhang - position_1 * zhang_1) / zhang_2;
//持仓成本＝（第一次买入价格×持仓数量＋加仓时价格×加仓数量）／（第一次持仓数量＋加仓数量）  
	
	printf("\n你需要在价格为：%.2f时加仓%d张\n\n",position,zhang_2);

	system("pause");
	return 0; 
}
