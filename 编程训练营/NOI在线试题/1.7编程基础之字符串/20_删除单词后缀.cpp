/*
	Name: 20_ɾ�����ʺ�׺
	Copyright: 
	Author: 
	Date: 02-09-17 15:56
	Description: 20_ɾ�����ʺ�׺
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ�����ʣ�����õ�����er��ly����ing��׺��β�� ��ɾ���ú�׺����Ŀ��֤ɾ����׺��ĵ��ʳ��Ȳ�Ϊ0�������򲻽����κβ�����
����
����һ�У�����һ�����ʣ������м�û�пո�ÿ��������󳤶�Ϊ32����
���
���������ĿҪ�����ĵ��ʡ�
��������
referer
�������
refer
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 33;
char S[N];

int main() 
{
	gets(S);
	int n = strlen(S);
	if ((S[n-2]=='e' && S[n-1]=='r') || (S[n-2]=='l' && S[n-1]=='y'))
	{
		for (int i=0; i<n-2; i++)
			cout << S[i];
		cout << endl;
	}
	else if (S[n-3]=='i' && S[n-2]=='n' && S[n-1]=='g')
	{
		for (int i=0; i<n-3; i++)
			cout << S[i];
		cout << endl;
	}
	else
		cout << S << endl;
			
	return 0;	
} 
