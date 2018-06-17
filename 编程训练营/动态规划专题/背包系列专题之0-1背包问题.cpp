/*
	Name: ��̬�滮ר��֮0-1��������
	Author: ����׾
	Description: 
0-1�������⣺��n����Ʒ��ѡȡ���ɼ���ͬһ����Ʒ���ѡһ�Σ���������Ϊc�ı�����ֱ���P[i]��W[i]�洢��i����Ʒ�ļ�ֵ��������
�����ôװ��Ʒ��ʹ��������Ʒ�ܼ�ֵ���
��������
4 12
2 3
5 7
6 8
10 12
�������
15
*/
#include<iostream>
#include<cstring>

using namespace std;

const int MAXC = 10000; //����������� 
const int MAXN = 2000; //��Ʒ��������
int W[MAXN+1];//��Ʒ������ 
int P[MAXN+1];//��Ʒ�ļ�ֵ 
int B2[MAXN+1][MAXC+1]; //����¼����¼����n����Ʒװ������Ϊc�ı���������ֵ 
int B3[MAXN+1][MAXC+1]; //��̬�滮�м�¼����i����Ʒװ������Ϊj�ı���������ֵ 
int pre[MAXC+1]; //��¼��һ��Ԫ��ֵ
int cur[MAXC+1]; //��¼��ǰ��Ԫ��ֵ
int F[MAXC+1]; //��̬�滮�м�¼����n����Ʒװ������Ϊj�ı���������ֵ
bool X[MAXN+1]; //��¼װ�뱳���е���Ʒ��� 
int cw, cp;//�ڻ����㷨�зֱ��¼����t����Ʒʱ����װ��Ʒ�����������ܼ�ֵ
int bestPrice; //�ڻ����㷨�м�¼Ŀǰ��֪������ܼ�ֵ����ʼ��Ϊ0 

int Sum(int n, int t);//�ۼƵ�t+1��n����Ʒ���ܼ�ֵ
void ZeroOnePack_1(int n, int c, int t);//�����㷨��0-1�������� 
int ZeroOnePack_2(int n, int c);//���仯����������¼�㷨����0-1�������� 
int ZeroOnePack_3(int n, int c);//��̬�滮����ά����洢��¼
int ZeroOnePack_4(int n, int c);//�Ż��Ķ�̬�滮�㷨��ʹ��2��һά��������ά����
int ZeroOnePack_5(int n, int c);//�Ż��Ķ�̬�滮�㷨��һά����洢��¼
int Show_3(int n, int c); //��������B3[][]�������Ʒװ�������������ʵ��װ������X[i]��ʼ��Ϊ0 
void Show(int i, int j);  //i��j�ֱ��ʾ���ڴ���ĵ�i����Ʒ�ʹ�ʱ������ʣ������

int main() 
{
	int n, c;
	cin >> n >> c;
	
	for (int i=1; i<=n; i++)//�����±�Ϊ0��Ԫ�� 
	{
		cin >> W[i] >> P[i];
	}
	
	//�����㷨����Ҫ�õ�ȫ�ֱ���cw, cp, bestPrice, W[], P[]
	ZeroOnePack_1(n, c, 1); //�����±�Ϊ0��Ԫ��
	cout << bestPrice << endl;
	
	//���仯����������¼�㷨������Ҫ�õ�ȫ�ֱ���W[], P[], ����B2[MAXN+1][]��ʼ��Ϊ-1
	memset(B2, -1, sizeof(B2)); //�ȳ�ʼ��B2��ֵȫΪ-1
	cout << ZeroOnePack_2(n, c) << endl; 
	
	//��̬�滮����ά����洢��¼����Ҫ�õ�ȫ�ֱ���W[], P[], ����B3[MAXN+1][]Ĭ�ϳ�ʼ��Ϊ0 
	cout << ZeroOnePack_3(n, c) << endl; 
	
	//��̬�滮��ʹ��2��һά����洢��¼����Ҫ�õ�ȫ�ֱ���W[], P[], ����pre[]��cur[]����ʼ��Ϊ0
	cout << ZeroOnePack_4(n, c) << endl; 
	
	//�Ż��Ķ�̬�滮�㷨��һά����洢��¼����Ҫ�õ�ȫ�ֱ���W[], P[], ����F[]��ʼ��Ϊ0
	cout << ZeroOnePack_5(n, c) << endl; 
	
	//��������B3[][]�������Ʒװ�������X[i]��ʼ��Ϊ0
	cout << Show_3(n, c) << endl; 
	
	//��������B3[][]�����ձ��˳�򣬵ݹ����װ�뱳������Ʒ��Ϣ����ţ���������ֵ��
	Show(n, c); 
	
	return 0;
}

int Sum(int n, int t)//�ۼƵ�t+1��n����Ʒ���ܼ�ֵ 
{
 	int s = 0;
    for (int i=t+1; i<=n; i++) 
	{
	 	s += P[i];
	}
    return s;
}

void ZeroOnePack_1(int n, int c, int t)//�����㷨��0-1�������� 
{
    if (t == n+1)
    {
        bestPrice = max(cp, bestPrice);
    }
    else
    {  
 		if (cw+W[t] <= c)//�������أ����ȷ���װt����Ʒ�����Σ�Ӧ���п��ܵõ����õĽ⣬��������һ��ͱ���֦�ˣ� 
 		{
			cw += W[t]; cp += P[t];
			ZeroOnePack_1(n, c, t+1);
			cw -= W[t]; cp -= P[t];
	    }	
	 	//�ٷ�����װt����Ʒ������
		if (cp+Sum(n, t) > bestPrice)//����п��ܵõ����õĽ⣬�������һ�㣨װ��ûװ���ж��Ƿ���Ҳ�ǰ��жϣ��ŵ���һ�������жϣ� 
			ZeroOnePack_1(n, c, t+1);
    }
}

