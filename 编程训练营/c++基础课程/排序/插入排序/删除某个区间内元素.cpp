/*
	Name: ɾ��ĳ��������Ԫ�� 
	Copyright: 
	Author: 
	Date: 18\09\18 13:50
	Description: ��дһ������ɾ������A��Ԫ��ֵ��[x,y]���������Ԫ�أ�
	�������µ����鳤�ȡ� 
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

int Fun(int A[], int n, int x, int y); 

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%100 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	int n = Fun(A, MAX, 50, 70);
	
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

int Fun(int A[], int n, int x, int y)
{
	int k = 0;
	
	for (int i=0; i<n; i++)
	{
		if (A[i] >= x && A[i] <= y)
		   k++;
        else
	        A[i-k] = A[i]; //ǰ��k��λ�� 
	}
	return n - k;
}
