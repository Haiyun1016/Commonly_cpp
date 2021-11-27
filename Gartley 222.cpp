#include <stdio.h>
#include <stdlib.h>

int i;                 //i记录用户输入目前已知量的个数 
float X,A,B,C,D;
float Ba[2],Ca[2],Da[3],E[2]; //a是array（数组）的缩写，E[3]记录D点确定后止损位和进攻位 

void XA_B_count() //已知X和A计算B点函数 
{
	Ba[0] = A + (X-A) * 0.618;
	Ba[1] = A + (X-A) * 0.786; 
	
	printf("\n"); 
	printf("----------------%.2f\n",Ba[1]);
	printf("----------------%.2f\n",Ba[0]);
	
	printf("\n要求影线或实体落在X->A斐波那契的0.618~0.786区间内，否则B点不成立！\n\n"); 
}
 
void XA()
{
	printf("请分别输入X和A的值\n"); 
	printf("X:");
	scanf("%f",&X);
	printf("A:");
	scanf("%f",&A);
	
	XA_B_count(); //已知X和A计算B点函数
}

void XAB_C_count() //已知X、A和B计算C点函数 
{
	Ca[0] = B - (B-A) * 0.382;
	Ca[1] = B - (B-A) * 0.886; 
	
	printf("\n"); 
	printf("----------------%.2f\n",Ca[0]);
	printf("----------------%.2f\n",Ca[1]);
	
	printf("\nC点需要落在A->B斐波那契的0.382~0.886区间内\n\n"); 
}

void XAB() 
{
	printf("请分别输入X、A和B的值\n"); 
	printf("X:");
	scanf("%f",&X);
	printf("A:");
	scanf("%f",&A);
	printf("B:");
	scanf("%f",&B);
	
	XAB_C_count(); //已知X、A和B计算C点函数
}

void XABC_D_count() //已知X、A、B和C计算D点函数 
{
	Da[0] = A + (X-A) * 0.786;
	Da[1] = A + (B-A) * 1.272;
	Da[2] = A + (B-A) * 1.618; 
	
	printf("\n");
	printf("----------------%.2f（B->A 161.8%）\n",Da[2]); 
	printf("----------------%.2f（B->A 127.2%）\n",Da[1]);
	printf("----------------%.2f（X->A  78.6%）\n",Da[0]);
	
	printf("\n如果D点落在X->A斐波那契的0.786和B->A斐波那契的1.272区间内,有明显反转信号即可做空\n");
	printf("\n如果D点落在B->A斐波那契的1.272~1.618区间内，等反转信号做空\n\n"); 
}

void XABC()
{
	printf("请分别输入X、A、B和C的值\n"); 
	printf("X:");
	scanf("%f",&X);
	printf("A:");
	scanf("%f",&A);
	printf("B:");
	scanf("%f",&B);
	printf("C:");
	scanf("%f",&C);
	
	XABC_D_count(); //已知X、A、B和C计算D点函数 
}

void XABCD_count() //已知X、A、B、C和D计算攻守位置函数 
{
	E[0] = A + (X-A) * 0.382;
	E[1] = A + (X-A) * 0.618;
	
	printf("\n");
	printf("----------------%.2f（止损点位）\n\n",X); 
	printf("----------------%.2f（X->A  61.8%）\n",E[1]);
	printf("----------------%.2f（X->A  38.2%）\n",E[0]);
	
	printf("\nX的点位为止损位置\n");
	printf("\n第一进攻位为0.618，第二进攻位为0.382\n\n"); 
}

void XABCD()
{
	printf("请分别输入X、A、B、C和D的值\n"); 
	printf("X:");
	scanf("%f",&X);
	printf("A:");
	scanf("%f",&A);
	printf("B:");
	scanf("%f",&B);
	printf("C:");
	scanf("%f",&C);
	printf("D:");
	scanf("%f",&D);
	
	XABCD_count(); //已知X、A、B、C和D计算攻守位置函数
} 

void print()
{
	printf("请输入目前已知XABCD几个量：");
	scanf("%d",&i);
	
	if (i<2 || i>5)   //一共5个量，至少知道2个，至多知道5个。
	  printf("\n输入有误！\n\n"); 
	if (i == 2)
      XA();
	if (i == 3)
      XAB();	
	if (i == 4)
	  XABC();
	if (i == 5)
      XABCD();	
}

void cycle()
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
	print();
    cycle();
	return 0;
}
 
