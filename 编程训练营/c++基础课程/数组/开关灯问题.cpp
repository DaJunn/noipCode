/*
	Name: ���ص����� 
	Copyright: 
	Author: 
	Date: 02-09-18 12:49
	Description: ��N���Ʒ���һ��,ȫ�����ڹر�״̬����1��N����˳���š�
��N����Ҳ��1��N���α�š�1�Ž���ȫ����, 2�Ž�����2�ı����ĵƹر�; 
3���������3�ı����ĵƽ��в���......һֱ����n����Ϊֹ�� 
��ôn���˲����������м�յ���ǿ��ŵģ� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

const int M = 40;
int A[M];

int Fun(int n);//���ؾ���n���˲��������ŵĵƵ����� 
int Fun2(int n);//���ؾ���n���˲��������ŵĵƵ����� 

int main() 
{
	int n  = M;
	cout << Fun(n) << endl;
	cout << Fun2(n) << endl;
	
	return 0;	
} 

int Fun(int n)//���ؾ���n���˲��������ŵĵƵ����� 
{
	int F[M] = {0};//0��ʾ�أ�1��ʾ�� 
    for (int i=1; i<=n; i++)
    {
		for (int j=i; j<=n; j+=i)
		{
			F[j] = 1- F[j];
		}
	}
	int s = 0;
	for (int i=1; i<=n; i++)
    {
		if (F[i] == 1)
		{
			cout << i << " ";
			s++;
		}
	}
	cout << endl;
	return s;
}

int Fun2(int n)//���ؾ���n���˲��������ŵĵƵ����� 
{
	int s = 0;
	for (int i=1; i<=n; i++)
    {
		int q = sqrt(i);
		if (i == q*q)
		{
			cout << i << " ";
			s++;
		}
	}
	cout << endl;
	return s;
}
