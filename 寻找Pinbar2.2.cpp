#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

#define M 1000
//M�������ǣ��������ݣ���ֹ�۸�����̫С�����㱶��ʱ���׹��� 

double open_price,close_price;   //���̼ۣ����̼�
double max_price,min_price;      //��߼ۣ���ͼ�
double yang_price[10];           //�����߼۸����飬��Ҫ���������� 
double yin_price[10];            //�����߼۸����飬��Ҫ����������
double beishu[8];                //���ʵ�塢����Ӱ������֮������� 

void print()  //���򹹽�����
{
	system("COLOR FC");
	
	cout << "���������ж�Pinbar��\n\n";
	cout << "�����뿪�̼ۣ�";
	cin >> open_price; 
	cout << "��������߼ۣ�";
	cin >> max_price;
	cout << "��������ͼۣ�";
	cin >> min_price;
	cout << "���������̼ۣ�";
	cin >> close_price;	
}

void mainf()  //����ʵ����Ҫ���ܺ��� 
{
	//��������
	void count_yang();
	void count_yin();    
	
	if (open_price > close_price)   //���̼۴������̼ۣ�Ϊ���� 
	{
		count_yin();  //С�������ݴ�����
	}
	if (open_price <= close_price)   //���̼�С�ڵ������̼ۣ�Ϊ����
	{
		count_yang();  //С�������ݴ�����
	}
}

void count_yang()  //С�������ݴ����� 
{
	yang_price[0] = close_price - open_price;             //ʵ�峤��
	yang_price[1] = max_price - close_price;              //��Ӱ�߳���
	yang_price[2] = open_price - min_price;               //��Ӱ�߳���
	yang_price[5] = max_price - min_price;                //Pinbar���
	beishu[0] = yang_price[0] * M;                        //ʵ�峤������M�� 
	beishu[1] = yang_price[1] * M;                        //��Ӱ�߳�������M�� 
	beishu[2] = yang_price[2] * M;                        //��Ӱ�߳�������M�� 
	beishu[6] = yang_price[5] * M;                        //K�߳�������M�� 
	yang_price[3] = beishu[1] / beishu[0];                //��Ӱ�߳���ʵ��
	yang_price[4] = beishu[2] / beishu[0];                //��Ӱ�߳���ʵ��
	
	cout << "\nʵ��ĳ���Ϊ��" << yang_price[0] << endl;
	cout << "��Ӱ�ߵĳ���Ϊ��" << yang_price[1] << endl;
	cout << "��Ӱ�ߵĳ���Ϊ��" << yang_price[2] << endl; 
	cout << "��Ӱ�ߵĳ���Ϊʵ���" << yang_price[3] << "��\n";
	cout << "��Ӱ�ߵĳ���Ϊʵ���" << yang_price[4] << "��\n"; 
	
	if (beishu[1] >= beishu[2])                           //�ж���Ӱ��
	{
		yang_price[6] = beishu[1] / beishu[6];
		cout << "��Ӱ�ߵĳ���Ϊ����K�ߵ�" << yang_price[6] << "��\n"; 
	}
	if (beishu[1] < beishu[2])
	{
		yang_price[6] = beishu[2] / beishu[6];
		cout << "��Ӱ�ߵĳ���Ϊ����K�ߵ�" << yang_price[6] << "��\n";
	}
	
	void pinbar_yang();  
	pinbar_yang();	
}

