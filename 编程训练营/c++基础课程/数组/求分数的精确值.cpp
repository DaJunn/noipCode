/*
	Name: ������ľ�ȷֵ 
	Copyright: 
	Author: 
	Date: 02-09-18 16:02
	Description: ������ľ�ȷֵ 
	������Ӻͷ�ĸ��������̣������Ϊѭ��С������ѭ������������������
	���������㵽��200λ�� 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 201;
int A[MAX] = {0};
int B[MAX] = {0};

int Fun(int m, int n); //������ľ�ȷֵ�������̵ĳ��� 
int Circulate(int n);//����ѭ���ڵ�λ�� 

int main() 
{
	int m, n;
	cin >> m >> n;
	while(m > 0 && n > 0)
	{
		cout << Fun(m, n) << endl;
		cin >> m >> n;
	}
	
    return 0;
}

int Fun(int m, int n) //������ľ�ȷֵ�������̵ĳ��� 
{
	int pos = 0; //ѭ���ڵ�λ��
	int pa = 0, pb = 0;
	
	A[0] = m / n;
	B[0] = m % n;
	while (B[pb] != 0 && pa < MAX && pos == pb)
	{
		m = B[pb] * 10;
		A[++pa] = m / n;
		B[++pb] = m % n;
		pos = Circulate(pb);
	}
	cout << A[0] << ".";
	for (int i=1; i<=pos; i++)
		cout << A[i];
	if (pos != pb)
		cout << "(";
	for (int i=pos+1; i<=pa; i++)
		cout << A[i];
	if (pos != pb)
		cout << ")";
	cout << endl;
	
	return pa;
}

int Circulate(int n)//����ѭ���ڵ�λ�� 
{
	for (int i=0; i<n; i++)
	{
		if (B[i] == B[n])
			return i;
	}
	return n;
}
