/*
	Name: �۰���ұ���4 
	Copyright: 
	Author: 
	Date: 21-08-18 17:09
	Description: ��֪����Ԫ��A[1]��A[10]��ֵ����Ϊ{3,9,21,21,21,21,27,28,39,40}��
	ִ�иó���κ󣬱���R,A[R]��ֵ�ֱ���( C  ) 
	A 2,9   B 3,21  C 6,21  D 7,27
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 11;
int A[MAX] = {0,3,9,21,21,21,21,27,28,39,40};

int BinarySearch(int L, int R, int key) //�۰����ֵΪx��Ԫ�ص��±꣬�Ҳ����򷵻�-1 
{
	int k=0, m;

	while (L <= R)
	{
		m = (L + R) / 2;
		if (key >= A[m])
			L = m + 1;
		else
			R = m - 1;
	}
	return R;
}

int main() 
{
	cout << BinarySearch(1, 10, 21) << endl;
		
    return 0;
}
