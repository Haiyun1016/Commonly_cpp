#include <stdio.h>
#include <stdlib.h>

int i;                 //i��¼�û�����Ŀǰ��֪���ĸ��� 
float X,A,B,C,D;
float Ba[2],Ca[2],Da[3],E[2]; //a��array�����飩����д��E[3]��¼D��ȷ����ֹ��λ�ͽ���λ 

void XA_B_count() //��֪X��A����B�㺯�� 
{
	Ba[0] = A + (X-A) * 0.618;
	Ba[1] = A + (X-A) * 0.786; 
	
	printf("\n"); 
	printf("----------------%.2f\n",Ba[1]);
	printf("----------------%.2f\n",Ba[0]);
	
	printf("\nҪ��Ӱ�߻�ʵ������X->A쳲�������0.618~0.786�����ڣ�����B�㲻������\n\n"); 
}
 
void XA()
{
	printf("��ֱ�����X��A��ֵ\n"); 
	printf("X:");
	scanf("%f",&X);
	printf("A:");
	scanf("%f",&A);
	
	XA_B_count(); //��֪X��A����B�㺯��
}

void XAB_C_count() //��֪X��A��B����C�㺯�� 
{
	Ca[0] = B - (B-A) * 0.382;
	Ca[1] = B - (B-A) * 0.886; 
	
	printf("\n"); 
	printf("----------------%.2f\n",Ca[0]);
	printf("----------------%.2f\n",Ca[1]);
	
	printf("\nC����Ҫ����A->B쳲�������0.382~0.886������\n\n"); 
}

void XAB() 
{
	printf("��ֱ�����X��A��B��ֵ\n"); 
	printf("X:");
	scanf("%f",&X);
	printf("A:");
	scanf("%f",&A);
	printf("B:");
	scanf("%f",&B);
	
	XAB_C_count(); //��֪X��A��B����C�㺯��
}

void XABC_D_count() //��֪X��A��B��C����D�㺯�� 
{
	Da[0] = A + (X-A) * 0.786;
	Da[1] = A + (B-A) * 1.272;
	Da[2] = A + (B-A) * 1.618; 
	
	printf("\n");
	printf("----------------%.2f��B->A 161.8%��\n",Da[2]); 
	printf("----------------%.2f��B->A 127.2%��\n",Da[1]);
	printf("----------------%.2f��X->A  78.6%��\n",Da[0]);
	
	printf("\n���D������X->A쳲�������0.786��B->A쳲�������1.272������,�����Է�ת�źż�������\n");
	printf("\n���D������B->A쳲�������1.272~1.618�����ڣ��ȷ�ת�ź�����\n\n"); 
}

void XABC()
{
	printf("��ֱ�����X��A��B��C��ֵ\n"); 
	printf("X:");
	scanf("%f",&X);
	printf("A:");
	scanf("%f",&A);
	printf("B:");
	scanf("%f",&B);
	printf("C:");
	scanf("%f",&C);
	
	XABC_D_count(); //��֪X��A��B��C����D�㺯�� 
}

void XABCD_count() //��֪X��A��B��C��D���㹥��λ�ú��� 
{
	E[0] = A + (X-A) * 0.382;
	E[1] = A + (X-A) * 0.618;
	
	printf("\n");
	printf("----------------%.2f��ֹ���λ��\n\n",X); 
	printf("----------------%.2f��X->A  61.8%��\n",E[1]);
	printf("----------------%.2f��X->A  38.2%��\n",E[0]);
	
	printf("\nX�ĵ�λΪֹ��λ��\n");
	printf("\n��һ����λΪ0.618���ڶ�����λΪ0.382\n\n"); 
}

void XABCD()
{
	printf("��ֱ�����X��A��B��C��D��ֵ\n"); 
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
	
	XABCD_count(); //��֪X��A��B��C��D���㹥��λ�ú���
} 

void print()
{
	printf("������Ŀǰ��֪XABCD��������");
	scanf("%d",&i);
	
	if (i<2 || i>5)   //һ��5����������֪��2��������֪��5����
	  printf("\n��������\n\n"); 
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
	printf("\n�Ƿ���Ҫ�ٴμ��㣿�����������1����������2��\n");
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
 
