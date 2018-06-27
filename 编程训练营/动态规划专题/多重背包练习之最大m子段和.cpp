/*  
  Name:  �������������֮����ϰ���m�Ӷκ�����  
  Author: ����׾  
  Description: ���m�Ӷκ�����  
������ n������������Ϊ����������ɵ�����a1��a2��a3��������an���Լ�һ�������� m��Ҫ��ȷ������ a1��a2��a3��������an�� m�����ཻ�ӶΣ�  
ʹ��m���Ӷε��ܺʹﵽ���������͡�  
���룺 
ÿ����������������������m��n��ʼ, ����������n������a1��a2��a3��������an��ֱ�������ļ������� 
����� 
��һ���������Ŀ��������˵�����͡� 
����ʾ���� 
1 3  
1 2 3 
2 6 
-1 4 -2 3 -2 3 
���ʾ���� 
6 
8 
  
�㷨˼·��   
����Ķ�̬�滮�Ż������⡣��f(i, j)��ʾǰj�������ֳ�i�Σ��Ұ�����j���������m�Ӷκͣ���ô��dp���̣�  
��������f(i, j) = max { f(i, j-1) + A[j], max {f(i-1, k) + A[j]}(k = i-1 ... j-1)}  
Ҳ����˵��j����Ҫô�Լ�������i�Σ�Ҫô��ǰһ����һ�𻮵���i�����棬ת����O(n)�ģ��ܸ��Ӷ�O(n * n * m)��  
����  
�㷨1��int MaxMSubSum(int i, int j);//�Զ����µı���¼�㷨   
����һ������¼����b[M+1][N+1]��b[i][j]��ʾ���ܳ���Ϊj�����зֳ�i���Ӷκ���i���Ӷε��ܺͣ����е�i���Ӷΰ���Ԫ��A[j]��  
����ԭ����ĵݹ��ϵ��ʹ�õݹ麯������⡣������b[m][j]���ҳ����Ž⡣  
  
�㷨2��int MaxMSubSum_2(int m, int n);//�Ե����ϵĶ�̬�滮�㷨    
��i=1��ʼ�����μ�¼ÿһ��b[i][j]�����������ģ��b[m][n]��  
���㷨1һ����������b[m][j]���ҳ����Ž⡣  
  
�㷨3��int MaxMSubSum_3(int m, int n);//�Ż��Ķ�̬�滮�㷨   
�Ƕ��㷨2���Ż����㷨2���õ��ı���¼����b[M+1][N+1]ռ�ռ�ϴ�ʵ������һ��������������һ�е��������ɵģ�  
����������û�й�ϵ�����ǿ���������һά���� cur[N+1] �� pre[N+1]����b[M+1][N+1]�� 
���� cur[j]�� pre[j]�ֱ����b[i][j]��b[i-1][j]��  
 
�㷨4��int MaxMSubSum_4(int m, int n);//�Ż��Ķ�̬�滮�㷨   
�Ƕ��㷨3���Ż����㷨3����cur[j]�� pre[j]�ֱ����b[i][j]��b[i-1][j]���ϸ�ذ��㷨2������㷨3����ʽ�� 
�ڼ���cur[j]ʱ��Ҫ����pre[k]�������ҳ����ֵ��Ȼ���ټ򵥵���cur[j]������pre[j]��ֵ�� 
˼������һ�������������pre[j]��ʾ������A[1...j]�ֳ�i-1���Ӷε����ͣ��Ӷ��в�һ������A[j]��cur[j]�ĺ��岻�䣬 
����ÿ�μ���cur[j]ʱ����Ҫ��Ҫ����pre[k]��ֻ��Ƚ�pre[j-1]��cur[j-1]���ɡ� 
ͬʱ�������ڸ���pre[j]ʱ��Ҫ�ӵ�i�Ӷΰ����򲻰���A[j]��ȡ�ϴ�ֵ���������º��pre[j]=cur[j]ʱ��ʾ����A[j]�� 
��pre[j]=pre[j-1]ʱ��ʾ������A[j]��  
  
���д��һ������ void PrintSubQue(int m, int n); //���ҵ�i�����������е����ұ߽磬�������Щ�����У�  
�ú�����Ҫ�õ�����¼����b[M+1][N+1]����ֻ�ܶ��㷨1���㷨2�����Ľ����Ч��   
*/    
#include<iostream>    
#include<cstring>    
    
