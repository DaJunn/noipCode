/*
	Name: �۰���ұ���5 
	Copyright: 
	Author: 
	Date: 21-08-18 17:09
	Description: ��֪����Ԫ��A[1]��A[5]��ֵ����Ϊ{6,18,25,37,49}��
	ִ�иó���κ�k��ֵΪ3����key��ֵ������Ϊ( A  ) 
	A 4   B 18  C 47  D 55
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 6;
int A[MAX] = {0,6,18,25,37,49};

int BinarySearch(int i, int j, int key)  
{
	int k=0, m;

	while (i <= j)
	{
		k++;
		m = (i + j) / 2;
		if (key == A[m])
			break;
		else if (key < A[m])
			j = m - 1;
		else
			i = m + 1;
	}
	return k;
}

int main() 
{
	for (int key=0; key<100; key++)
		cout << key << ":" << BinarySearch(1, 5, key) << endl;
		
    return 0;
}
