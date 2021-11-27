#include <stdio.h>
#include <stdlib.h>

float position_1,position_2;                 //起点和终点 
float position_up[3],position_down[3];       //回调或反抽的上下区间


void print_main()
{
	printf("本程序用来计算回调或反抽点位\n\n");
	printf("请输入一个低点或者一个高点：");
	scanf("%f",&position_1);
	printf("请输入一个高点或者一个低点：");
	scanf("%f",&position_2);
}

void print_up()
{
	printf("\n在该上升浪中，\n");
	printf("\n最小回调至：\n");
	printf("----------------%.2f\n",position_up[0]);
	printf("----------------%.2f\n",position_down[0]);
	printf("\n可能回调至：\n\n");
	printf("****************%.2f\n",position_up[1]);
	printf("\n可以在最小回调的最小值和该位置形成的区域做多！\n");
	printf("\n最大回调至：\n");
	printf("++++++++++++++++%.2f\n",position_up[2]); 
	printf("++++++++++++++++%.2f\n",position_down[2]);
	printf("\n如果回调超过了最大回调的%.2f，建议离场！该点可挂止损\n\n",position_down[2]);
} 

void print_down()
{
	printf("\n在该下跌浪中，\n");
	printf("\n最大反抽至：\n");
	printf("++++++++++++++++%.2f\n",position_up[2]); 
	printf("++++++++++++++++%.2f\n",position_down[2]);
	printf("\n如果反抽超过了最大反抽的%.2f，建议离场！该点可挂止损\n\n",position_up[2]);
	printf("\n可能反抽至：\n\n");
	printf("****************%.2f",position_up[1]);
	printf("\n可以在最小反抽的最大值和该位置形成的区域做空！\n");
	printf("\n最小反抽至：\n");
	printf("----------------%.2f\n",position_up[0]);
	printf("----------------%.2f\n",position_down[0]);
}

void count_up()
{
	position_up[0] = position_2 - (position_2 - position_1) * 0.33;    //33%回调 
	position_down[0] = position_2 - (position_2 - position_1) * 0.382; //38.2%回调	
	position_up[1] = position_2 - (position_2 - position_1) * 0.5;     //50%回调 
	position_up[2] = position_2 - (position_2 - position_1) * 0.618;   //61.8%回调 
	position_down[2] = position_2 - (position_2 - position_1) * 0.66;  //66%回调
	print_up();
}

void count_down()
{
	position_up[0] = position_2 + (position_1 - position_2) * 0.382;  //38.2%回调 
	position_down[0] = position_2 + (position_1 - position_2) * 0.33; //33%回调
	position_up[1] = position_2 + (position_1 - position_2) * 0.5;  //50%回调
	position_up[2] = position_2 + (position_1 - position_2) * 0.66;  //66%回调 
	position_down[2] = position_2 + (position_1 - position_2) * 0.618; //61.8%回调
	print_down();
}

void up()
{
	if (position_2 >= position_1)   //上升浪
	{
		count_up();		 	
	}
}

void down()
{
	if (position_2 < position_1)   //下跌浪
	{		
		count_down();		
	}
}

void cycle() //程序循环 
{
	int i;
	int main();
	printf("\n是否需要再次计算？如果是请输入1，否则输入2。\n");
	scanf("%d",&i);			
	if (i == 1)
	{
		system("cls");
		main();
	}     
	if (i == 2)
	 system("pause");
} 


int main()
{
	print_main();       //画出计算结果 
	up();               //判断上升浪并计算 
	down();             //判断下跌浪并计算 
	cycle();	        //程序循环 
	return 0; 
}
