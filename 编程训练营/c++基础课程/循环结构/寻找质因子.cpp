/*
	Name: Ѱ�������� 
	Copyright: 
	Author: 
	Date: 04\09\18 10:40
	Description: ����������n����������������������ӣ�����n=36�������2 3�� 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

void Fun(int n);//����������n�����������������������
void Fun2(int n);//����������n�����������������������

int main() 
{
	for (int i=3; i<=40; i++)
	{
		cout << i << ": ";
		Fun(i);
		cout << i << ": ";
		Fun2(i);
	}
	
	return 0;	
} 

void Fun(int n)//����������n�����������������������
{
    int m = 2;
	
    while (n >= 2)
    { 
        if (n % m == 0)
        	cout << m << " ";
		while (n % m == 0)
			n /= m;
		m++;
    }
    cout << endl;
}

void Fun2(int n)//����������n�����������������������
{
	bool flag = true;
    int m = 2;
	
    while (n >= 2)
    { 
        if (n % m == 0)
        {
        	n /= m;
        	if (flag)
        	{
        		cout << m << " ";
        		flag = false;
			}
		}
		else
		{
			m++;
			flag = true;
		}
    }
    cout << endl;
}

