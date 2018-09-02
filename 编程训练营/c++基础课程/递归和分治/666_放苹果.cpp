/*  
    Name: 666_��ƻ��  
    Author: ����׾  
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
 
�㷨������ 
��2��˼·��һ����ȷ�������������ƻ������ǰ����٣���һ����ȷ�������������ƻ������ǰ��Ķࡣ 
��2��˼·�ݹ���Ƚ��٣������븴��Щ���ر�Ҫע���n�������ܷ�ƻ����������Χ��  
�����ϵݹ����ⶼ����ת��Ϊ���仯������Ȼ��ת��Ϊ��̬�滮���⡣
�����㷨�൱����٣��������Ի����ϵ������������Դ洢����Ľ�ռ䡣 
*/    
#include<iostream>    
#include<cstdio>    
    
using namespace std;    
    
const int MAX = 100;     
int A1[MAX+1], A2[MAX+1];    
int A[MAX+1][MAX+1], F[MAX+1][MAX+1];  
int M, N, s1, s2;    
    
void DFS_1(int m, int n); //m��ʾ��m��ƻ����n��ʾ��n������     
void DFS_2(int m, int n); //m��ʾ��m��ƻ����n��ʾ��n������   
int DG(int m, int n); //m��ʾ��m��ƻ����n��ʾ��n������ 
int JYHSS(int m, int n); //���仯����   
int DTGH(int m, int n); //��̬�滮 
    
int main()     
{    
    int t;    
    cin >> t;    
    for (int k=0; k<t; k++)    
    {    
        cin >> M >> N;    
          
        s1 = 0;   
        DFS_1(M, 1);    
        cout << s1 << endl;    
          
        s2 = 0;   
        int minNum = M/N + (M%N!=0);   
        for (A2[1]=M; A2[1]>=minNum; A2[1]--)//��һ�����з�A2[1]��ƻ��   
        {    
            DFS_2(M-A2[1], 2);    
        }  
        cout << s2 << endl;    
        
        cout << DG(M, N) << endl;    
        cout << JYHSS(M, N) << endl;    
        cout << DTGH(M, N) << endl;    
    }    
        
    return 0;    
}    
  
void DFS_1(int m, int n) //m��ʾ��m��ƻ����n��ʾ��n������     
{    
    if (n == N)    
    {    
        A1[n] = m;    
        cout << s1 << " : ";    
        for (int i=1; i<=N; i++)    
            cout << A1[i] << " ";    
        cout << endl;    
        s1++;    
    }    
    else    
    {    
        for (A1[n]=A1[n-1]; A1[n]+A1[n]<=m; A1[n]++)    
        {   //ȷ��ʣ�µ�ƻ�����ȵ�ǰ�����е���     
            DFS_1(m-A1[n], n+1); 
       }    
    }       
}   
  
void DFS_2(int m, int n) //m��ʾ��m��ƻ����n��ʾ��n������     
{    
    if (m == 0 || n == N)  //û��ƻ������û��������   
    {    
        A2[n] = m;  
        cout << s2 << " : ";    
        for (int i=1; i<=n; i++)   
            cout << A2[i] << " ";   
        for (int i=n+1; i<=N; i++) //���������Ϊ��   
            cout << 0 << " ";   
        cout << endl;    
        s2++;    
    }    
    else    
    {    
        int maxNum = min(m, A2[n-1]);//ȷ�������������ƻ������ǰ��Ķ�  
        int minNum = m/(N-n+1) + (m%(N-n+1)!=0);  
        for (A2[n]=maxNum; A2[n]>=minNum; A2[n]--)     
        {        
            DFS_2(m-A2[n], n+1);    
       }    
    }       
}    

int DG(int m, int n) //m��ʾ��m��ƻ����n��ʾ��n������     
{    
    if (m == 0 || n == 1)  
	    return 1;
    else if (m < n) //�����Ӷ���ƻ��ʱ���൱�ڰ�m��ƻ���ŵ�m�������� 
	    return DG(m, m);  
    else //ÿ���������ٷ�1��ƻ������ϼ���������1�����̵���� 
		return DG(m-n, n) + DG(m, n-1); 
}  

int JYHSS(int m, int n) //���仯����  
{    
	if (A[m][n] != 0)
		return A[m][n];
    if (m == 0 || n == 1)  
	    A[m][n] = 1;
    else if (m < n) //�����Ӷ���ƻ��ʱ���൱�ڰ�m��ƻ���ŵ�m�������� 
	    A[m][n] = JYHSS(m, m);  
    else //ÿ���������ٷ�1��ƻ������ϼ���������1�����̵���� 
		A[m][n] = JYHSS(m-n, n) + JYHSS(m, n-1); 
	return A[m][n];
}  

int DTGH(int m, int n) //��̬�滮 
{    
	for (int i=1; i<=m; i++) 
    {  
        F[i][1] = 1;  
    }  
	for (int j=1; j<=n; j++) 
    {  
        F[0][j] = 1;  
    }  
	//Ϊʵ���Ե����ϣ�����Ҫ��֤j�����ѭ����
	//Ȼ����0<=i<j��j<=i<=m��˳�����ڲ�ѭ�����ֱ����m<n��m>=n��f(m, n)ֵ
    for (int j=1; j<=n; j++)
    {
	 	//f(m, n)=f(m, m); ( m < n ) 
	 	for (int i=1; i<j; i++) 
	 	{
		 	F[i][j] = F[i][j-1];
		}
		//f(m, n)=f(m - n, n) + f(m, n - 1); ( m >= n )
	 	for (int i=j; i<=m; i++)
	 	{
		 	F[i][j] = F[i-j][j] + F[i][j-1];
		}
	}
	return F[m][n];
}  

