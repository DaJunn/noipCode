/*
	Name: ����˹̹�Ľ���
	Copyright: 
	Author: 
	Date: 19-08-18 10:01
	Description: ����˹̹�Ľ��ݡ�
����˹̹����һ����������ѧ�⣺��һ�������ݣ�
��ÿ����2�ף������ʣһ�ף���ÿ����3 �ף������ʣ2�ף���ÿ����5�ף������ʣ4�ף���ÿ����6�������ʣ5�ס�
ֻ��ÿ�ο�7�ף���������һ�ײ�ʣ�����������ж��ٽ��ݣ�
*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	int n = 0;
	while (1)
	{
		n += 7;
		if (n%2==1 && n%3==2 && n%5==4 && n%6==5)
			break;
	}
	
	cout << n << endl;
	
	return 0;
}
