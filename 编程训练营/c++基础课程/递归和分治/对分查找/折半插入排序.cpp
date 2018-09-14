/*
	Name: �۰�������� 
	Copyright: 
	Author: 
	Date: 08-01-18 14:23
	Description:
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void InsertSort(int A[], int n);//�ò������򷨶�����A�������򣨷ǵݼ����У� 
void InsertSort_1(int A[], int n);//��������Ľ��㷨�����ֲ��� 
int BinaryInsert(int x, int low, int high); //�����㷨���۰����ֵΪx��Ԫ�صĲ���λ�� 
int DGBinaryInsert(int x, int low, int high); //�ݹ��㷨���۰����ֵΪx��Ԫ�صĲ���λ�� 

const int MAX = 10;
int A[MAX];

int main() 
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%10 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	InsertSort(A, MAX);
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
		
    return 0;
}

void InsertSort(int A[], int n)//�ò������򷨶�����A�������򣨷ǵݼ����У� 
{
	int p; //�����洢����λ�õ���ʱ���� 
	int temp; //������������Ԫ��ֵ����ʱ����
	for (int i=1; i<n; i++) //A[0..i-1]Ϊ�����򲿷֣���A[i]���뵽A[0..i-1]�� 
    {
		temp = A[i];
    	for (p=i; p>0; p--)//�ڲ�ѭ����������A[0..i-1]���ƶ�Ԫ�����ڳ�����λ�� 
        {
            if (A[p-1] > temp)
	            A[p] = A[p-1];
	        else
	        	break;
        }
        A[p] = temp;
	}
}

int BinaryInsert(int x, int low, int high) //�����㷨���۰����ֵΪx��Ԫ�صĲ���λ�� 
{
	int mid;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (A[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

int DGBinaryInsert(int x, int low, int high) //�ݹ��㷨���۰����ֵΪx��Ԫ�صĲ���λ�� 
{
	if (low > high)
		return low;
	
	int mid = (low+high)/2;
	if (A[mid] > x)
		return DGBinaryInsert(x, low, mid-1);
	else
		return DGBinaryInsert(x, mid+1, high);
}

void InsertSort_1(int A[], int n)//��������Ľ��㷨�����ֲ��� 
{
	int mid, pos;
	int temp; //�����洢������Ԫ�ص���ʱ���� 
	for (int i=1; i<n; i++) //A[0..i-1]Ϊ�����򲿷֣���A[i]���뵽A[0..i-1]�� 
    {
		temp = A[i];
		pos = BinaryInsert(temp, 0, i-1); //���ֲ��Ҳ���λ��
    	for (int j=i; j>pos; j--)//�ƶ�Ԫ�����ڳ�����λ�� 
	        A[j] = A[j-1];
        A[pos] = temp;
	}
}

/*
���������ڶԼ����Ѿ��ź�������ݲ���ʱ��Ч�ʸߣ��������Դﵽ���������Ч�ʣ������в������ʱ��ÿ��ֻ�ܽ������ƶ�һλ��������ִ����ظ��ƶ���
����ܽ�Ԫ�ؾ����ܿ���ƶ���������ȥ���ĵط������������ظ��ƶ��Ĵ��������Ч�ʡ�
ϣ�������ǰ�ȫ��Ԫ�ط������򣬽����о���Ϊ����gap��Ԫ�ط���ͬһ�����У�ͨ������Ծʽ�ƶ����ķ���������Ԫ��ÿ���ƶ�һ�󲽣�
������gap>1�����������ƶ���Ч�ʡ�һ��������������Ȼͬ���Ԫ��û�а���һ�𣬸���Ԫ���໥��������������ÿһ�鶼�Ѿ������ź����ˣ�
�����������л��ǡ��������򡱵ġ�
Ȼ����ȡԽ��ԽС�Ĳ�����������ֱ������gap=1ʱ��������ͨ�Ĳ������򣬵��ǵ����ⲽ�����������ǡ����������ˣ�ֱ�Ӳ�������Ҳ�ܸ�Ч��ɡ�
*/
void InsertSort_2(int A[], int n)//��������Ľ��㷨2��ϣ������ 
{
	int p; //�����洢����λ�õ���ʱ���� 
	int temp; //������������Ԫ��ֵ����ʱ����
   
    for (int gap=n/2; gap>0; gap/=2)//Ԫ����Ծ�Ĳ������ϼ��٣�����Ϊ1ʱ��Ϊֱ�Ӳ�������
	{
		for(int i=gap; i<n; i++)//��A[i]���뵽A[0..i-1]�� 
		{
			temp = A[i];
			for (p=i; p>=gap; p-=gap)//�����Ծ�ƶ�Ԫ�����ڳ�����λ�ã���Ծ����Ϊgap
	        {
	            if (A[p-gap] > temp)
		            A[p] = A[p-gap];
		        else
		        	break;
	        }
	        A[p] = temp;
		}
	}
}
