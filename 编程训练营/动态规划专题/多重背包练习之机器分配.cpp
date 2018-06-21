/* 
    Name: �������� 
    Copyright:  
    Author:  
    Date: 29-07-17 16:12 
    Description: ��������  
�ܹ�˾ӵ�и�Ч�豸M̨��׼���ָ�������N���ֹ�˾�����ֹ�˾�������Щ�豸������Ϊ�����ṩһ����ӯ�����ʣ���η�����M̨�豸����ʹ���ҵõ���ӯ�����������ӯ��ֵ������M��15��N��10������ԭ��ÿ����˾��Ȩ���������Ŀ���豸������̨���������豸��M��  
Input 
���������ļ���ʽΪ����һ��������������һ�����Ƿֹ�˾��N���ڶ��������豸̨��M��  
��������һ��N*M�ľ��󣬱����˵� I����˾���� J̨������ӯ���� 
Output 
�����һ��Ϊ���ӯ��ֵ��  
��������n�У��ֱ�Ϊ���ֹ�˾����Ļ������� 
Sample Input 
3 3  {�����ֹ�˾��3̨����}   
30 40 50 
20 30 50 
20 25 30 
Sample Output 
70   {���ӯ��ֵΪ70} 
1 1  {��һ�ֹ�˾��1̨} 
2 1  {�ڶ��ֹ�˾��1̨} 
3 1  {�����ֹ�˾��1̨} 
 
�㷨������  
״̬ת�Ʒ��̣� 
F[i][j] = max(F[i-1][j-k] + V[i][k])  ( 0<=k<=j) 
F[i][j]����j̨���ӷָ�ǰi����˾��������棬V[i][k]��ʾ��i����˾����k̨������ 
��ϸ������Ŀ�������һ�����ر������⣡����Ϊ����i����˾����k̨���������Ǽ򵥵���k��0-1ѡ�� 
������0-kѡ������ֻ�������ص����˼��⣬����������Լ򵥵ĶԵ�i��˾����k��0-1ѡ����㷨��  
*/  
#include<iostream>  
#include<cstring>  
  
using namespace std;  
  
const int MAXC = 10; //�ӹ�˾����   
const int MAXM = 15; //��������   
int V[MAXC+1][MAXM+1];//ӯ������   
int B1[MAXC+1][MAXM+1]; //��¼����n���ӹ�˾����m̨���������ӯ��   
int B2[MAXC+1][MAXM+1]; //��¼����n���ӹ�˾����m̨���������ӯ��   
int pre[MAXM+1]; //pre[j]�൱��B1[i-1][j]   
int cur[MAXM+1]; //cur[j]�൱��B1[i][j]  
int F1[MAXM+1]; //��¼���Ž�   
int X[MAXC+1]; //��¼���ֹ�˾����Ļ�����  
int BX[MAXC+1]; //��¼���ֹ�˾����Ļ�����  
int bestValue; //�û����㷨��ʱ������¼���ӯ��   
  
int Best_1(int n, int m);//��̬�滮:��ά����洢���   
int Best_2(int n, int m);//�Ż��Ķ�̬�滮�㷨����2��һά��������ά����   
int Best_3(int n, int m);//��һ���Ż��Ķ�̬�滮�㷨����1��һά��������ά����   
void Show(int i, int j); //�ݹ�������ֹ�˾����Ļ�����   
int Show_2(int n, int m); //��������B1[][]��������ֹ�˾����Ļ�������X[i]��ʼ��Ϊ0   
void DFS(int n, int i, int j); //�����㷨  
int MDFS(int i, int j); //����¼�㷨   
  
int main()   
{  
    int n, m;  
    cin >> n >> m;  
      
    for (int i=1; i<=n; i++)//�����±�Ϊ0��Ԫ��   
    {  
        for (int j=1; j<=m; j++)//�����±�Ϊ0��Ԫ��   
        {  
            cin >> V[i][j];  
        }  
    }  
      
    cout << Best_1(n, m) << endl;  
    cout << Best_2(n, m) << endl;  
    cout << Best_3(n, m) << endl;  
      
    Show(n, m);  
    cout << Show_2(n, m) << endl;  
      
    DFS(n, n, m);  
    cout << bestValue << endl;  
    for (int i=1; i<=n; i++)  
    {  
        cout << i << " " << BX[i] << endl;  
    }     
      
    cout << MDFS(n, m) << endl;  
  
   // system("pause");  
    return 0;  
}  
  
