/* 
    Name: 666_��ƻ�� 
    Copyright:  
    Author:  
    Date: 12-07-17 21:29 
    Description: 666_��ƻ�� 
�鿴 �ύ ͳ�� ���� 
��ʱ������: 1000ms �ڴ�����: 65536kB 
���� 
��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�������K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ��� 
���� 
��һ���ǲ������ݵ���Ŀt��0 <= t <= 20��������ÿ�о�������������M��N���Կո�ֿ���1<=M��N<=10�� 
��� 
�������ÿ������M��N����һ�������Ӧ��K�� 
�������� 
1 
7 3 
������� 
8 
*/  
#include<iostream>  
#include<cstdio>  
  
using namespace std;  
  
const int MAX = 10;   
int A[MAX+1];  
int M, N, s;  
  
void DFS(int m, int n); //m��ʾ��m��ƻ����n��ʾ��n������   
  
int main()   
{  
    int t;  
    cin >> t;  
    for (int i=0; i<t; i++)  
    {  
        cin >> M >> N;  
        s = 0;  
        DFS(M, 1);  
        cout << s << endl;  
    }  
      
    return 0;  
}  
void DFS(int m, int n) //m��ʾ��m��ƻ����n��ʾ��n������   
{  
    if (n == N)  
    {  
        A[n] = m;  
      cout << s << " : ";  
      for (int i=1; i<=N; i++)  
          cout << A[i] << " ";  
      cout << endl;  
        s++;  
    }  
    else  
    {  
        for (int i=A[n-1]; i<=m; i++)  
        {  
            A[n] = i;  
            if (m-i >= A[n]) //ȷ�������������ƻ������ǰ�����   
                DFS(m-i, n+1);  
            else  
                break;  
       }  
    }     
}  
