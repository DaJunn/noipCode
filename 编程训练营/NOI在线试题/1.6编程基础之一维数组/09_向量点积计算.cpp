/*
	Name: 09_�����������
	Copyright: 
	Author: 
	Date: 15-08-17 10:48
	Description: 09_�����������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
�����Դ��������㼸���У����������һ��ʮ����Ҫ�����㡣

��������nά����a=(a1,a2,...,an)��b=(b1,b2,...,bn)������a��b=a1b1+a2b2+...+anbn��

����
��һ����һ������n��1 <= n <= 1000��
�ڶ��а���n������a1,a2,...,an��
�����а���n������b1,b2,...,bn��
��������֮���õ����ո������ÿ�������ľ���ֵ��������1000��
���
һ�������������������ĵ�������
��������
3
1 4 6
2 1 5
�������
36
*/
#include <iostream>

using namespace std;

const int M = 10001;
int A[M], B[M];

int main() 
{
	int n;
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	for (int i=0; i<n; i++)
		cin >> B[i];
	
	int s = 0;
	for (int i=0; i<n; i++)
		s += A[i] * B[i]; 
	cout << s << endl;
	
	return 0;	
} 
