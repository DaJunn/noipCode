/*
	Name: 02_�ҵ�һ��ֻ����һ�ε��ַ�
	Copyright: 
	Author: 
	Date: 31-08-17 16:43
	Description: 02_�ҵ�һ��ֻ����һ�ε��ַ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ��ֻ����Сд��ĸ���ַ����������ҵ���һ��������һ�ε��ַ������û�У����no��

����
һ���ַ���������С��100000��
���
�����һ��������һ�ε��ַ�����û�������no��
��������
abcabd
�������
c
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100001;
char A[N];

int main() 
{
	gets(A);
	char *q, *r, *p=A;
	while (*p != '\0')
	{
		q = strchr(A, *p);//����ָ���ַ����ַ����е�һ�γ��ֵ�λ�� 
		r = strrchr(A, *p);//����ָ���ַ����ַ��������һ�γ��ֵ�λ�� 
		if (q == r)
			break;
		p++;
	}
	if (*p != '\0')
		cout << *p << endl;
	else
		cout << "no" << endl;
		
	return 0;	
} 
