/*
	Name: 6049_����
	Copyright: 
	Author: 
	Date: 24-06-18 15:23
	Description: 6049_����
����
С��������nԪǮȫ���������飬��ļ۸�Ϊ10Ԫ��20Ԫ��50Ԫ��100Ԫ��
��С���ж��������鷽������ÿ����ɹ���౾��
����
һ������ n�������ܹ�Ǯ������0 <= n <= 1000��
���
һ������������ѡ�񷽰�����
��������
��������1��
20
��������2��
15
��������3��
0
�������
�������1��
2
�������2��
0
�������3��
0 
*/
#include<iostream>  
#include<cstring>
  
using namespace std;  
  
const int N = 1001; 
int A[5] = {0,10,20,50,100};   
long long F[N]; //����¼����¼�������� 

long long CompletePack_2(int n, int c); //����ȫ����ת��Ϊ0-1���� 
long long CompletePack_4(int n, int c);//�Ż��Ķ�̬�滮�㷨��һά����洢��¼ 
  
int main()   
{  
    int n;  
      
    cin >> n; 
    cout << CompletePack_2(4, n) << endl;  
    
    return 0;  
} 

long long CompletePack_4(int n, int c)//��һ���Ż��Ķ�̬�滮�㷨����1��һά��������ά����
{
	F[0] = 1;
 	for (int i=1; i<=n; i++)
	{
		for (int j=A[i]; j<=c; j++) //j����iС���ܹ��γ��µķ��� 
		{
			F[j] += F[j-A[i]];
		}
	}
	
	return F[c];
} 

long long CompletePack_2(int n, int c) //����ȫ����ת��Ϊ0-1���� 
{
	F[0] = 1;
 	for (int i=1; i<=n; i++)
	{
		for (int j=c; j>=A[i]; j--) //����ȫ����ת��Ϊ0-1���� 
		{
			for (int k=j/A[i]; k>0; k--)
				F[j] += F[j-k*A[i]];
		}
	}
	
	return F[c];
}
