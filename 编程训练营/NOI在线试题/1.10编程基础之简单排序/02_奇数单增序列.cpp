/*
	Name: 02_������������
	Copyright: 
	Author: 
	Date: 17-08-17 10:45
	Description: 02_������������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ������ΪN��������500�������������У��뽫���е���������ȡ�����������������

����
��2�У�
��1��Ϊ N��
��2��Ϊ N ��������������ÿո�����
���
����������������У�����֮���Զ��ż�������ݱ�֤������һ��������
��������
10
1 3 2 6 5 4 9 8 7 10
�������
1,3,5,7,9
*/
#include<iostream>

using namespace std;

const int M = 500;
int A[M], B[M];

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	//��ȡ��һ������ 
	int f = 0;
	while (f < n && A[f]%2 == 0)
		f++;
	B[0] = A[f];
	
	int len = 1, low, high, mid;
	for (int i=f+1; i<n; i++)//�������˲������򣨴洢��ţ� 
	{
		if (A[i]%2 == 1)
		{
			low = 0;
			high = len-1;
			while(low <= high) //�۰���Ҳ���λ��
			{
				mid = (low + high)/2;
				if (B[mid] > A[i])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j=len++; j>low; j--)
		    {
				B[j] = B[j-1];
		    }
		    B[low] = A[i];
		}
	}
	
	cout << B[0];
	for (int i=1; i<len; i++)
		cout << "," << B[i];
	cout << endl;
	
    return 0;
}
