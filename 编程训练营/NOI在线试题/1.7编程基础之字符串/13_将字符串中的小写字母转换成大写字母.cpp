/*
	Name: 13_���ַ����е�Сд��ĸת���ɴ�д��ĸ
	Copyright: 
	Author: 
	Date: 01-09-17 17:11
	Description:13_���ַ����е�Сд��ĸת���ɴ�д��ĸ
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ��������������е�Сд��ĸת���ɴ�д��ĸ��

����
����һ�У�����һ���ַ��������Ȳ�����100�����ܰ����ո񣩡�
���
���ת������ַ�����
��������
helloworld123Ha
�������
HELLOWORLD123HA 
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
		if (islower(S[i]))
        	cout << char(S[i]-32);
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
} 
