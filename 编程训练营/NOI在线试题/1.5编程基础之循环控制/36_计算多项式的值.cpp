/*
	Name: 36_�������ʽ��ֵ
	Copyright: 
	Author: ����׾ 
	Date: 03-07-17 21:14
	Description: 36_�������ʽ��ֵ
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
�ٶ�����ʽ����ʽΪxn+xn-1+��+x2+x+1���������������ȸ�����x��������nֵ��������������ʽ��ֵ��

����
�����һ�У�����x��n���õ����ո������x��float��Χ�ڣ�n <= 1000000��
���
���һ��ʵ����������ʽ��ֵ����ȷ��С�������λ����֤���ս����float��Χ�ڡ�
��������
2.0 4
�������
31.00
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    float x, s=1, m=1;
    
    cin >> x >> n;
    
	for (int i=1; i<=n; i++) 
	{
	 	m *= x;  
	 	s += m;
	} 
	
	printf("%.2f", s);
			  
    return 0;
}
