/*
	Name: ����ϵ��ר��֮��ȫ��������
	Author: ����׾
	Description: 
��ȫ�������⣺��n����Ʒ��ѡȡ���ɼ���ͬһ����Ʒ�ɶ��ѡȡ����������Ϊc�ı�����ֱ���P[i]��W[i]�洢��i����Ʒ�ļ�ֵ��������
�����ôװ��Ʒ��ʹ��������Ʒ�ܼ�ֵ���
��������
4 12
2 3
5 7
6 8
10 12
�������
18
*/
#include<iostream>

using namespace std;

const int MAXC = 10000; //����������� 
const int MAXN = 2000; //��Ʒ��������
int W[MAXN+1];//��Ʒ������ 
int P[MAXN+1];//��Ʒ�ļ�ֵ 
int B1[MAXN+1][MAXC+1]; //��¼����n����Ʒװ������Ϊc�ı���������ֵ 
int B2[MAXN+1][MAXC+1]; //��¼����n����Ʒװ������Ϊc�ı���������ֵ 
int pre[MAXC+1]; //pre[j]�൱��B2[i-1][j] 
int cur[MAXC+1]; //cur[j]�൱��B2[i][j]
int B4[MAXC+1]; //��¼���Ž� 
int X[MAXN+1]; //��¼װ�뱳���е���Ʒ��ż������� 

int CompletePack_1(int n, int c);//��̬�滮+���ص����˼��
int CompletePack_2(int n, int c);//��̬�滮:F[i][j] = max(F[i-1][j], F[i][j-W[i]] + P[i])
int CompletePack_3(int n, int c);//�Ż��Ķ�̬�滮�㷨����2��һά��������ά���� 
int CompletePack_4(int n, int c);//�Ż��Ķ�̬�滮�㷨��һά����洢��¼
void Show(int i, int j);  //i��j�ֱ��ʾ���ڴ���ĵ�i����Ʒ�ʹ�ʱ������ʣ������
int Show_2(int n, int c); //��������B2[][]�������Ʒװ�������������ʵ��װ������X[i]��ʼ��Ϊ0 

int main() 
{
	int n, c;
	cin >> n >> c;
	
	for (int i=1; i<=n; i++)//�����±�Ϊ0��Ԫ�� 
	{
		cin >> W[i] >> P[i];
	}
	
	//��̬�滮+���ص����˼�룬��Ҫ�õ�ȫ�ֱ���W[], P[], ����B1[MAXN+1][]��ʼ��Ϊ0
	cout << CompletePack_1(n, c) << endl; 
	
	//��̬�滮����ά����洢��¼����Ҫ�õ�ȫ�ֱ���W[], P[], ����B2[MAXN+1][]Ĭ�ϳ�ʼ��Ϊ0 
	cout << CompletePack_2(n, c) << endl; 
	
	//��̬�滮��ʹ��2��һά����洢��¼����Ҫ�õ�ȫ�ֱ���W[], P[], ����pre[]��cur[]����ʼ��Ϊ0
	cout << CompletePack_3(n, c) << endl; 
	
	//�Ż��Ķ�̬�滮�㷨��һά����洢��¼����Ҫ�õ�ȫ�ֱ���W[], P[], ����B4[]��ʼ��Ϊ0
	cout << CompletePack_4(n, c) << endl; 
	
	//��������B2[][]�������Ʒװ�������X[i]��ʼ��Ϊ0
	cout << Show_2(n, c) << endl; 
	
	//��������B2[][]�����ձ��˳�򣬵ݹ����װ�뱳������Ʒ��Ϣ����ţ���������������ֵ��
	Show(n, c); 
	
	return 0;
}

