/*
	Name: 05:�������12λС���ĸ�����
	Copyright: 
	Author: 
	Date: 10-07-16 07:08
	Description: 
	05:�������12λС���ĸ�����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ��˫���ȸ�����������12λС������������������

����
ֻ��һ�У�һ��˫���ȸ�������
���
Ҳֻ��һ�У�����12λС���ĸ�������
��������
3.1415926535798932
�������
3.141592653580

�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	516kB	0ms	    170 B   	G++	   10-07-16 07:14
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main( )
{
	double a;
	
	cin >> a;
	
	cout << fixed << setprecision(12) << a << endl;
	printf("%.12lf", a);
    
    return 0;
}
