/* 
  Name:  ��̬�滮ר��֮�������������֮�� 
  Author:  ����׾ 
  Description:  �������������֮�� 
����K������������{ N1,N2, ..., NK }�����������������пɱ�ʾΪ{Ni, Ni+1, ..., Nj }�� 
���� 1 <= i <= j <= K���������������������������������Ԫ�غ�����һ���� 
�����������{ -2, 11, -4, 13, -5, -2 }�����������������Ϊ{ 11, -4, 13 }������Ϊ20��  
���룺
��������������ɲ���������ÿ����������ռ2�У���1�и���������K( < 10000 )����2�и���K���������м��ÿո�ָ���
��KΪ0ʱ�������������������������
�����
��ÿ��������������1����������͡�������K��Ԫ�ض��Ǹ���������������Ϊ0��
����ʾ����
6
-2 11 -4 13 -5-2
10
-10 1 2 3 4 -5-23 3 7 -21
6
5 -8 3 2 5 0
1
10
3
-1 -5 -2
3
-1 0 -2
0
���ʾ����
20
10
10
10
0
0

�㷨������
�㷨1��
��ֱ�ӵ��뷨��������١�����ÿһ�ο��ܵ�����������A[i..j]֮�ͣ�Ȼ�������ֵ������������ѭ������ʱ�临�Ӷ�ΪO(N^3)��

�㷨2��
��ϸ�۲��㷨1�����Ƿ�����ʵ���ڲ�ѭ���ǲ���Ҫ�ģ���Ϊ���ǿ���ֱ���������ѭ��������sum = 0;Ȼ���ۼ�ÿһ��A[j]ֵ�Ϳ��Եõ�A[i..j]֮���ˡ�
����ֻ������ѭ������ʱ�临�Ӷ�ΪO(N^2)��

�㷨3��
��Ȼ�㷨2��ʱ�临�Ӷȼ�С��O(N^2)�������㲻�ϸ�Ч���㷨�����ǿ��Բ���һ�֡����Ρ����ԣ������зֳ������������֣�
����������кͿ������������֣���벿���Ұ벿�����߿�Խ���ݵ��в���ռ���������벿�֡�
ǰ������������Եݹ���⣬�����������Ҫ�������벿���ͣ����������벿����Ԫ�أ��Լ��Ұ벿���ͣ���������Ұ벿����Ԫ�أ���
Ȼ���������ͼ���һ����󷵻����ߵ����ֵ��
���ڲ����˷����㷨������ʱ�临�Ӷȿ��Լ�С��O(NlogN)��

�㷨4��
���仯����������¼�㷨��������һ��ȫ�ֱ���B[i]�����洢����A[i]���������������֮�ͣ�Ȼ���Զ����£��ݹ�������Ž⡣
�ڱ����У���Ϊÿ����������ʵֻ��������һ�Σ�����ʹ�ü��仯�����㷨�������ƣ��Ұ����ó�������Ҫ��Ϊ�˺��㷨5���Ƚϡ� 

�㷨5��
������Ҫ�������ǡ���̬�滮���㷨����Ҳ��������¡���Ƽ����㷨������ʵ�ʸ��Ӷ�ΪO(N)���ǽ���������������㷨��
��̬�滮�㷨����η����ƣ������˼��Ҳ�ǽ����������ֽ�����ɸ������⣬����������⣬Ȼ�����Щ������Ľ�õ�ԭ����Ľ⡣
����η���ͬ���ǣ��ʺ����ö�̬�滮�������⣬���ֽ�õ��������������ǻ�������ġ����÷��η������������⣬��ֽ�õ�����������Ŀ̫�࣬
��Щ�����ⱻ�ظ������˺ܶ�Ρ���������ܹ������ѽ����������Ĵ𰸣�������Ҫʱ���ҳ�����õĴ𰸣������Ϳ��Ա���������ظ����㣬��ʡʱ�䡣
���ǿ�����һ��������¼�����ѽ��������Ĵ𰸡����ܸ��������Ժ��Ƿ��õ���ֻҪ������������ͽ�����������С�����Ƕ�̬�滮���Ļ���˼·��
�ڱ����У����ǿ��԰�ǰi(1<=i<=n)��Ԫ�ص���������кͼ�¼��������������i�����͵õ�n��Ԫ�ص���������к͡�
������һ������¼����S[i]����¼����Ԫ��A[i]���������������֮�ͣ� 
�������������������еĹ�ģ������ע�⵽��������Ԫ��A[i]ʱ�����������������к�S[i-1]>0�� 
��S[i]=S[i-1]+A[i]�п��������Ž⣻ ��S[i-1]<0 ����S[i]=A[i]�п��������Ž⡣ 
��������е�S[i]���ٱ���һ������S[i]���ҳ����ֵ��

�㷨6��
���ǵ��㷨5��S[i]��ֵֻ��S[i-1]�йأ���������е�S[i]����¼����������ʹ��һ���������汸��¼���飬 
�ñ���sum����S[i-1]���ǵ�ÿ������һ��Ԫ��A[i]����Ҫ��ʱ����sum��ֵ�� 

�㷨7�� 
�㷨6����һ��д����˼·��һ���ģ���sum��ʼֵ����A[0]������0��Ȼ��ÿ�β������ж�sum�������Ȱ�A[i]�ӵ�sum�У����sum��ɸ���������������sum=0��
 
�㷨8�� 
���㷨5�Ļ�����������������У��ڼ�¼����¼�����ͬʱ����¼���Ž�����ұ߽硣

�㷨9�� 
���㷨6�Ļ�����������������У��ڼ�¼����ֵ��ͬʱ����¼���Ž�����ұ߽硣
*/  
#include<iostream>  
#include<string>  
  
