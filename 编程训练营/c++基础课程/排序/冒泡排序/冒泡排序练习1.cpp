/*
	Name: ð��������ϰ1 
	Copyright: 
	Author: 
	Date: 04\09\18 10:40
	Description: ����Ԫ��A[1]��A[6]��ֵ����Ϊ{52,6,39,47,15,21}��
	�����ó���μӹ�������Ԫ��A[1]��A[6]��ֵ����Ϊ���٣� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M] = {0,52,6,39,47,15,21};

int main() 
{
	for (int i=1; i<=2; i++)
	{
		for (int j=1; j<=6-i; j++)
		{
			if (A[j] > A[j+1])
				swap(A[j], A[j+1]);
		}
	}
	for (int i=0; i<M; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 
