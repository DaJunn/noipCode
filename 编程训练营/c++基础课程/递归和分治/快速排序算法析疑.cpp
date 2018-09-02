/* 
    Name: ���������㷨����  
    Copyright:  
    Author: ����׾ 
    Date: 13-01-18 15:38 
    Description:���������㷨  
��������Ļ���˼����ͨ��һ�����򽫴������зָ�ɶ��������������У�Ȼ��ֱ�������������зֱ���������Դﵽ������������  
�������������Ϊa[low:high+1]��������ѡһ��Ԫ��ֵ��Ϊ��Ŧ���ٷֱ�������������м�ɨ�裬ͨ�����������������ںͲ�С����Ŧ��Ԫ�طֱ������������࣬  
ʹ��һ��������������е�Ԫ�ؾ��������������е�Ԫ�ء�  
Ϊ��ֹ�����±�Խ����ظ�ɨ���������޵ݹ飬��Ҫ�±����Խ��������á���λ��־����  
���ݼ�鷽���Ĳ�ͬ�������˸��ֲ�ͬ�ı�﷽ʽ��������Դ˽��з�����ץס����ı��ʡ� 
Ϊ������㷨Ч�ʣ����������㷨����ȡ�����ȡ��Ŧ������β�ݹ��Ż��������㷨һ���㷨��Ч�ʽϸߣ��ֱ����õ�ֵԪ���ٺͶ�����Ρ�   
*/  
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib>  
  
using namespace std;  
  
const int N = 400000;  
int A[N] = {0};  
int B1[N] = {0};  
int B2[N] = {0};  
int B3[N] = {0};  
int B4[N] = {0};  
int B5[N] = {0};  
  
void QuickSort_1(int A[], int low, int high);  
void QuickSort_2(int A[], int low, int high);  
void QuickSort_3(int A[], int low, int high);  
void QuickSort_4(int A[], int low, int high);  
  
int Cmp(const void *a, const void *b)    
{    
    return *(int *)a - *(int *)b;    
}   
  