using namespace std;  

const int INF = -100000;  
const int MAX = 10000;  
int B[MAX]; //B[i]�����洢����A[i]���������������֮��
  
int MaxSubsequenceSum_1(const int A[], int n);//��Ч�㷨1     
int MaxSubsequenceSum_2(const int A[], int n);//��Ч�㷨2
int MaxSubsequenceSum_3(const int A[], int n);//�����㷨 
int MaxSubSum(const int A[], int left, int right);//�����㷨�ӳ���  
int MaxSubsequenceSum_4(const int A[], int i);//���仯����������¼�㷨�� 
int MaxSubsequenceSum_5(const int A[], int n);//ʹ��һά����Ķ�̬�滮�㷨  
int MaxSubsequenceSum_6(const int A[], int n);//ʹ��һ����������һά����  
int MaxSubsequenceSum_7(const int A[], int n);//ʹ��һ����������һά�������һ��д�� 
int MaxSubsequenceSum_8(const int A[], int n);//��¼�����ͬʱ����¼���Ž�����ұ߽�   
int MaxSubsequenceSum_9(const int A[], int n);//ʹ��һ����������һά���飬��������� 

  
int main()  
{  
	int A[MAX] = {0};  
	int n; 
	cin >> n;
	while (n != 0)
	{
		for (int i=0; i<n; i++)
			cin >> A[i];
		cout << MaxSubsequenceSum_1(A, n) << endl;  
	    cout << MaxSubsequenceSum_2(A, n) << endl;  
	    cout << MaxSubsequenceSum_3(A, n) << endl; 
	    
		for (int i=0; i<n; i++)
			B[i] = INF;
	    MaxSubsequenceSum_4(A, n-1);//ȫ�ֱ���B2[MAX] 
		int maxSum = max(0, B[0]);  //ע��ȫ�Ǹ��������� 
	    for (int i=1; i<n; i++)//�洢�����������е�����      
	    {  
	        if (B[i] > maxSum)  
	           maxSum = B[i];  
	    }  
	    cout << maxSum << endl;
	    
	    cout << MaxSubsequenceSum_5(A, n) << endl;  
	    cout << MaxSubsequenceSum_6(A, n) << endl;  
	    cout << MaxSubsequenceSum_7(A, n) << endl;  
	    cout << MaxSubsequenceSum_8(A, n) << endl;  
	    cout << MaxSubsequenceSum_9(A, n) << endl;  
	    
	    cin >> n;
	}
      
    return 0;  
}  