void count_yin()  //С�������ݴ����� 
{
	yin_price[0] = open_price - close_price;              //ʵ�峤��
	yin_price[1] = max_price - open_price;                //��Ӱ�߳���
	yin_price[2] = close_price - min_price;               //��Ӱ�߳���
	yin_price[5] = max_price - min_price;                 //Pinbar���
	beishu[3] = yin_price[0] * M;                         //ʵ�峤������M�� 
	beishu[4] = yin_price[1] * M;                         //��Ӱ�߳�������M�� 
	beishu[5] = yin_price[2] * M;                         //��Ӱ�߳�������M�� 
	beishu[7] = yin_price[5] * M;                        //K�߳�������M��
	yin_price[3] = beishu[4] / beishu[3];                 //��Ӱ�߳���ʵ��
	yin_price[4] = beishu[5] / beishu[3];                 //��Ӱ�߳���ʵ��
	
	cout << "\nʵ��ĳ���Ϊ��" << yin_price[0] << endl;
	cout << "��Ӱ�ߵĳ���Ϊ��" << yin_price[1] << endl;
	cout << "��Ӱ�ߵĳ���Ϊ��" << yin_price[2] << endl;
	cout << "��Ӱ�ߵĳ���Ϊʵ���" << yin_price[3] << "��\n";
	cout << "��Ӱ�ߵĳ���Ϊʵ���" << yin_price[4] << "��\n";
	
	if (beishu[4] >= beishu[5])                           //�ж���Ӱ��
	{
		yin_price[6] = beishu[4] / beishu[7]; 
		cout << "��Ӱ�ߵĳ���Ϊ����K�ߵ�" << yin_price[6] << "��\n"; 
	}
	if (beishu[4] < beishu[5])
	{
		yin_price[6] = beishu[5] / beishu[7];
		cout << "��Ӱ�ߵĳ���Ϊ����K�ߵ�" << yin_price[6] << "��\n";
	} 
	 
	void pinbar_yin();
	pinbar_yin();
} 

void pinbar_yang()  //�������õ����ݺ��� 
{
	if (yang_price[1] >= yang_price[2])  //�ж��������ߣ�С���� 
	{
		if (yang_price[3] > 2)
		{
			cout << "\n��С����Ϊ������\n";
			cout << "���������Ƿ�λ��һ����������Ķ��ˣ�λ�ò��ԣ�Ч��ȫ�ޣ�\n";
			cout << "ֹ��۸�Ϊ��" << max_price;
			
	    	cout << "\n\n��һ���볡��ʽ��\n";
	    	cout << "�볡���ռ۸�Ϊ���̼۸�" << open_price;
	    	cout << "\n�����۸�ΪPinbar�����" << open_price - yang_price[5];
	    	cout << "\n��ʱӯ����Ϊ��" << yang_price[5] / (max_price - open_price); //ӯ����λ��Pinbar���
	    	
	    	cout << "\n\n�ڶ����볡��ʽ��\n";
	    	cout << "�볡���ռ۸�Ϊ�ص�50%�۸�" << (max_price + min_price) / 2;
			cout << "\n�����۸�ΪPinbar�����" << open_price - yang_price[5];
			cout << "\n��ʱӯ����Ϊ��" << yang_price[5] / (max_price - (max_price + min_price) / 2); //ӯ����λ��Pinbar���
		}
		if (yang_price[3] <= 2)
		  cout << "\n�����������ߵĶ��壡\n";
	}
	
	if (yang_price[1] < yang_price[2])  //�ж��Ǵ����ߣ�С���� 
	{
		if (yang_price[4] > 2)
		{
            cout << "\n��С����Ϊ������\n";
			cout << "�˴������Ƿ�λ��һ���µ�����ĵ׶ˣ�λ�ò��ԣ�Ч��ȫ�ޣ�\n";
			cout << "ֹ��۸�Ϊ��" << min_price;
			
	    	cout << "\n\n��һ���볡��ʽ��\n";
	    	cout << "�볡����۸�Ϊ���̼۸�" << close_price;
	    	cout << "\n�����۸�ΪPinbar�����" << close_price + yang_price[5];
	    	cout << "\n��ʱӯ����Ϊ��" << yang_price[5] / (close_price - min_price); //ӯ����λ��Pinbar���
	    	
	    	cout << "\n\n�ڶ����볡��ʽ��\n";
	    	cout << "�볡����۸�Ϊ�ص�50%�۸�" << (max_price + min_price) / 2;
	    	cout << "\n�����۸�ΪPinbar�����" << (max_price + min_price) / 2 + yang_price[5];
            cout << "\n��ʱӯ����Ϊ��" << yang_price[5] / ((max_price + min_price) / 2 - min_price);//ӯ����λ��Pinbar��� 
		}
		if (yang_price[4] <= 2)
		  cout << "\n�����ϴ����ߵĶ��壡\n"; 
	} 
}

