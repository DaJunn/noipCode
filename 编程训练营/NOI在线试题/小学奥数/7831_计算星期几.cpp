/*
	Name: 7831_�������ڼ�
	Copyright: 
	Author: ����׾ 
	Date: 01-07-17 20:18
	Description: 7831_�������ڼ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��������������գ���ô��ab��֮�������ڼ���

����
����������a��b���м��õ����ո������0 < a <= 100, 0 < b <= 10000��
���
һ���ַ����������ab?��֮�������ڼ���
���У�Monday������һ��Tuesday�����ڶ���Wednesday����������Thursday�������ģ�Friday�������壬Saturday����������Sunday�������ա�
��������
3 2000
�������
Tuesday
��Դ
�������������һ������Сѧ���꼶���� (ISBN 978-7-5445-2883-2) ģ������� ��16��
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int a, b, d, m=1;
    
    cin >> a >> b;
    
    for (int i=0; i<b; i++)  
    {
	 	m = (m * a )% 7;
	}
    
    switch(m)
	{
		case 1: cout << "Monday";break;
		case 2: cout << "Tuesday";break;
		case 3: cout << "Wednesday";break;
		case 4: cout << "Thursday";break;
		case 5: cout << "Friday";break;
		case 6: cout << "Saturday";break;
		case 0: cout << "Sunday";break;
	} 
	  
    return 0;
}
