/*
	Name: 14_��Сд��ĸ����
	Copyright: 
	Author: 
	Date: 01-09-17 17:06
	Description: 14_��Сд��ĸ����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��һ���ַ��������г��ֵĴ�д��ĸ���滻��Сд��ĸ��ͬʱ��Сд��ĸ�滻�ɴ�д��ĸ��

����
����һ�У����������ַ�����
���
���һ�У���ɻ������ַ������ַ�������С��80����
��������
If so, you already have a Google Account. You can sign in on the right. 
�������
iF SO, YOU ALREADY HAVE A gOOGLE aCCOUNT. yOU CAN SIGN IN ON THE RIGHT. 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 81;  
char S[N];   
char *A="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char *B="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char L[255]; 
  
int main()   
{  
	for (int i=0; A[i]!='\0'; i++)//��ȡת����ϵ�� 
	{
		L[A[i]] = B[i];
	}  
	gets(S);  
    for (int i=0; S[i]!='\0'; i++)  
    {  
		if (isalpha(S[i]))
        	cout << L[S[i]];
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
} 
