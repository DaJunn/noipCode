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
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 201;
char s0[N],a0[N],b[N];
char s2[N];

int main() 
{
	gets(s0); gets(a0); gets(b);
	int t=0;;
	for (int i=0; s0[i]!='\0'; i++)
	{
		if (s0[i] == ' ')
		{
			s2[t] = '\0'; //����һ���ַ��� 
			t = 0;
			if (strcmp(s2, a0) == 0) //�ж�һ������ 
				cout << b << " ";
			else
				cout << s2 << " ";
		}
		else
		{
			s2[t++] = s0[i];
		}
	}
	s2[t] = '\0'; 
	if (strcmp(s2, a0) == 0) //�ж����һ������ 
		cout << b << endl;
	else
		cout << s2 << endl;
		
	return 0;	
} 
