/*
	Name: ��̬�滮ר��֮�������� 
	Author: ����׾ 
	Description:7625_���������·������
������������ʾ�������������ֹ��ɵ�������: 
7 
3 8 
8 1 0 
2 7 4 4 
4 5 2 6 5 

�������εĶ������ײ��кܶ�����ͬ��·��������ÿ��·������·������������������Եõ�һ���ͣ�������·����Ϊ���·����
����������������·���ϵ�����֮�͡� 
ע�⣺·���ϵ�ÿһ��ֻ�ܴ�һ�����ߵ���һ���Ϻ���������±ߣ����·������������ұߣ����·���������

����
��һ��Ϊ�����θ߶�100>=h>=1��ͬʱҲ����ײ�ߵ����ֵ���Ŀ��
�ӵڶ��п�ʼ��ÿ��Ϊ��������Ӧ�е����֣��м��ÿո�ָ���
���
���·���ĳ�����ֵ��
��������
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
��
1
8
�������
30
��
8
*/
#include<iostream>  
#include<cstring>
  
using namespace std;  
  
const int MAX = 100;   
int map[MAX][MAX];  
int B1[MAX][MAX]; //����¼����¼��λ��(x,y)�����������õ����ֵ
int B2[MAX][MAX]; //��̬�滮����¼��λ��(x,y)�����������õ����ֵ
int pre[MAX]; //pre[j]�൱��B2[i+1][j] 
int cur[MAX]; //cur[j]�൱��B2[i][j]
int F[MAX];//��¼��ǰ�е����Ž�
int bestP; //��¼���Ž� 
  
void DFS(int n, int x, int y, int curP);//n��ʾ������x,y��ʾ��ǰλ�����꣬curP��ʾĿǰ����·���ϵ�Ȩֵ�� 
int DP_1(int n, int x, int y);//n��ʾ�����������λ��(x,y)�����������õ����ֵ 
int DP_2(int n); //��̬�滮�����Ʒ���
int DP_3(int n); //��̬�滮����ά�Ż�1��
int DP_4(int n); //��̬�滮����ά�Ż�2�� 
int DP_5(int n); //��̬�滮������ԭ���ݣ�
void PrintPath(int n); //������·��
void PrintPath_2(int n); //������·��
  
int main()   
{  
    int n;  
    cin >> n;  
    for (int i=0; i<n; i++)  
    {  
        for (int j=0; j<=i; j++)  
        {  
            cin >> map[i][j];  
        }  
    }  
     
    //�����㷨����Ҫ�õ�ȫ�ֱ���map[MAX][MAX]������bestP��ʼ��Ϊ0
    DFS(n, 0, 0, map[0][0]);  
    cout << bestP << endl;  
    
	//���仯����������¼�㷨������Ҫ�õ�ȫ�ֱ���map[MAX][]������B1[MAX][]��ʼ��Ϊ-1
	memset(B1, -1, sizeof(B1)); //�ȳ�ʼ��B1��ֵȫΪ-1  
    cout << DP_1(n, 0, 0) << endl;  
    
    //��̬�滮�����Ʒ�������Ҫ�õ�ȫ�ֱ���B2[MAX][]
    cout << DP_2(n) << endl;  
    
    //��̬�滮�����Ʒ�������Ҫ�õ�ȫ�ֱ���pre[]��cur[] 
    cout << DP_3(n) << endl;  
    
    //��̬�滮�����Ʒ�������Ҫ�õ�ȫ�ֱ���F[]
    cout << DP_4(n) << endl;  
    
    PrintPath(n); //������·��
    
    //��̬�滮�����Ʒ�������Ҫ�õ�ȫ�ֱ���map[MAX][]
    cout << DP_5(n) << endl;  
    
    PrintPath_2(n); //������·��
      
    return 0;  
}  

