/*
	Name: ɾ��������ֵͬ 
	Copyright: 
	Author: 
	Date: 18\09\18 13:50
	Description: ��֪����A��Ԫ��ֵ���ǵݼ��������У���дһ������ɾ��������ͬԪ�أ�
	�������µ����鳤�ȡ� 
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX] = {1,1,3,3,5,6,7,7,7,7};

int Fun(int A[], int n); 
int Fun2(int A[], int n);
int Fun3(int A[], int n);

int main()
{
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	int n = Fun3(A, MAX);
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

int Fun(int A[], int n)
{
	int i = 1, j;
	
	while (i < n)
	{
		if (A[i-1] != A[i])
		   i++;
        else
        {
        	for (j=i; j<n; j++)
        		A[j-1] = A[j];
       		n--;
		}
	}
	return n;
}


int Fun2(int A[], int n)
{
	int i, j, k, num;
	
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n && A[j]==A[i]; j++);
		num = j - i - 1; //��A[i]��ֵ��Ԫ�ظ��� 
		if (num > 0)
		{
			for (k=j; k<n; k++) //�����ƶ� 
				A[k-num] = A[k];
			n -= num;
		}
	}
	return n;
}


int Fun3(int A[], int n)
{
	int k = 0;
	
	for (int i=1; i<n; i++)
	{
		if (A[i-1] == A[i])
		   k++;
        else
	        A[i-k] = A[i]; //ǰ��k��λ�� 
	}
	return n - k;
}
