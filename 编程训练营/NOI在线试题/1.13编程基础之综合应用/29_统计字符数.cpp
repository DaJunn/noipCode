/*
	Name: 29_ͳ���ַ���
	Copyright: 
	Author: 
	Date: 18-08-17 15:31
	Description: 29_ͳ���ַ���
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ����a-z��26���ַ���ɵ��ַ�����ͳ�������ĸ��ַ����ֵĴ�����ࡣ
����
�������һ�У�һ���ַ��������Ȳ�����1000��
���
���һ�У��������ִ��������ַ��͸��ַ����ֵĴ������м���һ���ո�ֿ�������ж���ַ����ֵĴ�����ͬ����࣬��ô���ascii����С����һ���ַ���
��������
abbccc
�������
c 3
*/
#include<iostream>
#include<string>

using namespace std;

int T[26];

int main()
{
	string A;
	cin >> A;
	int n = A.length();
	
	for (int i=0; i<n; i++)//��Ԫ��װ��Ͱ�� 
	{
		T[A[i]-'a']++;
	}
	int m = 0;
	for (int i=1; i<26; i++)  
	{
		if (T[i] > T[m])
			m = i;
	}
	cout << char(m+'a') << " " << T[m] << endl;
	
    return 0;
}
