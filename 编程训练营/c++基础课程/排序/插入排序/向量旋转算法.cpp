/*
	Name: ������ת�㷨 
	Copyright: 
	Author: 
	Date: 18\09\18 13:50
	Description: ������A�е�Ԫ�طֳ����������֣�Ȼ�����彻�������ֵ�Ԫ�ص�λ�ã���Ϊ��ת������
	����A[6]={1,2,3,4,5,6}�������󲿷ֳ���leftlen=4���������ת��A[6]={5,6,1,2,3,4} 
	��дһ��������ʵ��������ת�� 
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

void ReverseRotate(int A[], int n, int r); 
void Reverse(int A[], int left, int right);
void Fun(int A[], int n, int r);

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%50 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	ReverseRotate(A, MAX, 8);
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	Fun(A, MAX, 2);
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void Fun(int A[], int n, int r)
{
	for (int i=0; i<r; i++)
	{
		int t = A[0];
		for (int j=1; j<n; j++)
			A[j-1] = A[j];
		A[n-1] = t;
	}
}

//��������ʹ��һ�����������ԭ�Ӳ���
/*
�������ƣ�Reverse
�������ܣ����������ԭ�Ӳ��� 
���������int A[]����Ҫ�����õ����� 
          int left�� �������� 
          int right��������ҽ� 
���������int A[]�����ú������ 
����ֵ���� 
*/
void Reverse(int A[], int left, int right)
{    
    int t; 
    while (left < right) 
    {
        t = A[left]; 
        A[left] = A[right]; 
        A[right] = t;
        left++;
        right--;
    } 
}

/*
�������ƣ�ReverseRotate
�������ܣ������ĵ�����������ת�㷨������һ�����������ԭ�Ӳ����Ӻ�����Ȼ�����ò�ͬ���������ҽ磬
          �����ε����Ӻ��������ˡ���Ϊÿ��Ԫ�ض���Ҫ�ƶ����Σ�����Ч�ʲ��Ǻܸߡ� 
���������int A[]����Ҫ����ת������ 
          int n�������ĳ��� 
          int r���������γ��� 
���������int A[]����ת������� 
����ֵ���� 
*/
void ReverseRotate(int A[], int n, int r)
{    
    Reverse(A, 0, r-1); //������������
    Reverse(A, r, n-1); //�����Ұ������ 
    Reverse(A, 0, n-1); //������������ 
}

