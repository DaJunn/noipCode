/*
	Name: 19_�ַ�����λ��������
	Copyright: 
	Author: 
	Date: 31-08-17 16:00
	Description: 19_�ַ�����λ��������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ�����˵������һ��ѭ����λ����Ϊ�����ַ����ĵ�һ���ַ��ƶ���ĩβ�γ��µ��ַ�����
���������ַ���s1��s2��Ҫ���ж�����һ���ַ����Ƿ�����һ�ַ���ͨ�����ɴ�ѭ����λ������ַ������Ӵ���
����CDAA����AABCD������λ��������´�BCDAA���Ӵ�����ABCD��ACBD����ͨ�������λ���õ�����һ���ַ������´����Ӵ���
����
һ�У����������ַ������м��ɵ����ո�������ַ���ֻ������ĸ�����֣����Ȳ�����30��
���
���һ���ַ�������һ�ַ���ͨ�����ɴ�ѭ����λ�������´����Ӵ��������true���������false��
��������
AABCD CDAA
�������
true
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 61;
char S1[N],S2[N],T[N];

int main() 
{
	scanf("%s%s", S1, S2);
	if (strlen(S1) < strlen(S2))
	{
		strcpy(T, S1);
		strcpy(S1, S2);
		strcpy(S2, T);
	}
	strcpy(T, S1);
	if (strstr(strcat(S1,T), S2) == NULL)
		cout << "false" << endl;
	else
		cout << "true" << endl;
		
	return 0;	
} 
