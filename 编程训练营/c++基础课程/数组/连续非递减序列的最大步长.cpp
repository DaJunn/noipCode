/*
	Name:�����ǵݼ����е���󲽳� 
	Copyright: 
	Author: 
	Date: 04\09\18 10:01
	Description: ������A�У����������ǵݼ����е���󲽳�����ν������ָ�����ǵݼ�������ʼĩλ��Ԫ�صĲ�ֵ��
	˵����
	Ҫ��1�������������󲽳��� 
	Ҫ��2���������һ�����������ĸ������ǵݼ����С� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 20;
int A[M];

int Fun_1(int n);//���������ǵݼ����е���󲽳�
void Fun_2(int n);//����������ǵݼ�����
int Fun_3(int n);//���������ǵݼ����е���󲽳�
void Fun_4(int n);//����������ǵݼ�����

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 69 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun_1(n) << endl;
	Fun_2(n);
	cout << Fun_3(n) << endl;
	Fun_4(n);
	
	return 0;	
} 

int Fun_1(int n)//���������ǵݼ����е���󲽳�
{
    int msub = 0, left = 0;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
		    if (A[i-1]-A[left] > msub)  
	   	   	    msub = A[i-1]-A[left];
		    left = i;
		}
    }
    //�����������һ��Ԫ��
	if (A[n-1] > A[n-2] && A[n-1]-A[left] > msub)  
		msub = A[n-1]-A[left];
	return msub;
}

void Fun_2(int n)//����������ǵݼ�����
{
    int left = 0, mleft = 0, mright = 0;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
		    if (A[i-1]-A[left] > A[mright]-A[mleft])  
   		    {
	   	   	    mleft = left;
	   	   	    mright = i - 1;
		    }
		    left = i;
		}
    }
    //�����������һ��Ԫ��
	if (A[n-1] > A[n-2] && A[n-1]-A[left] > A[mright]-A[mleft])  
	{
 	    mleft = left;
	    mright = n - 1;
    }
    for (int i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}

int Fun_3(int n)//���������ǵݼ����е���󲽳�
{
    int msub = 0, left = 0;
	
    for (int i=1; i<n; i++)
    { 
        while (i < n && A[i] > A[i-1])
        	i++;
		if (A[i-1]-A[left] > msub)  
  		    msub = A[i-1]-A[left];
		left = i;
    }
    
    return msub;  
}

void Fun_4(int n)//����������ǵݼ�����
{
    int left = 0, mleft = 0, mright = 0;
    int m = 0, t = 1, i = 1;
	
    for (int i=1; i<n; i++)
    { 
        while (i < n && A[i] > A[i-1])
        	i++;
		if (A[i-1]-A[left] > A[mright]-A[mleft])  
  		{
		    mleft = left;
		    mright = i - 1;
		}
		left = i;
    }
    
    for (i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}

