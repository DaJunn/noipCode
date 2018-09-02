/*
	Name: ���������㷨 
	Copyright: 
	Author: 
	Date: 06-10-16 16:16
	Description: 
	һ��ľͰ��ֱ�װ�к������ɫС�򣨷ֱ���0,1,2��ʾ������������е�'0'������ǰ�棬���е�'1'���м䣬���е�'2'�����
Ҫ��Ҫ��ռ临�Ӷ�ΪO(1),ֻ�����һ���ַ������顣 
֮���Խк������죬����Ϊ���ǿ��Խ��������ɫС���������״��������к�������ɺ������졣
*/
#include <iostream>
#include <cstdlib>

using namespace std;

void Swap(int &a, int &b);
void TheDutchFlag(int lib[], int n, int min, int max);

int main()
{
	const int COLORNUM = 3;
	int color[COLORNUM] = {0, 1, 2};
	
	const int MAXSIZE = 30;
	int lib[MAXSIZE] = {0};
	
	for (int i=0; i<MAXSIZE; i++) //�������3ɫС�� 
	{
		lib[i] = color[rand() % COLORNUM];
	}
	
	for (int i=0; i<MAXSIZE; i++)
	{
		cout << lib[i] << " ";
	}
	cout << endl;
		
	TheDutchFlag(lib, MAXSIZE, color[0], color[2]);
	
	for (int i=0; i<MAXSIZE; i++)
	{
		cout << lib[i] << " ";
	}
	cout << endl;
    
    return 0;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void TheDutchFlag(int lib[], int n, int min, int max)
{
	int left = 0;
	int right = n - 1;
	
	while (lib[left] == min) //ȷ����߽��λ�� 
	{
		left++;
	}
		
	while (lib[right] == max) //ȷ���ұ߽��λ�� 
	{
		right--;
	}
		
	int i = left;
	while (i <= right)
	{
		if (lib[i] == min) //����Сֵ�������������Ԫ�ؽ�����ͬʱ��߽����ƣ��α�Ҳ���� 
		{
			Swap(lib[i++], lib[left++]);
		}
		else if (lib[i] == max) //�����ֵ�������������Ԫ�ؽ�����ͬʱ�ұ߽����ƣ��α겻�� 
		{
			Swap(lib[i], lib[right--]);
		}
		else //�Ȳ������ֵҲ������Сֵ�����Ԫ�������м����򣬲����κν������α����� 
		{
			i++;
		}
	}
}

