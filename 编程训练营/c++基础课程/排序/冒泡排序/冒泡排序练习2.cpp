/*
	Name: ð��������ϰ2
	Copyright: 
	Author: 
	Date: 04\09\18 10:40
	Description:
	�����´���Σ�
	for (int i=1; i<=9; i++)
	{
		for (int j=10; j>=i+2; j--)
		{
			if (A[j] < A[j-2])
				swap(A[j], A[j-2]);
		}
	}
	 ����Ԫ��A[1]��A[10]��ֵ����Ϊ{10,9,8,7,6,5,4,3,2,1}��
	�����ó���μӹ�������Ԫ��A[8]��ֵΪ( A  )
	A 7   B 8    C 9    D 10
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 11;
int A[M] = {0,10,9,8,7,6,5,4,3,2,1};

int main() 
{
	for (int i=1; i<=9; i++)
	{
		for (int j=10; j>=i+2; j--)
		{
			if (A[j] < A[j-2])
				swap(A[j], A[j-2]);
		}
	}
	for (int i=0; i<M; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 
