/*
	Name: �Էֲ���ѭ���������� 
	Copyright: 
	Author: 
	Date: 12-09-18 21:09
	Description: ��νѭ������������ָ��һ���ǵݼ�����ֳ��������Σ�Ȼ���������������û���
	�õ�һ��ѭ���������飬���磬ԭ����A[6]={1��2��3��4��5��6}��
	��������B[6]={1��2��3��4��5��6, 1��2},����C[6]={5��6, 1��2��3��4}��ѭ���������顣 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M] = {11,13,15,17,19,1,3,5,7,9};

int Fun(int low, int high, int key);//�Էֲ���ѭ���������� 

int main() 
{
	int n  = M;
	
	for (int i=0; i<n; i++)
		cout << i << ": " << A[i] << " ";
	cout << endl;
	for (int k=0; k<=20; k++)
		cout << k << ": " << Fun(0,n-1,k) << " ";
	cout << endl;
	return 0;	
} 

int Fun(int low, int high, int key)//�Էֲ���ѭ���������� 
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == key)
			return mid;
		if (A[mid] >= A[low]) //mid�ڹȵ���� 
		{
			if (A[mid] >= key && A[low] <= key) //key��mid��� 
				high = mid - 1;
			else                         //key��mid�Ҳ� 
				low = mid + 1;
		}
		else   //mid�ڹȵ��Ҳ� 
		{
			if (A[mid] <= key && A[high] >= key) //key��mid�Ҳ� 
				low = mid + 1;
			else                         //key��mid��� 
				high = mid - 1;
		}
	}
	return -1;
}
