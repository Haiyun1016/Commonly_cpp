#include <stdio.h>
#include <stdlib.h>

float position_1,position_2;                 //�����յ� 
float position_up[3],position_down[3];       //�ص��򷴳����������
float position_true;

//�����˻ص�Ϊ�գ��µ��˻ص�Ϊ��
//MIN-1 ��С�ص�����ֵ down[0] 
//MIN-2 ��С�ص�����ֵ up[0] 
//MID   50%�ص�ֵ      up[1]
//MAX-1 ���ص�����ֵ down[2]
//MAX-2 ���ص�����ֵ up[2] 
//�������У�down[0]>up[0]>up[1]>down[2]>up[2] 
//�µ����У�down[0]<up[0]<up[1]<down[2]<up[2]

void print_main()
{
	printf("��������������ص��򷴳��λ\n\n");
	printf("������һ���͵����һ���ߵ㣺");
	scanf("%f",&position_1);
	printf("������һ���ߵ����һ���͵㣺");
	scanf("%f",&position_2);
	printf("��������ʵ�ص�ֵ:");
	scanf("%f",&position_true);
}

void print_up()
{
	printf("\n�ڸ��������У�\n");
	printf("\n��С�ص�����\n");
	printf("----------------%.2f\n",position_up[0]);
	printf("----------------%.2f\n",position_down[0]);
	printf("\n���ܻص�����\n\n");
	printf("****************%.2f\n",position_up[1]);
	printf("\n��������С�ص�����Сֵ�͸�λ���γɵ��������࣡\n");
	printf("\n���ص�����\n");
	printf("++++++++++++++++%.2f\n",position_up[2]); 
	printf("++++++++++++++++%.2f\n",position_down[2]);
	printf("\n����ص����������ص���%.2f�������볡���õ�ɹ�ֹ��\n\n",position_down[2]);
} 

void print_down()
{
	printf("\n�ڸ��µ����У�\n");
	printf("\n��󷴳�����\n");
	printf("++++++++++++++++%.2f\n",position_up[2]); 
	printf("++++++++++++++++%.2f\n",position_down[2]);
	printf("\n������鳬������󷴳��%.2f�������볡���õ�ɹ�ֹ��\n\n",position_up[2]);
	printf("\n���ܷ�������\n\n");
	printf("****************%.2f",position_up[1]);
	printf("\n��������С��������ֵ�͸�λ���γɵ��������գ�\n");
	printf("\n��С��������\n");
	printf("----------------%.2f\n",position_up[0]);
	printf("----------------%.2f\n",position_down[0]);
}

void count_up()
{
	position_up[0] = position_2 - (position_2 - position_1) * 0.33;    //33%�ص� 
	position_down[0] = position_2 - (position_2 - position_1) * 0.382; //38.2%�ص�	
	position_up[1] = position_2 - (position_2 - position_1) * 0.5;     //50%�ص� 
	position_up[2] = position_2 - (position_2 - position_1) * 0.618;   //61.8%�ص� 
	position_down[2] = position_2 - (position_2 - position_1) * 0.66;  //66%�ص�
	print_up();
}

void count_down()
{
	position_up[0] = position_2 + (position_1 - position_2) * 0.382;  //38.2%�ص� 
	position_down[0] = position_2 + (position_1 - position_2) * 0.33; //33%�ص�
	position_up[1] = position_2 + (position_1 - position_2) * 0.5;  //50%�ص�
	position_up[2] = position_2 + (position_1 - position_2) * 0.66;  //66%�ص� 
	position_down[2] = position_2 + (position_1 - position_2) * 0.618; //61.8%�ص�
	print_down();
}

void test_up()   //�����˲��� 
{
	if (position_true > position_up[0]) 
	{
		printf("\n����������ʵ�ص�û�дﵽ��С�ص�\n");
	}
	if (position_true <= position_up[0] && position_true > position_down[0]) 
	{
		printf("��������ʵ�ص���MIN��Χ��\n");
	}
	if (position_true <= position_down[0] && position_true > position_up[1]) 
	{
		printf("��������ʵ�ص���MIN-2��MID��Χ��\n");
	}
	if (position_true <= position_up[1] && position_true > position_up[2]) 
	{
		printf("��������ʵ�ص���MID��MAX-1��Χ��\n");
	}
	if (position_true <= position_up[2] && position_true > position_down[2]) 
	{
		printf("��������ʵ�ص���MAX��Χ��\n");
	}
	if (position_true < position_down[2])  
	{
		int i; 
		printf("\n��ʱ��ʵ�ص����������ص��������Ƿ�ת�������������1����������2��\n"); 
		scanf("%d",&i);
		if (i == 1)
		 printf("\n��������Ȼ�������ص���Χ���������Ѿ���ת\n");
		if (i == 2)
		 printf("\n����������Ȼ�������ص���Χ��������û�з�ת\n");
	}
	
}

void test_down()   //�µ��˲��� 
{
	if (position_true < position_down[0]) 
	{
		printf("\n����������ʵ�ص�û�дﵽ��С�ص�\n");
	}
	if (position_true >= position_down[0] && position_true < position_up[0]) 
	{
		printf("��������ʵ�ص���MIN��Χ��\n");
	}
	if (position_true >= position_up[0] && position_true < position_up[1]) 
	{
		printf("��������ʵ�ص���MIN-2��MID��Χ��\n");
	}
	if (position_true >= position_up[1] && position_true < position_down[2]) 
	{
		printf("��������ʵ�ص���MID��MAX-1��Χ��\n");
	}
	if (position_true >= position_down[2] && position_true < position_up[2]) 
	{
		printf("��������ʵ�ص���MAX��Χ��\n");
	}
	if (position_true > position_up[2]) 
	{
		int i; 
		printf("\n��ʱ��ʵ�ص����������ص��������Ƿ�ת�������������1����������2��\n");
		scanf("%d",&i);
		if (i == 1)
		 printf("\n��������Ȼ�������ص���Χ���������Ѿ���ת\n");
		if (i == 2)
		 printf("\n����������Ȼ�������ص���Χ��������û�з�ת\n");
	} 
}

void up() //������
{
	if (position_2 >= position_1)   
	{
		count_up();
		test_up();		 	
	}
}

void down() //�µ���
{
	if (position_2 < position_1)   
	{		
		count_down();
		test_down();		
	}
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
	print_main();
	up();
	down(); 
	cycle();	 
	return 0; 
}
