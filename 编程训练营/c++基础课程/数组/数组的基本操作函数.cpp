/*
	Name: ����Ļ����������� 
	Copyright: 
	Author: 
	Date: 04\09\18 15:24
	Description: 
*/
#include <iostream>
#include <cstdlib>

using namespace std;

//////////////////��1�ڣ����������� 
//�������A������Ԫ�أ�Ԫ�ؼ��ÿո������
void PrintArray(const int A[], int n);
//�������A������[low,high]��Ԫ�أ�Ԫ�ؼ��ÿո������
void PrintArray(const int A[], int low, int high);
//������A������[low,high]��Ԫ�ظ��Ƶ�����B������������B�ĳ��� 
int CopyArray(const int A[], int B[], int low, int high);
//����n�������Ϊ����A��ֵ 
void CreateArray(int A[], int n);
//�Ӽ��̶���n����Ϊ����A��ֵ 
void CreateArray(int A[], int n);
//������A��ֵΪx��Ԫ�ظ�Ϊy 
void ChangeValue(int A[], int n, int x, int y);
//ͳ������A������������ 
int OddNumber(const int A[], int n);
//������A�е������洢������B������������B�ĳ��� 
int OddNumerArray(const int A[], int B[], int n);
//������A�в�ѯ�Ƿ����ֵΪx��Ԫ�أ������ڷ��ص�һ��ֵΪx��Ԫ�ص��±꣬���򷵻�-1 
int Find(const int A[], int n, int x);
//ͳ������A��ֵΪx��Ԫ�ص����� 
int NumOfValue(const int A[], int n, int x);

int main()
{
	const int MAX = 20;
	int A[MAX] = {0};
	
	for (int i=0; i<MAX; i++)  
	{
		A[i] = i * 5;
	}
	
	PrintArray(A, MAX);
	
    return 0;
}

//�������A������Ԫ�أ�Ԫ�ؼ��ÿո������
void PrintArray(const int A[], int n)
{
	for (int i=0; i<n; i++)  
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