using namespace std;    
    
const int M = 300;    
const int N = 700;    
int A[N+1];   
int B1[M+1][N+1];    
int B2[M+1][N+1];  
int pre[N+1];//pre[j]�洢j���������i-1�Ӷκ�  
int cur[N+1];//cur[j]�洢��ǰ�����а���A[j]�����i�Ӷκ�  
int L[M+1], R[M+1];  
  
int MaxMSubSum_1(int i, int j);//�Զ����µı���¼�㷨     
int MaxMSubSum_2(int m, int n);//��̬�滮����ά����   
int MaxMSubSum_3(int m, int n);//�Ż��Ķ�̬�滮�㷨      
int MaxMSubSum_4(int m, int n);//�Ż��Ķ�̬�滮�㷨     
void SearchSubQue(int m, int n, int B[M+1][N+1]);//���ö�ά����B[][]���ҵ�i�����������е����ұ߽�     
void PrintSubQue(int m); //���m���Ӷ�    
    
int main()    
{    
    int m, n;  
    cin >> m >> n;  
    for (int i=1; i<=n; i++)  
        cin >> A[i];  
      
    int maxSum;  
    maxSum = MaxMSubSum_1(m, n);   //��ǰ������Ǹ���ʱ����ȫ��   
    for (int j=n-1; j>=m; j--)    
    {    
        if (maxSum < B1[m][j])    
            maxSum = B1[m][j];    
    }    
    cout << maxSum << endl;   
    SearchSubQue(m, n, B1); //���ҵ�i�����������е����ұ߽�   
    PrintSubQue(m);  //���m���Ӷ�   
        
    memset(L, 0, sizeof(L));  
    memset(R, 0, sizeof(R));  
    maxSum = MaxMSubSum_2(m, n);    
    cout << maxSum << endl;   
    SearchSubQue(m, n, B2); //���ҵ�i�����������е����ұ߽�   
    PrintSubQue(m);  //���m���Ӷ�   
      
    memset(pre, 0, sizeof(pre));  
    memset(cur, 0, sizeof(cur));  
    maxSum = MaxMSubSum_3(m, n);    
    cout << maxSum << endl;    
      
    memset(pre, 0, sizeof(pre));  
    memset(cur, 0, sizeof(cur));  
    maxSum = MaxMSubSum_4(m, n);    
    cout << maxSum << endl;    
      
    return 0;    
}    
    
int MaxMSubSum_1(int i, int j)//����¼�㷨      
{      
    if (B1[i][j] != 0)    
       return B1[i][j];    
        
    if (i==0 || j<i)    
        return 0;  
      
    if (i == j)//ע��������������������ܵõ�����   
    {  
        B1[i][j] = MaxMSubSum_1(i-1, j-1) + A[j];     
    }  
    else    
    {    
        int maxSum = MaxMSubSum_1(i, j-1);  
        for (int k=i-1; k<j; k++)    
        {    
            if (maxSum < MaxMSubSum_1(i-1, k))    
               maxSum = B1[i-1][k];    
        }   
        B1[i][j] = maxSum + A[j];     
    }    
          
    return B1[i][j];      
}      
    
int MaxMSubSum_2(int m, int n)//��̬�滮����ά����      
{      
    int maxSum;  
      
    for (int i=1; i<=m; i++)  //����i���Ӷ�  
    {    
        B2[i][i] = B2[i-1][i-1] + A[i];  //���������ɶ� 
        for (int j=i+1; j<=n; j++)   //����j���� 
        {    
            maxSum = B2[i][j-1]; //Ĭ��A[j]��A[j-1]ͬ���ڵ�i���Ӷ�   
            for (int k=i-1; k<j; k++)  //�����ǲ���A[j]��ռ��i���Ӷθ���   
            {    
                if (maxSum < B2[i-1][k])    
                    maxSum = B2[i-1][k];    
            }  
            B2[i][j] = maxSum + A[j];   
        }    
    }    
    //����B2[m][j]���ҵ����ֵ   
    maxSum = B2[m][n];  
    for (int j=m; j<n; j++)  
    {  
        if (maxSum < B2[m][j])    
            maxSum = B2[m][j];  
    }  
         
    return maxSum;      
}      
    
