/*
	Name: ѡ��������ϰ��1 
	Copyright: 
	Author: 
	Date: 09-09-18 22:18
	Description: 
	for (int i=1; i<=2; i++)
	{
		int k = i;
		for (int j=i+1; j<=5; j++)
		{
			if (A[k] < A[j])
				k = j;
		}
		if (k != i)
			swap(A[k], A[i]);
	}
�����ó���Ρ��ӹ���������Ԫ�� A[1]�� A[5]��ֵ����Ϊ"44,35,30,11,7"��������Ԫ�� A[1]�� A[5]��ԭʼ��������Ϊ��  D��
A.30,44,7,11,35   B.30,11,44,7,35   C.44,30,11,7,35   D.30,7,44,11,35
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	int A[6] = {0,30,7,44,11,35};
	 
	for (int i=1; i<=2; i++)
	{
		int k = i;
		for (int j=i+1; j<=5; j++)
		{
			if (A[k] < A[j])
				k = j;
		}
		if (k != i)
			swap(A[k], A[i]);
	}
	
	for (int i=1; i<=5; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 
