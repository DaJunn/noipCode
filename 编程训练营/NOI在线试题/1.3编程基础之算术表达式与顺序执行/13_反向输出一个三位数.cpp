/*
	Name: 13:�������һ����λ��
	Copyright: 
	Author: 
	Date: 11-07-16 16:01
	Description: 
	13:�������һ����λ��
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��һ����λ�����������

����
һ����λ��n��
���
�������n��
��������
100
�������
001
�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	200kB	1ms	    166 B    	G++    2016-07-11 15:48:07
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	int r;
	
	cin >> r;
	
	cout << r%10 << (r%100) / 10 << r / 100 << endl;
	
    return 0;
}

