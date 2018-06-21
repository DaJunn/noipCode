/*
	Name: 1808_����������
	Copyright: 
	Author: 
	Date: 21-06-18 09:25
	Description: 1808_����������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
���ǳ�����Z = < z1, z2, ..., zk >������X = < x1, x2, ..., xm >�������е��ҽ������� �ϸ����� ������< i1, i2, ..., ik >��ʹ�ö�j = 1, 2, ... ,k, ��xij = zj������Z = < a, b, f, c > ��X = < a, b, c, f, b, c >�������С�

���ڸ�����������X��Y������������ҵ�X��Y����󹫹������У�Ҳ����˵Ҫ�ҵ�һ���������Z��ʹ��Z����X��������Ҳ��Y�������С�
����
�����������������ݡ�ÿ�����ݰ���һ�У������������Ȳ�����200���ַ�������ʾ�������С������ַ���֮�������ɸ��ո������
���
��ÿ���������ݣ����һ�У������������е���󹫹������еĳ��ȡ�
��������
abcfbc         abfcab
programming    contest 
abcd           mnp
�������
4
2
0
*/
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int N = 200;
int B[N+1][N+1];
int B1[N+1][N+1];
int pre[N+1]; //pre[j]�൱��B1[i-1][j]   
int cur[N+1]; //cur[j]�൱��B1[i][j] 
string X, Y; 

int LCSLength(int i, int j);//�Զ����µı���¼�㷨
int LCSLength_1(int n, int m);//��̬�滮 
int LCSLength_2(int n, int m);//��̬�滮 
void PrintLCS(int i, int j);

int main()
{  
    while (cin >> X >> Y)
    {
		memset(B, 0, sizeof(B));
		memset(pre, 0, sizeof(pre));
    	cout << LCSLength(X.length(), Y.length()) << endl;
    	cout << LCSLength_1(X.length(), Y.length()) << endl;
    	cout << LCSLength_2(X.length(), Y.length()) << endl;
    	PrintLCS(X.length(), Y.length());
	}
    
   
    return 0;  
}  

int LCSLength(int i, int j)//�Զ����µı���¼�㷨
{
	if (B[i][j] != 0)
		return B[i][j];
	
	if (i == 0 || j == 0) 
		B[i][j] = 0;
	else if (X[i-1] == Y[j-1])
		B[i][j] = LCSLength(i-1, j-1) + 1;
	else
		B[i][j] = max(LCSLength(i-1, j), LCSLength(i, j-1));
 
	return B[i][j];
}

int LCSLength_1(int n, int m)//��̬�滮 
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (X[i-1] == Y[j-1])
				B1[i][j] = B1[i-1][j-1] + 1;
			else
				B1[i][j] = max(B1[i-1][j], B1[i][j-1]);
		}
	}
 
	return B1[n][m];
}

int LCSLength_2(int n, int m)//�Ż��Ķ�̬�滮�㷨����2��һά��������ά����  
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (X[i-1] == Y[j-1])
				cur[j] = pre[j-1] + 1;
			else
				cur[j] = max(pre[j], cur[j-1]);
		}
		for (int j=1; j<=m; j++)
		{
			pre[j] = cur[j];
		}
	}
 
	return pre[m];
}


void PrintLCS(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (X[i-1] == Y[j-1])
    {
        PrintLCS(i-1, j-1);
        cout << "x[" << i-1 << "]= " << X[i-1] << " : "<< "y[" << j-1 << "]= " << Y[j-1] << endl;
    }
    else if(B[i-1][j] > B[i][j-1])//�����ϲ��� 
        PrintLCS(i-1, j);
    else                          //��������� 
        PrintLCS(i, j-1);
}
