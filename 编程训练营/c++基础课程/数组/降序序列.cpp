/*
	Name: �������� 
	Copyright: 
	Author: 
	Date: 04\09\18 10:01
	Description: ��һ�����������У����������������ļ���������Ϊһ���������У��ý������������ĸ�����Ϊ���г��ȡ�
	�������������n�����ݵ����У�
	Ҫ��1�����ҳ�������������еĳ���
	Ҫ��2�����������������С� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 20;
int A[M];

int Fun(int n);//������������еĳ���
void Fun_2(int n);//��������������
int Fun_3(int n);//������������еĳ���
void Fun_4(int n);//��������������

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i]=n-i;//A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun(n) << endl;
	Fun_2(n);
	cout << Fun_3(n) << endl;
	Fun_4(n);
	
	return 0;	
} 

int Fun(int n)//������������еĳ���
{
    int m = 0, t = 1;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
        	t++;
		}
		else
		{
			if (t > m)
				m = t;
			t = 1;
		}
    }
    return (t > m) ? t : m; //��������а������һ��Ԫ��  
}

void Fun_2(int n)//��������������
{
    int left = 0, mleft = 0, mright = 0;
    int m = 0, t = 1;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
        	t++;
		}
		else
		{
			if (t > m)
			{
				m = t;
				mleft = left;
				mright = i - 1;
			}
			t = 1;
			left = i;
		}
    }
    if (t > m) //��������а������һ��Ԫ�� 
	{
	    m = t;
	    mleft = left;
		mright = n - 1;
	}
    
    for (int i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}

int Fun_3(int n)//������������еĳ���
{
    int m = 0, t = 1, i = 1;
	
    while (i < n)
    { 
        while (i < n && A[i] < A[i-1])
        {
        	t++;
        	i++;
		}
		if (t > m)
			m = t;
		t = 1;
		i++;
    }
    
    return m;  
}

void Fun_4(int n)//��������������
{
    int left = 0, mleft = 0, mright = 0;
    int m = 0, t = 1, i = 1;
	
    while (i < n)
    { 
        while (i < n && A[i] < A[i-1])
        {
        	t++;
        	i++;
		}
		if (t > m)
		{
			m = t;
			mleft = left;
			mright = i - 1;
		}
		t = 1;
		left = i++;
    }
    
    for (i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}
