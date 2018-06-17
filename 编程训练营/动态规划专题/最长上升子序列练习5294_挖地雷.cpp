/*
	Name: ����������ϰ5294_�ڵ���
	Author: ����׾ 
	Description:5294_�ڵ���
��Ŀ���� Description
��һ����ͼ����N���ؽѣ�N<=20����ÿ���ؽ�������һ�������ĵ��ס�ͬʱ�������ؽ�֮�������·����
���ؽѼ������ӵ����ݸ���֮��ĳ�˿��Դӵ�һ���ؽѿ�ʼ�ڵ��ף�Ȼ���������ָ�������������ڣ�����ѡ��һ��·��������������ʱ�ڵ��׹���������
���һ���ڵ��׵ķ�����ʹĳ�����ڵ����ĵ��ס�

�������� Input Description
��1��ֻ��һ�����֣���ʾ�ؽѵĸ���N��
��2����N�������ֱ��ʾÿ���ؽ��еĵ��׸�����
��3������N+1�б�ʾ�ؽ�֮������������
��3����n-1������0��1������ʾ��һ���ؽ�����2������3����������n���ؽ��з�·�����ӡ�
���3��Ϊ1 1 0 0 0 �� 0�����ʾ��1���ؽ�����2���ؽ���·��������3���ؽ���·��������4���ؽѡ���5����������n���ؽ�û��·����
��4����n-2��������ʾ�ڶ����ؽ�����3������4����������n���ؽ��з�·�����ӡ�
�� ��
��n+1����1��������ʾ��n-1���ؽ�����n���ؽ��з�·�����ӡ���Ϊ0��ʾû��·����Ϊ1��ʾ��·������

������� Output Description
��һ�б�ʾ�ڵ�������ʱ���ڵ��׵�˳�򣬸��ؽ���ż���һ���ո�ָ��������ж���Ŀո�
�ڶ���ֻ��һ��������ʾ���ڵ�������������

�������� Sample Input
5
10 8 4 7 6
1 1 1 0
0 0 0
1 1
1
������� Sample Output
1 3 4 5
27
*/
#include<iostream>  
#include<cstring>
  
using namespace std;  
  
const int MAX = 20;   
int map[MAX+1][MAX+1];  
int W[MAX+1]; //��¼ÿ���ؽ��еĵ��׸���
int F[MAX+1]; //��¼�ӵ�i���ؽѿ�ʼ�������ڳ��ĵ����� 
int F2[MAX+1]; //��¼�ӵ�i���ؽѿ�ʼ�������ڳ��ĵ�����
int next[MAX+1]; //��¼�ؽ�i�ĺ����ؽѱ�� 
  
int DP(int n); //��̬�滮�����Ʒ���
void PrintPath(int pos); //������·��
int DP_2(int n, int i); //����¼�㷨
  
int main()   
{  
    int n;  
    cin >> n;  
    for (int i=1; i<=n; i++)  
    {  
        cin >> W[i];
    }  
    
    for (int i=1; i<n; i++)  
    {  
        for (int j=i+1; j<=n; j++)  
        {  
            cin >> map[i][j];  
        }  
    } 
    
    //��̬�滮�㷨 
	int pos = DP(n);  
    PrintPath(pos); //������·��
    cout << F[pos] << endl;
    
    //����¼�㷨
	pos = n;  
	F2[n] = W[n];
	for (int i=1; i<n; i++)//��Ϊ����ж��������һһ���� 
    {  
        if (F2[pos] < DP_2(n, i))
        	pos = i;
    } 
    PrintPath(pos); //������·��
    cout << F2[pos] << endl; 
      
    return 0;  
}  

int DP(int n) //��̬�滮�����Ʒ����������������±� 
{  
    F[n] = W[n];
	for (int i=n-1; i>0; i--)
	{
		for (int j=i+1; j<=n; j++)//Ѱ�����·�� 
		{
			if (map[i][j] && F[i] < F[j])
			{
				F[i] = F[j];
				next[i] = j;
			}
		}
		F[i] += W[i];
	} 
	
	int m = n;
	for (int i=1; i<n; i++)//�ҵ��������±� 
    {  
        if (F[i] > F[m])
            m = i;
    }  
    
    return m;
} 
int DP_2(int n, int i) //����¼�㷨 
{  
    if (F2[i] != 0)
    	return F2[i];
    
    if (i == n)
    {
		F2[i] = W[n];
	}
	else
	{
		int t, m = 0;
		for (int j=i+1; j<=n; j++)
		{
			if (map[i][j])
			{
				t = DP_2(n, j);
				if (m < t)
				{
					m = t;
					next[i] = j;
				}
			}
		}
		F2[i] = m + W[i];
	}
    
    return F2[i];
} 

void PrintPath(int pos) //������·�� 
{  
	cout << pos;
    for(pos=next[pos]; pos!=0; pos=next[pos])
    {
		cout << " " << pos;
	}
    cout << endl;
}  

