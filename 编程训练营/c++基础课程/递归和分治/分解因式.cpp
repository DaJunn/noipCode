/*
	Name: �ֽ���ʽ 
	Copyright: 
	Author: 
	Date: 16-01-18 10:52
	Description: 
*/
#include<iostream>    
#include<cstdio>   
#include<cmath>  
#include<cstdlib> 
    
using namespace std;    
    
const int MAX = 10;     
int A1[MAX+1], A2[MAX+1];    
int M, N, s1, s2;    
    
void DFS_1(int n, int min);
int DFS_2(int n, int i); 
    
int main()     
{    
    int t;    
    cin >> t;    
    for (int k=0; k<t; k++)    
    {    
        cin >> N;    
          
        s1 = 0;   
        DFS_1(N, 2); //��С��������2   
        cout << s1 << endl;  
        
        cout << DFS_2(N, N) << endl;  
    }    
        
    return 0;    
}   

void DFS_1(int n, int min) //���ݷ� 
{
	if (n == 1)
	{
		s1++;
		return;
	}
	for (int i=min; i<=n; i++)
	{
		if (n % i == 0)
		{//ȷ�����Ӱ��ǵݼ����� 
			DFS_1(n/i, i);
		}
	}
} 

int DFS_2(int n, int i)
{
	if (n == 1)  //�����Ϊ1��������֣���������1 
	    return 1;
	else if (i == 1) //����Ϊ1����������ѭ�������� 
	    return 0;
    else if (n % i == 0) //���n�����ӿ���Ϊi��Ҳ���ܱ�iС 
	    return DFS_2(n/i, i) + DFS_2(n, i-1);  
    else //i�������ӿɣ������iС������ 
		return DFS_2(n, i-1);  
} 
