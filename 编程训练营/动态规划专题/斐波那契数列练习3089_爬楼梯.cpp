/*
	Name: 3089_��¥��
	Copyright: 
	Author: ����׾ 
	Date: 18-01-18 09:21
	Description: 
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����ʦ��¥�ݣ�������ÿ����1������2��������¥�ݵļ�������ͬ���߷���
���磺¥��һ����3����������ÿ�ζ���һ�������ߵ�һ����һ�����ڶ���������
Ҳ���Ե�һ�����������ڶ�����һ����һ��3�ַ�����

����
������������У�ÿ�а���һ��������N������¥�ݼ�����1 <= N <= 30
���
��ͬ���߷�����ÿһ�������Ӧһ�����
��������
5
8
10
�������
8
34
89
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

int dg(int n);

int main()
{
	int n;
	while(cin >> n)
	{
		cout << dg(n) << endl;
	}
	
	return 0;
}

int dg(int n)
{
	if (n == 1 || n == 2)
		return n;
	int a = 1, b = 2, c = 3;
	for (int i=3; i<=n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

