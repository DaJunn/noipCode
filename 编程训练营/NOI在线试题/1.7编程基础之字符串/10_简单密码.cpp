/*
	Name: 10_������
	Copyright: 
	Author: 
	Date: 01-09-17 10:31
	Description: 10_������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
Julius Caesar����ʹ�ù�һ�ֺܼ򵥵����롣���������е�ÿ���ַ�������������ĸ���к�5λ��Ӧ���ַ������棬�����͵õ������ġ�
�����ַ�A��F�����档���������ĺ��������ַ��Ķ�Ӧ��ϵ��
����
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
����
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 
��������ǶԸ��������Ľ��н��ܵõ����ġ�
����Ҫע����ǣ������г��ֵ���ĸ���Ǵ�д��ĸ��������Ҳ��������ĸ���ַ�������Щ�ַ����ý��н��롣
����
һ�У��������ģ����Ĳ�Ϊ�գ��������е��ַ���������200��
���
���һ�У������Ķ�Ӧ�����ġ�
��������
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
�������
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
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
        if (isupper(S[i]))
        {
			cout << char((S[i]-'A'+26-5)%26 + 'A');
		}
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
}   
