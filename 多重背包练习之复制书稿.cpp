/* 
    Name: ������� 
    Copyright:  
    Author:  
    Date: 09-06-18 22:53 
    Description:������� 
Problem Description 
����Ҫ��m����˳�����ָ�k���˸���(��д)��ÿһ���˵ĳ�д�ٶȶ�һ����һ���鲻���������(������)���˳�д���ָ�ÿһ���˵��飬�����������ģ����粻�ܰѵ�һ�������͵��ı����ͬһ���˳�д�� 
�����������һ�ַ�����ʹ�ø���ʱ����̡�����ʱ��Ϊ��дҳ����������ȥ��ʱ�䡣 
Input 
�����ж������ݣ�ÿ�����ݵ�1����������m,k(k<=m<=500)�� 
��2��m����������i��������ʾ��i�����ҳ���� 
Output 
����ÿ���������k�У�ÿ��������������i�б�ʾ��i���˳�д�������ʼ��ź���ֹ��š�k�е���ʼ���Ӧ�ô�С�������У�����ж�⣬�򾡿�����ǰ������ٳ�д�� 
Sample Input 
9 3 
1 2 3 4 5 6 7 8 9 
Sample Output 
1 5 
6 7 
8 9 
 
Hint 
���m=k=0����������� 
 
�㷨������  
�㷨1�����͵Ķ��ر������⣬��B[i][j]����ʾ����i���˺�j��������Ž⡣  
״̬ת�Ʒ��̣� 
B[i][j] = min(max(B[i-1][k] + S[j]-S[k]))  ( i-1<=k<j) 
S[j]����ǰj�������ҳ���� 
�����Զ��㷨1���и��ֽ�ά�Ż��� 
���б���¼�㷨Ҳ�ǻ����㷨1��˼�롣  
������巽��ʱ����ʹ�õݹ�ͷǵݹ�ķ���������˳������������ҳ�룬 
����˳����������䣬��ʹ��̰�Ĳ��ԣ����������ȷ�����˶೭��  
*/   
#include<iostream>  
#include<cstring>  
  
using namespace std;  
  
const int INF = 1000000; //�Զ�������ֵ   
const int MAXC = 500; //�˵�����   
const int MAXM = 500; //�鱾����   
int V[MAXM+1];//V[i]��ʾ��i�����ҳ��   
int S[MAXM+1];//S[i]��ʾǰi�������ҳ��   
int B1[MAXC+1][MAXM+1]; //��¼����i���˺�j��������Ž�  
int B2[MAXC+1][MAXM+1]; //��¼��������i���˺�j��������Ž�  
int pre[MAXM+1]; //pre[j]�൱��B1[i-1][j]   
int cur[MAXM+1]; //cur[j]�൱��B1[i][j]  
int F1[MAXM+1]; //��¼���Ž�   
  
int Best_1(int n, int m);//��̬�滮:��ά����洢���   
int Best_2(int n, int m);//�Ż��Ķ�̬�滮�㷨����2��һά��������ά����   
int Best_3(int n, int m);//��һ���Ż��Ķ�̬�滮�㷨����1��һά��������ά����   
void Show(int minTime, int i, int j); //�ݹ������д�鱾�ķ���   
void Show_2(int minTime, int n, int m);//�ǵݹ����������д�鱾�ķ���   
void Show_3(int minTime, int n, int m);//�ǵݹ�˳�������д�鱾�ķ���   
int DFS(int i, int j); //�����㷨  
int MDFS(int i, int j); //����¼�㷨   
void Show_3(int n, int m);//�����㷨2�õ��Ķ�̬�滮�ⷨ   
  
int main()   
{  
    int n, m;  
    cin >> m >> n;//m����n����   
      
    for (int i=0; i<=MAXC; i++)//�����±�Ϊ0��Ԫ��   
    {  
        for (int j=0; j<=MAXM; j++)//�����±�Ϊ0��Ԫ��   
        {  
            B2[i][j] = B1[i][j] = INF;  
        }  
    }  
      
    for (int j=1; j<=m; j++)//�����±�Ϊ0��Ԫ��   
    {  
        cin >> V[j];  
        S[j] = S[j-1] + V[j];  
    }  
      
    cout << Best_1(n, m) << endl;  
    Show(B1[n][m], n, m);  
    Show_2(B1[n][m], n, m);  
    Show_3(B1[n][m], n, m);  
      
    cout << Best_2(n, m) << endl;  
    cout << Best_3(n, m) << endl;  
    cout << DFS(n, m) << endl;  
    cout << MDFS(n, m) << endl;  
  
   // system("pause");  
    return 0;  
}  
  
int Best_1(int n, int m)//��̬�滮:��ά����洢���  
{  
    for (int j=1; j<=m; j++)  
    {  
        B1[1][j] = S[j]; //1���˳�дǰj��������ʱ��   
    }  
    for (int i=2; i<=n; i++) //����i����   
    {  
        for (int j=i; j<=m-n+i; j++) //����ǰj���飬j��ȡ��m��ԭ���Ǹ������ÿ��������1����   
        {//���ص����˼�룬�����i�˳���k+1����j����ʱ���Ŷ���Ҫ������ʱ���Ƕ��٣��洢���Ž⵽B1[i][j]   
            int bestP = INF;  
            for (int k=i-1; k<j; k++)  
            {  
                if (bestP > max(B1[i-1][k], S[j]-S[k]))//��ǰi-1���˵������ʱ�͵�i���˵���ʱ��ȡ���ϴ�ֵ   
                    bestP = max(B1[i-1][k], S[j]-S[k]);  
            }  
            B1[i][j] = bestP;  
        }  
    }  
      
    return B1[n][m];  
}  
  
