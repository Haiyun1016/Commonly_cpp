#include <stdio.h>
#include <stdlib.h>

int main()
{
	int zhang;       //�Ӳֺ������� 
	int zhang_1,zhang_2;   //����  
    float position,position_1,position_2;
    
	printf("��������������δ��Ӳֵ���Ŀ���λ\n\n");
	printf("������Ŀǰ�ɱ��۸� ��");
	scanf("%f",&position_1);
	printf("������Ŀǰ�ֲ����� ��");
	scanf("%d",&zhang_1);
	printf("������Ŀ��ɱ��۸� ��");
	scanf("%f",&position_2);
	printf("������Ŀ��Ӳ����� ��");
	scanf("%d",&zhang_2);
	
	zhang = zhang_1 + zhang_2;
	position = (position_2 * zhang - position_1 * zhang_1) / zhang_2;
//�ֲֳɱ�������һ������۸���ֲ��������Ӳ�ʱ�۸���Ӳ�������������һ�γֲ��������Ӳ�������  
	
	printf("\n����Ҫ�ڼ۸�Ϊ��%.2fʱ�Ӳ�%d��\n\n",position,zhang_2);

	system("pause");
	return 0; 
}
