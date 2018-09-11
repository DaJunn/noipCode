/*
	Name: ������������ 
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: ��֪����A��������Ԫ�أ���д����������A����������������
��ν��������������ָ����Сֵ�������м䣬Ȼ����������Сֵ�����������е�2�͵�3СԪ�ء�
���磬������A[7]={3,5,7,2,4,1,6}ʱ�������A[7]={6,4,2,1,3,5,7} �� 
	
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 11;
int A[MAX];

void SelectSort1(int n);

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%19 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	SelectSort1(MAX);
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void SelectSort1(int n)
{
	int i, j, k, p1, p2;
	for (i=0,j=n-1; i<j; i++,j--)
	{
		p1 = j, p2 = i;//�ֱ������Ҷ˺�����˷������ֵ�ʹδ�ֵ 
		if (A[p1] < A[p2]) 
		   swap(A[p1], A[p2]);
		
		for (k=i+1; k<j; k++)
		{
			if (A[k] > A[p1]) //�������ֵ�ʹδ�ֵ�±� 
    	    {
    	    	p2 = p1;
    	    	p1 = k;
    	    }
		    else if (A[k] > A[p2])//���´δ�ֵ�±� 
                p2 = k;
		}
		if (j != p1)
		   swap(A[j], A[p1]);
        if (j == p2)
           p2 = p1;
        if (i != p2)
		   swap(A[i], A[p2]);
	}
}

