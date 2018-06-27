/*
	Name: ��̬�滮ר��֮ʯ�Ӻϲ�
	Author: ����׾ 
	Description: 
��һ���ٳ��ϰڷ���һ��N��ʯ�ӡ���Ҫ��ʯ���д���غϲ���һ�ѡ��涨ÿ��ֻ��ѡ���ڵ�2��ʯ�Ӻϲ����µ�һ�ѣ������µ�һ��ʯ������Ϊ�ôκϲ��ĵ÷֡�
�����һ���㷨���������N��ʯ�Ӻϲ���һ�ѵ���С�÷֡�
�������� Input Description
��һ����һ����N��1��N��100
����N��ÿ��һ����A����ʾʯ����Ŀ��1��A��200
������� Output Description
��һ��������N��ʯ�Ӻϲ���һ�ѵ���С�÷֡�
�������� Sample Input
7
13 7 8 16 21 4 18
������� Sample Output
239
*/
#include<iostream>

using namespace std;

const int INT_MAX = 2147483647;
const int MAX = 1000;

int A[MAX+1];//��¼ÿ��ʯ�ӵ����� 
int Sum[MAX+1];//��¼ǰn��ʯ�ӵ����� 
int B[MAX+1][MAX+1];//��¼��i����������j����������Ž�
int S[MAX+1][MAX+1];//��¼������Ͽ��Ĳſɵõ���������Ž�
bool flag[MAX+1]; //��¼A[i]�Ƿ��Ѿ�������� 

int StonesCombined(int i, int j);//�Զ����£�ʹ�ñ���¼����Ķ�̬�滮�㷨  
int StonesCombined_2(int n);//�Ե����ϵĶ�̬�滮�㷨������������ʯ�Ӷ����� 
int StonesCombined_3(int n);//�Ե����ϵĶ�̬�滮�㷨������ɨ��  
int StonesCombined_4(int n);//�Ե����ϵĶ�̬�滮�㷨��˳��ɨ��  
void Traceback(int i, int j);//����s[][]��¼�ĸ����Ӷε����Ž⣬�������

int main()
{
	int n = 0;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> A[i];
		Sum[i] = Sum[i-1] + A[i];
	}
		
  // cout << StonesCombined(1, n) << endl;//�Զ����£�ʹ�ñ���¼����Ķ�̬�滮�㷨 
    cout << StonesCombined_2(n) << endl;//�Ե����ϵĶ�̬�滮�㷨 
    Traceback(1, n);
    cout << endl;
    
    return 0;
}

int StonesCombined(int i, int j)//�Զ����£�ʹ�ñ���¼����Ķ�̬�滮�㷨  
{
 	if (B[i][j] != 0) //Ĭ��Ϊ0
        return B[i][j];
	if (i == j)
		return 0;
	int t, m = INT_MAX;
	for (int k=i; k<j; k++)
	{
	 	t = StonesCombined(i, k) + StonesCombined(k+1, j) + Sum[j] - Sum[i-1];
	 	if (t < m)
	 	{
	        m = t;
	        S[i][j] = k;
        }
	} 
	return B[i][j] = m;
}

int StonesCombined_2(int n)//�Ե����ϵĶ�̬�滮�㷨������������ʯ�Ӷ�����  
{
	for (int len=2; len<=n; len++)//�������������������ȣ�
	{
	 	for (int i=1; i<=n-len+1; i++)//��߽� 
	 	{
		 	int j = i + len - 1; //�ұ߽� 
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]��ʼ��Ϊ0 
			{
			 	t = B[i][k] + B[k+1][j] + Sum[j] - Sum[i-1];
			 	if (t < m)
			 	{
			        m = t;
			        S[i][j] = k;
		        }
			} 
			B[i][j] = m;
		}
	}
	
	return B[1][n];
}

int StonesCombined_3(int n)//�Ե����ϵĶ�̬�滮�㷨������ɨ��  
{
	for (int i=n-1; i>0; i--)//��߽� 
	{
	 	for (int j=i+1; j<=n; j++)//�ұ߽� 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]��ʼ��Ϊ0 
			{
			 	t = B[i][k] + B[k+1][j] + Sum[j] - Sum[i-1];
			 	if (t < m)
			 	{
			        m = t;
			        S[i][j] = k;
		        }
			} 
			B[i][j] = m;
		}
	}
	
	return B[1][n];
}

int StonesCombined_4(int n)//�Ե����ϵĶ�̬�滮�㷨��˳��ɨ��  
{
	for (int j=2; j<=n; j++)//�ұ߽� 
	{
	 	for (int i=j-1; i>0; i--)//��߽� 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]��ʼ��Ϊ0 
			{
			 	t = B[i][k] + B[k+1][j] + Sum[j] - Sum[i-1];
			 	if (t < m)
			 	{
			        m = t;
			        S[i][j] = k;
		        }
			} 
			B[i][j] = m;
		}
	}
	
	return B[1][n];
}

void Traceback(int i,int j)//����s[][]��¼�ĸ����Ӷε����Ž⣬�������
{
    if (i == j)
	   return ;
    
    cout << "(";
    Traceback(i, S[i][j]);
    if (flag[i] == 0)
    {
        cout << A[i] << " ";
        flag[i] = 1;
    }
    Traceback(S[i][j]+1, j);
    if (flag[j] == 0)
    {
        cout << A[j];
        flag[j] = 1;
    }
    cout << ")";
}
