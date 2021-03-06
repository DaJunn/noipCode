/*
  Name: 整数划分问题
  Copyright: 
  Author: 巧若拙 
  Date: 27-06-17 15:19
  Description: 整数划分问题是算法中的一个经典命题之一，有关这个问题的讲述在讲解到递归时基本都将涉及。
  所谓整数划分，是指把一个正整数n写成如下形式：
n=m1+m2+...+mi; （其中mi为正整数，并且1 <= mi <= n），则{m1,m2,...,mi}为n的一个划分。
如果{m1,m2,...,mi}中的最大值不超过m，即max(m1,m2,...,mi)<=m，则称它属于n的一个m划分。
这里我们记n的m划分的个数为f(n,m);
 例如但n=4时，他有5个划分，{4},{3,1},{2,2},{2,1,1},{1,1,1,1};
 注意4=1+3 和 4=3+1被认为是同一个划分。
该问题是求出n的所有划分个数，即f(n, n)。下面我们考虑求f(n,m)的方法;
        ---------------------------------------------------------------------
                                           （一）递归法
        ---------------------------------------------------------------------
根据n和m的关系，考虑以下几种情况： 
（1）当 n = 1 时，不论m的值为多少（m > 0 )，只有一种划分即 { 1 };
 (2) 当 m = 1 时，不论n的值为多少，只有一种划分即 n 个 1，{ 1, 1, 1, ..., 1 };
 (3) 当 n = m 时，根据划分中是否包含 n，可以分为两种情况：
 	 (a). 划分中包含n的情况，只有一个即 { n }；
	 (b). 划分中不包含n的情况，这时划分中最大的数字也一定比 n 小，即 n 的所有 ( n - 1 ) 划分。
	 因此 f(n, n) = 1 + f(n, n-1);
 (4) 当 n < m 时，由于划分中不可能出现负数，因此就相当于 f(n, n);
 (5) 但 n > m 时，根据划分中是否包含最大值 m，可以分为两种情况：
	(a). 划分中包含 m 的情况，即 { m, { x1, x2, ..., xi } }, 其中 { x1, x2, ..., xi } 的和为 n - m，
	可能再次出现 m，因此是（n - m）的 m 划分，因此这种划分个数为 f(n-m, m);
	(b). 划分中不包含 m 的情况，则划分中所有值都比 m 小，即 n 的 ( m - 1 ) 划分，个数为 f(n, m - 1);
	因此 f(n, m) = f(n - m, m) + f(n, m - 1);

 综合以上情况，我们可以看出，上面的结论具有递归定义特征，其中（1）和（2）属于回归条件，
 （3）和（4）属于特殊情况，将会转换为情况（5）。而情况（5）为通用情况，属于递推的方法，
 其本质主要是通过减小m以达到回归条件，从而解决问题。其递推表达式如下：
 f(n, m) = 1;  ( n = 1 or m = 1 )
 f(n, n);      ( n < m )
 1+ f(n, m - 1); ( n = m )
 f(n - m, m) + f(n, m - 1); ( n > m )
 
 ---------------------------------------------------------------------
                                           （二）动态规划法 
        ---------------------------------------------------------------------
 因为整数划分问题满足最优子结构和子问题重叠特征，故可以用动态规划算法来解。
 分别使用了自顶向下的备忘录算法和自底向上动态规划算法，
 其中动态规划算法给出了行序优先和列序优先两种写法，并且给出了一个优化算法。 
*/
#include<iostream>
#include<cmath>

using namespace std;

const int N = 400;
int F[N][N]; //备忘录，记录n的m划分的个数
int Fun_2(int n, int m); //自顶向下的备忘录算法解整数划分问题
int Fun_3(int n, int m); //行序优先的自底向上的动态规划算法解整数划分问题
int Fun_4(int n, int m); //列序优先的自底向上的动态规划算法解整数划分问题
int Fun_5(int n, int m); //优化的列序优先自底向上的动态规划算法解整数划分问题

int Fun(int n, int m); //递归法解整数划分问题

int main() 
{
 	int n = 12;
 	
 	for (n=1; n<=10; n++)
 	{
	 	for (int i=0; i<=n; i++)
	 	{
		 	for (int j=0; j<=n; j++)
		 		F[i][j] = 0;
		}
		memset(F, 0, sizeof(F));  
	 	cout << Fun(n, n) << "  ";
	 	memset(F, 0, sizeof(F));  
	 	cout << Fun_2(n, n) << "  ";
	 	memset(F, 0, sizeof(F));  
	 	cout << Fun_3(n, n) << "  ";
	 	memset(F, 0, sizeof(F));  
	 	cout << Fun_4(n, n) << "  ";
	 	memset(F, 0, sizeof(F));  
	 	cout << Fun_5(n, n) << endl;
    }
 	
    system("pause");
    return 0;
}

