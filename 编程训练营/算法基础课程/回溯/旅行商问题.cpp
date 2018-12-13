/*
  Name: ����������
  Copyright: 
  Author: ����׾ 
  Date: 09-03-17 15:33
  Description: 
  ����������
���������⣨Traveling Salesman Problem,TSP����������Ҫ�����ɸ��������У�������֮��ķ�������֪�ģ�Ϊ�˽�ʡ���ã������̾��������ڳ��г�������ÿ����������һ�κ󷵻س�ʼ���У�����Ӧѡ��ʲô����·�߲���ʹ���ߵ��ܷ�����̣���������������£���G=(V,E)��һ�����б߳ɱ�cij������ͼ��cij�Ķ������£��������е�i��j��cij>0,��<i,j>������E����cij=�ޡ���|V|=n��������n>1�� G��һ������·���ǰ���V��ÿ������һ�����򻷣�����·�ߵĳɱ��Ǵ�·�������бߵĳɱ��͡�
���������
����������Ҫ��ͼG����������·������ȡ��С�ɱ�������·�ߣ����ӳ�ʼ�����������·��һ����(n-1)!���������ڳ���ʼ������n-1�����������������������������һ���������⡣����������Ӽ��ϵ�ѡ������ͨ��Ҫ�������ö࣬������Ϊn��������n!�����У�ֻ�� ���Ӽ���(n!>O( ))��ͨ��ö��(n-1)!������·�ߣ������ҳ�һ��������С�ɱ�������·�ߵ��㷨�������ʱ����ȻΪO(n!)��
*/
#include<iostream>
#include<string>

using namespace std;

const int N = 4; //ͼ�ж���ĸ���
const int MAXINT = 9999999; //�Զ�������������������� 

int map[N][N]={0,20,6,4,
               20,0,5,10,
               6,5,0,15,
               4,10,15,0};//�ڽӾ���
int X[N]; //������
int bestX[N]; //���Ž������ 
int d = 0; //��ǰ·������
int bestd = MAXINT; //���ŵ�·������ 

void Swap(int &a, int &b); //������������ֵ 
bool OK(int i, int j);//��鵱ǰ�����Ƿ�Ϸ�
void Backtrace(int t); //�ݹ���� 
void Backtrace_2(); //�ǵݹ���� 

int main() 
{
 	for (int i=0; i<N; i++) //���ó�ʼ�Ķ���˳�� 
	{
	 	X[i] = i;
	}
    Backtrace(1);
  // Backtrace_2();
  
    cout << "2���·��Ϊ��" << bestd << "��������Ϊ��";
    for (int i=0; i<N; i++)
	{
	 	cout << bestX[i] << " ";
	}
	cout << endl;
	
    system("pause");
    return 0;
}

void Swap(int &a, int &b)
{
    //a ^= b ^= a ^= b; 
    int temp = a;
    a = b;
    b = temp;
}

bool OK(int i, int j)//��鵱ǰ�����Ƿ�Ϸ�
{
    return (map[i][j] < MAXINT) && (d + map[i][j] < bestd);
}

void Backtrace(int t) //�ݹ���� 
{
    if(t == N-1)//���һ������ 
    {
        if (OK(X[t-1], X[t]))
        {
	        d += map[X[t-1]][X[t]];
	        if(OK(X[t], X[0]))
	        {
		        bestd = d + map[X[t]][X[0]];
				for(int i=0; i<N; i++)
				{
					bestX[i] = X[i];
				}
				cout << "���·��Ϊ��" << bestd << "��������Ϊ��";
				for (int i=0; i<N; i++)
				{
				 	cout << bestX[i] << " ";
				}
				cout << endl;
            }
            d -= map[X[t-1]][X[t]];
        }
    }
    else
    {
        for(int i=t; i<N; i++)
        {
	 		if (OK(X[t-1], X[i]))//�������Լ�������������X[i]��� 
	        {
		        Swap(X[t], X[i]); //�Ȱ����������Ľ��X[i]�����±�Ϊt�� 
				d += map[X[t-1]][X[t]]; 
				Backtrace(t+1);
				//�²����������ٻ�����������������һ�����ܵĽ��X[i] 
				d -= map[X[t-1]][X[t]];
				Swap(X[t], X[i]);
	        }
        }
    }
}
