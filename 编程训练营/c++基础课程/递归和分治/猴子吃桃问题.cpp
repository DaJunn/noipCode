/*
	Name: ���ӳ�������
	Copyright: 
	Author: 
	Date: 22-01-18 14:19
	Description: ���ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬
	����񫣬�ֶ����һ���ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ����
	�Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����һ��������10���������ٳ�ʱ����ֻʣ��һ�������ˡ�
	���һ�칲ժ�˶��١�
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int Fun(int n);

int main() 
{
	cout << Fun(1) << endl;
	
	int n = 1;
	for (int i=9; i>0; i--)
		n = (n+1)*2;
	cout << n << endl;
		
    return 0;
}

int Fun(int n)
{
	if (n == 10)
		return 1;
	return (Fun(n+1) + 1) * 2;
}
