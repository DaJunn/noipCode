/*
	Name: ʹ�ò�������ֱ��������ż������ 
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
	int mid = low; //mid�ǵ�һ��������ż�����±� 
    for (int i=low; i<=high; i++) //��Ϊ��֪����һ��������ż�ԣ��ʴӵ�1��Ԫ�ؿ�ʼ
    {
    	int t = A[i];
    	int j = i - 1;
        if (A[i] % 2 == 1)
        {
        	while (j >= mid || (j >= low && A[j] > t))
        	{
        		A[j+1] = A[j];
        		j--;
			}
			A[j+1] = t;
			mid++;
		}
		else
		{
			while (j >= mid && A[j] > t)
        	{
        		A[j+1] = A[j];
        		j--;
			}
			A[j+1] = t;
		}
    }
}