int Best_1(int n, int m)//��̬�滮:��ά����洢���  
{  
    for (int i=1; i<=n; i++) //����ǰi����˾   
    {  
        for (int j=1; j<=m; j++) //����j̨������j������ݼ�����   
        {//���ص����˼�룬�����k̨������i��˾ʱ����ö��ټ�ֵ���洢����ֵ��B1[i][j]   
            int bestP = 0;  
            for (int k=0; k<=j; k++)  
            {  
                if (bestP < B1[i-1][j-k] + V[i][k])//��k̨������i��˾   
                    bestP = B1[i-1][j-k] + V[i][k];  
            }  
            B1[i][j] = bestP;  
        }  
    }  
      
    return B1[n][m];  
}  
  
int Best_2(int n, int m)//�Ż��Ķ�̬�滮�㷨����2��һά��������ά����   
{  
    //pre[j]�൱��B1[i-1][j]��cur[j]�൱��B1[i][j]   
    for (int j=1; j<=m; j++) //ֻ��1����˾������  
        pre[j] = V[1][j];  
       
    for (int i=2; i<=n; i++) //����ǰi����˾   
    {  
        for (int j=1; j<=m; j++) //����j̨������j������ݼ�����    
        {  
            int bestP = 0;  
            for (int k=0; k<=j; k++)  
            {  
                if (bestP < pre[j-k] + V[i][k])  
                    bestP = pre[j-k] + V[i][k];  
            }  
            cur[j] = bestP;  
        }  
        for (int j=1; j<=m; j++)  
        {  
            pre[j] = cur[j];   
        }  
    }  
      
    return pre[m];  
}  
  
int Best_3(int n, int m)//��һ���Ż��Ķ�̬�滮�㷨����1��һά��������ά����   
{  
    for (int i=1; i<=n; i++) //ʵ���Ͼ���һ�����ر�������   
    {  
        for (int j=m; j>0; j--) //������0-1�������⣬jֻ�ܵݼ�  
        {  
            //���ص����˼�룬�����k̨������i��˾ʱ����ö��ټ�ֵ���洢����ֵ��F1[j]   
            int bestP = 0;  
            for (int k=0; k<=j; k++)  
            {  
                if (bestP < F1[j-k] + V[i][k])  
                    bestP = F1[j-k] + V[i][k];  
            }  
            F1[j] = bestP;  
        }  
    }  
      
    return F1[m];  
}  
  
void Show(int i, int j)//�ݹ�������ֹ�˾����Ļ�����    
{  
    if (i == 0 || j == 0)  
        return;  
    for (int k=0; k<=j; k++)  
    {    
        if (B1[i][j] == B1[i-1][j-k] + V[i][k])//��k̨������i��˾ʱ���������ֵ  
        {  
            Show(i-1, j-k);  
            cout << i << " " << k << endl;  
            break;  
        }  
    }  
}  
  
int Show_2(int n, int m) //��������B1[][]��������ֹ�˾����Ļ�������X[i]��ʼ��Ϊ0   
{  
    for (int i=n,j=m; i>0; i--)  
    {  
        for (int k=0; k<=j; k++)  
        {  
            if (B1[i][j] == B1[i-1][j-k] + V[i][k])//��k̨������i��˾ʱ���������ֵ  
            {  
                X[i] = k;  
                j -= k; //����j��ֵ   
                break;  
            }  
        }  
    }  
      
    int s = 0;  
    for (int i=1; i<=n; i++)  
    {  
        cout << i << " " << X[i] << endl;  
        s += V[i][X[i]];  
    }     
    return s;  
}   
  
void DFS(int n, int i, int j) //�����㷨  
{  
    if (i==0 || j==0) //û�й�˾��û�л�����  
    {  
        int s = 0;  
        for (int k=1; k<=n; k++)  
        {  
            s += V[k][X[k]];  
        }  
        if (bestValue < s) //��¼���Ž�   
        {  
            bestValue = s;  
            for (int k=1; k<=n; k++)  
            {  
                BX[k] = X[k];  
            }  
        }  
        return;  
    }   
    for (int k=0; k<=j; k++)  
    {  
        X[i] == k;  
        DFS(n, i-1, j-k);  
    }  
}   
  
int MDFS(int i, int j)//����¼�㷨   
{  
    if (B2[i][j] != 0)  
        return B2[i][j];  
    if (i==0 || j==0) //û�й�˾��û�л�����  
        return 0;  
    int bestP = 0;  
    for (int k=0; k<=j; k++)  
    {  
        if (bestP < MDFS(i-1, j-k) + V[i][k])  
            bestP = MDFS(i-1, j-k) + V[i][k];  
    }  
    return B2[i][j] = bestP;      
}  
