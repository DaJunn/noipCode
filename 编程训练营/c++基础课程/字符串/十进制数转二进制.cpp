/*
	Name: ʮ������ת������ 
	Copyright: 
	Author: 
	Date: 06\09\18 09:44
	Description: ʮ��������ת���ɶ������������á���2��ȡ�ࡱ����ʮ����С��ת���ɶ�����С�����á���2˳ȡ��������
���������ǣ���С�����ֳ���2��Ȼ��ȡ�������������֣�ʣ�µ�С�����ּ�������2��Ȼ��ȡ�����������֡�
��˽��У�ֱ������С������Ϊ0�����ߴﵽ��Ҫ��ľ���Ϊֹ�� 
	����һ��ʮ�����������ݹ涨�ľ��ȣ������Ӧ�Ķ��������� 
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

string Convert(double a, int p);//�����Ӧ�Ķ�������

int main() 
{
	double a;
	
	cin >> a;
	cout << Convert(a, 3) << endl;
	
	return 0;	
} 

string Convert(double a, int p)//�����Ӧ�Ķ�������
{
	int z = int(a);
	double x = a - z;
	string b;
	
	if (z == 0)
		b = "0";
	while (z > 0)
	{
		b = char(z%2+'0') + b;
		z /= 2;
	}
	if (p == 0) //����Ϊ0�������С������ 
		return b;
		
	b += ".";
	while (p > 0)
	{
		b += char(int(x * 2)+'0');
		x = x * 2 - int(x * 2);
		p--;
	}
	return b;
}
