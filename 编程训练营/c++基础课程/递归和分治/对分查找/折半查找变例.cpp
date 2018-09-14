/*
	Name: �۰���ұ��� 
	Copyright: 
	Author: 
	Date: 20-08-18 16:32
	Description: ��һ���ݼ����飬����һ������x�����㲻С��x��Ԫ��ֵ�������� 
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib>  

using namespace std;

int BinarySearch(int x, int low, int high); //�۰���ҵ�һ��С��x��Ԫ�ص��±�(δ�ҵ��򷵻�high+1) 

const int MAX = 10;
int A[MAX];

int Cmp(const void *a, const void *b)    
{    
    return *(int *)b - *(int *)a;    
}   

int main() 
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%10 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	qsort(A, MAX, sizeof(A[0]), Cmp);  
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;  
	
	int x;
	cin >> x;
	cout << BinarySearch(x, 0, MAX-1) + 1 << endl;
		
    return 0;
}

int BinarySearch(int x, int low, int high) //�۰���ҵ�һ��С��x��Ԫ�ص��±�(δ�ҵ��򷵻�high+1) 
{
	for (int mid=(low+high)/2; low<=high; mid=(low+high)/2)
	{
		if (x <= A[mid])
			low = mid + 1;
		else  
			high = mid - 1;
	}
	return high;
}
