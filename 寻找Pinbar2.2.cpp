#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

#define M 1000
//M的作用是，扩大数据，防止价格数字太小，计算倍数时容易归零 

double open_price,close_price;   //开盘价，收盘价
double max_price,min_price;      //最高价，最低价
double yang_price[10];           //锤形线价格数组，需要做四则运算 
double yin_price[10];            //流星线价格数组，需要做四则运算
double beishu[8];                //存放实体、上下影线扩大之后的数据 

void print()  //程序构建函数
{
	system("COLOR FC");
	
	cout << "程序用来判定Pinbar！\n\n";
	cout << "请输入开盘价：";
	cin >> open_price; 
	cout << "请输入最高价：";
	cin >> max_price;
	cout << "请输入最低价：";
	cin >> min_price;
	cout << "请输入收盘价：";
	cin >> close_price;	
}

void mainf()  //程序实现主要功能函数 
{
	//函数声明
	void count_yang();
	void count_yin();    
	
	if (open_price > close_price)   //开盘价大于收盘价，为阴线 
	{
		count_yin();  //小阳线数据处理函数
	}
	if (open_price <= close_price)   //开盘价小于等于收盘价，为阳线
	{
		count_yang();  //小阴线数据处理函数
	}
}

void count_yang()  //小阳线数据处理函数 
{
	yang_price[0] = close_price - open_price;             //实体长度
	yang_price[1] = max_price - close_price;              //上影线长度
	yang_price[2] = open_price - min_price;               //下影线长度
	yang_price[5] = max_price - min_price;                //Pinbar振幅
	beishu[0] = yang_price[0] * M;                        //实体长度扩大M倍 
	beishu[1] = yang_price[1] * M;                        //上影线长度扩大M倍 
	beishu[2] = yang_price[2] * M;                        //下影线长度扩大M倍 
	beishu[6] = yang_price[5] * M;                        //K线长度扩大M倍 
	yang_price[3] = beishu[1] / beishu[0];                //上影线除以实体
	yang_price[4] = beishu[2] / beishu[0];                //下影线除以实体
	
	cout << "\n实体的长度为：" << yang_price[0] << endl;
	cout << "上影线的长度为：" << yang_price[1] << endl;
	cout << "下影线的长度为：" << yang_price[2] << endl; 
	cout << "上影线的长度为实体的" << yang_price[3] << "倍\n";
	cout << "下影线的长度为实体的" << yang_price[4] << "倍\n"; 
	
	if (beishu[1] >= beishu[2])                           //判断主影线
	{
		yang_price[6] = beishu[1] / beishu[6];
		cout << "上影线的长度为整个K线的" << yang_price[6] << "倍\n"; 
	}
	if (beishu[1] < beishu[2])
	{
		yang_price[6] = beishu[2] / beishu[6];
		cout << "下影线的长度为整个K线的" << yang_price[6] << "倍\n";
	}
	
	void pinbar_yang();  
	pinbar_yang();	
}

void count_yin()  //小阴线数据处理函数 
{
	yin_price[0] = open_price - close_price;              //实体长度
	yin_price[1] = max_price - open_price;                //上影线长度
	yin_price[2] = close_price - min_price;               //下影线长度
	yin_price[5] = max_price - min_price;                 //Pinbar振幅
	beishu[3] = yin_price[0] * M;                         //实体长度扩大M倍 
	beishu[4] = yin_price[1] * M;                         //上影线长度扩大M倍 
	beishu[5] = yin_price[2] * M;                         //下影线长度扩大M倍 
	beishu[7] = yin_price[5] * M;                        //K线长度扩大M倍
	yin_price[3] = beishu[4] / beishu[3];                 //上影线除以实体
	yin_price[4] = beishu[5] / beishu[3];                 //下影线除以实体
	
	cout << "\n实体的长度为：" << yin_price[0] << endl;
	cout << "上影线的长度为：" << yin_price[1] << endl;
	cout << "下影线的长度为：" << yin_price[2] << endl;
	cout << "上影线的长度为实体的" << yin_price[3] << "倍\n";
	cout << "下影线的长度为实体的" << yin_price[4] << "倍\n";
	
	if (beishu[4] >= beishu[5])                           //判断主影线
	{
		yin_price[6] = beishu[4] / beishu[7]; 
		cout << "上影线的长度为整个K线的" << yin_price[6] << "倍\n"; 
	}
	if (beishu[4] < beishu[5])
	{
		yin_price[6] = beishu[5] / beishu[7];
		cout << "下影线的长度为整个K线的" << yin_price[6] << "倍\n";
	} 
	 
	void pinbar_yin();
	pinbar_yin();
} 

