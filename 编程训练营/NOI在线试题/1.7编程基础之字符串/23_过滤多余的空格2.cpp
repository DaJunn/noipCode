/*
	Name: 23_���˶���Ŀո�
	Copyright: 
	Author: 
	Date: 03-09-17 07:53
	Description: 23_���˶���Ŀո�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
һ��������Ҳ���ж�������ո񣬹��˵�����Ŀո�ֻ����һ���ո�

����
һ�У�һ���ַ��������Ȳ�����200�������ӵ�ͷ��β��û�пո�
���
����֮��ľ��ӡ�
��������
Hello      world.This is    c language.
�������
Hello world.This is c language.
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;
char A[N];

int main() 
{
	cin >> A;
	cout << A;
	while (cin >> A)
	{
		cout << " " << A;
	}
	cout << endl;
			
	return 0;	
} 
