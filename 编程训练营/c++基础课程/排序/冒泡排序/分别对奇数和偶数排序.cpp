/*
	Name: �ֱ��������ż������ 
	Copyright: 
	Author: 
	Date: 30-08-18 16:26
	Description: ��һ����������Ҫ��ֱ��������ż������������������������ǰ��ż���ں� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 30;
int A[M];

int OddNum(int n);//Ҫ���������ż���ֳ����룬����������ǰ��ż���ں󣬷�������������
void Fun(int low, int high);//Ҫ��ֱ��������ż������������������������ǰ��ż���ں�

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 39 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	int len = OddNum(n);//Ҫ���������ż���ֳ����룬����������ǰ��ż���ں󣬷�������������
	Fun(0, len-1);
	Fun(len, n);
	
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void Fun(int low, int high)//Ҫ��ֱ��������ż������������������������ǰ��ż���ں�
{
    int lastSwapPos;//���һ�η�������������λ��
    int temp; //������������Ԫ��ֵ����ʱ����
    int i;

    while (low < high)
    {
        lastSwapPos = low;//�������һ�ν���λ��Ϊ��߽磨���޽����� 
        for (i=low; i<high; i++)
        {
            if (A[i] > A[i+1])
            {
                temp = A[i];
                A[i] =A[i+1];
                A[i+1] =temp;
                lastSwapPos = i;//�ô������˽���������������Ҫ����ĳ�Ա��Χ 
            }
        }

        high = lastSwapPos;//�����µ��ұ߽�
        for (i=high; i>low; i--)
        {
            if (A[i] < A[i-1])
            {
                temp = A[i];
                A[i] = A[i-1];
                A[i-1] = temp;
                lastSwapPos = i;//�ô������˽���������������Ҫ����ĳ�Ա��Χ 
            }
        }
        low = lastSwapPos;//�����µ���߽� 
    }
}

int OddNum(int n)//Ҫ���������ż���ֳ����룬����������ǰ��ż���ں󣬷�������������
{
    int i = 0, j = n - 1;
	
    while (i < j)
    { 
        while (i < j && A[i] % 2 == 1)
			i++;
		while (i < j && A[j] % 2 == 0)
			j--;
		if (i < j)
			swap(A[i++], A[j--]);
    }
    if (A[j] % 2 == 0)
    	j--;
    return j+1;
}


