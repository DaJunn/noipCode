/*
	Name: ð��������չ1 
	Copyright: 
	Author: 
	Date: 06\09\18 15:23
	Description: 
	������A��ֵ��С��key��Ԫ�ؽ��е�������ͬʱ���ı�С��key��Ԫ�ص�λ�á�
	���磬A[]={34,56,21,45,13,31}����key=30���������A[]={31,34,21,45,13,56} 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M];

void Fun(int n, int key);//������A��ֵ��С��key��Ԫ�ؽ��е�������

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	Fun(n, 10);
	
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void Fun(int n, int key)//������A��ֵ��С��key��Ԫ�ؽ��е�������
{
	int P[M] = {0};
	int m = 0;
	
	for (int i=0; i<n; i++) //��¼����������Ԫ�� 
	{
		if (A[i] >= key)
		   P[m++] = i; //���1 
	}
	for (int i=m-1; i>0; i--)////���2 
	{
		for (int j=0; j<i; j++)
		{
			if (A[P[j]] > A[P[j+1]]) //���3
			   swap(A[P[j]],A[P[j+1]]);
		}
	}
}



