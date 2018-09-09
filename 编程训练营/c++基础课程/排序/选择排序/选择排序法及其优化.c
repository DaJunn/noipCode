/*
	Name: ѡ�����򷨼����Ż� 
	Copyright: 
	Author: ����׾ 
	Date: 09/09/14 18:11
	Description: 
	ѡ����������㷨��ÿһ�˴Ӵ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ�˳��������ź�������е����ֱ��ȫ�������������Ԫ�����ꡣ 
	�Ľ��汾��Ϊ�˼��ٱȽϵĴ������ɲ���ÿһ��ɨ��ʱ��ͬʱѡ��������Сֵ����������Сɨ�跶Χ��ֱ��ֻʣ��һ��Ԫ�ء� 
	�Ľ��汾����һ��Ҫע�⣺������ֵ������ߣ��϶�Ҫ�����ߣ���ʱҪת�Ƶ���Ӧ����λ�á� 
*/
#include<stdio.h>
#include<stdlib.h> 

#define MAX 10

void SelectSort_1(int vec[], int n);
void SelectSort_2(int vec[], int n);
void DisPlay(int vec[], int n);

int main(void)
{
	int vec[MAX] = {1,2,8,3,3,5,9,7,7,4};
	int n = MAX;
	
	DisPlay(vec, n);
	SelectSort_2(vec, n);
	DisPlay(vec, n);
	
	return 0;
}

void DisPlay(int vec[], int n)
{
	int i;
	
	printf("\n����%d��Ԫ�أ�", n);
	
	for (i=0; i<n; i++)
	{
		printf("%d, ", vec[i]);
	}
	printf("\n");
}

void SelectSort_1(int vec[], int n) //ѡ����������㷨 
{
	int i, j, min;
	int temp;
	
	for (i=0; i<n-1; i++)
	{
		min = i;
		for (j=i+1; j<n; j++)
		{
			if (vec[j] < vec[min])
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			temp = vec[i];
			vec[i] = vec[min];
			vec[min] = temp;
		}	
	}
}

void SelectSort_2(int vec[], int n) //ѡ������Ľ��㷨��ͬʱѡ��������Сֵ 
{
	int i, min, max, left, right;
	int temp;
	
	for (left=0, right=n-1; left<right; left++, right--)
	{
		min = left;
		max = right;
		for (i=left; i<=right; i++)
		{
			if (vec[i] < vec[min])
			{
				min = i;
			}
			else if (vec[i] > vec[max])
			{
				max = i;
			}
		}
		
		if (min != left)
		{
			temp = vec[left];
			vec[left] = vec[min];
			vec[min] = temp;
			
			if (max == left) //������ֵ������ߣ��϶�Ҫ�����ߣ���ʱҪת�Ƶ���Ӧ����λ�� 
			{
				max = min;
			}
		}	
		
		if (max != right)
		{
			temp = vec[right];
			vec[right] = vec[max];
			vec[max] = temp;
		}
	}
}