int MaxSubsequenceSum_1(const int A[], int n)//��Ч�㷨1   
{  
    int sum, maxSum = 0;    
      
    for (int i=0; i<n; i++)  
    {  
        for (int j=i; j<n; j++)  
        {  
            sum = 0;  
            for (int k=i; k<=j; k++)//��������������A[i..j]֮��  
            {  
                sum += A[k];  
            }  
            if (sum > maxSum)  
                maxSum = sum;  
        }  
    }   
      
    return maxSum;  
}  

int MaxSubsequenceSum_2(const int A[], int n)//��Ч�㷨2  
{  
    int sum, maxSum = 0; 
      
    for (int i=0; i<n; i++)  
    {  
        sum = 0;  
        for (int j=i; j<n; j++)  
        {  
            sum += A[j];  
            if (sum > maxSum)  
                maxSum = sum;  
        }  
    }   
      
    return maxSum;  
}  

int MaxSubsequenceSum_3(const int A[], int n)//�����㷨  
{  
    return MaxSubSum(A, 0, n-1);  
}  
  
int MaxSubSum(const int A[], int left, int right)//�����㷨�ӳ���  
{  
    int maxLeftSum, maxRightSum;  
    int maxLeftBorderSum, maxRightBorderSum;  
    int leftBorderSum, rightBorderSum; 
      
    if (left == right)  
        return (A[left] > 0) ? A[left] : 0;  
          
    int mid = (left + right) / 2;  
    maxLeftSum = MaxSubSum(A, left, mid); //�ݹ������벿����������   
    maxRightSum = MaxSubSum(A, mid+1, right);//�ݹ�����Ұ벿����������   
      
    maxLeftBorderSum = leftBorderSum = 0;  
    for (int i=mid; i>=left; i--)  //���м俪ʼ����������A[mid]�����е�����   
    {  
        leftBorderSum += A[i];  
        if (leftBorderSum > maxLeftBorderSum)  
            maxLeftBorderSum = leftBorderSum;  
    }  
      
    maxRightBorderSum = rightBorderSum = 0;  
    for (int i=mid+1; i<=right; i++)   //���м俪ʼ���Ҽ���A[mid+1]�����е�����   
    {  
        rightBorderSum += A[i];  
        if (rightBorderSum > maxRightBorderSum)  
            maxRightBorderSum = rightBorderSum;  
    }  
      
    return max(max(maxLeftSum, maxRightSum), maxLeftBorderSum+maxRightBorderSum);  
}   

int MaxSubsequenceSum_4(const int A[], int i)//���仯����������¼�㷨��   
{    //B[i]�����洢����A[i]���������������֮��
    if (B[i] != INF)
    	return B[i];
    if (i == 0)
    {
		B[i] = A[0];
	}
	else
	{
		if (MaxSubsequenceSum_4(A, i-1) > 0)  //��֮ǰ������������֮�ʹ���0�����A[i]�ۼ���ȥ 
			B[i] = MaxSubsequenceSum_4(A, i-1) + A[i];
		else  //�������¿�ʼ 
			B[i] = A[i]; 
	}
	
    return B[i];    
}  

int MaxSubsequenceSum_5(const int A[], int n)//ʹ��һά����Ķ�̬�滮�㷨    
{    
    int S[MAX] = {A[0]};//S[i]�����洢����A[i]���������������֮��     
   
    for (int i=1; i<n; i++)//�洢�����������е�����      
    {    
        if (S[i-1] > 0) //��֮ǰ������������֮�ʹ���0�����A[i]�ۼ���ȥ     
            S[i] = S[i-1] + A[i];    
        else   //�������¿�ʼ     
            S[i] = A[i];      
    }     
      
    int maxSum = max(0, S[0]);  //ע��ȫ�Ǹ��������� 
    for (int i=1; i<n; i++)//�洢�����������е�����      
    {  
        if (S[i] > maxSum)  
           maxSum = S[i];  
    }  
        
    return maxSum;    
}   