int main()   
{  
    for (int i=0; i<N; i++)  
    {  
        B1[i] = B2[i] = B3[i] = B4[i] = B5[i] = A[i] = rand() % 100;  
    }  
 /*    
    for (int i=0; i<N; i++) 
    { 
        cout << A[i] << "  "; 
    } 
    cout << endl; 
   */  
     
    time_t startTime;  
    time_t endTime;  
      
    time(&startTime);   
    QuickSort_1(B1, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    time(&startTime);   
    QuickSort_2(B2, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    time(&startTime);   
    QuickSort_3(B3, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    time(&startTime);   
    QuickSort_4(B4, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
   /* 
    for (int i=0; i<N; i++) 
    { 
        cout << A[i] << "  "; 
    } 
    cout << endl; 
    */  
      
    time(&startTime);  
    qsort(A, N, sizeof(A[0]), Cmp);    
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    int sum = 0;  
    for (int i=0; i<N; i++)  
    {  
        sum += (A[i] != B1[i]) || (A[i] != B2[i]) || (A[i] != B3[i]) || (A[i] != B4[i]);  
    }  
    cout << sum << endl;  
      
    return 0;  
}  
/* 
����һ���˷�ֻ��ȡ����Ŧ��ֵ����δ����Ŧ���ж�λ���������������Ŧλ�ò�ȷ����  
Ϊ���⵱��ŦΪ������СԪ��ֵʱ���ᵥ��ɨ����������������κδ����������޵ݹ顣  
Ӧ����Ŧ��Ϊ����λ��־����ɨ��ʱ������Ŧ��ͣ�£��������꽻��������i,j����ǰһ����  
����������±����Խ���飬����ȷ��һ�������j<i�������г������ٱ�ԭ������1��  
��Ȼ�˷���ɨ��ʱ������ŦҲͣ�£�ʹ�ý����������ӣ��������������±�Խ�磬ɨ��Ч�ʺܸߣ��ر��ʺϵ�ֵԪ�ز�������Ρ� 
�������������  
tΪ��Сֵ��1.i������j����ɨ�赽pos��ͣ�£�����a[i],a[j]��i,j����ǰһ����  
2.i������j����ɨ�赽low��ͣ�£���Ϊi>j�����ѭ��������  
3.��ʱj==low��i==low+1���ݹ�ִ��qsort_1(a,i,high)��  
tΪ���ֵ��1.i����ɨ�赽pos��ͣ��,j����������a[i],a[j]��i,j����ǰһ����  
2.i����ɨ�赽high��ͣ��,j��������Ϊi>j�����ѭ��������  
3.��ʱj==high-1��i==high���ݹ�ִ��qsort_1(a,low,j)�� 
*/  
void QuickSort_1(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        i = low; j = high; t = A[p];  
        while (i <= j) //ע���±����ʱҲҪɨ�裬ȷ������j<i   
        {  
            while (A[i] < t)  
                i++;  
            while (A[j] > t)  
                j--;  
            if (i <= j)//������ϣ�i,j����ǰһ�����Ǳ��㷨�ĸ�Ч֮��  
                swap(A[i++], A[j--]);  
        }  
        if (j > low)  
            QuickSort_1(A, low, j);  
        low = i; //����β�ݹ�qsort_1(a,i,high);   
    }  
}  
  
/* 
������������һδ����Ŧ���ж�λ������ŦΪ��ֵʱ����������޵ݹ飬�����Ƚ���Ŧ��λ��a[low]����ɱ������޵ݹ顣  
��Ϊɨ��ʱ����������Ŧ��ֵ��Ԫ�أ�������±����Խ���飬ȷ��һ�������i==j�� 
Ȼ����Ŧ������a[j]������������ȷ�������г������ٱ�ԭ������1��  
����ɨ��ʱ��Ҫ����±�Խ�磬ʹ��ɨ���ٶȱ�������Ȼ�����������٣�������Ч�ʻ����½��ˡ�  
�������������  
tΪ��Сֵ��1.j����ɨ�赽low��ͣ�£�i��������Ϊi==j�����ѭ��������  
2.����a[j],a[low]����ʱj==low��i==low���ݹ�ִ��qsort_2(a,i+1,high)��  
tΪ���ֵ��1.j������i����ɨ�赽high��ͣ�£���Ϊi==j�����ѭ��������  
2.����a[j],a[low]����ʱj==high��i==high���ݹ�ִ��qsort_2(a,low,j-1)�� 
*/   
void QuickSort_2(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        swap(A[low], A[p]);  
        i = low; j = high; t = A[low];  
        while (i < j) //ѭ������ʱi==j    
        {  
            while (i < j && A[j] > t)//��Ϊ��ŦԪ��������࣬Ӧ������ɨ�裬ȷ������a[j]<t   
                j--;  
            while (i < j && A[i] <= t)  
                i++;  
            if (i < j)  
                swap(A[i], A[j]);  
        }  
        swap(A[low], A[j]);  
        if (j-1 > low) //��ŦԪ��a[j]�Ѿ��źã������ٴ���   
            QuickSort_2(A, low, j-1);  
        low = i + 1; //����β�ݹ�qsort_2(a,i+1,high);   
    }  
}  
  
/* 
����������������������ɨ��ʱ����Ҫ����±�Խ�磬��i==jʱ�����ѭ��������Ϊ��ȷ������a[j]<t������������ɨ�衣  
��Ϊ�����Ѿ�����Ŧ�ŵ���a[low]����������ɨ��ʱ�����Խ���Ŧ��Ϊ����λ��־����j����low��ʱ����ͣ�£� 
�������������±�Խ�磬����ɨ�跽�����ɱ䡣  
���⣬�������н�������ǰ��Ҫ�ж�if i<j����Щ�ظ������ǿ��Խ����������ᵽǰ�棬����һ���жϡ�  
Ϊ�˽����������ᵽǰ�棬����Ҫ��ȡa[high]Ϊ��Ŧ��Ȼ��ѭ��֮���ͽ�����������Ԫ�أ���ô�ں���Ĺ�������Ŧֵ��Ȼ��a[low]��  
�˷�����һ���ô�������ȷ������a[i+1,high+1]��ֵ��������Ŧ��a[i]>=t���������ڽ�������β�ݹ��Ż��󣬵ݹ���ȴ����١�  
������������ɨ��ʱҪ����±꣬����ɨ��ʱҪ����Ŧֵ��ͣ�£�������˵Ч�ʲ��ߣ��ٶ��뷽�����ӽ���  
�������������  
tΪ��Сֵ��1.����a[i],a[j]��i��ǰһ����j����ɨ�赽low��ͣ�£���Ϊi>j�����ѭ��������  
2.����a[j],a[low]����ʱj==low��i==low+1���ݹ�ִ��qsort_3(a,i,high)��  
tΪ���ֵ��1.����a[i],a[j]��i����ɨ�赽high��ͣ�£�j��������Ϊi==j�����ѭ��������  
2.����a[j],a[low]����ʱj==high��i==high���ݹ�ִ��qsort_3(a,low,j-1)�� 
*/  
void QuickSort_3(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        swap(A[high], A[p]);  
        i = low; j = high; t = A[high];  
        while (i < j)  
        {  
            swap(A[i], A[j]);  
            while (i < j && A[i] <= t)  
                i++;  
            while (A[j] > t)  
                j--;  
        }  
        swap(A[low], A[j]);  
        if (i < high)  
            QuickSort_3(A, i, high);  
        high = j - 1; //����β�ݹ�qsort_3(a,low,j-1);   
    }  
}  
  
/* 
�����ģ��������ͷ�����������Ŧ�����˶�λ������ŦԪ��Ϊ�磬��ԭ���з�Ϊ�������������У��ݹ�ִ�е��������ж���������ŦԪ�ء�  
�������һ����������������������д��ڴ�������Ŧ��ֵ��Ԫ�أ�����ЩԪ�������ֲ�����Ŧ���࣬����ЩԪ���Ѿ��ź��򣬲�Ӧ�����������������ٴεݹ�����  
�˷��ڷ������Ļ����Ͻ����˸Ľ���������i,j��ɨ�跶Χ��ʹ���ܹ������Ŧ�Ҳ������ֵ��Ԫ�أ������²�ݹ�������г��ȣ� 
����Ҫ�ֱ���high��lowΪɨ��߽磬���ڲ�ѭ��ʱi���Դ���j�������ѭ����⵽i>jʱ��ѭ�������� 
�˷��ر��ʺϵ�ֵԪ�ض�����飬�뷽��һ��Ϊ���䡣  
�������������  
tΪ��Сֵ��1.i��ǰһ����j����ɨ�赽low��ͣ�£���Ϊi>j�����ѭ��������  
2.����a[j],a[low]����ʱj==low��i==low+1���ݹ�ִ��qsort_4(a,i,high)��  
tΪ���ֵ��1.i����ɨ�赽high+1��ͣ�£�j��������Ϊi>j�����ѭ��������  
2.����a[j],a[low]����ʱj==high��i==high+1���ݹ�ִ��qsort_4(a,low,j-1)�� 
*/   
void QuickSort_4(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        swap(A[low], A[p]);  
        i = low; j = high; t = A[low];  
        while (i <= j)  
        {  
            while (i <= high && A[i] <= t)  
                i++;  
            while (j > low && A[j] >= t)  
                j--;  
            if (i < j)  
                swap(A[i++], A[j--]);  
        }  
        swap(A[low], A[j]);  
        if (j-1 > low) //��Ϊa[j:i]��ֵ��������Ŧ������������   
            QuickSort_4(A, low, j-1);  
        low = i; //����β�ݹ�qsort_4(a,i,high);   
    }  
}  

