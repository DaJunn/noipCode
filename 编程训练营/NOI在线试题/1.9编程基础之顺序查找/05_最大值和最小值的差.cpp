/*
	Name: 05_���ֵ����Сֵ�Ĳ�
	Copyright: 
	Author: 
	Date: 15-08-17 21:07
	Description: 05_���ֵ����Сֵ�Ĳ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���һ����������������������С�����Ĳ

����
��һ��ΪM����ʾ�������������������������10000��
�ڶ���ΪM���������Կո������ÿ�������ľ���ֵ�������10000��
���
���M���������ֵ����Сֵ�Ĳ
��������
5
2 5 7 4 2
�������
5
*/
#include <iostream>

using namespace std;

const int M = 10000;
int A[M];

int main() 
{
	int n;
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	
	int min=A[0], max=A[0];
	for (int i=1; i<n; i++)
	{
		if (A[i] > max)
			max = A[i];
		else if (A[i] < min)
			min = A[i];
	}
	
	cout << max-min << endl;
	
	return 0;	
} 
