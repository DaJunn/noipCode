/*
	Name: 02_�����߷�����ѧ������
	Copyright: 
	Author: 
	Date: 15-08-17 21:00
	Description: 02_�����߷�����ѧ������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����ѧ����������Ȼ��������ÿλѧ���ķ�����������������߷�����ѧ����������

����
��һ������һ��������N��N <= 100������ʾѧ����������������N�У�ÿ�и�ʽ���£�
���� ����
������һ���Ǹ���������С�ڵ���100��
����Ϊһ���������ַ������м�û�пո񣬳��Ȳ�����20��
���ݱ�֤��߷�ֻ��һλͬѧ��
���
�����߷���ͬѧ��������
��������
5
87 lilei
99 hanmeimei
97 lily
96 lucy
77 jim
�������
hanmeimei
*/
#include <iostream>
#include <string>

using namespace std;

const int M = 100;
int A[M];
string B[M];

int main() 
{
	int n;
	
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
		cin >> B[i];
	}
	
	int p = 0;	
	for (int i=0; i<n; i++)
	{
		if (A[i] > A[p])
			p = i;
	}
	cout << B[p] << endl;
	
	return 0;	
} 
