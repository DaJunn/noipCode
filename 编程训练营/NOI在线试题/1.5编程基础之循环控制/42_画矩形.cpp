/*
	Name: 42_������
	Copyright: 
	Author: ����׾ 
	Date: 03-07-17 21:14
	Description: 42_������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���ݲ������������Ρ�

����
����һ�У������ĸ�������ǰ��������Ϊ���������δ�����εĸߺͿ��߲�����3�в�����10�У�������5�в�����10�У���������������һ���ַ�����ʾ������ͼ�ľ��η��ţ����ĸ�����Ϊ1��0��0������ģ�1����ʵ�ġ�
���
���������ͼ�Ρ�
��������
7 7 @ 0
�������
@@@@@@@
@     @
@     @
@     @
@     @
@     @
@@@@@@@
*/
#include<iostream>

using namespace std;

void DrawRectangle(int h, int w, char c, bool f);

int main()
{
    int h, w, flag;
    char c, ch;
    
//    cin >> h >> w >> c >> flag;
//    ch = (flag == 0) ? ' ' : c;
//    
//    for (int j=0; j<w; j++)//�����һ��
//		cout << c;
//	cout << endl;
//	
//	for (int i=2; i<h; i++) //����м�h-2��
//	{
//	 	cout << c;
//	 	for (int j=2; j<w; j++)//���w-2�����ڷ��� 
//			cout << ch;
//	    cout << c << endl;
//	} 
//	
//	for (int j=0; j<w; j++)//�����h��
//		cout << c;
//	cout << endl;
	
	DrawRectangle(5, 7, 57, 0);
			  
    return 0;
}

void DrawRectangle(int h, int w, char c, bool f)
{
	char ch = (f == 0) ? ' ' : c;
    
    for (int j=0; j<w; j++)//�����һ��
		cout << c;
	cout << endl;
	
	for (int i=2; i<h; i++) //����м�h-2��
	{
	 	cout << c;
	 	for (int j=2; j<w; j++)//���w-2�����ڷ��� 
			cout << ch;
	    cout << c << endl;
	} 
	
	for (int j=0; j<w; j++)//�����h��
		cout << c;
	cout << endl;
}
