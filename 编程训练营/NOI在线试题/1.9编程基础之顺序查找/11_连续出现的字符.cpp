/*
	Name: 11_�������ֵ��ַ�
	Copyright: 
	Author: 
	Date: 16-08-17 14:56
	Description: 11_�������ֵ��ַ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ��������ַ������ҵ���һ��������������k�ε��ַ���
����
��һ�а���һ��������k����ʾ������Ҫ�������ֵĴ�����1 <= k <= 1000��
�ڶ��а�����Ҫ���ҵ��ַ������ַ���������1��1000֮�䣬�Ҳ������κοհ׷���
���
������������������k�ε��ַ���������ַ����������No��
��������
3
abcccaaab
�������
c
*/
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string A;
	int k;
	cin >> k;
	cin >> A;
	int n = A.length();
	
	if (k == 1)//��������k==1������
	{
		cout << A[0] << endl;
		return 0;
	} 
	
	int s = 1;
	for (int i=1; i<n; i++)
	{
		if (A[i] == A[i-1])
		{
			if (++s == k)
			{
				cout << A[i] << endl;
				return 0;
			} 
		}
		else //��ԭ 
		{
			s = 1;
		}
	}
	cout << "No" << endl;
	
	return 0;	
} 
