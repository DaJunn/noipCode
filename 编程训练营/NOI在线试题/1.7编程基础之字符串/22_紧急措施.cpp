/*
	Name: 22_������ʩ
	Copyright: 
	Author: 
	Date: 02-09-17 17:13
	Description: 22_������ʩ
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���գ�һЩ������վ���ܺڿ����֣���Щ��վ���˺š����뼰email�����ݲ���й¶��
������Щ��վ��ע�������˺ţ�ʹ�õ��û�����һ����ͬ��������ע��ʱʹ������ͬ��email�����ʱ�õ����Ƿ�й¶�����ݣ�ϣ�����콫�Լ���������ġ�
�������£�����email�ҵ�����û��������룬Ȼ��������롣���ĵĹ���Ϊ��Сд�ʹ�д����������ĸ�ַ����ֲ��䡣
����
��һ��Ϊ���email��ַ�����Ȳ�����50���ַ���ֻ������ĸ�����ֺ͡�@�����š�
�ڶ���Ϊ�˺���N��N(0 < N < 10000)��
������N�У�ÿ�б�ʾһ���˺ţ���ʽΪ��
�û��� ���� email
����֮���õ����ո�ֿ����û��������롢email�������ո��ҳ��Ȳ�����50���ַ���
���
�������У�ÿ��Ϊ���һ���˺ţ�����������˺ţ��޸ĺ�����루֮���õ����ո�ָ�����
���û������˺ţ������empty��
��������
��������1��
abc@pku.edu.cn
5
helloKitty iLoveCats abc@pku.edu.cn
2012 maya2012 cplusplus@exam.com
KittyCat 5iKitty abc@pku.edu.cn
program password teacher@exam.com
whoAmi Feb.29$ abc@pku.edu.cn
��������2��
abc@pku.edu.cn
1
2012 maya2012 cplusplus@exam.com
�������
�������1��
helloKitty IlOVEcATS
KittyCat 5IkITTY
whoAmi fEB.29$
�������2��
empty
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 51;
char email[N],name[N],pwd[N],e[N];

int main() 
{
	gets(email);
	int n, s=0;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> name >> pwd >> e;
		if (strcmp(email, e) == 0)
		{
			s++;
			cout << name << " ";
			for (int j=0; pwd[j]!='\0'; j++)
			{
				if (pwd[j]>='a' && pwd[j]<='z')
					cout << char(pwd[j]-32);
				else if (pwd[j]>='A' && pwd[j]<='Z')
					cout << char(pwd[j]+32);
				else
					cout << pwd[j];
			}
			cout << endl;
		}
	}
	if (s == 0)
		cout << "empty" << endl;
		
	return 0;	
} 
