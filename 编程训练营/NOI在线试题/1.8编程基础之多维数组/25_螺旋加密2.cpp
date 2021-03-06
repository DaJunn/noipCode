/*
	Name: 25_螺旋加密
	Copyright: 
	Author: 
	Date: 07-09-17 19:41
	Description: 25_螺旋加密
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Chip和Dale发明了一种文本信息加密技术。他们事先秘密约定好矩阵的行数和列数。接着，将字符按如下方式编码：

1. 所有文本只包含大写字母和空格。

2. 每个字符均赋予一个数值：空格=0，A=1，B=2，……，Y=25，Z=26。

按照下图所示的方式，将每个字符对应数值的5位二进制数依次填入矩阵。最后用0将矩阵补充完整。例如，对于信息“ACM”，行列数均为4时，矩阵将被填充为：



将矩阵中的数字按行连起来形成数字串，完成加密。例子中的信息最终会被加密为：0000110100101100。

输入
一行。首先是两个整数R(1≤R≤20)和C(1≤C≤20)，表示行数和列数。之后是一个只包含大写字母和空格的字符串。字符串的长度≤(R*C)/5。R和C之间以及C和字符串之间均用单个空格隔开。
输出
一行，为加密后的二进制串。注意你可能需要用0将矩阵补充完整。
样例输入
4 4 ACM
样例输出
0000110100101100
*/
#include <iostream>
#include <cstdio>
using namespace std;
int n,m,l,c,x,y,t,a[105][105];
string s,ss,q="0000100010000110010000101001100011101000010010101001011011000110101110011111000010001100101001110100101011011010111110001100111010";

int main()
{
	cin >>n>>m; getchar(); getline(cin,s);
	l = s.size();
	for (int k=0;k<l;k++)
	{
		if (s[k]==' ')
			ss+="00000";
		else 
			ss+=q.substr(5*(s[k]-'A'),5);
	}
	
	while (t<5*l)
	{
		x = y = ++c;
		while (y+c<=m+1&&t<5*l){a[x][y]=ss[++t-1]-'0';y++;}y--;x++;
		while (x+c<=n+1&&t<5*l){a[x][y]=ss[++t-1]-'0';x++;}x--;y--;
		while (y>=c&&t<5*l){a[x][y]=ss[++t-1]-'0';y--;}y++;x--;
		while (x>c&&t<5*l){a[x][y]=ss[++t-1]-'0';x--;}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cout<<a[i][j];
	return 0;
}
