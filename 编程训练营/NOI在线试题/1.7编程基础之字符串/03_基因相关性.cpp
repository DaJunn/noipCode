/*
	Name: 03_���������
	Copyright: 
	Author: 
	Date: 31-08-17 16:57
	Description: 03_���������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
Ϊ�˻�֪���������ڹ��ܺͽṹ�ϵ������ԣ�������Ҫ��������ͬ���е�DNA���бȶԣ����жϸñȶԵ�DNA�Ƿ��������ԡ�
�ֱȶ�����������ͬ��DNA���С����ȶ�������DNA������ͬλ�õļ��Ϊһ������ԣ����һ��������е����������ͬ�Ļ������Ϊ��ͬ����ԡ�
���ż�����ͬ�����ռ�ܼ���������ı���������ñ������ڵ��ڸ�����ֵʱ���ж�������DNA��������صģ�������ء�
����
�����У���һ���������ж�������DNA�����Ƿ���ص���ֵ�����2��������DNA���У����Ȳ�����500����
���
������DNA������أ��������yes�������������no����
��������
0.85
ATCGCCGTAAGTAACGGTTTTAAATAGGCC
ATCGCCGGAAGTAACGGTCTTAAATAGGCC
�������
yes
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 501;
char S1[N], S2[N];

int main() 
{
	double a, s=0;
	cin >> a >> S1 >> S2;
	for (int i=0; S1[i]!='\0'; i++)
	{
		s += (S1[i] == S2[i]);
	}
	s /= strlen(S1);
	if (s >= a)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	
	return 0;	
} 
