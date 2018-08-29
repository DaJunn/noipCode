/*
  Name: ��kСԪ��
  Copyright: 
  Author: 
  Date: 13-04-17 15:28
  Description: ��һ�����еĵ�kСԪ�أ����÷��εĲ��Խ��еݹ���⡣
  ģ�¿������򷨵�˼·��ֻ����ÿ��ֻ�ݹ鴦���kСԪ�����ڵ����У�
  ʹ������β�ݹ��Ż���Ч�����á� 
*/
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

const int N = 6000000;
int A[N] = {0};
int B1[N] = {0};
int B2[N] = {0};
int B3[N] = {0};

int SelectK_1(int A[], int low, int high, int k);
int SelectK_12(int A[], int low, int high, int k);
int SelectK_2(int A[], int low, int high, int k);
int SelectK_3(int A[], int low, int high, int k);

int main() 
{
 	for (int i=0; i<N; i++)
 	{
	 	B1[i] = B2[i] = B3[i] = A[i] = rand() % 1000000;
    }
    time_t startTime;
	time_t endTime;
	for (int k = 1; k<6000000; k+=1000000)
	{
	
		time(&startTime); 
	    cout << "1:" << SelectK_1(A, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
		
		time(&startTime); 
	    cout << "12:" << SelectK_12(B1, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
		
		time(&startTime); 
	    cout << "2:" << SelectK_2(B2, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
		
		time(&startTime); 
	    cout << "3:" << SelectK_3(B3, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
    }
    
    return 0;
}

int SelectK_1(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int p = (low+high)/2; 
	swap(A[low], A[p]);
	int i = low, j = high, t = A[low];
	while (i < j) //ѭ������ʱi==j  
	{
		while (i < j && A[j] > t)//��Ϊ��ŦԪ��������࣬Ӧ������ɨ�裬ȷ������a[j]<t 
			j--;
		while (i < j && A[i] <= t)
			i++;
		if (i < j)
			swap(A[i], A[j]);
	}
	swap(A[low], A[j]);
	if (j == k)
		return A[j];
	else if (j > k)
		return SelectK_1(A, low, j-1, k);
	else 
		return SelectK_1(A, i+1, high, k);
}

int SelectK_12(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int t;
	int i, j, p;
	while (low < high)
	{   
		p = (low+high)/2; 
		swap(A[low], A[p]);
		i = low; j = high; t = A[low];
		while (i < j) //ѭ������ʱi==j  
		{
			while (i < j && A[j] > t)//��Ϊ��ŦԪ��������࣬Ӧ������ɨ�裬ȷ������a[j]<t 
				j--;
			while (i < j && A[i] <= t)
				i++;
			if (i < j)
				swap(A[i], A[j]);
		}
		swap(A[low], A[j]);
		if (j == k)
			return A[j];
		else if (j > k)
			high = j - 1; //����β�ݹ�SelectK_1(A, low, j-1, k);
		else 
			low = i + 1; //����β�ݹ�SelectK_1(A, i+1, high, k);
	}
}

int SelectK_2(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int p = (low+high)/2; 
	swap(A[high], A[p]);
	int i = low, j = high,t = A[high];
	while (i < j) //ѭ������ʱi==j  
	{
		swap(A[i], A[j]);
		while (i < j && A[i] <= t)
			i++;
		while (A[j] > t)
			j--;
	}
	swap(A[low], A[j]);
	if (j == k)
		return A[j];
	else if (j > k)
		return SelectK_2(A, low, j-1, k);
	else 
		return SelectK_2(A, i, high, k);
}

int SelectK_3(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int p = (low+high)/2; 
	swap(A[low], A[p]);
	int i = low, j = high,t = A[low];
	while (i <= j)
	{
		while (i <= high && A[i] <= t)
			i++;
		while (j > low && A[j] >= t)
			j--;
		if (i < j)
			swap(A[i++], A[j--]);
	}
	swap(A[low], A[j]);
	if (j <= k && k < i)
		return A[j];
	else if (j > k)
		high = j - 1; //����β�ݹ�SelectK_1(A, low, j-1, k);
	else 
		low = i; //����β�ݹ�SelectK_1(A, i+1, high, k);
	while (i < j) //ѭ������ʱi==j  
	{
		swap(A[i], A[j]);
		while (i < j && A[i] <= t)
			i++;
		while (A[j] > t)
			j--;
	}
	swap(A[low], A[j]);
	if (j <= k && k < i)
		return A[j];
	else if (j > k)
		return SelectK_3(A, low, j-1, k);
	else 
		return SelectK_3(A, i, high, k);
}
