/*
	Name: ������������ 
	Copyright: 
	Author: 
	Date: 30-08-18 16:26
	Description: ��һ����������Ҫ��������е����������������򣬲����������������������
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 20;
int A[M];

int Fun(int n);//�������е����������������򣬲��������������������

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun(n) << endl;
	
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

int Fun(int n)//�������е����������������򣬲��������������������
{
	int i = 0;
	bool flag = true;
	
	while (flag && i < n)
	{
		flag = false; //���1 
		for (int j=n-1; j>i; j--)
		{
			if (A[j] % 2 == 0)
				continue;  //���2 
			if (A[j-1] % 2 == 0 || A[j-1] > A[j]) //���3 
			{
				swap(A[j], A[j-1]);
				flag = true;
			}
		}
		i++;
	}
	int m = 0;
	while (A[m]%2 == 1) //���4 
		m++;
	
	return m;
}
