/*
	Name: 10_�������ӷ�
	Copyright: 
	Author: 
	Date: 15-08-17 10:06
	Description:10_�������ӷ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
������������200λ�ķǸ������ĺ͡�

����
�����У�ÿ����һ��������200λ�ķǸ������������ж����ǰ��0��
���
һ�У�����Ӻ�Ľ��������ﲻ���ж����ǰ��0������������342����ô�Ͳ������Ϊ0342��
��������
22222222222222222222
33333333333333333333
�������
55555555555555555555 
*/
#include <iostream>
#include <string>

using namespace std;

const int M = 302;
int C[M];

int main() 
{
	string A, B;
	cin >> A >> B;
	
	int pA=A.length()-1, pB=B.length()-1, pC=0;
	while (pA>=0 && pB>=0)
	{
		C[pC++] += A[pA--] - '0' + B[pB--] - '0'; 
		if (C[pC-1] > 9) //��λ 
		{
			C[pC-1] -= 10;
			C[pC] += 1;
		}
	}
	while (pA>=0)
	{
		C[pC++] += A[pA--] - '0';
		if (C[pC-1] > 9) //��λ 
		{
			C[pC-1] -= 10;
			C[pC] += 1;
		}
	}
	while (pB>=0)
	{
		C[pC++] += B[pB--] - '0';
		if (C[pC-1] > 9) //��λ 
		{
			C[pC-1] -= 10;
			C[pC] += 1;
		}
	}
	while (pC>=0 && C[pC]==0)//ȥ������ǰ��0 
	{
		pC--;
	}
	if (pC < 0)//�� Ϊ0
		cout << 0;
	while (pC>=0)
	{
		cout << C[pC--];
	}
	cout << endl;
	
	return 0;	
} 

