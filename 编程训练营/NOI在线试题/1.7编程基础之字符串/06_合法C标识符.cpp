/*
	Name: 06_�Ϸ�C��ʶ��
	Copyright: 
	Author: 
	Date: 01-09-17 09:08
	Description: 06_�Ϸ�C��ʶ��
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���������հ׷����ַ��������ж��Ƿ���C���ԺϷ��ı�ʶ���ţ�ע����Ŀ��֤��Щ�ַ���һ������C���Եı����֣���
C���Ա�ʶ��Ҫ��
1. �Ǳ����֣�
2. ֻ������ĸ�����ּ��»��ߣ���_������
3. �������ֿ�ͷ��
����
һ�У�����һ���ַ������ַ����в������κοհ��ַ����ҳ��Ȳ�����20��
���
һ�У��������C���ԵĺϷ���ʶ���������yes���������no��
��������
RKPEGX9R;TWyYcp
�������
no
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 21;  
char S[N]; 
  
int main()   
{  
	gets(S); //С���ַ����а����ո񣬻س���ASCII��13�����У�ASCII��10���ո�ASCII��32 
	int n = strlen(S);
	bool flag = 1;
	if (!(S[0]=='_' || isalpha(S[0])))
	{
		flag = 0;
	}
	else
	{
		for (int i=1; i<n; i++)  
	    {  
	        if (!(S[i]=='_' || isalnum(S[i])))
	        {
				flag = 0;
				break;
			}
	    }  
	}
    if (flag)
    	cout << "yes" << endl;
    else
    	cout << "no" << endl;
    
    return 0;     
}   
