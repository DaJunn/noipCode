/*
	Name: ��������ż���ֳ����� 
	Copyright: 
	Author: 
	Date: 30-08-18 16:26
	Description: ��һ����������Ҫ���������ż���ֳ����룬����������ǰ��ż���ں󣬷��������������� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M];

int Fun(int n);//Ҫ���������ż���ֳ����룬����������ǰ��ż���ں󣬷�������������

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

int Fun(int n)//Ҫ���������ż���ֳ����룬����������ǰ��ż���ں󣬷�������������
{
    int i = 0, j = n - 1;
	
    while (i < j)
    { 
        while (i < j && A[i] % 2 == 1)
			i++;
		while (i < j && A[j] % 2 == 0)
			j--;
		if (i < j)
			swap(A[i++], A[j--]);
    }
    if (A[j] % 2 == 0)
    	j--;
    return j+1;
}


