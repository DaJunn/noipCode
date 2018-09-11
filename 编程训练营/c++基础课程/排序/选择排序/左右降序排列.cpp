/*
	Name: ���ҽ�������
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: ��д����������A�������ҽ�������
��ν���ҽ���������ָ���δ������������м�ɨ�裬�������ʹδ�Ԫ�ء�
���磬������A[7]={3,5,7,2,4,1,6}ʱ�������A[7]={7,5,3,1,2,4,6} �� 
������A[8]={3,5,7,2,4,1,6,8}ʱ�������A[7]={8,6,4,2,1,3,5,7} ��
	
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
		A[i] = rand()%9 + 1;
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
		p1 = i, p2 = j;//�ֱ�������˺����Ҷ˷������ֵ�ʹδ�ֵ 
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
		if (i != p1)
		   swap(A[i], A[p1]);
        if (i == p2)
           p2 = p1;
        if (j != p2)
		   swap(A[j], A[p2]);
	}
}

