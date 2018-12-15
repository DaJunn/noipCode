/*
	Name: �����Ȼ��
	Copyright: 
	Author:  ����׾ 
	Date: 15/12/18 13:25
	Description: �����Ȼ��
Problem Description
�κ�һ������1����Ȼ��n���ܿ��Բ�ֳ����ɸ�С��n����Ȼ��֮�͡�
Input
�����ж������ݣ�����ÿ�����ݾ�һ����n��
Output
����ÿ���������n�Ĳ�ַ�����
Sample Input
4
Sample Output
1+1+1+1
1+1+2
1+3
2+2
	 
�㷨1�������㷨���1���ȴ���ݹ���ڣ����յ㣩����ö�ٸ��ֿ���ֵ���ݹ�������һ�㡣 
�㷨2�������㷨���2����ö�ٸ��ֿ���ֵ�����ж��Ƿ񵽴��յ㣬�������յ���������������ݹ�������һ�㡣 
�㷨2��������ȱ��㷨1Ҫ��һ�㣬���ǲ����㷨1�ṹ������
�㷨3���ǵݹ��㷨���Զ���ջģ���㷨2�ĵݹ���̡�
*/
#include<iostream>
#include<cmath>

using namespace std;

const int N = 10; //����n��Χ 
int a[N+1] = {1}; //ȷ��a[1]��С��1 
int n;

void Print(int t);
void dfs1(int s, int t); //���1 
void dfs2(int s, int t); //���2 
void dfs3(); //�ǵݹ��㷨 

int main()
{
	while (cin >> n)
	{
		dfs1(n, 1);
	//	dfs2(n, 1);
	//	dfs3();
	}
	
	return 0;
}

void Print(int t)
{
	for (int i=1; i<t; i++)
	{
		cout << a[i] << "+";
	}
	cout << a[t] << endl; 
}

void dfs1(int s, int t) //���1 
{
	if (s == 0) //�����յ㣬������ 
	{
		Print(t-1); 
	}
	else
	{
		for (int i=a[t-1]; i<=s; i++) //ö�ٸ��ֿ���ֵ������һ���ǵݼ����� 
		{
			if (i < n) //��������:��ֳ����ɸ�С��n����Ȼ�� 
			{
				a[t] = i;
				dfs1(s-i, t+1); //������һ�� 
			}
		}
	}
}

void dfs2(int s, int t)//���2 
{
	for (int i=a[t-1]; i<=s; i++) //ö�ٸ��ֿ���ֵ������һ���ǵݼ����� 
	{
		if (i < n) //��������:��ֳ����ɸ�С��n����Ȼ�� 
		{
			a[t] = i;
			if (s == i) //�����յ㣬������ 
			{
				Print(t); 
			}
			else
				dfs2(s-i, t+1); //������һ�� 
		}
	}
}

void dfs3() //�ǵݹ��㷨 
{
	int s = n;
	int t = 1;
	while (t >= 1)
	{
		while (++a[t] <= s) //ö�ٸ��ֿ���ֵ������һ���ǵݼ����� 
		{
			if (a[t] >= a[t-1] && a[t] < n)   //�������� 
			{
				if (s == a[t])  //�����յ㣬������ 
				{
					Print(t); 
					break;
				}
				else
				{
					s -= a[t];  //�޸ı��  
					t++;  //������һ�� 
				}
			}
		}
		a[t] = 0; //���� 
		s += a[--t]; //�ָ���� 
	}
}
