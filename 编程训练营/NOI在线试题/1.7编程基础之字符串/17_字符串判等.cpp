/*
	Name: 17_�ַ����е�
	Copyright: 
	Author: 
	Date: 01-09-17 21:35
	Description: 17_�ַ����е�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
�ж������ɴ�Сд��ĸ�Ϳո���ɵ��ַ����ں��Դ�Сд���Һ��Կո���Ƿ���ȡ�
����
���У�ÿ�а���һ���ַ�����
���
�������ַ�����ȣ����YES���������NO��
��������
a A bb BB ccc CCC
Aa BBbb CCCccc
�������
YES
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;
char S1[N],S2[N];

void Fun(char *S);//ȥ���ո񲢽���д��ĸת��ΪСд��ĸ

int main() 
{
	gets(S1); gets(S2);
	Fun(S1); Fun(S2);
	if (strcmp(S1, S2) == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
		
	return 0;	
} 
void Fun(char *S)//ȥ���ո񲢽���д��ĸת��ΪСд��ĸ 
{
	int i, j;
	for (i=0,j=0; S[i]!='\0'; i++)
	{
		if (S[i] == ' ')
			continue;
		if (S[i]>='A' && S[i]<='Z')
			S[j++] = S[i] + 32;
		else
			S[j++] = S[i];
	}
	S[j] = '\0';
}
