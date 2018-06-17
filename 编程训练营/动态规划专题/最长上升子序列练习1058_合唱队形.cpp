/*
	Name: 1058_�ϳ�����
	Author:����׾ 
	Description: 1058_�ϳ�����  2004��NOIPȫ�����������
Nλͬѧվ��һ�ţ�������ʦҪ�����е�(N-K)λͬѧ���У�ʹ��ʣ�µ�Kλͬѧ�ųɺϳ����Ρ�
�ϳ�������ָ������һ�ֶ��Σ���Kλͬѧ���������α��Ϊ1��2����K�����ǵ���߷ֱ�ΪT1��T2������TK��  
�����ǵ��������T1<...<Ti>Ti+1>��>TK(1<=i<=K)��
��������ǣ���֪����Nλͬѧ����ߣ�����������Ҫ��λͬѧ���У�����ʹ��ʣ�µ�ͬѧ�ųɺϳ����Ρ�
�������� Input Description
�����ļ�chorus.in�ĵ�һ����һ������N(2<=N<=100)����ʾͬѧ����������һ����n���������ÿո�ָ���
��i������Ti(130<=Ti<=230)�ǵ�iλͬѧ�����(����)��
������� Output Description
����ļ�chorus.out����һ�У���һ��ֻ����һ������������������Ҫ��λͬѧ���С�
�������� Sample Input
8
186 186 150 200 160 130 197 220
������� Sample Output
4
*/
#include<iostream>

using namespace std;

const int MAX = 1001; 
int A[MAX];
int SL2[MAX]; //��¼��Ԫ��iΪֹ������������еĳ��� 
int SR2[MAX]; //��¼��Ԫ��iΪֹ������������еĳ��� 

int DP_2(int n); //˳���� 

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
	}
	
	cout << DP_2(n) << endl;//˳���� 
	
    return 0;
}

int DP_2(int n) //˳������ 
{
	for (int i=0; i<n; i++)//���������������������� 
	{ 
		for (int j=i-1; j>=0; j--) 
		{
			if (A[i] > A[j] && SL2[j] > SL2[i])
				SL2[i] = SL2[j];
		}
		SL2[i]++;  
	}
	
	for (int i=n-1; i>=0; i--)//���������������������� 
	{ 
		for (int j=i+1; j<n; j++) 
		{
			if (A[i] > A[j] && SR2[j] > SR2[i])
				SR2[i] = SR2[j];
		}
		SR2[i]++;  
	}
	
	int m = 0;
	for (int i=0; i<n; i++) 
	{ 
		if (m < SL2[i] + SR2[i])
			m = SL2[i] + SR2[i];	 
	}
	
	return n - m + 1; //��ߵ��ظ�������һ�� 
}