int CompletePack_1(int n, int c)//��̬�滮+���ص����˼��
{
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++)
		{
			//���ص����˼�룬���װ���i����Ʒ���������洢�ܻ�õ�����ֵ��B[i][j] 
			int bestP = 0;
			for (int k=0; k*W[i]<=j; k++)
			{
				if (bestP < B1[i-1][j-k*W[i]] + k*P[i])
					bestP = B1[i-1][j-k*W[i]] + k*P[i];
			}
			B1[i][j] = bestP;
		}
	}
	
	return B1[n][c];
}

int CompletePack_2(int n, int c)//��̬�滮:F[i][j] = max(F[i-1][j], F[i][j-W[i]] + P[i])
{
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++)
		{
			if (j < W[i]) //����������������͸���i-1����Ʒװ������Ϊj�ı����Ľ��һ�� 
				B2[i][j] = B2[i-1][j];
			else //���������㹻�����ο���ѡ��װ��װ��i����Ʒ����Ϊ��i����Ʒ����װ���޴Σ��ʱ����п����Ѿ�װ�е�i����Ʒ�ˣ� 
				B2[i][j] = max(B2[i-1][j], B2[i][j-W[i]] + P[i]);
		}
	}
	
	return B2[n][c];
}

int CompletePack_3(int n, int c)//�Ż��Ķ�̬�滮�㷨����2��һά��������ά���� 
{
	//pre[j]�൱��B2[i-1][j]��cur[j]�൱��B2[i][j] 
 	for (int i=1; i<=n; i++)
	{   //�������������j��С��F[j]������ѭ������j��ֵ��С�������
		for (int j=1; j<=c; j++)
		{
			if (j < W[i] || pre[j] > cur[j-W[i]] + P[i])
				cur[j] = pre[j]; 
			else
				cur[j] = cur[j-W[i]] + P[i];
		}
		for (int j=0; j<=c; j++)
		{
			pre[j] = cur[j]; 
		}
	}
	
	return cur[c];
}

int CompletePack_4(int n, int c)//��һ���Ż��Ķ�̬�滮�㷨����1��һά��������ά����
{
 	for (int i=1; i<=n; i++)
	{//�������������j��С��F[j]������ѭ������j��ֵ��С������� 
		for (int j=W[i]; j<=c; j++)
		{//��(j < W[i] || B4[j] > B4[j-W[i]] + P[i])ʱ��B4[j]��ֵ����
			if (B4[j] < B4[j-W[i]] + P[i])
				B4[j] = B4[j-W[i]] + P[i];
		}
	}
	
	return B4[c];
}

void Show(int i, int j)  //i��j�ֱ��ʾ���ڴ���ĵ�i����Ʒ�ʹ�ʱ������ʣ������
{
	if (j == 0 || i == 0)
		return;
	
	if (B2[i][j] == B2[i-1][j]) 
	{
		Show(i-1, j); //δװ����Ʒi
	}
	else
	{
		for (int k=j/W[i]; k>0; k--)
		{
			if (B2[i][j] == B2[i-1][j-k*W[i]] + k*P[i]) //װ����k����Ʒi 
			{
				Show(i-1, j-k*W[i]);
				cout << i << ": " << k << " " << W[i] << " " << P[i] << endl;
				return;
			}
		}
	}
} 

int Show_2(int n, int c) //��������B2[][]�������Ʒװ�������������ʵ��װ������X[i]��ʼ��Ϊ0 
{
	for (int i=n,j=c; i>0; i--)
	{
		if (B2[i][j] != B2[i-1][j]) 
		{
			for (int k=j/W[i]; k>0; k--)
			{
				if (B2[i][j] == B2[i-1][j-k*W[i]] + k*P[i])
				{
					X[i] = k;
					j -= k*W[i]; //����j��ֵ 
					break;
				}
			}
		}
	}
	
	int s = 0;
	for (int i=1; i<=n; i++)
	{
		if (X[i] > 0)
		{
			s += P[i] * X[i];
			cout << i << ": " << X[i] << " " << W[i] << " " << P[i] << endl;
		}
	}	
	return s;
} 