void Show(int minTime, int i, int j)//�ݹ������д�鱾�ķ���   
{  
    if (i == 0 || j == 0)  
        return;  
    if (i == 1) //��1���˳�д1��j����  
    {  
        cout << 1 << " " << j << endl;  
        return;  
    }   
    int t = j, x = V[j]; //��i���˳����ҳ��Ϊx    
    while (t>1 && x+V[t-1] <= minTime)//�ӵ�j���鿪ʼ����������i���˳�д��ʹ��̰�Ĳ��ԣ����������ȷ�����˶೭   
    {    
        x += V[t-1];  
        t--;  
    }  
    Show(minTime, i-1, t-1);//��ʣi-1���˺�t-1����  
    cout << t << " " << j << endl;  
}  
  
void Show_2(int minTime, int n, int m)//�ǵݹ����������д�鱾�ķ���   
{  
    int i, j, t, x;  
      
    for (i=n,j=m; i>0 && j>0; i--,j=t-1)  
    {  
        t = j, x = V[j]; //��i���˳����ҳ��Ϊx    
        while (t>1 && x+V[t-1] <= minTime)//�ӵ�j���鿪ʼ����������i���˳�д��ʹ��̰�Ĳ��ԣ����������ȷ�����˶೭   
        {    
            x += V[t-1];  
            t--;  
        }  
        cout << t << " " << j << endl;  
    }  
}  
  
void Show_3(int minTime, int n, int m)//�ǵݹ�˳�������д�鱾�ķ���   
{  
    int i, j, t, x;  
      
    for (i=1,j=1; i<=n && j<=m; i++,j=t+1)  
    {  
        t = j, x = V[j]; //��i���˳����ҳ��Ϊx    
        while (t<m && x+V[t+1] <= minTime)//�ӵ�j���鿪ʼ˳��������i���˳�д��ʹ��̰�Ĳ��ԣ����������ȷ�����˶೭   
        {    
            x += V[t+1];  
            t++;  
        }  
        cout << j << " " << t << endl;  
    }  
}  
  
int Best_2(int n, int m)//�Ż��Ķ�̬�滮�㷨����2��һά��������ά����   
{//pre[j]�൱��B1[i-1][j]��cur[j]�൱��B1[i][j]   
    for (int j=1; j<=m; j++)  
    {  
        pre[j] = S[j]; //1���˳�дǰj��������ʱ��   
    }  
    for (int i=2; i<=n; i++) //����i����   
    {  
        for (int j=i; j<=m-n+i; j++) //����ǰj���飬j��ȡ��m��ԭ���Ǹ������ÿ��������1����   
        {//���ص����˼�룬�����i�˳���k��j����ʱ���Ŷ���Ҫ������ʱ���Ƕ��٣��洢���Ž⵽B1[i][j]   
            int bestP = INF;  
            for (int k=i-1; k<j; k++)  
            {  
                if (bestP > max(pre[k], S[j]-S[k]))//��ǰi-1���˵������ʱ�͵�i���˵���ʱ��ȡ���ϴ�ֵ   
                    bestP = max(pre[k], S[j]-S[k]);  
            }  
            cur[j] = bestP;  
        }  
        for (int j=i; j<=m-n+i; j++)  
        {  
            pre[j] = cur[j];   
        }  
    }  
    return pre[m];  
}  
  
int Best_3(int n, int m)//��һ���Ż��Ķ�̬�滮�㷨����1��һά��������ά����   
{  
    for (int j=1; j<=m; j++)  
    {  
        F1[j] = S[j]; //1���˳�дǰj��������ʱ��   
    }  
    for (int i=2; i<=n; i++) //ʵ���Ͼ���һ�����ر�������   
    {  
        for (int j=m-n+i; j>=i; j--) //������0-1�������⣬jֻ�ܵݼ�  
        {  
            int bestP = INF;  
            for (int k=i-1; k<j; k++)  
            {  
                if (bestP > max(F1[k], S[j]-S[k]))//��ǰi-1���˵������ʱ�͵�i���˵���ʱ��ȡ���ϴ�ֵ   
                    bestP = max(F1[k], S[j]-S[k]);  
            }  
            F1[j] = bestP;  
        }  
    }  
      
    return F1[m];  
}  
  
int DFS(int i, int j) //�����㷨  
{  
    if (i == 1) //1���˳�дǰj��������ʱ��   
    {  
        return S[j];  
    }  
    int bestP = INF;  
    for (int k=i-1; k<j; k++)  
    {  
        if (bestP > max(DFS(i-1, k), S[j]-S[k]))//��ǰi-1���˵������ʱ�͵�i���˵���ʱ��ȡ���ϴ�ֵ   
            bestP = max(DFS(i-1, k), S[j]-S[k]);  
    }  
      
    return bestP;   
}   
  
int MDFS(int i, int j)//����¼�㷨   
{  
    if (B2[i][j] != INF)  
        return B2[i][j];  
    if (i == 1) //1���˳�дǰj��������ʱ��   
    {  
        return B2[i][j] = S[j];  
    }  
          
    int bestP = INF;  
    for (int k=i-1; k<j; k++)  
    {  
        if (bestP > max(MDFS(i-1, k), S[j]-S[k]))//��ǰi-1���˵������ʱ�͵�i���˵���ʱ��ȡ���ϴ�ֵ   
            bestP = max(MDFS(i-1, k), S[j]-S[k]);  
    }  
      
    return B2[i][j] = bestP;   
} 
