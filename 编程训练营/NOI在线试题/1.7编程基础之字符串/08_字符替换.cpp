/*
	Name: 08_�ַ��滻
	Copyright: 
	Author: 
	Date: 01-09-17 10:21
	Description: 08_�ַ��滻
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��һ���ַ������ض����ַ�ȫ���ø������ַ��滻���õ�һ���µ��ַ�����
����
ֻ��һ�У���һ���ַ����������ַ���ɣ��м��õ����ո�������ַ����Ǵ��滻���ַ������ַ�������С�ڵ���30���ַ����Ҳ����ո�ȿհ׷���
������һ���ַ�Ϊ��Ҫ���滻���ض��ַ���
������һ���ַ�Ϊ�����滻�ĸ����ַ���
���
һ�У����滻����ַ�����
��������
hello-how-are-you o O
�������
hellO-hOw-are-yOu
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 31;  
char S[N];    
  
int main()   
{  
	char a, b;
    cin >> S >> a >> b;  
    for (int i=0; S[i]!='\0'; i++)  
    {  
        if (S[i] == a)
        	cout << b;
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
}   
