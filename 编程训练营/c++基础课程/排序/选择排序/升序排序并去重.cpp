/*
	Name: ��������ȥ�� 
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: ��д����������A�����������򣬲�ȥ���ظ���Ԫ�أ�����������ĳ��ȡ�
	�����д�����е���䲹��������
int SelectSort2(int n)
{
	int i = 0, j, k, r = n - 1;
	while (i < r)
	{
		k =  //���1 
		for (j=r; j>i; j--)
		{
			if (A[j] == A[i])
			{
				A[j] = //���2 
				if (k == r)
				   k = //���3 
	            r--;
			}   
		    else if (A[k] > A[j])
                k = //���4
		}
		if (k != i)
		   swap(A[i], A[k]);
        else  
        	//���5
	}
	return //���6
} 
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

int SelectSort1(int n); 
int SelectSort2(int n); 
int SelectSort3(int n); 

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%5 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << SelectSort3(MAX) << endl;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

int SelectSort1(int n)
{
	int i, j, k, r = n - 1;
	for (i=0; i<r; i++)
	{
		k = i;
		for (j=i+1; j<=r; j++)
		{
			if (A[j] == A[k])
    	        A[j--] = A[r--];   
		    else if (A[k] > A[j])
                k = j;
		}
		if (k != i)
		   swap(A[i], A[k]);
	}
	return r + 1;
}

int SelectSort2(int n)
{
	int i = 0, j, k, r = n - 1;
	while (i < r)
	{
		k = i;
		for (j=r; j>i; j--)
		{
			if (A[j] == A[i])
			{
				A[j] = A[r];   
				if (k == r)
				   k = j;
	            r--;
			}   
		    else if (A[k] > A[j])
                k = j;
		}
		if (k != i)
		   swap(A[i], A[k]);
        else  //ע�⣺ֻ��δ����ʱ��ǰ������������Դ�����A[k]��ֵ����СԪ�� 
        	i++;
	}
	return r + 1;
}

int SelectSort3(int n)
{
	int i = 0, j, k, r = n - 1;
	while (i < r)
	{
		k = i;
		for (j=i+1; j<=r; j++)
		{
			if (A[j] == A[i])
				A[j--] = A[r--]; 
		    else if (A[k] > A[j])
                k = j;
		}
		if (k != i)
		   swap(A[i], A[k]);
        else  
        	i++;
	}
	return r + 1;
}
