/*
	Name: �Էֲ���ѭ��������������ֵ 
	Copyright: 
	Author: 
	Date: 12-09-18 21:09
	Description: ��νѭ������������ָ��һ���ǵݼ�����ֳ��������Σ�Ȼ���������������û���
	�õ�һ��ѭ���������飬���磬ԭ����A[6]={1��2��3��4��5��6}��
	��������B[6]={1��2��3��4��5��6, 1��2},����C[6]={5��6, 1��2��3��4}��ѭ���������顣
	�㷨˼�룺������С������Χ�����ֻʣ2��Ԫ�أ�
	��Ϊѭ���������飬����low��high�ֱ�ָ�����ֵ����Сֵ��
	��Ϊ���������飬����low��high�ֱ�ָ��δ�ֵ�����ֵ�� 
 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 5;
//int A[M] = { 1,3,5,7,9,11,11,11,19,19};
int A[M] = {11,19,21, 3,4};

int Fun(int low, int high);//�Էֲ���ѭ��������������ֵ�±� 

int main() 
{
	int n  = M;
	
	for (int i=0; i<n; i++)
		cout << i << ": " << A[i] << " ";
	cout << endl;
	
	cout << A[Fun(0,n-1)] << endl;
	return 0;	
} 

int Fun(int low, int high)//�Էֲ���ѭ��������������ֵ�±� 
{
	int maxPos = high; //��Ϊ���������飬��ѭ������������Ҷγ���Ϊ0���򷵻�maxPos 
	int mid;
	
	while (low < high) //����1��Ԫ�� 
	{ 
        if (low + 1 == high)//ֻʣ2��Ԫ��
        {
        	if (A[low] <= A[high]) //�Ǵ��������飬�򷵻�minPos
			   return maxPos;
			else                   //����A[low]Ϊ���ֵ 
				return low; 
		 } 
		mid = (low + high) / 2;
		if (A[mid] >= A[low]) //mid�����ֵ��࣬��������ֵ 
			low = mid;
		else   //mid�����ֵ�Ҳ�
			high = mid; //���ʣ�Ϊ�β���д��high=mid-1��ԭ�򣺿���A[mid]Ϊ���ֵ������ 
	}
	
	return maxPos; //ֻ��һ��Ԫ�� 
}