int MaxSubsequenceSum_6(const int A[], int n)//ʹ��һ����������һά����
{  
    int sum = A[0];  
    int maxSum = max(0, sum); //ע��ȫ�Ǹ��������� 
    
    for (int i=1; i<n; i++)//�洢�����������е�����      
    {    
        if (sum > 0) //��֮ǰ������������֮�ʹ���0�����A[i]�ۼ���ȥ    
        {   
            sum += A[i];    
            if (sum > maxSum) 
                maxSum = sum; 
        }  
        else   //�������¿�ʼ     
        {   
            sum = A[i]; 
        }  
    }   
      
    return maxSum;  
}   

int MaxSubsequenceSum_7(const int A[], int n)//ʹ��һ����������һά�������һ��д�� 
{  
    int sum = 0;  
    int maxSum = max(0, sum); //ע��ȫ�Ǹ��������� 
    
    for (int i=0; i<n; i++)//�洢�����������е�����      
    {    
		sum += A[i];
        if (sum > maxSum)   //�������ֵ 
        {   
            maxSum = sum; 
        }  
        else if (sum < 0)   //���¿�ʼ     
        {   
            sum = 0; 
        }  
    }   
      
    return maxSum;  
}  
  
int MaxSubsequenceSum_8(const int A[], int n)//��¼�����ͬʱ����¼���Ž�����ұ߽�   
{    
    int S[MAX] = {A[0]};//S[i]�����洢����A[i]���������������֮��   
    int maxSum = max(0, S[0]);  
    int left = 0, mLeft = 0, right = 0; //mLeft��right�ֱ�洢������������е����ұ߽�   
      
    for (int i=1; i<n; i++)//�洢�����������е�����      
    {    
        if (S[i-1] > 0) //��֮ǰ������������֮�ʹ���0�����A[i]�ۼ���ȥ    
        {   
            S[i] = S[i-1] + A[i];    
            if (S[i] > maxSum)   
            {  
                maxSum = S[i];  
                mLeft = left;  
                right = i;  
            }  
        }  
        else   //�������¿�ʼ     
        {   
            S[i] = A[i];    
            left = i;  
        }  
    }     
    
	if (maxSum > 0) 
	{
		cout << "A[" << mLeft << ":" << right << "] : ";  
	    for (int i=mLeft; i<=right; i++)//�洢�����������е�����      
	    {  
	        cout << A[i] << " ";  
	    }  
	    cout << "= ";  
	}
      
    return maxSum;    
}    

int MaxSubsequenceSum_9(const int A[], int n)//ʹ��һ����������һά���飬���������   
{    
    int sum = A[0];  
    int maxSum = max(0, sum);  
    int left = 0, mLeft = 0, right = 0; //mLeft��right�ֱ�洢������������е����ұ߽�   
      
    for (int i=1; i<n; i++)//�洢�����������е�����      
    {    
        if (sum > 0) //��֮ǰ������������֮�ʹ���0�����A[i]�ۼ���ȥ    
        {   
            sum += A[i];    
            if (sum > maxSum)   
            {  
                maxSum = sum;  
                mLeft = left;  
                right = i;  
            }  
        }  
        else   //�������¿�ʼ     
        {   
            sum = A[i];    
            left = i;  
        }  
    }     
    
	if (maxSum > 0)  
	{
		cout << "A[" << mLeft << ":" << right << "] : ";  
	    for (int i=mLeft; i<=right; i++)       
	    {  
	        cout << A[i] << " ";  
	    }  
	    cout << "= ";  
	}
      
    return maxSum;    
} 


