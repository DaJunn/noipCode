/*
	Name: ����ѡ����1
	Copyright: 
	Author: 
	Date: 04\09\18 15:49
	Description: 
	1.	�����´���Σ�
	int A[11], n = 10;
	for (int i=0; i<=n/2; i++)
		A[i] = 2 * i + 1;
	for (int i=n; i>=6; i--)
		A[i] = A[n-i];
    cout << A[n-3];
	ִ����������κ󣬳�������� C  ��
	A 3   B 5   C 7   D 9 
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	int A[11], n = 10;
	for (int i=0; i<=n/2; i++)
		A[i] = 2 * i + 1;
	for (int i=n; i>=6; i--)
		A[i] = A[n-i];
    cout << A[n-3];
	
	return 0;	
} 
