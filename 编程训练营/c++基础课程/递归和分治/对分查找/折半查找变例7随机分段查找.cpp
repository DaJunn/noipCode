/*
	Name: �۰���ұ���7����ֶβ���
	Copyright: 
	Author: 
	Date: 14\09\18 14:51
	Description: ���۰���Ҹ�Ϊ����趨��Ŧ 
    �����1,2���������� 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 6;
int A[MAX] = {0,6,18,25,37,49};

int BinarySearch(int i, int j, int key) //����ֶβ���ֵΪx��Ԫ�ص��±꣬�Ҳ����򷵻�-1 
{
	int m;

	while (i <= j)
	{
		m = rand() % (j - i + 1) + i;
		if (key == A[m])
			return m;
		else if (key < A[m])
			j = m - 1; //���1 
		else
			i = m + 1; //���2
	}
	return -1;
}

int main() 
{
	for (int key=0; key<50; key++)
		cout << key << ":" << BinarySearch(1, 5, key) << endl;
		
    return 0;
}
