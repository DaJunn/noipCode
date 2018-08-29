/*
	Name:  43_�������ֽ�
	Copyright: 
	Author: 
	Date: 02-07-17 13:36
	Description: 43_�������ֽ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��֪������ n ��������ͬ�������ĳ˻���������ϴ���Ǹ�������

����
����ֻ��һ�У�����һ�������� n��

����60%�����ݣ�6 �� n �� 1000��
����100%�����ݣ�6 �� n �� 2*10^9��
���
���ֻ��һ�У�����һ�������� p�����ϴ���Ǹ�������
��������
21
�������
7
*/
#include<iostream>
#include<cmath>

using namespace std;

bool IsPrim(int n);

int main()
{
    int n, p;
    
    cin >> n;
    
    for (p=floor(sqrt(n)); p>1; p--)
    {
	 	if (n % p == 0 && IsPrim(p) && IsPrim(n/p))
	 	{
            cout << n / p;
            break;
	    }
	}
			  
    return 0;
}

bool IsPrim(int n)
{
    for (int i=floor(sqrt(n)); i>1; i--)
    {
	 	if (n % i == 0)
	 	   return false;
    }
    return true;
}
