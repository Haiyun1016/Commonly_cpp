//������ cout���ָ��λ�������㲹0 
#include <iostream>
#include <iomanip>   //�����ͷ�ļ�
using namespace std;

int main()
{
	int a = 123;
	cout << setw(6) << setfill('0') << a << endl;
	return 0;	
} 
