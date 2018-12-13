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
    for (int k=0; k<t; k++)  
    {  
        cin >> M >> N;  
        s = 0; 
        int minNum = M/N + (M%N!=0); 
        for (int i=M; i>=minNum; i--)//��һ�����з�i��ƻ�� 
        {
			A[1] = i;  
			DFS(M-i, 2);  
		}
        cout << s << endl;  
    }  
      
    return 0;  
}  
void DFS(int m, int n) //m��ʾ��m��ƻ����n��ʾ��n������   
{  
    if (m == 0 || n == N)  //û��ƻ������û�������� 
    {  
		//A[n] = m;
//        cout << s << " : ";  
//        for (int i=1; i<=n; i++) 
//            cout << A[i] << " "; 
//        for (int i=n+1; i<=N; i++) //���������Ϊ�� 
//            cout << 0 << " "; 
//        cout << endl;  
        s++;  
    }  
    else  
    {  
		int maxNum = min(m, A[n-1]);//ȷ�������������ƻ������ǰ��Ķ�
		int minNum = m/(N-n+1) + (m%(N-n+1)!=0);
        for (int i=maxNum; i>=minNum; i--)   
        {  
            A[n] = i;  
            DFS(m-i, n+1);  
       }  
    }     
}  
