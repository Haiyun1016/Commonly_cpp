//本程序 cout输出指定位数，不足补0 
#include <iostream>
#include <iomanip>   //必须的头文件
using namespace std;

int main()
{
	int a = 123;
	cout << setw(6) << setfill('0') << a << endl;
	return 0;	
} 
