/*
	Name: 21_�����滻
	Copyright: 
	Author: 
	Date: 02-09-17 16:22
	Description: 21_�����滻
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ������Իس��������ַ�������<=100�������ַ��������ɸ�������ɣ�����֮����һ���ո���������е������ִ�Сд��
����Ҫ�����е�ĳ�������滻����һ�����ʣ�������滻֮����ַ�����
����
�������3�У�
��1���ǰ���������ʵ��ַ��� s;
��2���Ǵ��滻�ĵ���a(���� <= 100);
��3����a�����滻�ĵ���b(���� <= 100).
s, a, b ��ǰ�������涼û�пո�.
���
���ֻ�� 1 �У���s�����е���a�滻��b֮����ַ�����
��������
You want someone to help you
You
I
�������
I want someone to help you
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 101;
char s[N],a[N],b[N];

int main() 
{
	gets(s); gets(a); gets(b);
	int n = strlen(a);
	char *q, *r, *p = s;
	while (*p != '\0')//�����ַ���s
	{
		q = strstr(p, a);
		if (q != NULL)
		{
			for (r=p; r<q; r++)
			{
				cout << *r;
			}
			if ((q==p || *(q-1)==' ') && (*(q+n)=='\0' || *(q+n)==' '))	//ȫ����ƥ�� 
				cout << b;
			else //���ʲ���ƥ�� 
				cout << a;
			p = q + n; 
		}
		else
		{
			cout << p;
			break;
		}
	} 
	cout << endl;
			
	return 0;	
} 