int MaxMSubSum_3(int m, int n)//�Ż��Ķ�̬�滮�㷨      
{        
    int maxSum;    
    for (int i=1; i<=m; i++)    
    {    
        cur[i] = pre[i-1] + A[i];  
        for (int j=i+1; j<=n; j++)     
        {    
            maxSum = cur[j-1]; //Ĭ��A[j]��A[j-1]ͬ���ڵ�i���Ӷ�   
            for (int k=i-1; k<j; k++)  //�����ǲ���A[j]��ռ��i���Ӷθ���   
            {    
                if (maxSum < pre[k])    
                    maxSum = pre[k];    
            }  
            cur[j] = maxSum + A[j];  
        }  
        for (int j=i; j<=n; j++)     
        {    
            pre[j] = cur[j];//����pre[j]  
        }  
    }      
    //����pre[j]���ҵ����ֵ   
    maxSum = pre[n];  
    for (int j=m; j<n; j++)  
    {  
        if (maxSum < pre[j])    
            maxSum = pre[j];  
    }  
         
    return maxSum;      
}  
  
int MaxMSubSum_4(int m, int n)//�Ż��Ķ�̬�滮�㷨      
{   //cur[j]��ʾ�ֳ�i���Ӷε�����£���i���Ӷα������A[j]������  
    //pre[j]��ʾ������A[1...j]�ֳ�i-1���Ӷε����ͣ��Ӷ��в�һ������A[j]   
    for (int i=1; i<=m; i++)    
    {    
        cur[i] = pre[i-1] + A[i];   
        for (int j=i+1; j<=n; j++)     
        {  //��A[j]��ռ��i���Ӷκ�A[j]��A[j-1]ͬ�ڵ�i���Ӷ���ȡ�ϴ�ֵ   
            cur[j] = max(pre[j-1], cur[j-1]) + A[j];  
        }  
        //����pre[j]��pre[j]��ʾ������A[1...j]�ֳ�i���Ӷε�����   
        pre[i] = cur[i]; //��i��Ԫ�طֳ�i���ӶΣ�ÿ��Ԫ�ض�ռ1���Ӷ�   
        for (int j=i+1; j<=n; j++)     
        {  //�ڵ�i���Ӷΰ����򲻰���A[j]��ȡ�ϴ�ֵ   
            pre[j] = max(cur[j], pre[j-1]);//ע���ʱ��pre[j-1]���Ѹ��µģ����Ѿ��ֳ���i���Ӷ�  
        }  
    }     
             
    return pre[n];      
}  
  
void SearchSubQue(int m, int n, int B[M+1][N+1])//���ö�ά����B[][]���ҵ�i�����������е����ұ߽�     
{    
    int maxSum;    
    int left, right;    
        
    for (int i=m,j=n; i>0; i--,j=left)    
    {    
        maxSum = B[i][j];     
        right = j;    
        for (int k=j; k>=i; k--) //���ҵ�i�����������к͵����ֵ�Ͷ�Ӧ�ұ߽�    
        {    
            if (B[i][k] > maxSum)    
            {    
                maxSum = B[i][k];    
                right = k;    
            }    
        }     
        left = right; //���ҵ�i�����������е���߽�    
        while (left>=i && B[i][left]>0 && B[i][left]>B[i-1][left])    
        {    
            left--;    
        }     
            
        L[i] = left+1;    
        R[i] = right;     
    }    
}  
  
void PrintSubQue(int m) //���m���Ӷ�    
{  
    for (int i=1; i<=m; i++) //���m��������     
    {    
        cout << i << " : " << "(";   
        int s = A[R[i]];   
        for (int j=L[i]; j<R[i]; j++)    
        {    
            cout << A[j] << ", ";   
            s += A[j];   
        }    
        cout << A[R[i]] << ") = " << s << endl;     
    }    
}   
