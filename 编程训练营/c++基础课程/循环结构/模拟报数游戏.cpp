/*
	Name: ģ�ⱨ����Ϸ
	Copyright: 
	Author: 
	Date: 19-08-18 10:01
	Description: ģ�ⱨ����Ϸ���̡�
��Ϸ���򣺰�˳����������Ҫ����3�ı������������3����������ĳ���༶��40�ˣ�ÿ��ͬѧ����ȷ����������Ǳ����Ĺ��̣���������֣��ÿո��������

*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	int n = 0, s = 0;
	while (1)
	{
		n++;
		if (n%3==0 || n%10==3 || n/10%10==3 || n/100%10==3 || n/1000%10==3)
			continue;
		cout << n << " ";
		if (++s == 40)
			break;
	}
	
	return 0;
}
