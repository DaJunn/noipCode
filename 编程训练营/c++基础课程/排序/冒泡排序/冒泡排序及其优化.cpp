/*
	Name: ð���������Ż� 
	Copyright: 
	Author: 
	Date: 30-08-18 16:26
	Description: ð���������Ż�
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 50;
int A[M];

void BubbleSort_1(int lib[], int n);
void BubbleSort_2(int lib[], int n);
void BubbleSort_3(int lib[], int n); 

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 49 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	BubbleSort_3(A, n);
	
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void BubbleSort_1(int lib[], int n) //ð�ݷ��������򣺽��ϴ��������ƶ�
{
    int high;  //�����򲿷�������ϱ߽磬��lib[0..high]Ϊ�����򲿷֣�lib[high+1..n-1]Ϊ�����򲿷�
    int temp; //������������Ԫ��ֵ����ʱ����
    int i;

    for (high=n-1; high>0; high--) //���ѭ�����ƴ����򲿷�������ϱ߽磬ÿ���һ��ð�ݣ��ϱ߽�����һ��λ��
    {
        for (i=0; i<high; i++)//�ڲ�ѭ��ɨ������򲿷����飬�Ƚ�����Ԫ�أ���ͨ������Ԫ��ֵ�ķ�ʽ�����ֵ�������Ϸ�
        {
             if (lib[i] > lib[i+1])
             {
                  temp = lib[i];
                  lib[i] = lib[i+1];
                  lib[i+1] = temp;
             }
        }
    }
}

void BubbleSort_2(int lib[], int n) //�Ľ���1�����ý�����־���Ա���ǰ����ɨ��
{
     int high;  //�����򲿷�������ϱ߽磬��lib[0..high]Ϊ�����򲿷֣�lib[high+1..n-1]Ϊ�����򲿷�
     int temp; //������������Ԫ��ֵ����ʱ����
     int SwapFlag; //������־
     int i;

     for (high=n-1; high>0; high--) //���ѭ�����ƴ����򲿷�������ϱ߽磬ÿ���һ��ð�ݣ��ϱ߽�����һ��λ��
     {
         SwapFlag= 0; //���ý�����־
         for(i=0; i<high; i++)
         {
             if(lib[i] > lib[i+1])
             {
                 temp = lib[i];
                 lib[i] = lib[i+1];
                 lib[i+1] = temp;
                 SwapFlag = 1; //�ô������˽�������
             }
         }
         if(SwapFlag == 0) //��δ���н���������˵�������Ѿ���ɣ���ǰ����ɨ�蹤��
             break;
     }
}

void BubbleSort_3(int lib[], int n)//�Ľ���3��˫��ð��
{
     int low, high;  //�����򲿷�����ı߽磬��lib[low..high]Ϊ�����򲿷֣�lib[0..low-1]��lib[high+1..n-1]Ϊ�����򲿷�
     int lastSwapPos;//���һ�η�������������λ��
     int temp; //������������Ԫ��ֵ����ʱ����
     int i;

     low = 0;
     high = n - 1;
     while (low < high)
     {
          lastSwapPos = low;//�������һ�ν���λ��Ϊ��߽磨���޽����� 
          for (i=low; i<high; i++)
          {
              if (lib[i] > lib[i+1])
              {
                   temp = lib[i];
                   lib[i] =lib[i+1];
                   lib[i+1] =temp;
                   lastSwapPos = i;//�ô������˽���������������Ҫ����ĳ�Ա��Χ 
              }
          }

          high = lastSwapPos;//�����µ��ұ߽�
          for (i=high; i>low; i--)
          {
              if (lib[i] < lib[i-1])
              {
                   temp = lib[i];
                   lib[i] = lib[i-1];
                   lib[i-1] = temp;
                   lastSwapPos = i;//�ô������˽���������������Ҫ����ĳ�Ա��Χ 
              }
          }
          low = lastSwapPos;//�����µ���߽� 
     }
}


