/*
  Name: ѭ�����ճ̱�
  Copyright: 
  Author: 
  Date: 18-04-17 10:18
  Description: ����n=2k��ѡ�ֲμӱ�����Ҫ�����һ������һ��Ҫ��ı����ճ̱�:
��1��ÿ��ѡ�ֱ�����������n-1��ѡ�ָ�����һ�Σ�
��2��ÿ��ѡ��ÿ��ֻ����һ�� ��
����Ҫ����԰ѱ����ճ̱���Ƴ�һ��n��n-1�еĶ�ά�����е�i�е�j�б�ʾ��i��ѡ���� ��j�������ѡ�֡�

�ֱ�����˵ݹ���η��͵����������㷨�����������㷨�������ȳ�ʼ����1�У��Ա㸴�Ƶ��������
���һ�����Ʊ��ĺ����������Ͻ�����Ϊ(x1,y1)����СΪn�ı���Ƶ����Ͻ�����Ϊ(x2,y2)�ı���ϡ�
 
�㷨1���õݹ���η�����ѭ�����ճ̱� 
���������1���򽫱��Է�Ϊ���룬�ֱ�ݹ�ش������ϽǺ����½Ǳ��Ȼ�󡰺ϲ����Ѿ�����õı��
�������ϽǱ���Ƶ����½ǣ������½Ǳ���Ƶ����Ͻǡ� ����ֱ�Ӹ��Ʊ�� 

�㷨2���õ���������ѭ�����ճ̱� 
���ѭ���ñ���Сt��1��ʼ�ɱ����ӣ��ڲ�ѭ�������������δ���ÿһ���СΪt*2�ı��
�������ϽǱ���Ƶ����½ǣ������½Ǳ���Ƶ����Ͻǡ�
ÿ������һ�������Ͻ�������x������Ծ2*t�С� 
*/
#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

const int N = 40;
int A[N][N];

void CopyTable(int x1, int y1, int x2, int y2, int n);
void Table(int x, int y, int n);//�õݹ���η�����ѭ�����ճ̱� 
void Table_2(int x, int y, int n);//�õ���������ѭ�����ճ̱� 
void PrintTable(int x, int y, int n);

int main() 
{
 	int n = 8;
 	for (int i=0; i<n; i++) //��ʼ����1�У��Ա㸴�Ƶ�������� 
 		A[i][0] = i + 1;
 		
	Table(0, 0, n);//�÷��η�����ѭ�����ճ̱� 
//	Table_2(0, 0, n);//�õ���������ѭ�����ճ̱� 	
 	PrintTable(0, 0, n);//������Ͻ�����Ϊ(x1,y1)����СΪn�ı��
 	
    system("pause");
    return 0;
}

void Table(int x, int y, int n)//�õݹ���η�����ѭ�����ճ̱� 
{
	n /= 2;
	if (n > 1)
	{
		Table(x, y, n); //�ݹ鴦�����ϽǱ��
		Table(x+n, y, n); //�ݹ鴦�����½Ǳ��
		
	}
	CopyTable(x, y, x+n, y+n, n); //�����ϽǱ���Ƶ����½�
	CopyTable(x+n, y, x, y+n, n); //�����½Ǳ���Ƶ����Ͻ�
}

void Table_2(int x, int y, int n)//�õ���������ѭ�����ճ̱� 
{
	for (int t=1; t<=n; t*=2)
	{
	 	for (int x=0; x<n; x+=t*2)//�����������δ���ÿһ���СΪt*2�ı�� 
	 	{
		 	CopyTable(x, y, x+t, y+t, t); //�����ϽǱ���Ƶ����½�
			CopyTable(x+t, y, x, y+t, t); //�����½Ǳ���Ƶ����Ͻ�
		}
	}
}

//�����Ͻ�����Ϊ(x1,y1)����СΪn�ı���Ƶ����Ͻ�����Ϊ(x2,y2)�ı���� 
void CopyTable(int x1, int y1, int x2, int y2, int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			A[x2+i][y2+j] = A[x1+i][y1+j];
		}
	}
}

void PrintTable(int x, int y, int n)//������Ͻ�����Ϊ(x1,y1)����СΪn�ı��
{
    for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << A[x+i][y+j] << " ";
		}
		cout << endl;
	}
	cout << endl;	 
}


