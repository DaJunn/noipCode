/*
	Name: 15_����ҩ��
	Author: ����׾ 
	Description: 
����
ҽ������дҩƷ����ʱ�򾭳���ע���Сд����ʽ�Ƚϻ��ҡ���Ҫ����дһ������ҽ����д���ҵ�ҩƷ�������ͳһ�淶�ĸ�ʽ��
��ҩƷ���ĵ�һ���ַ��������ĸҪ��д��������ĸСд���罫ASPIRIN��aspirin�����Aspirin��
����
��һ��һ������n����ʾ��n��ҩƷ��Ҫ����n������100��
������n�У�ÿ��һ�����ʣ����Ȳ�����20����ʾҽ�������ҩƷ����ҩƷ������ĸ�����ֺ�-��ɡ�
���
n�У�ÿ��һ�����ʣ���Ӧ�����ҩƷ���Ĺ淶д����
��������
4
AspiRin
cisapride
2-PENICILLIN
Cefradine-6
�������
Aspirin
Cisapride
2-penicillin
Cefradine-6
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 21;
char S[N];

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> S;
		if (S[0]>='a' && S[0]<='z')
			cout << char(S[0]-32);
		else
			cout << S[0];
		for (int i=1; S[i]!='\0'; i++)  
	    {  
			if (S[i]>='A' && S[i]<='Z')
				cout << char(S[i]+32);
	        else
	        	cout << S[i];
	    }  
	    cout << endl;
	}
	return 0;	
} 
