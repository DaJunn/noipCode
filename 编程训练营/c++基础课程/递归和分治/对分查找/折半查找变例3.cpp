/*
	Name: �۰���ұ���3 
	Copyright: 
	Author: 
	Date: 21-08-18 17:09
	Description: ��֪����Ԫ��A[1]��A[8]��ֵ����Ϊ{3,18,20,24,45,56,67,88}��
	ִ�иó���κ󣬺������ص�ֵ��������( B  ) 
	A -3   B -4  C 3  D 4
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 9;
int A[MAX] = {0,3,18,20,24,45,56,67,88};

int BinarySearch(int i, int j) //�۰����ֵΪx��Ԫ�ص��±꣬�Ҳ����򷵻�-1 
{
	int k=0, m;
	int key = rand()%100;

	while (i <= j)
	{
		m = (i + j) / 2;
		if (key == A[m])
			break;
		else if (key < A[m])
			j = m - 1, k--;
		else
			i = m + 1, k++;
	}
	return k;
}

int main() 
{
	cout << BinarySearch(1, 8) << endl;
		
    return 0;
}
