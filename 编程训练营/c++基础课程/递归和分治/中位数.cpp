/*
	Name: ��λ��median 
	Author: ����׾ 
	Description: 
����
����n��nΪ������С��1000���������������ķ�Χ��0-m��0<m<2^31��֮�䣬��ʹ�ö��ַ�����n����������λ����
��ν��λ������ָ����n��������֮���������м������
����
��һ������������n��m��
�ڶ������ÿո������n������ 
���
һ����λ�� 
��������
5 10
3 7 2 5 4 
�������
4
*/
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
  
using namespace std;  
  
const int MAXN = 1000;  
int A[MAXN];  
  
int main()   
{  
	int n, m;
    cin >> n >> m;  
    for (int i=0; i<n; i++)  
        cin >> A[i];  
    
    int mid, count, left = 0, right = m; 
    while (left <= right)  
    {  
        mid = (left + right) / 2;  
        count = 0;
        for (int i=0; i<n; i++)
        {
			if (A[i] >= mid)//��¼��С��mid����������
				count++; 
		}
        if (count > n/2)    
            left = mid + 1;  
        else  
            right = mid - 1;  
        
     //   cout << mid << " " << left << " " << right << " " << count << " " << n/2 << endl;
    }  
      
    cout << right << endl;   
      
    return 0;  
}  
