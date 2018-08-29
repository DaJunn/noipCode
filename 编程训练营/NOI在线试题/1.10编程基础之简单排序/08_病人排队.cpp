/*
	Name:  08_�����Ŷ�
	Copyright: 
	Author: 
	Date: 17-08-17 09:53
	Description: 08_�����Ŷ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���˵Ǽǿ�������дһ�����򣬽��ǼǵĲ��˰�������ԭ���ų��������Ⱥ�˳�� 
1. �����ˣ����� >= 60�꣩�ȷ����������ȿ����� 
2. �����˰�����Ӵ�С��˳�򿴲���������ͬ�İ��Ǽǵ��Ⱥ�˳������ 
3. �������˰��Ǽǵ��Ⱥ�˳�򿴲���
����
��1�У�����һ��С��100������������ʾ���˵ĸ�����
���水�ղ��˵Ǽǵ��Ⱥ�˳��ÿ������һ�����˵���Ϣ��������һ������С��10���ַ�����ʾ���˵�ID��ÿ�����˵�ID������ͬ��ֻ�����ֺ���ĸ����
һ��������ʾ���˵����䣬�м��õ����ո������
���
���źõĿ���˳��������˵�ID��ÿ��һ����
��������
5
021075 40
004003 15
010158 67
021033 75
102012 30
�������
021033
010158
021075
004003
102012
*/
#include<iostream>
#include<string>

using namespace std;

const int M = 100;
string ID[M];
int Age[M], Old[M];

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> ID[i] >> Age[i];
	//��ȡ��һ����������� 
	int f = 0;
	while (f < n && Age[f] < 60)
		f++;
	Old[0] = f;
	
	int len = 1, low, high, mid;
	for (int i=f+1; i<n; i++)//�������˲������򣨴洢��ţ� 
	{
		if (Age[i] >= 60)
		{
			low = 0;
			high = len-1;
			while(low <= high) //�۰���Ҳ���λ��
			{
				mid = (low + high)/2;
				if (Age[Old[mid]] < Age[i])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j=len++; j>low; j--)
		    {
				Old[j] = Old[j-1];
		    }
		    Old[low] = i; //�������i 
		}
	}
	
	if (f == n)//ȫ�������� 
	{
		for (int i=0; i<n; i++)//��������� 
			cout << ID[i] << endl;
	}
	else if (len == n)//ȫ�������� 
	{
		for (int i=0; i<len; i++)//��������� 
			cout << ID[Old[i]] << endl;
	}
	else 
	{
		for (int i=0; i<len; i++)//��������� 
			cout << ID[Old[i]] << endl;
		for (int i=0; i<n; i++)//��������� 
		{
			if (Age[i] < 60)
				cout << ID[i] << endl;
		}
	}
	
    return 0;
}
