/*
	Name: �Էֲ�������ż������ 
	Copyright: 
	Author: 
	Date: 29-08-18 22:28
	Description: ���� a Ϊһ����������������ǰ��ż���ں�������ż���ѷֱ���������
	���ݶԷֲ���˼�룺���һ�������� a �в������� Key �ĳ�����д���1-5�� 
���£�
*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	int a[10] = {1,3,5,7,9,2,4,6,8,10};
	int key;
	int i=0, j=9, m;
	cin >> key; 
	
	while (i <= j)
	{
		m = (i + j) / 2;
		if (a[m] == key)
			break; //���1 
		if (a[m]%2==1 && key%2==0)
			i = m + 1; //���2 
		else if (a[m]%2==0 && key%2==1)
			j = m - 1; //���3
		else
		{
			if (a[m] < key)
				i = m + 1; //���4 
			else
				j = m - 1;	 //���5
		}
	}
	if (i <= j)
		cout << "λ�ã�" << m << endl;
	else
		cout << "δ�ҵ�" << endl;
		
	return 0;
}
