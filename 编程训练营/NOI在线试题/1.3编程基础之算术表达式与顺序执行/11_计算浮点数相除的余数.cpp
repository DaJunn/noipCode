/*
	Name: 11:���㸡�������������
	Copyright: 
	Author: 
	Date: 11-07-16 15:38
	Description: 
	11:���㸡�������������
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��������˫���ȸ�����a��b�������������a��b���������ġ�����������r���Ķ����ǣ�a = k * b + r������ k�������� 0 <= r < b��

����
�����һ�У���������˫���ȸ�����a��b��
���
���Ҳ��һ�У�a��b������
��������
73.263 0.9973
�������
0.4601
��ʾ
ע�⣺���ʱС��β��û�ж����0���������������ָ�ʽ��
double x;
x = 1.33;
printf("%g", x);

�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	200kB	6ms	    178 B   	G++    2016-07-11 15:29:03
����׾	Accepted	10	200kB	0ms	    158 B   	G++    2016-07-11 15:35:22
*/
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int main( )
//{
//	double a, b;
//	
//	cin >> a >> b;
//	
//	while (a >= b)
//	{
//		a -= b;
//	}
//	
//	printf("%g", a);
//	
//    return 0;
//}

#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	double a, b;
	
	cin >> a >> b;

	printf("%g", a - b * int(a/b));
	
    return 0;
}

