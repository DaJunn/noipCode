/*
	Name: 7650_�����������
	Copyright: 
	Author: ����׾ 
	Date: 03-07-17 21:14
	Description: 7650_�����������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����������a��b��c���󲻶����� ax+by=c ����δ֪��x��y�����зǸ�������������

����
һ�У���������������a��b��c����������֮���õ����ո������ÿ������������1000��
���
һ�����������������̵ķǸ�������������
��������
2 3 18
�������
4
*/
//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main()
//{
//    int a, b, c, s = 0;
//    
//    cin >> a >> b >> c;
//    
//	for (int x=0; x<=c/a; x++) 
//	{
//	 	for (int y=0; y<=c/b; y++)
//	 	{
//		 	s += (a*x + b*y == c);
//	    }
//	} 
//	
//	cout << s << endl;
//			  
//    return 0;
//}

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int a,b,c;
	int x,y,s=0;
	
	cin>>a>>b>>c;
	
	for(x=0;x<=c/a;x++)
	{
		y=(c-a*x)/b;
		if(a*x+b*y==c)
			s++;
	}
	cout<<s;
	
	return 0;
}

