/*
	Name: 12:����������
	Copyright: 
	Author: 
	Date: 11-07-16 15:48
	Description: 
	12:����������
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���ڰ뾶Ϊr����������ļ��㹫ʽΪV=4/3*��r3������ȡ��= 3.14��

�ָ���r����V��

����
����Ϊһ��������100�ķǸ�ʵ��������뾶������Ϊdouble��
���
���һ��ʵ��������������������С�����2λ��
��������
4
�������
267.95
�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	200kB	2ms	    186 B    	G++    2016-07-11 15:42:22
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	const double pi = 3.14; 
	double r;
	
	cin >> r;
	
	printf("%.2lf", pi * r * r * r * 4 / 3);
	
    return 0;
}


