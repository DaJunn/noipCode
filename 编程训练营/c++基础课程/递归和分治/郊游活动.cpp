/*
	Name: ���λ
	Copyright: 
	Author: 
	Date: 20-09-17 15:23
	Description: ��n��ͬѧ�μ�ѧУ��֯�Ľ��λ����֪ѧУ����n��ͬѧ�Ľ����ܾ���ΪAԪ��
���ͬʱ��iλͬѧ�Լ�Я����MiԪ��Ϊ�˷��㽼�Σ���ص��ṩB(��n)�����г��������ã����õ�j�����г��ļ۸�ΪCjԪ��
ÿλͬѧ����ʹ���Լ�Я����Ǯ����ѧУ�Ľ��ξ��ѣ�Ϊ�˷����������ÿλͬѧֻ��Ϊ�Լ��������г����Ҳ����Ǯ�����ˣ�
������֪������ж���λͬѧ�ܹ����õ����г��������ġ����2.5�֣�����3�֣�
 ������ö��ַ�����������[l, r]������ȡ�м��mid���ж����õ����г��������ܷ�ﵽmid��
 �жϵĹ���������̰���㷨ʵ�ֵġ�
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAXN = 10;
int M[MAXN], C[MAXN];
int A, B, n;

int Cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

bool Check(int num) //���±�Ϊnum�����Ƿ������õ��� 
{
	int count = 0, i = n - num - 1, j = 0; //i������߽磬[i,n)��num+1���� 
	while (i < n)
	{
		if (C[j] > M[i])//�ۼ�Ƿ����ֵ 
		{
			count += C[j] - M[i];
		}
		i++; j++;
	}
	return count <= A; //�ܾ����ܷ�֧��Ƿ�� 
}

int main() 
{
	cin >> n >> B >> A;
	
	for (int i=0; i<n; i++)
		cin >> M[i];
	for (int i=0; i<B; i++)
		cin >> C[i];
 	qsort(M, n, sizeof(M[0]), Cmp);
 	qsort(C, B, sizeof(C[0]), Cmp);
 	
 //	for (int i=0; i<n; i++)
//		cout <<  M[i] << " ";
//	for (int i=0; i<B; i++)
//		cout <<  C[i] << " ";
 	
 	int ans = 0, mid, left = 0, right = n-1;
 	while (left <= right)
 	{
		mid = (left + right) / 2;
		if (Check(mid))
		{
			ans = mid; //ע��mid���±꣬��ans������ 
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	
 	cout << ans+1 << endl; 
 	
    return 0;
}
