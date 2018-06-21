/*
	Name: �༭���� 
	Copyright: 
	Author: 
	Date: 21-06-18 14:11
	Description: 
��A��B��2���ַ�����Ҫ�����ٵ��ַ��������ַ���Aת��Ϊ�ַ���B��
������˵���ַ��������� (1)ɾ��һ���ַ��� (2)����һ���ַ��� (3)��һ���ַ���Ϊ��һ���ַ���
���ַ���A�任Ϊ�ַ���B���õ������ַ���������Ϊ�ַ���A��B�ı༭���룬��Ϊ d(A,B)��
�����һ����Ч�㷨�����θ���2 ���ַ���A��B����������ǵı༭����d(A,B)��
Input
  ����ĵ�һ�����ַ���A���ļ��ĵڶ������ַ���B��
Output
  �������н���ʱ�����༭����d(A,B)�����
Sample Input
fxpimu
xwrs
Sample Output
5
*/
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int INF = 2000;
const int N = 200;
int B[N+1][N+1];
int B1[N+1][N+1];
string X, Y; 

int LCSLength(int i, int j);//�Զ����µı���¼�㷨
int LCSLength_1(int n, int m);//��̬�滮 
void PrintLCS(int i, int j);

int main()
{  
    while (cin >> X >> Y)
    {
		for (int i=0; i<=N; i++)
			for (int j=0; j<=N; j++)
				B[i][j] = INF;
		
    	cout << LCSLength(X.length(), Y.length()) << endl;
    	
    	memset(B1, 0, sizeof(B1));
    	cout << LCSLength_1(X.length(), Y.length()) << endl;
    	PrintLCS(X.length(), Y.length());
	}
    
   
    return 0;  
}  

int LCSLength(int i, int j)//�Զ����µı���¼�㷨
{
	if (B[i][j] != INF)
		return B[i][j];
	
	if (i == 0) //�ַ���X�ĳ���Ϊ0������j���ַ� 
		B[i][j] = j;
	else if (j == 0) //�ַ���Y�ĳ���Ϊ0��ɾ��i���ַ� 
		B[i][j] = i;
	else if (X[i-1] == Y[j-1])//���ַ���ͬ������༭ 
		B[i][j] = LCSLength(i-1, j-1);
	else  //���ַ���ͬ���Ӳ��룬ɾ�����޸�3����������ѡ�༭������̵ģ��ټ�1 
		B[i][j] = min(min(LCSLength(i-1, j), LCSLength(i, j-1)), LCSLength(i-1, j-1)) + 1;
 
	return B[i][j];
}

int LCSLength_1(int n, int m)//��̬�滮 
{
	for (int i=1; i<=n; i++)//�ַ���Y�ĳ���Ϊ0��ɾ��i���ַ� 
		B1[i][0] = i;
	for (int j=1; j<=m; j++)//�ַ���X�ĳ���Ϊ0������j���ַ� 
		B1[0][j] = j;
		
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (X[i-1] == Y[j-1])
				B1[i][j] = B1[i-1][j-1];
			else
				B1[i][j] = min(min(B1[i-1][j], B1[i][j-1]), B1[i-1][j-1]) + 1;
		}
	}
 
	return B1[n][m];
}

void PrintLCS(int i, int j)//��Ȼ����ȷ����֪Ϊ�Σ� 
{
    if (i == 0 || j == 0)
        return;
    if (X[i-1] == Y[j-1])
    {
        PrintLCS(i-1, j-1);
        cout << "���䣺" << "X[" << i << "]= " << X[i-1] << endl;
    }
    else if(B[i][j] == B[i-1][j-1]+1)
    {
		PrintLCS(i-1, j-1);
		cout << "�޸ģ�x[" << i << "]= " << X[i-1] << " : "<< "y[" << j << "]= " << Y[j-1] << endl;
    } 
    else if(B[i][j] == B[i-1][j]+1)//�����ַ� 
    {
		PrintLCS(i-1, j);
		cout << "���룺" << "y[" << j << "]= " << Y[j-1] << endl;
    }
    else //ɾ���ַ� 
    {
		PrintLCS(i, j-1);
		cout << "ɾ����" << "X[" << i << "]= " << X[i-1] << endl;
    } 
}

