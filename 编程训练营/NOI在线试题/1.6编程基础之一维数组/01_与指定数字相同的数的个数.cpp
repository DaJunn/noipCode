/*
	Name: 01_��ָ��������ͬ�����ĸ���
	Copyright: 
	Author: 
	Date: 14-08-17 21:14
	Description: 01_��ָ��������ͬ�����ĸ���
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���һ��������������ָ��������ͬ�����ĸ�����

����
����������У�
��һ��ΪN����ʾ�������еĳ���(N <= 100)��
�ڶ���ΪN������������֮����һ���ո�ֿ���
�����а���һ��������Ϊָ��������m��
���
���ΪN��������m��ͬ�����ĸ�����
��������
3
2 3 2
2
�������
2
*/
#include <iostream>

using namespace std;

const int M = 100;
int NumOfValue(const int A[], int n, int x);

int main() 
{
	int A[M] = {0};
	int n, m;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	cin >> m;
	cout << NumOfValue(A, n, m) << endl; //���3
	
	return 0;	
} 

//ͳ������A��ֵΪx��Ԫ�ص����� 
int NumOfValue(const int A[], int n, int x)
{
	int s = 0;
	for (int i=0; i<n; i++)
	{
		s += (A[i] == x); 
	}
	return s;
}
