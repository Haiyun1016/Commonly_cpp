#include <stdio.h>
#include <stdlib.h>

int main()
{
	int zhang;       //�Ӳֺ������� 
	int zhang_1,zhang_2;   //����  
    float position,position_1,position_2;
    
	printf("��������������Ӳֺ�ĳɱ���λ\n\n");
	printf("������Ŀǰ�ɱ��۸� ��");
	scanf("%f",&position_1);
	printf("������Ŀǰ�ֲ����� ��");
	scanf("%d",&zhang_1);
	printf("�����뵱ǰ�Ӳּ۸� ��");
	scanf("%f",&position_2);
	printf("�����뵱ǰ�Ӳ����� ��");
	scanf("%d",&zhang_2);
	
	zhang = zhang_1 + zhang_2;
	position = (position_1 * zhang_1 + position_2 * zhang_2) / zhang;
//�ֲֳɱ�������һ������۸���ֲ��������Ӳ�ʱ�۸���Ӳ�������������һ�γֲ��������Ӳ�������  
	
	printf("\n�ڵ�ǰλ�üӲֺ�۸�Ϊ��%.2f\n\n",position);

	system("pause");
	return 0; 
}
