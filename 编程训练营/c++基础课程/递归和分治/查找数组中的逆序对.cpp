/*
	Name: ���������е������
	Copyright: 
	Author: 
	Date: 10-01-18 13:57
	Description: ��Ŀ������
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ�����飬�����������е�����Ե�������
���룺
ÿ�����԰����������У�
��һ�а���һ������n����ʾ�����е�Ԫ�ظ���������1 ��n ��40000��
�ڶ��а���n��������ÿ�������Ϊint���͡�
�����
��Ӧÿ�����԰��������һ����������ʾ�����е�����Ե�������
�������룺
4
7 5 6 4
���������
5

�㷨������
�㷨һ�����ͳ�ƣ�ʱ�临�Ӷ���N^2
�㷨�������ù鲢�����˼�룬�ںϲ�������ͳ������Եĸ�����ʱ�临�Ӷ��� N*Log(N)�� 
*/

#include<iostream>

using namespace std;

const int MAX = 40001;
int A[MAX], TA[MAX];
int sum = 0;

int ReverseNum_1(int n); //���ͳ��������� 
int ReverseNum_2(int n); //�鲢����������� 
void MergeSort(int low, int high);//�鲢�����㷨���ݹ飩 
void MergeSort_2(int low, int high);//�鲢�����㷨���ǵݹ飩 
void Merge_1(int low, int mid, int high);//�ϲ����У�ͬʱͳ����������� 
void Merge_2(int low, int mid, int high);//�ȸ����ٺϲ�������ʹ�������� 

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
	}
	
	cout << ReverseNum_2(n);
		
    return 0;
}

int ReverseNum_1(int n)
{
	int s = 0;
	for (int i=1; i<n; i++)
	{
		for (int j=0; j<i; j++)
		{
			s += A[j] > A[i];
		}
	}
	return s;
}

int ReverseNum_2(int n)
{
	MergeSort(0, n-1);
	return sum;
}

void MergeSort(int low, int high)
{
	if (low == high)
		return;
		
	int mid = (low + high) / 2;
	MergeSort(low, mid);
	MergeSort(mid+1, high);
	Merge_2(low, mid, high);
}

void MergeSort_2(int low, int high)
{
	int i, L1, L2=1, n=high-low+1;
	for (L1=L2; L2<=n; L1=L2)//�ⲿ for ѭ����ѭ����ÿִ��һ�Σ���ʹL1��L2�ӱ�
	{
		L2 = L1 * 2;
		for (i=0; i+L2<=n; i+=L2)
		{
			Merge_2(i, i+L1-1, i+L2-1);
		}
		//��ʣ�µ�Ԫ����������L1��L2֮�䣬˵�����������������ȵ����У������ǽ��кϲ�������
		//��ʣ�µ�Ԫ������������L1��˵����ЩԪ������ͬһ������������У�����ϲ���
		if (i+L1 < n)
			Merge_2(i, i+L1-1, n-1);
	}
}

void Merge_1(int low, int mid, int high)
{
	int i=low, j=mid+1, k=low;
	//��A[]��Ԫ�ذ��ǵݼ���鲢��TA[] 
	while (i<=mid && j<=high)
	{
		if (A[i] <= A[j])
		{
			TA[k++] = A[i++];
		}	
		else
		{
			TA[k++] = A[j++];
			sum += mid - i + 1;//ͳ����������� 
		}
	}
	//��A[]��ʣ���Ԫ�ظ��Ƶ�TA[] 
	while (i <= mid)
	{
		TA[k++] = A[i++];
	}
	while (j <= high)
	{
		TA[k++] = A[j++];
	}
	//���ϲ��õ��������и��Ƶ�A[] 
	for (i=low; i<=high; i++)
	{
		A[i] = TA[i];
	}
}

void Merge_2(int low, int mid, int high)
{
	int i, j, k;
	//��A[low..mid]��Ԫ��˳���Ƶ�tempA[low..mid]
	for (i=low; i<=mid; i++) 
	{
		TA[i] = A[i];
	}
	//��A[mid+1..hig]��Ԫ���������Ƶ�tempA[mid+1..hig]
	for (i=mid+1,j=high; i<=high; i++,j--) 
	{
		TA[i] = A[j];
	}
	//��TA[]��Ԫ�ذ��ǵݼ���鲢��A[] 
	for (k=i=low,j=high; k<=high; )//ֻ���ж�k�Ƿ�Խ�磨Ҳ���ж�i<=j�� 
	{
		if (TA[i] <= TA[j])
		{
			A[k++] = TA[i++];
		}	
		else
		{
			A[k++] = TA[j--];
			sum += mid - i + 1;//ͳ����������� 
		}
	}
}
