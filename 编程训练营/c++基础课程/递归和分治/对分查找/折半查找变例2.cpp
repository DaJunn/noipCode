/*
	Name: �۰���ұ���2 
	Copyright: 
	Author: 
	Date: 20-08-18 16:53
	Description: һֱ���������������100��Ԫ��a[1]��a[100]���������find��ȷ�����ҵ�����
	��������к󣬱���cs��ֵ�������ǣ� C ��
	A 7   B 13  C 14  D 50 
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib>  

using namespace std;

int BinarySearch(int x); //�ݼ���Ծ����ֵΪx��Ԫ�أ����ز��ҵĴ���

int main() 
{
	for (int i=1; i<=100; i++)
		cout << i << ":" << BinarySearch(i) << " ";
		
    return 0;
}

int BinarySearch(int x) //�ݼ���Ծ����ֵΪx��Ԫ�أ����ز��ҵĴ���
{
	int a[101] = {0};
	for(int i=0; i<101; i++)
		a[i] = i;
		
	int len = 14;//Ϊʲô��14����Ϊ1+2+3+...+14 = 105 > 100���� 1+2+3+...+13 = 91 < 100
	int left = 0, right = len, cs = 0;
	
	while (right <= 100)
	{
		cs++;
		if (a[right] == x)//�ҵ�x 
			break;
		else if (a[right] > x) //�ұ߽����� 
		{
			right--;
			if (left == right)//���ұ߽��غ��ˣ�ֻʣ��һ��Ԫ��x 
				break;
		}
		else //��߽����ƣ��ұ߽��������ƶ�len��λ�� 
		{
			left = right;
			len--;
			right += (right+len > 100) ? 1 : len;
		}
	}
	return cs;
}