void DFS(int n, int x, int y, int curP)//n��ʾ������x,y��ʾ��ǰλ�����꣬curP��ʾĿǰ����·���ϵ�Ȩֵ�� 
{  
    if (x == n-1)
    {
		if (curP > bestP)
			bestP = curP;
	}
	else
	{
		DFS(n, x+1, y, curP+map[x+1][y]); //�����·��� 
		DFS(n, x+1, y+1, curP+map[x+1][y+1]); //�����·��� 
	}
}  

int DP_1(int n, int x, int y)//n��ʾ�����������λ��(x,y)�����������õ����ֵ 
{  
    if (B1[x][y] != -1)  
		return B1[x][y];
 	
	if (x == n-1)
		B1[x][y] = map[x][y];
	else
		B1[x][y] = map[x][y] + max(DP_1(n,x+1,y), DP_1(n,x+1,y+1));
	
    return B1[x][y]; 
}  

int DP_2(int n) //��̬�滮�����Ʒ��� 
{  
	for (int j=0; j<n; j++)  //��ײ�����Ԫ�غ;͵���Ԫ��ֵ 
		B2[n-1][j] = map[n-1][j];
    for (int i=n-2; i>=0; i--) //�����½�б�����ߣ����յ��ﶥ�㣬�պõõ���  
    {  
        for (int j=i; j>=0; j--)
        {  
            B2[i][j] = map[i][j] + max(B2[i+1][j], B2[i+1][j+1]);  
        }  
    }  
    return B2[0][0];  
} 

int DP_3(int n) //��̬�滮����ά�Ż�1�� 
{  
    for (int j=0; j<n; j++)  //��ײ�����Ԫ�غ;͵���Ԫ��ֵ 
		pre[j] = map[n-1][j];
    for (int i=n-2; i>=0; i--) //�����½�б�����ߣ����յ��ﶥ�㣬�պõõ���  
    {  
        for (int j=i; j>=0; j--)   
        {  
            cur[j] = map[i][j] + max(pre[j], pre[j+1]);  
        } 
		for (int j=i; j>=0; j--)   
        {  
            pre[j] = cur[j];  
        }  
    }  
    return pre[0];  
} 

int DP_4(int n) //��̬�滮����ά�Ż�2�� 
{  
    for (int j=0; j<n; j++)  //��ײ�����Ԫ�غ;͵���Ԫ��ֵ 
		F[j] = map[n-1][j];
    for (int i=n-2; i>=0; i--) //�����½�б�����ߣ����յ��ﶥ�㣬�պõõ���  
    {  
        for (int j=0; j<=i; j++)   
        {  
            F[j] = map[i][j] + max(F[j], F[j+1]);  
        } 
    }  
    return F[0];  
} 

int DP_5(int n) //��̬�滮������ԭ���ݣ� 
{  
    for (int i=n-2; i>=0; i--) //�����½�б�����ߣ����յ��ﶥ�㣬�պõõ���  
    {  
        for (int j=i; j>=0; j--)   
        {  
            map[i][j] += max(map[i+1][j], map[i+1][j+1]);  
        }  
    }  
    return map[0][0];  
} 

void PrintPath(int n) //������·�� 
{  
	int j = 0; 
    for (int i=0; i<n-1; i++) //���ǰn-1�� 
    {  
		cout << map[i][j] << "->"; //�����һ��Ԫ�� 
        if (B2[i+1][j] < B2[i+1][j+1]) //�����·��ߣ����������·��� 
        {  
            j++;
        }  
    }  
    //����ײ�Ԫ��   
    cout << map[n-1][j] << endl;  
}  

void PrintPath_2(int n) //������·�� 
{  
    int i = 0, j = 0; 
      
    for (int k=1; k<n; k++) //���ǰn-1��   
    {  
        if (map[i+1][j] > map[i+1][j+1]) //�����·���  
        {  
            cout << map[i][j] - map[i+1][j] << "->";  
            i++;  
        }   
        else //�����·���  
        {  
            cout << map[i][j] - map[i+1][j+1] << "->";  
            i++;  
            j++;  
        }   
    }  
    //����ײ�Ԫ��   
    cout << map[i][j] << endl;  
}  
