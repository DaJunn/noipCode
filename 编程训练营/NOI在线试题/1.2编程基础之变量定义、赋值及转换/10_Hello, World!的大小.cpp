/*
	Name: 10:Hello, World!�Ĵ�С
	Copyright: 
	Author: 
	Date: 10-07-16 09:37
	Description: 
	10:Hello, World!�Ĵ�С
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���ǵ�����һ�����������������ġ�Hello, World!����

����Ȼ���Ǳ������漰�Ļ����������͵����ݣ�������ͬ��������sizeof�����������ռ�õĿռ��С��

����������Ĵ�С����������������Ƿ�һ����

����
�ޡ�
���
һ������������Hello, World!���Ĵ�С��
��������
���ޣ�
�������
�����ṩ��
��ʾ
��Hello, World!��ʵ�������ַ������ͣ�����1.7������ϸ���ܡ�

�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	252kB	0ms	   139 B    	G++      10-07-16 10:24
*/
#include <iostream>

using namespace std;

int main( )
{
	const char s[] = "Hello, World!";
	
	cout << sizeof(s) << endl;
	
    return 0;
}

