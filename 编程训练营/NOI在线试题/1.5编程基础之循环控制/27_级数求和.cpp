/*
	Name:  27_�������
	Copyright: 
	Author: 
	Date: 02-07-17 13:36
	Description: 27_�������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��֪��Sn= 1��1��2��1��3������1��n����Ȼ��������һ������K����n�㹻���ʱ��Sn����K��

�ָ���һ������K��1<=k<=15����Ҫ������һ����С��n��ʹ��Sn��K��

����
һ������K��
���
һ������n��
��������
1
�������
2
*/
#include<iostream>

using namespace std;

int main()
{
    int k, n = 1;
    double s = 1;
   
    cin >> k;
    
    while (s <= k)  
    {
	 	n++;
	 	s += 1.0 / n;
	}
    
    cout << n << endl;
			  
    return 0;
}
