/*
	Name: 
	Copyright: 
	Author: 
	Date: 18\09\18 15:01
	Description: ���������ڶԼ����Ѿ��ź�������ݲ���ʱ��Ч�ʸߣ��������Դﵽ���������Ч�ʣ������в������ʱ��ÿ��ֻ�ܽ������ƶ�һλ��������ִ����ظ��ƶ�������ܽ�Ԫ�ؾ����ܿ���ƶ���������ȥ���ĵط������������ظ��ƶ��Ĵ��������Ч�ʡ�

ϣ�������ǰ�ȫ��Ԫ�ط������򣬽����о���Ϊ����gap��Ԫ�ط���ͬһ�����У�ͨ������Ծʽ�ƶ����ķ���������Ԫ��ÿ���ƶ�һ�󲽣�������gap>1�����������ƶ���Ч�ʡ�һ��������������Ȼͬ���Ԫ��û�а���һ�𣬸���Ԫ���໥��������������ÿһ�鶼�Ѿ������ź����ˣ������������л��ǡ��������򡱵ġ�

Ȼ����ȡԽ��ԽС�Ĳ�����������ֱ������gap=1ʱ��������ͨ�Ĳ������򣬵��ǵ����ⲽ�����������ǡ����������ˣ�ֱ�Ӳ�������Ҳ�ܸ�Ч��ɡ�

�������£�
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

void ShellSort(int vec[], int n) ;

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%50 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	ShellSort(A, MAX); //ϣ������
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void ShellSort(int vec[], int n) //ϣ������
{
    int i, j, gap;
    int temp;
    for (gap=n/2; gap>0; gap/=2)
    {
        for(i=gap; i<n; i++)
        {
		    temp= vec[i]; //���1 
		    for(j=i; (j>=gap) && (temp<vec[j-gap]); j-=gap)//��Ծ���룬��Ծ����Ϊgap
			{
                vec[j]= vec[j-gap]; //���2 
            }
			vec[j]= temp; //���3 
        }
   }
}
