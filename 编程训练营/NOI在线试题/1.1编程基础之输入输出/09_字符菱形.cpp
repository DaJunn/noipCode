/*
	Name: 09:�ַ�����
	Copyright: 
	Author: 
	Date: 10-07-16 07:42
	Description: 
	09:�ַ�����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ַ�����������һ���Խ��߳�5���ַ�����б���õ����Ρ�

����
����ֻ��һ�У� ����һ���ַ���
���
���ַ����ɵ����Ρ�
��������
*
�������
  *
 ***
*****
 ***
  *
  
�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	256kB	0ms	    534 B    	G++      10-07-16 07:46
*/

#include <iostream>

using namespace std;

int main( )
{
	const int n = 3;
	char c;
	
	cin >> c;
	
	
	for (int i=0; i<n; i++)  //˳����� 
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
	
	for (int i=n-2; i>=0; i--)  //������� 
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

