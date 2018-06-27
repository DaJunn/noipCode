/*
	Name: 3546_�������˷�
	Author: ����׾ 
	Description: 
��Ŀ���� Description
������n��Ҫ��˵ľ��󹹳ɵ����У�����<A1,A2,A3,.......,An>��Ҫ����˻�A1A2.....An��һ������Ǽ�ȫ�����ŵġ�
�����������Ŷ�����������кܴ�Ӱ�졣
������������A��B���ݣ���A����������B�����������ſ��Խ���������㡣���A��һ��p��q����B��q��r���󣬽��C��p��r�ľ���
����C��ʱ���ɳ˷�������������ģ�����Ϊp��q��r��
�������˷�����ɱ���Ϊ������n�����󹹳ɵ�һ����<A1��A2��A3.......��An>������i=1,2,3,4.....,n������Ai��ά��ΪPi-1 ��Pi��
�Գ˻�A1A2A3.....An����һ����С�����˷������ķ�ʽ���м�ȫ�����š�
�������� Input Description
�����n�����飬���һ������n+1������ֵ
������� Output Description
���е�������һ����С�����˷������ķ�ʽ���м�ȫ�����š�
�������� Sample Input
1 2 3 4 
������� Sample Output
((A1A2)A3)
���ݷ�Χ����ʾ Data Size & Hint
n<=100  1<=Ai<=50
*/
#include<iostream>

using namespace std;

const int INT_MAX = 2147483647;
const int MAX = 100;

int P[MAX+1];//P[i-1]��P[i]�ֱ��¼�˾���A[i]������������ 
int B[MAX+1][MAX+1];//��¼��i����������j����������Ž�
int S[MAX+1][MAX+1];//��¼������Ͽ��Ĳſɵõ���������Ž�
bool flag[MAX+1]; //��¼A[i]�Ƿ��Ѿ�������� 

int MatrixChain(int i, int j);//�Զ����£�ʹ�ñ���¼����Ķ�̬�滮�㷨  
int MatrixChain_2(int n);//�Ե����ϵĶ�̬�滮�㷨�����������о������� 
int MatrixChain_3(int n);//�Ե����ϵĶ�̬�滮�㷨������ɨ��  
int MatrixChain_4(int n);//�Ե����ϵĶ�̬�滮�㷨��˳��ɨ��  
void Traceback(int i,int j);//����s[][]��¼�ĸ����Ӷε����Ž⣬�������

int main()
{
	int n = 0;
	while (cin >> P[n])
		n++;
    n--;
   // MatrixChain(1, n);//�Զ����£�ʹ�ñ���¼����Ķ�̬�滮�㷨 
    MatrixChain_4(n);//�Ե����ϵĶ�̬�滮�㷨 
    Traceback(1, n);
    cout << endl;
    
    return 0;
}

int MatrixChain(int i, int j)//�Զ����£�ʹ�ñ���¼����Ķ�̬�滮�㷨  
{
 	if (B[i][j] != 0) //Ĭ��Ϊ0
        return B[i][j];
	if (i == j)
		return 0;
	int t, m = INT_MAX;
	for (int k=i; k<j; k++)
	{
	 	t = MatrixChain(i, k) + MatrixChain(k+1, j) + P[i-1] * P[k] * P[j];
	 	if (t < m)
	 	{
	        m = t;
	        S[i][j] = k;
        }
	} 
	return B[i][j] = m;
}

int MatrixChain_2(int n)//�Ե����ϵĶ�̬�滮�㷨�����������о�������  
{
	for (int len=2; len<=n; len++)//�������������������ȣ�
	{
	 	for (int i=1; i<=n-len+1; i++)
	 	{
		 	int j = i + len - 1;
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]��ʼ��Ϊ0 
			{
			 	t = B[i][k] + B[k+1][j] + P[i-1] * P[k] * P[j];
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

int MatrixChain_3(int n)//�Ե����ϵĶ�̬�滮�㷨������ɨ��  
{
	for (int i=n-1; i>0; i--)//��߽� 
	{
	 	for (int j=i+1; j<=n; j++)//�ұ߽� 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]��ʼ��Ϊ0 
			{
			 	t = B[i][k] + B[k+1][j] + P[i-1] * P[k] * P[j];
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

int MatrixChain_4(int n)//�Ե����ϵĶ�̬�滮�㷨��˳��ɨ��  
{
	for (int j=2; j<=n; j++)//�ұ߽� 
	{
	 	for (int i=j-1; i>0; i--)//��߽� 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]��ʼ��Ϊ0 
			{
			 	t = B[i][k] + B[k+1][j] + P[i-1] * P[k] * P[j];
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
        cout << "A" << i;
        flag[i] = 1;
    }
    Traceback(S[i][j]+1, j);
    if (flag[j] == 0)
    {
        cout << "A" << j;
        flag[j] = 1;
    }
    cout << ")";
}
