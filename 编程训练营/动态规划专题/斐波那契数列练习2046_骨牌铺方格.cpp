/*
	Name: 2046_�����̷���
	Copyright: 
	Author: 
	Date: 14-06-18 13:51
	Description: ��������2��n��һ�������η�����,��һ��1�� 2�Ĺ�����������,����n ,����̷ŷ���������������n=3ʱ,Ϊ2�� 3���񣬹��Ƶ��̷ŷ���������,����ͼ��
 
���룺���������ɶ�����ɣ�ÿ�а���һ������n,��ʾ�ò���ʵ���ĳ����η���Ĺ����2��n (0<n<=50)��
���������ÿ������ʵ����������̷ŷ�����������ÿ��ʵ�������ռһ�С�

��������
1
3
2
�������
1
3
2
*/
#include<iostream>  
#include<cmath>  
  
using namespace std;  
  
const int MAXN = 51;  
long long F2[MAXN] = {0, 1, 2};//Fibonacci����  
  
long long Fun_2(int n);//��̬�滮���Ե׶���  
long long Fun_3(int n);//��̬�滮����ά�Ż�
  
int main()   
{  
    int n, a;  
	
	//Fun_2(MAXN); //��̬�滮���ȼ�¼����������Ľ� 
	while (cin >> n)  
    {  
        //cout << F2[n] << endl;
    	cout << Fun_3(n) << endl;
    }  
      
    return 0;  
}  
  
long long Fun_2(int n)//��̬�滮���Ե׶���  
{  
    for (int i=3; i<=n; i++)  
    {  
        F2[i] = F2[i-1] + F2[i-2];  
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
		cur = pre1 + pre2;  
        pre1 = pre2;
        pre2 = cur;
    }  
      
    return cur;  
}  
