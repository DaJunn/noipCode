/*
	Name: 03:�������
	Copyright: 
	Author: ����׾ 
	Date: 09-07-16 21:32
	Description: 
	03:�������
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����������������ÿ������ռ8���ַ��Ŀ�ȣ��Ҷ���������ǡ�

����
ֻ��һ�У�������������������֮����һ���ո�ֿ���
���
ֻ��һ�У����ո�ʽҪ�������������������֮����һ���ո�ֿ���
��������
123456789 0 -1
�������
123456789        0       -1

�ύ��	 ���	   ����	�ڴ�	ʱ��	���볤��	����	�ύʱ��
����׾	Accepted	10	252kB	0ms	     256 B   	G++	   09-07-16 22:38
����׾  Accepted	10	252kB	0ms	     236 B   	G++	   09-07-16 22:41
*/
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main( )
//{
//	int a, b, c;
//	
//	cin >> a >> b >> c;
//	
//    cout << setw(8) << right << a << ' '; 
//	cout << setw(8) << right << b << ' ';
//	cout << setw(8) << right << c << endl;
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>
using namespace std;

int main( )
{
	int a, b, c;
	
	cin >> a >> b >> c;
	
	cout.width(8);
    cout << a << ' ';
    cout.width(8);
    cout << b << ' ';
    cout.width(8);
    cout << c << endl;
    
    printf("%8d %8d %8d", a, b, c);
    
    return 0;
}
