/*
	Name: 18_��֤�Ӵ�
	Copyright: 
	Author: 
	Date: 01-09-17 22:06
	Description: 18_��֤�Ӵ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���������ַ�������֤����һ�����Ƿ�Ϊ��һ�������Ӵ���
����
���������ַ�����ÿ���ַ���ռһ�У����Ȳ�����200�Ҳ����ո�
���
����һ����s1�ǵڶ�����s2���Ӵ��������(s1) is substring of (s2) 
�������ڶ�����s2�ǵ�һ����s1���Ӵ������(s2) is substring of (s1) 
������� No substring��
��������
abc
dddncabca
�������
abc is substring of dddncabca
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;
char S1[N],S2[N];

int main() 
{
	gets(S1); gets(S2);
	if (strlen(S1) >= strlen(S2))
	{
		if (strstr(S1, S2) != NULL)
			cout << S2 << " is substring of " << S1 << endl;
		else
			cout << "No substring" << endl;
	}
	else
	{
		if (strstr(S2, S1) != NULL)
			cout << S1 << " is substring of " << S2 << endl;
		else
			cout << "No substring" << endl;
	}
	return 0;	
} 
