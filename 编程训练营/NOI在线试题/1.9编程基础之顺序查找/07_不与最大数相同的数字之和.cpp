/*
	Name: 07_�����������ͬ������֮��
	Copyright: 
	Author: 
	Date: 16-08-17 10:56
	Description: 07_�����������ͬ������֮��
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���һ�����������в����������ͬ������֮�͡�

����
�����Ϊ���У�
��һ��ΪN(NΪ���������ĸ�����N <= 100)��
�ڶ���ΪN��������������֮����һ���ո�ֿ���ÿ�������ķ�Χ��-1000,000��1000,000��
���
���ΪN�����г�ȥ�������������֮�͡�
��������
3
1 2 3 
�������
3
*/
#include <iostream>

using namespace std;

const int M = 100;

int main() 
{
	int A[M] = {0};
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	
	int m = A[0];
	for (int i=1; i<n; i++)
	{
		if (A[i] > m)
			m = A[i];
	}
	
	int s = 0;
	for (int i=0; i<n; i++)
	{
		if (A[i] != m)
			s += A[i];
	}
	cout << s << endl;
	
	return 0;	
} 
