/*
	Name: 7830_��С����ĳһλ
	Copyright: 
	Author: ����׾ 
	Date: 01-07-17 20:18
	Description: 7830_��С����ĳһλ
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����a/b��ΪС����С������nλ�������Ƕ��٣�

����
����������a��b��n������������֮���õ����ո������0 < a < b < 100��1 <= n <= 10000��
���
һ�����֡�
��������
1 2 1
�������
5
��Դ
�������������һ������Сѧ���꼶���� (ISBN 978-7-5445-2882-5) ģ���Ծ�� ��3��
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int a, b, n;
    int factor, remainder;
    
    cin >> a >> b >> n;
    
    a *= 10;
    for (int i=0; i<n; i++)  
    {
	 	factor = a / b;
	 	remainder = a % b;
	 	a = remainder * 10;
	}
    
    cout << factor;
			  
    return 0;
}
