/*
	Name: ʹ��ѡ������ֱ��������ż������ 
	Copyhigh: 
	Author: 
	Date: 30-08-18 16:26
	Description: ��һ����������Ҫ��ֱ��������ż������������������������ǰ��ż���ں� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 30;
int A[M];

void Fun(int low, int high);//Ҫ��ֱ��������ż������������������������ǰ��ż���ں�
int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 39 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	Fun(0, n-1);
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void Fun(int low, int high)//Ҫ��ֱ��������ż������������������������ǰ��ż���ں�
{
	int i, k, m;
	
	while (low <= high)
	{
		if (A[low] % 2 == 1) //�����������Сֵ���������
		{
			for (m=low,k=low+1; k<=high; k++) 
			{
				if (A[k] % 2 == 1 && A[k] < A[m])
					m = k;
			}
			if (m != low)//�������� 
				swap(A[m], A[low]);
			low++;
	    } 
	    else  //��ż��������ֵ�������Ҷ�
	    {
			for (m=low,k=low+1; k<=high; k++) 
			{
				if (A[k] % 2 == 0 && A[k] > A[m])
					m = k;
			}
			swap(A[m], A[high]);
			high--; //ż���ݼ� 
	    } 
	}
}
