/*
	Name: 09_���뷭��
	Copyright: 
	Author: 
	Date: 01-09-17 10:25
	Description: 09_���뷭��
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���鱨���ݹ����У�Ϊ�˷�ֹ�鱨���ػ�������Ҫ���鱨��һ���ķ�ʽ���ܣ��򵥵ļ����㷨��Ȼ��������ȫ�����鱨�����룬����Ȼ�ܷ�ֹ�鱨�����׵�ʶ��
���Ǹ���һ�����ĵļ��ܷ������Ը�����һ���ַ����������д�a-y��A-Y����ĸ��������ĸ�������z��Z��a��A�������������ĸ�ַ����䣬
��ɵõ�һ���򵥵ļ����ַ�����
����
����һ�У�����һ���ַ���������С��80���ַ���
���
���ÿ���ַ����ļ����ַ�����
��������
Hello! How are you!
�������
Ifmmp! Ipx bsf zpv!
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 81;  
char S[N];    
  
int main()   
{  
	gets(S);  
    for (int i=0; S[i]!='\0'; i++)  
    {  
        if (isalpha(S[i]))
        {
			if (S[i] == 'z')
				cout << 'a';
			else if (S[i] == 'Z')
				cout << 'A';
			else
			    cout << char(S[i]+1);
		}
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
}   
