/*
	Name: ������� 
	Copyright: 
	Author: 
	Date: 06\09\18 09:44
	Description: ����һ�����ַ�","������ʵ����������е����ʵ�� 
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

double MaxNum(const string s);//������ʵ�� 

int main() 
{ 
	string s;
	
	cin >> s;
	cout << MaxNum(s) << endl;
	
	return 0;	
} 

double MaxNum(const string s)//������ʵ�� 
{
	bool xiaoshu = false;
	double sum = 0, x = 0.1, max = -99999999, f = 1;//f���������� 
	int n = s.length();
	
	for (int i=0; i<n; i++)
	{
		if (s[i] == ',')
		{
			sum *= f;
			max = (sum > max) ? sum : max;
			xiaoshu = false;
			sum = 0;
			x = 0.1;
			f = 1;
		}
		else if (s[i] == '-')
			f = -1;
		else if (s[i] == '.')
			xiaoshu = true;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (!xiaoshu) //������������ 
			{
				sum = sum * 10 + (s[i]-'0');
			}
			else//�ۼ�С������ 
			{
				sum += x * (s[i]-'0');
				x *= 0.1;
			}
		}
	}
	//�������һ������ 
	sum *= f;
	max = (sum > max) ? sum : max;
	return max;
}
