/*
	Name: 13_������������
	Copyright: 
	Author: 
	Date: 15-08-17 11:01
	Description: 13_������������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��֪������k����2<=k<=9���ָ����������Ϊ30λ��ʮ���ƷǸ�����c��������������c��k��

����
һ���Ǹ�����c��c��λ��<=30��
���
���������� c%k == 0 ��k����С�����������������k������������֮���õ����ո��������û��������k�������"none"��
��������
30
�������
2 3 5 6 

�㷨��������Ϊ��������С������Ҫ�����Ż���ֱ���жϼ��ɡ� 
*/
#include <iostream>
#include <string>

using namespace std;

const int M = 32;

int main() 
{
	string C;
	cin >> C;
	
	int n = C.length()-1;
	int A[M] = {0};
	int B[M] = {0};
	
	for (int i=0; i<=n; i++)
		A[i] = C[i] - '0';
	
	int s = 0;
	for(int k=2; k<=9; k++)
	{
		for (int i=0; i<=n; i++)
			B[i] = A[i];
		for (int i=0; i<n; i++)//�����㷨 
			B[i+1] += (B[i] % k) * 10;
			
		if (B[n] % k == 0)	
		{
			s++;
			cout << k << " ";
		}
	}
	if (s == 0)
		cout << "none";
	
	return 0;	
} 
