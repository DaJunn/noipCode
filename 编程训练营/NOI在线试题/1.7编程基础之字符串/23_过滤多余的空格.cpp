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
	gets(A); 
	int s = 0;
	for (int i=0; A[i]!='\0'; i++)
	{
		if (A[i] == ' ')
		{
			if (s == 0) //ֻ���1���ո� 
				cout << ' ';
			s = 1;
		}
		else
		{
			cout << A[i];
			s = 0;
		}
	}
	cout << endl;
			
	return 0;	
} 
