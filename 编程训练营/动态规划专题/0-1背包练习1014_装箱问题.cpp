/*
	Name: 1014_װ������  
	Author: ����׾ 
	Description: 
��һ����������ΪV����������0����V����20000����ͬʱ��n����Ʒ��0��n����30����ÿ����Ʒ��һ�����������������
Ҫ��n����Ʒ�У���ȡ���ɸ�װ�����ڣ�ʹ���ӵ�ʣ��ռ�Ϊ��С��
�������� Input Description
һ������v����ʾ��������
һ������n����ʾ��n����Ʒ
������n���������ֱ��ʾ��n ����Ʒ�ĸ������
������� Output Description
һ����������ʾ����ʣ��ռ䡣

�������� Sample Input
24 
6 
8 3 12 7 9 7

������� Sample Output
0 
�㷨����������һ�����͵�0-1�������⣬������Ʒ�ļ�ֵ��С�����������������ֵ��
*/
#include<iostream>

using namespace std;

const int MAXC = 20000; //����������� 
const int MAXN = 30; //��Ʒ��������
int V[MAXN+1];//��i������ֵ�൱��0-1��������Ʒ������ͼ�ֵ 
int F[MAXC+1]; //��̬�滮�м�¼����n����Ʒװ������Ϊj�ı���������ֵ

int ZeroOnePack_5(int n, int c);//�Ż��Ķ�̬�滮�㷨��һά����洢��¼��F[j]��ʼ��Ϊ0 

int main() 
{
	int n, c;
	cin >> c >> n;
	
	for (int i=1; i<=n; i++)//�����±�Ϊ0��Ԫ�� 
	{
		cin >> V[i];
	}
	
	cout << c - ZeroOnePack_5(n, c) << endl; 
	
	return 0;
}

int ZeroOnePack_5(int n, int c)//�Ż��Ķ�̬�滮�㷨��һά����洢��¼��F[j]��ʼ��Ϊ0  
{
 	for (int i=1; i<=n; i++)
	{//�������������j�ϴ��F5[j]������ѭ������j��ֵ�Ӵ�С�ݼ�
		for (int j=c; j>=V[i]; j--)
		{
			if (F[j] < F[j-V[i]] + V[i])
				F[j] = F[j-V[i]] + V[i];
		}
	}
	
	return F[c];
}