void pinbar_yang()  //处理计算好的数据函数 
{
	if (yang_price[1] >= yang_price[2])  //判定是流星线（小阳） 
	{
		if (yang_price[3] > 2)
		{
			cout << "\n该小阳线为流星线\n";
			cout << "此流星线是否位于一波上涨行情的顶端？位置不对，效果全无！\n";
			cout << "止损价格为：" << max_price;
			
	    	cout << "\n\n第一种入场方式：\n";
	    	cout << "入场做空价格为开盘价格：" << open_price;
	    	cout << "\n出场价格为Pinbar振幅：" << open_price - yang_price[5];
	    	cout << "\n此时盈亏比为：" << yang_price[5] / (max_price - open_price); //盈利点位是Pinbar振幅
	    	
	    	cout << "\n\n第二种入场方式：\n";
	    	cout << "入场做空价格为回调50%价格：" << (max_price + min_price) / 2;
			cout << "\n出场价格为Pinbar振幅：" << open_price - yang_price[5];
			cout << "\n此时盈亏比为：" << yang_price[5] / (max_price - (max_price + min_price) / 2); //盈利点位是Pinbar振幅
		}
		if (yang_price[3] <= 2)
		  cout << "\n不符合流星线的定义！\n";
	}
	
	if (yang_price[1] < yang_price[2])  //判定是锤形线（小阴） 
	{
		if (yang_price[4] > 2)
		{
            cout << "\n该小阳线为锤形线\n";
			cout << "此锤形线是否位于一波下跌行情的底端？位置不对，效果全无！\n";
			cout << "止损价格为：" << min_price;
			
	    	cout << "\n\n第一种入场方式：\n";
	    	cout << "入场做多价格为收盘价格：" << close_price;
	    	cout << "\n出场价格为Pinbar振幅：" << close_price + yang_price[5];
	    	cout << "\n此时盈亏比为：" << yang_price[5] / (close_price - min_price); //盈利点位是Pinbar振幅
	    	
	    	cout << "\n\n第二种入场方式：\n";
	    	cout << "入场做多价格为回调50%价格：" << (max_price + min_price) / 2;
	    	cout << "\n出场价格为Pinbar振幅：" << (max_price + min_price) / 2 + yang_price[5];
            cout << "\n此时盈亏比为：" << yang_price[5] / ((max_price + min_price) / 2 - min_price);//盈利点位是Pinbar振幅 
		}
		if (yang_price[4] <= 2)
		  cout << "\n不符合锤形线的定义！\n"; 
	} 
}

void pinbar_yin()   //处理计算好的数据函数 
{
	if (yin_price[1] >= yin_price[2])  //判定是流星线（小阴） 
	{
		if (yin_price[3] > 2)
		{
			printf("\n该小阴线为流星线\n");
			printf("此流星线是否位于一波上涨行情的顶端？位置不对，效果全无！\n"); 
			cout << "止损价格为：" << max_price;
			
	    	cout << "\n\n第一种入场方式：\n";
	    	cout << "入场做空价格为开盘价格：" << close_price;
	    	cout << "\n出场价格为Pinbar振幅：" << close_price - yin_price[5];
	    	cout << "\n此时盈亏比为：" << yin_price[5] / (max_price - close_price);//盈利点位是Pinbar振幅  
	    	
	    	cout << "\n\n第二种入场方式：\n";
	    	cout << "入场做空价格为回调50%价格：" << (max_price + min_price) / 2;
			cout << "\n出场价格为Pinbar振幅：" << close_price - yin_price[5];
			cout << "\n此时盈亏比为：" << yin_price[5] / (max_price - (max_price + min_price) / 2); //盈利点位是Pinbar振幅 
		}
		if (yin_price[3] <= 2)
		  printf("\n不符合流星线的定义！\n"); 
	}
	
	if (yin_price[1] < yin_price[2])  //判定是锤形线（小阴） 
	{
		if (yin_price[4] > 2)
		{
			printf("\n该小阴线为锤形线\n");
			printf("此锤形线是否位于一波下跌行情的底端？位置不对，效果全无！\n"); 
			cout << "止损价格为：" << min_price;
			
	    	cout << "\n\n第一种入场方式：\n";
	    	cout << "入场做多价格为收盘价格：" << open_price;
	    	cout << "\n出场价格为Pinbar振幅：" << open_price + yin_price[5];
	    	cout << "\n此时盈亏比为：" << yin_price[5] / (open_price - min_price); //盈利点位是Pinbar振幅
	    	
	    	cout << "\n\n第二种入场方式：\n";
	    	cout << "入场做多价格为回调50%价格：" << (max_price + min_price) / 2;
			cout << "\n出场价格为Pinbar振幅：" << (max_price + min_price) / 2 + yin_price[5]; 
			cout << "\n此时盈亏比为：" << yin_price[5] / (((max_price + min_price) / 2) - min_price);//盈利点位是Pinbar振幅 
		}
		if (yin_price[4] <= 2)
		  printf("\n不符合锤形线的定义！\n"); 
	} 
}

void look_out()  //要点！
{ 
	printf("\n\n\n找位置：");
	printf("\n");
	printf("\t1.流星线必须是在一波上涨行情的顶端\n");
	printf("\t2.锤形线必须是在一波下跌行情的底端\n");
	printf("\t3.Pinbar必须处在某个关键位，位置不对，效果全无！\n\n");
	
	printf("出场（二选一）：");
	printf("\n");
	printf("\t1.盈亏比大于1.5，长期严格执行，40%的胜率即可挣到钱\n");
	printf("\t2.至少吃到与Pinbar振幅（max-min）相当的点位\n\n");
		
	printf("总结：");
	printf("\n");
	printf("\t1.只找锤形线和流星线\n");
	printf("\t2.位置要对，震荡行情无效\n");
	printf("\t3.至少2条以上的入场理由（交易量）\n\n");
} 

void over()
{
	int i;
	void over(); 
	printf("\n\n请输入1结束本程序：");
	scanf("%d",&i);
	if (i!=1)
	{
		over();	
	}
}

int main()
{
	print();    //程序构建函数 
	mainf();    //程序实现主要功能函数 
	look_out();  
	over();
	system("pause");
	return 0;
}
