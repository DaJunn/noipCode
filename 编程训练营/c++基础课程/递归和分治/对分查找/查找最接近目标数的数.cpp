/*
	Name: ������ӽ�Ŀ�������� 
	Author: ����׾ 
	Description: 
����
������СΪn����������A������һ����key��������A�в�����ӽ�key��Ԫ�أ�����ӽ�������2��ʱ�����ֵ�ϴ��һ���� 
����
��һ������������n��key��
�ڶ������ÿո������n������ 
���
��ӽ���Ԫ��ֵ 
��������
5 4
1 3 5 7 9
�������
5
*/
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
  
using namespace std;  
  
const int MAXN = 1000;  
int A[MAXN];  
  
int main()   
{  
	int n, key;
    cin >> n >> key;  
    for (int i=0; i<n; i++)  
        cin >> A[i];  
    
    if (key <= A[0])
    	cout << A[0] << endl;
    else if (key >= A[n-1])
    	cout << A[n-1] << endl;
	else
	{
		int mid, left = 0, right = n; 
	    while (left <= right)  
	    {  
	        mid = (left + right) / 2;  
	        if (key > A[mid])    
	            left = mid + 1;  
	        else  
	            right = mid - 1;  
	    }  
	    if (A[left]-key <= key-A[right])//����ӽ�������2��ʱ�����ֵ�ϴ��һ��
	    	cout << A[left] << endl;
	    else
	    	cout << A[right] << endl; 
	} 
    	
    return 0;  
}  
