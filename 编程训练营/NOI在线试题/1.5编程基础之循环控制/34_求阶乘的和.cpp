/*
	Name: 34_��׳˵ĺ�
	Copyright: 
	Author: ����׾ 
	Date: 03-07-17 21:14
	Description: 34_��׳˵ĺ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����������n���󲻴���n���������Ľ׳˵ĺͣ�����1!+2!+3!+...+n!��

����
������һ�У�����һ��������n��1 < n < 12����
���
�����һ�У��׳˵ĺ͡�
��������
5
�������
153
*/
#include<iostream>

using namespace std;

int main()
{
    int n, s=0, f=1;
    cin >> n;
    
	for (int i=1; i<=n; i++) 
	{
	 	f *= i; // f = i!
	 	s += f;
	} 
	
	cout << s;
			  
    return 0;
}
