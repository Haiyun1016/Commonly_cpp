#include <stdio.h>
#include <stdlib.h>

void print()
{
	float A,B,C;
	float D1,D2,D3;
	printf("������Ϊ���ɲ�����λ���㹫ʽ��������������㣡\n\n");
	printf("ʹ�ñ������������£�\n�۸��ȴ�һ�����Եĸߵ��͵�A�˶�����B\nȻ���۷�����C���ٰ�ԭ���ķ����˶�����D\n���D���������ܵĵ�λ\n");
	printf("��ֱ�����A,B,C��ֵ\n");
	printf("A:");
	scanf("%f",&A);
	printf("B:");
	scanf("%f",&B); 
	printf("C:");
	scanf("%f",&C);
	D1=C+0.618*(B-A);
	D2=C+1*(B-A);
	D3=C+1.618*(B-A);
	printf("\n����ó���\n");
	printf("D1=%.2f\tD2=%.2f\tD3=%.2f",D1,D2,D3);
	printf("\n\n˵����\n");  
	printf("1.һ�����ȡD2��\n2.���������ȡD1��\n3.��D3����һ���ܴ��ѹ������D1��D2������ѹ��λ��������һ����С��������ͻ�Ƶ�ѹ��λ��ͬʱ�����ܵ���Ϣ��̼����Ƚ�ǿ�ƣ���ȡD3��\n");
}

int main()
{
	int i;
	print();
	printf("\n�Ƿ���Ҫ�ٴμ��㣿�����������1����������2��\n");
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
 
