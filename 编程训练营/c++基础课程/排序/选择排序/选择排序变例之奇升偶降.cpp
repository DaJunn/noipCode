/*
	Name: ѡ���������֮����ż�� 
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: ��һ����������Ҫ������е����������������򣬶�ż�����н�������
	�������������ǰ��ż���ں�����ʾ�����£�
	����ǰ��64 58 52 95 39 67 60 71
	�����39 67 71 95 64 60 58 52 
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

void SelectSort(int left, int right); 

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%10 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	SelectSort(0,MAX-1);
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void SelectSort(int left, int right)
{
	int k, m;
	
	while (left < right)
	{
		for (m=left,k=left+1; k<=right; k++)//�ҳ���Сֵ 
		{
			if (A[k] < A[m])
				m = k;
		}
		if (A[m]%2 == 1)//�������� 
		{
			swap(A[m], A[left]);
			left++;
		}
		else  //ż���ݼ� 
		{
			swap(A[m], A[right]);
			right--;
		}
	}
}
