#include <stdio.h>
#include <stdlib.h>

void print()
{
	float A,B,C;
	float D1,D2,D3;
	printf("本程序为迪纳波利点位计算公式，用来计算出场点！\n\n");
	printf("使用本程序条件如下：\n价格先从一个明显的高点或低点A运动到点B\n然后折返到点C，再按原来的方向运动到点D\n则点D有三个可能的点位\n");
	printf("请分别输入A,B,C的值\n");
	printf("A:");
	scanf("%f",&A);
	printf("B:");
	scanf("%f",&B); 
	printf("C:");
	scanf("%f",&C);
	D1=C+0.618*(B-A);
	D2=C+1*(B-A);
	D3=C+1.618*(B-A);
	printf("\n计算得出：\n");
	printf("D1=%.2f\tD2=%.2f\tD3=%.2f",D1,D2,D3);
	printf("\n\n说明：\n");  
	printf("1.一般情况取D2；\n2.若行情较弱取D1；\n3.若D3处有一个很大的压力，而D1和D2处不是压力位，或者是一个较小、较容易突破的压力位，同时行情受到消息面刺激，比较强势，则取D3。\n");
}

int main()
{
	int i;
	print();
	printf("\n是否需要再次计算？如果是请输入1，否则输入2。\n");
	scanf("%d",&i);			
	if (i == 1)
	{
		system("cls");
		main();
	}     
	if (i == 2)
	 system("pause");
	return 0; 
 } 
 
