/*
	Name: ѡ��������ϰ��2
	Copyright: 
	Author: 
	Date: 09-09-18 22:18
	Description: 
	ĳѧУ����У԰���ֱ���������A��Ÿ��ֵĵ÷֣�����B������Ρ�
	���μ������Ϊ���ȶ�����A�е�Ԫ�ذ��ߵ��͵����򣬷�ֵ���Ϊ��1������ֵ��ͬ��������ͬ��
	���統A[6] = {80,70,70,70,60,60}����B[6] = {1,2,2,2,5,5}�� 
���ִ������£��뽫���1�����5��д������ 
for (int i=n-1; i>0; i--)
	{
		int k = i;
		for (int j=0; j<i; j++)
		{
			if ( ) //���1 
				k = j;
		}
		if (k != i)
			swap( );//���2 
	}
	
	B[0] =  ; //���3
	for (int i=1; i<n; i++)
	{
		if (A[i] == A[i-1])
			B[i] =  ; //���4
		else
			B[i] =  ; //���5
	}
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	const int M = 20;
	int A[M] = {0}, B[M] = {0};
	int n = M;
	for (int i=0; i<n; i++)
		A[i] = rand()%9 + 1;
		
	for (int i=n-1; i>0; i--)
	{
		int k = i;
		for (int j=0; j<i; j++)
		{
			if (A[k] < A[j]) //���1 
				k = j;
		}
		if (k != i)
			swap(A[k], A[i]);//���2 
	}
	
	B[0] = 1; //���3
	for (int i=1; i<n; i++)
	{
		if (A[i] == A[i-1])
			B[i] = B[i-1]; //���4
		else
			B[i] = i + 1; //���5
	}
	for (int i=0; i<n; i++)
		cout << A[i] << " " << B[i] << endl;
	
	
	return 0;	
} 
