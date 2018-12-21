/*
	Name: ѭ����������
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: ѭ������
��������10��[1,100]֮������������ʵ�ֽ���10��������ѭ����������
����β��������һ���������С�Ҫ���һ����Сֵλ�ò��䣬Ȼ�����ν������С�
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 11;
int A[MAX], B[MAX];

void SelectCircleSort(int n);
void SelectCircleSort2(int n);

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%9 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	SelectCircleSort2(MAX);
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void SelectCircleSort(int n) //��һ����Сֵλ�ò��� 
{
	int i, j, k, p=0;
	for (i=1; i<n; i++) //������Сֵ�±� 
	{
		if (A[p] > A[i])
		   p = i;
	}
	B[p] = 1;
	p = (p == 0) ? n-1 : p-1; //��ȡ���ֵ�±� 
 	
	for (i=1; i<n; i++) //��n-1��Ԫ�ذ��յݼ���ѡ������ 
	{
		k = p;
		for (j=0; j<n; j++)
		{
			if (B[j] == 0 && A[j] > A[k]) //�������ֵ�±� 
	    	    k = j;
		}
		if (k != p)
		   swap(A[k], A[p]);
        B[p] = 1;
        p = (p == 0) ? n-1 : p-1; //�����µ����ֵ�±� 
	}
}

void SelectCircleSort2(int n) //��һ�����ֵλ�ò��� 
{
	int i, j, k, p=0;
	for (i=1; i<n; i++) //�������ֵ�±� 
	{
		if (A[p] < A[i])
		   p = i;
	}
	B[p] = 1;
	p = (p == n-1) ? 0 : p+1; //��ȡ��Сֵ�±� 
 	
	for (i=1; i<n; i++) //��n-1��Ԫ�ذ��յ�����ѡ������ 
	{
		k = p;
		for (j=0; j<n; j++)
		{
			if (B[j] == 0 && A[j] < A[k]) //������Сֵ�±� 
	    	    k = j;
		}
		if (k != p)
		   swap(A[k], A[p]);
        B[p] = 1;
        p = (p == n-1) ? 0 : p+1; //�����µ���Сֵ�±� 
	}
}