void pinbar_yin()   //�������õ����ݺ��� 
{
	if (yin_price[1] >= yin_price[2])  //�ж��������ߣ�С���� 
	{
		if (yin_price[3] > 2)
		{
			printf("\n��С����Ϊ������\n");
			printf("���������Ƿ�λ��һ����������Ķ��ˣ�λ�ò��ԣ�Ч��ȫ�ޣ�\n"); 
			cout << "ֹ��۸�Ϊ��" << max_price;
			
	    	cout << "\n\n��һ���볡��ʽ��\n";
	    	cout << "�볡���ռ۸�Ϊ���̼۸�" << close_price;
	    	cout << "\n�����۸�ΪPinbar�����" << close_price - yin_price[5];
	    	cout << "\n��ʱӯ����Ϊ��" << yin_price[5] / (max_price - close_price);//ӯ����λ��Pinbar���  
	    	
	    	cout << "\n\n�ڶ����볡��ʽ��\n";
	    	cout << "�볡���ռ۸�Ϊ�ص�50%�۸�" << (max_price + min_price) / 2;
			cout << "\n�����۸�ΪPinbar�����" << close_price - yin_price[5];
			cout << "\n��ʱӯ����Ϊ��" << yin_price[5] / (max_price - (max_price + min_price) / 2); //ӯ����λ��Pinbar��� 
		}
		if (yin_price[3] <= 2)
		  printf("\n�����������ߵĶ��壡\n"); 
	}
	
	if (yin_price[1] < yin_price[2])  //�ж��Ǵ����ߣ�С���� 
	{
		if (yin_price[4] > 2)
		{
			printf("\n��С����Ϊ������\n");
			printf("�˴������Ƿ�λ��һ���µ�����ĵ׶ˣ�λ�ò��ԣ�Ч��ȫ�ޣ�\n"); 
			cout << "ֹ��۸�Ϊ��" << min_price;
			
	    	cout << "\n\n��һ���볡��ʽ��\n";
	    	cout << "�볡����۸�Ϊ���̼۸�" << open_price;
	    	cout << "\n�����۸�ΪPinbar�����" << open_price + yin_price[5];
	    	cout << "\n��ʱӯ����Ϊ��" << yin_price[5] / (open_price - min_price); //ӯ����λ��Pinbar���
	    	
	    	cout << "\n\n�ڶ����볡��ʽ��\n";
	    	cout << "�볡����۸�Ϊ�ص�50%�۸�" << (max_price + min_price) / 2;
			cout << "\n�����۸�ΪPinbar�����" << (max_price + min_price) / 2 + yin_price[5]; 
			cout << "\n��ʱӯ����Ϊ��" << yin_price[5] / (((max_price + min_price) / 2) - min_price);//ӯ����λ��Pinbar��� 
		}
		if (yin_price[4] <= 2)
		  printf("\n�����ϴ����ߵĶ��壡\n"); 
	} 
}

void look_out()  //Ҫ�㣡
{ 
	printf("\n\n\n��λ�ã�");
	printf("\n");
	printf("\t1.�����߱�������һ����������Ķ���\n");
	printf("\t2.�����߱�������һ���µ�����ĵ׶�\n");
	printf("\t3.Pinbar���봦��ĳ���ؼ�λ��λ�ò��ԣ�Ч��ȫ�ޣ�\n\n");
	
	printf("��������ѡһ����");
	printf("\n");
	printf("\t1.ӯ���ȴ���1.5�������ϸ�ִ�У�40%��ʤ�ʼ�������Ǯ\n");
	printf("\t2.���ٳԵ���Pinbar�����max-min���൱�ĵ�λ\n\n");
		
	printf("�ܽ᣺");
	printf("\n");
	printf("\t1.ֻ�Ҵ����ߺ�������\n");
	printf("\t2.λ��Ҫ�ԣ���������Ч\n");
	printf("\t3.����2�����ϵ��볡���ɣ���������\n\n");
} 

void over()
{
	int i;
	void over(); 
	printf("\n\n������1����������");
	scanf("%d",&i);
	if (i!=1)
	{
		over();	
	}
}

int main()
{
	print();    //���򹹽����� 
	mainf();    //����ʵ����Ҫ���ܺ��� 
	look_out();  
	over();
	system("pause");
	return 0;
}