int ZeroOnePack_2(int n, int c)//���仯����������¼�㷨����0-1�������⣬B2[n][c]��ʼ��Ϊ-1 
{
 	if (B2[n][c] != -1)  
		return B2[n][c];
 	
	int bestP = 0;
	if (n == 1)//����ֻ������1����Ʒ������ 
	{
		bestP = (c >= W[n]) ? P[n] : 0;
	}
	else
	{
		if (c < W[n])//��װ���£���װ��n����Ʒ
			bestP = ZeroOnePack_2(n-1, c);
		else //���װ���£���װ�Ͳ�װ������ȡ���ֵ 
		    bestP = max(ZeroOnePack_2(n-1, c), ZeroOnePack_2(n-1, c-W[n]) + P[n]);
	}
	
    return B2[n][c] = bestP;//������¼ 
}

int ZeroOnePack_3(int n, int c)//��̬�滮����ά����洢��¼��B3[i][j]��ʼ��Ϊ0 
{
	//��¼ǰi(1<=i<n)����Ʒװ������Ϊ1-c�ı���������ֵ 
 	for (int i=1; i<n; i++)
	{
		//for (int j=1; j<W[i]; j++)//������������������װ�µ�i����Ʒ 
//			B3[i][j] = B3[i-1][j];
//		for (int j=W[i]; j<=c; j++)//���������㹻������ѡ��װ��װ��i����Ʒ 
//			B3[i][j] = max(B3[i-1][j], B3[i-1][j-W[i]] + P[i]);
        for (int j=1; j<=c; j++)
		{
			B3[i][j] = B3[i-1][j]; //�ȷ�����װ��i����Ʒ������ 
			if (j >= W[i] && B3[i-1][j] < B3[i-1][j-W[i]] + P[i])
				B3[i][j] = B3[i-1][j-W[i]] + P[i];
		}
	}
	//��Ϊÿ����Ʒ���ֻ��װһ�Σ��ʱ�����һ����װ��������ڸ�����n����Ʒ��˵��B[n][c]==B[n][j]������W[n]<=j<=c 
	//���ԶԵ�n����Ʒ��˵��ֻ��ֱ�Ӽ���B[n][c]�������ÿ�������������j���������Լ��ټ����� 
	if (c < W[n])
		B3[n][c] = B3[n-1][c]; 
	else 
		B3[n][c] = max(B3[n-1][c], B3[n-1][c-W[n]]+P[n]);
	
	return B3[n][c];
}

int ZeroOnePack_4(int n, int c)//�Ż��Ķ�̬�滮�㷨��ʹ��2��һά��������ά���飬pre[j]��cur[j]����ʼ��Ϊ0 
{
	//pre[j]�൱��ZeroOnePack_3()�е�B3[i-1][j]��cur[j]�൱��B3[i][j] 
	//Ϊ�򻯴��룬û�а�i==n�����ε����ó�����������Ҫ���������n����Ʒ���ɲο�ZeroOnePack_3()
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++)
		{
			if (j < W[i] || pre[j] > pre[j-W[i]] + P[i])
				cur[j] = pre[j]; 
			else
				cur[j] = pre[j-W[i]] + P[i];
		}
		for (int j=1; j<=c; j++)//������һ�е����ݵ���ǰ�� 
		{
			pre[j] = cur[j]; 
		}
	}

	return cur[c];
}

int ZeroOnePack_5(int n, int c)//�Ż��Ķ�̬�滮�㷨��һά����洢��¼��F[j]��ʼ��Ϊ0  
{
	//Ϊ�򻯴��룬û�а�i==n�����ε����ó�����������Ҫ���������n����Ʒ���ɲο�ZeroOnePack_3()
 	for (int i=1; i<=n; i++)
	{//�������������j�ϴ��F[j]������ѭ������j��ֵ�Ӵ�С�ݼ�
		for (int j=c; j>=W[i]; j--)
		{//��(j < W[i] || F[j] > F[j-W[i]] + P[i])ʱ��F[j]��ֵ����
			if (F[j] < F[j-W[i]] + P[i])
				F[j] = F[j-W[i]] + P[i];
		}
	}
	
	return F[c];
}

int Show_3(int n, int c) //��������B3[][]�������Ʒװ�������������ʵ��װ������X[i]��ʼ��Ϊ0 
{
	for (int i=n; i>0; i--)
	{
		if (B3[i][c] == B3[i-1][c-W[i]] + P[i])//װ���˵�i����Ʒ 
		{
			X[i] = 1;
			c -= W[i];
		}
	}
	
	int s = 0;
	for (int i=1; i<=n; i++)
	{
		if (X[i])
		{
			s += W[i];
			cout << i << ": " << W[i] << " " << P[i] << endl;
		}
	}	
	return s;
} 

void Show(int i, int j)  //i��j�ֱ��ʾ���ڴ���ĵ�i����Ʒ�ʹ�ʱ������ʣ������
{
	if (i == 0)
		return;
		
	if (B3[i][j] == B3[i-1][j-W[i]] + P[i])//װ���˵�i����Ʒ 
	{
		Show(i-1, j-W[i]);
		cout << i << ": " << W[i] << " " << P[i] << endl;
	}
	else //δװ�ص�i����Ʒ 
	{
		Show(i-1, j);
	}
} 


