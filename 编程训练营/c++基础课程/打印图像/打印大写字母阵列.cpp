/*
	Name: ��ӡ��д��ĸ����
	Copyright: 
	Author: 
	Date: 19-08-18 21:34
	Description: ����n����ӡ��д��ĸ����
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)//��ӡ��������
	{
		for (int j=0; j<n-i; j++)//����ո� 
			cout << " ";
		for (int j=0; j<i; j++)//˳�������ĸ 
			cout << char('A'+j);
		for (int j=i-2; j>=0; j--)//���������ĸ 
			cout << char('A'+j);
		cout << endl;
	} 
    return 0;               
}           
