/*
	Name: 08:�ַ�������
	Copyright: 
	Author: 
	Date: 10-07-16 06:48
	Description: 
	08:�ַ�������
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ�����������һ���ױ߳�5���ַ�����3���ַ��ĵ����ַ������Ρ�

����
����ֻ��һ�У� ����һ���ַ���
���
���ַ����ɵĵ��������Σ��ױ߳�5���ַ�����3���ַ���
��������
*
�������
  *
 ***
*****

�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	252kB	0ms	     309 B	    G++	    10-07-16 07:08
*/
#include <iostream>

using namespace std;

int main( )
{
	const int n = 3;
	char c;
	
	cin >> c;
	
	
	for (int i=0; i<n; i++)
	{
		for (int j=n-i; j>1; j--) //����ո� 
		{
			cout << ' ';
		}
		
		for (int j=0; j<i+i+1; j++)//������� 
		{
			cout << c;
		}
		cout <<  endl;
	}
	
    
    return 0;
}
