/*
	Name: һԪ���η������
	Copyright: 
	Author: 
	Date: 22-01-18 15:08
	Description: һԪ���η������

��ʱ������: 1000ms �ڴ�����: 65536kB 
���� 
�����磺ax3+bx2+cx+d=0 ������һ��һԪ���η��̡�
�����÷����и����ϵ��(a��b��c��d ��Ϊʵ��)����Լ���÷��̴���������ͬʵ��(���ķ�Χ��-100��100֮��)��
�Ҹ����֮��ľ���ֵ>=1��Ҫ����С����������ͬһ�����������ʵ��(�����֮�����пո�)������ȷ��С�����2λ��

���� 
һ�У������ĸ�ʵ��a��b��c��d������������֮���õ����ո������ 
��� 
һ�У���������ʵ����Ϊ�÷��̵�����ʵ��������С����˳�����У�����������֮���õ����ո��������ȷ��С�����2λ�� 
�������� 
1.0 -5.0 -4.0 20.0 
������� 
-2.00 2.00 5.00
*/

#include<iostream>  
#include<cmath>  
#include<cstdio> 
#include<cstdlib>  
  
using namespace std;  

double f(double x); 
void Fun1(); //ö�ٷ���ö��ÿһ���⿴�Ƿ������
void Fun2(); //ö�ٷ���ö��ÿһ���⿴�Ƿ������
void Fun3(); //���η���ö�����䣬����������ĸ����������С���䷶Χ��ȷ���⡣

double a,b,c,d;

int main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    Fun1();
    Fun2();
    Fun3();
} 

void Fun1()
{
	for (double x=-100;x<=100;x+=0.01)
    {
        if (abs(a*x*x*x+b*x*x+c*x+d)<=0.000001)//�൱��f(x-0.0005)*f(x+0.0005)<=0
            printf("%.2f ",x);
    }
    cout << endl;
}

void Fun2()
{
	for (double x=-100;x<=100;x+=0.01)
    {
        if (f(x-0.0005)*f(x+0.0005)<=0) 
            printf("%.2f ",x);
    }
    cout << endl;
}

void Fun3()
{
	double x,x1,x2,xx;
	for (x=-100;x<=100;x+=1)
    { 
        x1=x;x2=x+1;
        if (f(x1)==0) 
			printf("%.2f ",x1);
        else if (f(x1)*f(x2)<0)
        {
            while (x2-x1>=0.001)
            {
                xx=(x1+x2)/2;
                if ((f(x1)*f(xx))<=0)
                    x2=xx;
                else x1=xx;
            }
            printf("%.2f ",x1);
        }
    }
    cout << endl;
}

double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
