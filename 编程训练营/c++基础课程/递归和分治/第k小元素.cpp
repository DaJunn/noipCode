/*
  Name: ��kСԪ��
  Copyright: 
  Author: 
  Date: 13-04-17 15:28
  Description: ��һ�����еĵ�kСԪ�أ����÷��εĲ��Խ��еݹ���⡣
  ģ�¿������򷨵�˼·��ֻ����ÿ��ֻ�ݹ鴦���kСԪ�����ڵ����С�
  Ҫע��ÿ�ζ�Ӧ�ü��������ķ�Χ��������Ϊ���������������µ���ѭ�� 
*/
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

const int N = 60000000;
int A[N] = {0};

int Partition(int A[], int low, int high);
int SelectK(int A[], int low, int high, int k);
void Swap(int &a, int &b);

int main() 
{
 	for (int i=0; i<N; i++)
 	{
	 	A[i] = rand() % 1000;
    }
    /* 
    for (int i=0; i<N; i++)
 	{
	 	cout << A[i] << "  ";
    }
    cout << endl;
    */
    time_t startTime;
	time_t endTime;
	
	time(&startTime); 
    int k = 5555555;
    cout << SelectK(A, 0, N-1, k) << endl;
    time(&endTime);
	cout << difftime(endTime, startTime) << endl;
    /*
    for (int i=0; i<N; i++)
 	{
	 	cout << A[i] << "  ";
    }
    cout << endl;
 	*/
 	
    return 0;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int SelectK(int A[], int low, int high, int k)
{
 	if (low == high)
 	   return A[low];
 	   
    int mid = Partition(A, low, high);
    int leftLen = mid - low + 1;
    
    if (k == leftLen)
       return A[mid];
    else if (k < leftLen) //Ҫ�����������������������Σ����������ѭ�� 
        return SelectK(A, low, mid-1, k);
    else
    	return SelectK(A, mid+1, high, k-leftLen);
}

int Partition(int A[], int low, int high)
{
 	srand((unsigned)time(NULL)); //���������
 	int i, j = rand() % (high - low) + low; 
 	Swap(A[low], A[j]); //����ŦԪ���û�������� 
 	int x = A[low];
 	i = low; 
    j = high + 1;
    
    while (true)
    {
        while (A[++i] <= x && i < high) ;
        while (A[--j] > x) ;
        if (i >= j)
            break;
        
        Swap(A[i], A[j]);
    } 
    Swap(A[low], A[j]); //����ŦԪ���û������ô���λ��
	
	return j; 
}


