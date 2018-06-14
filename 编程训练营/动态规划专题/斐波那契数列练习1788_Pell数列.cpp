/*
	Name: 1788_Pell����
	Copyright: 
	Author: 
	Date: 14-06-18 11:38
	Description: 1788_Pell����
�鿴 �ύ ͳ�� ����
��ʱ������: 3000ms �ڴ�����: 65536kB
����
Pell����a1, a2, a3, ...�Ķ����������ģ�a1 = 1, a2 = 2, ... , an = 2 * an - 1 + an - 2 (n > 2)��
����һ��������k��Ҫ��Pell���еĵ�k��ģ��32767�Ƕ��١�
����
��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�����һ��������k (1 �� k < 1000000)��
���
n�У�ÿ�������Ӧһ�����롣���Ӧ��һ���Ǹ�������
��������
2
1
8
�������
1
408
*/
#include<iostream>  
#include<cmath>  
  
using namespace std;  

const int MOD = 32767; 
const int MAXN = 1000000;  
long long F2[MAXN] = {0, 1, 2};//Pell����
  
long long Fun_2(int n);//��̬�滮���Ե׶���  
long long Fun_3(int n);//��̬�滮����ά�Ż�
  
int main()   
{  
    int n, a;  
	
	Fun_2(MAXN); //��̬�滮���ȼ�¼����������Ľ� 
	cin >> n;
	for (int i=0; i<n; i++)  
    {  
		cin >> a;
        cout << F2[a] << endl;
    	//cout << Fun_3(a) << endl;
    }  
      
    return 0;  
}  
  
long long Fun_2(int n)//��̬�滮���Ե׶���  
{  
    for (int i=3; i<=n; i++)  
    {  
        F2[i] = (2*F2[i-1] + F2[i-2]) % MOD;  
    }  
      
    return F2[n];  
}  

long long Fun_3(int n)//��̬�滮����ά�Ż� 
{  
	long long cur, pre1, pre2;
	
	if (n == 1 || n == 2)
		cur = n;  
	pre1 = 1, pre2 = 2; //��ʼ�� 	
    for (int i=3; i<=n; i++) //�Ե����ϣ��������±���ֵ 
    {  
		cur = (2 * pre2 + pre1) % MOD;  
        pre1 = pre2;
        pre2 = cur;
    }  
      
    return cur;  
}  
