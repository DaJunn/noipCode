/*
	Name: 12_���ܵĲ�����
	Copyright: 
	Author: 
	Date: 01-09-17 10:58
	Description: 12_���ܵĲ�����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
СӢ��ҩѧרҵ������ѧ��������ڼ�����ȥҽԺҩ��ʵϰ�Ļ��ᡣ 
��ҩ��ʵϰ�ڼ䣬СӢ��ʵ��רҵ���������ҽ����һ�º�������֪СӢ�ڼ��������ȡ�ù��óɼ��������ֶ��⽻����һ������
���ܿ�սʱ�ڱ����ܹ���һЩ��Ա�������� 
�����о���СӢ���������¼��ܹ��ɣ���������һ����ԭ�� -> ���ġ������ӣ� 
1. ԭ�������е��ַ�������ĸ���б�ѭ������������λ�ã�dec -> abz�� 
2. ����洢��abcd -> dcba �� 
3. ��Сд��ת��abXY -> ABxy�� 
����
һ�����ܵ��ַ�����������С��50��ֻ������Сд��ĸ��
���
������ܺ���ַ�����
��������
GSOOWFASOq
�������
Trvdizrrvj
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 101;  
char S[N];   
char *A="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char *B="defghijklmnopqrstuvwxyzabcDEFGHIJKLMNOPQRSTUVWXYZABC";
char L[255]; 
  
int main()   
{  
	for (int i=0; A[i]!='\0'; i++)//��ȡת����ϵ�� 
	{
		L[A[i]] = B[i];
	}  
	gets(S);  
    int n = strlen(S);
    for (int i=n-1; i>=0; i--)  
    {  
        cout << L[S[i]];
    }  
    cout << endl;
    
    return 0;     
} 