int Fun(int n, int m) //递归法解整数划分问题
{
 	if (n == 0 || m == 0)
        return 0;
 	if (n == 1 || m == 1)
 	    return 1;
    if (n < m)
        return Fun(n, n);
    if (n == m)
        return Fun(n, n-1) + 1;
    
    return Fun(n-m, m) + Fun(n, m-1);
}

int Fun_2(int n, int m) //自顶向下的备忘录算法解整数划分问题
{
 	if (F[n][m] > 0)
        return F[n][m];
 	if (n == 0 || m == 0)
 	    return 0;
 	   
    if (n == 1 || m == 1)
	    return F[n][m] = 1;
    else if (n < m)
        return F[n][m] = Fun_2(n, n);
    else if (n == m)
        return F[n][m] = Fun_2(n, n-1) + 1;
    else
        return F[n][m] = Fun_2(n-m, m) + Fun_2(n, m-1);
}

int Fun_3(int n, int m) //行序优先：自底向上的动态规划算法解整数划分问题
{  
    for (int i=1; i<=n; i++) // ( n = 1 or m = 1 )  
    {  
        F[i][1] = F[1][i] = 1;  
    }  
      
    for (int i=2; i<=n; i++) //根据定义一一构造函数关系 
    {  
        for (int j=2; j<i; j++) // ( n > m )  
        {  
            F[i][j] = F[i][j-1] + F[i-j][j];   
        }  
          
        F[i][i] = 1 + F[i][i-1];  // ( n = m )  
          
        for (int j=i+1; j<=n; j++) // ( n < m )  
        {  
            F[i][j] = F[i][i];   
        }  
    }  
      
    return F[n][n];  
} 

int Fun_4(int n, int m) //列序优先，自底向上的动态规划算法解整数划分问题
{
 	//f(n, m)=1+ f(n, m - 1); ( n = m ) 即F[i][j] = F[0][j] + F[i][j-1]; ( i = j ) 
 	for (int j=1; j<=n; j++) 
    {  
        F[0][j] = 1;  
    }  
 	 
    //为实现自底向上，必须要保证j在外层循环，
	//然后按照0<=i<j和j<=i<=n的顺序在内层循环，分别计算n<m和n>=m的f(n, m)值，
	//这样生成的矩阵顺序为列序优先，从上到下输出每列元素	   
    for (int j=1; j<=m; j++)
    {
	 	//f(n, m)=f(n, n); ( n < m ) 
	 	for (int i=1; i<j; i++) 
	 	{
		 	F[i][j] = F[i][j-1];
		}
		//f(n, m)=f(n - m, m) + f(n, m - 1); ( n > m )
	 	for (int i=j; i<=n; i++)
	 	{
		 	F[i][j] = F[i-j][j] + F[i][j-1];
		}
	}
    
    return F[n][m];
}

int Fun_5(int n, int m) //优化的列序优先自底向上的动态规划算法解整数划分问题
{
 	int cur[N] = {1}; //记录第j列第i行的元素值，第j列第i行的元素等于第j-1列第i行的元素与第j列第i-j行的元素之和 
 	
 	//因为算法4中f(n, m)=f(n, n); ( n < m ) 且f(n, m)=f(n - m, m) + f(n, m - 1); ( n > m )，
	 //即当前元素等于上方与左侧元素之和,故只需记录上一列和当前列的元素即可。
	 //可以类比杨辉三角中的算法，用一维数组代替二维数组，
	 //外层循环j表示第j列，cur[i]表示第i行元素的值，内层循环i递增，表示从上到下依次计算第j列的元素值， 
	 //cur[i] += cur[i-j]表示把第j-1列第i行的元素值，和第j列第i-j行的元素值加起来，赋值给第j列第i行元素， 
	 //注意到当n < m时，f(n, m)=f(n, n)，故当i<j时第j列的cur[i]值与左侧的cur[i]值相等，不再发生变化， 
	 //相当于算法4中的F[i][j] = F[i][j-1]; ( i < j)
    for (int j=1; j<=m; j++)
    {
	 	for (int i=j; i<=n; i++)
	 	{
		 	cur[i] += cur[i-j];
		}
	}
    
    return cur[n];
}
