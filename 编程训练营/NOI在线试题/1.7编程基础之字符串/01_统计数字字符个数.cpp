/*
	Name: 01_ͳ�������ַ�����
	Copyright: 
	Author: 
	Date: 31-08-17 15:27
	Description: 01_ͳ�������ַ�����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ���ͳ�Ƴ����������ַ��ĸ�����
����
һ���ַ������ܳ��Ȳ�����255��
���
���Ϊ1�У�����ַ������������ַ��ĸ�����
��������
Peking University is set up at 1898.
�������
4
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 256;
char A[N];

int main() 
{
	int s = 0;
	gets(A);
	for (int i=0; A[i]!='\0'; i++)
	{
		s += (A[i]>='0' && A[i]<='9');
	}
	cout << s << endl;
	
	return 0;	
} 

