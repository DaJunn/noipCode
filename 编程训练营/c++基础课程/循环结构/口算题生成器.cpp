/*
	Name: ������������ 
	Copyright: 
	Author: 
	Date: 19-08-18 10:01
	Description: Ϊһ�꼶С�������һ���Զ����ɺ�����10���ڼӷ��ĳ���
�ܹ�����6����Ŀ��ÿ���������2��[1,9]����������Ҫ�����ǵĺͲ�����10�����������������ǡ�
�����ʾ�* + * = ���ȴ�ѧ������𰸡�
������ȷ�����"��ȷ"����10�֣��������"������ȷ��Ϊ*"�����Ʒ֡�
�������ֲܷ���������
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	srand(time(NULL));
	
	int a, b, c, ans, n = 0, s = 0;
	while (1)
	{
		a = rand() % 9 + 1;
		b = rand() % 9 + 1;
		c = a + b;
		if (c > 10)
			continue;
			
		printf("%d + %d = ", a, b);
		cin >> ans;
		if (ans == c)
		{
			s += 10;
			cout << "��ȷ��" << endl;
		}
		else
		{
			cout << "����ȷ����ȷ���ǣ�" << c << endl;
		}
		
		if (++n == 6)
			break;
	}
	
	cout << "����ܷ�Ϊ��" << s << endl;
	
	return 0;
}
