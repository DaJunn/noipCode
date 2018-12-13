/*
	Name: 1792_�Թ�
	Copyright: 
	Author: 
	Date: 13-07-17 21:30
	Description: 1792_�Թ�
�鿴 �ύ ͳ�� ����
��ʱ������: 3000ms �ڴ�����: 65536kB
����
һ��Extense��ɭ����̽�յ�ʱ��С��������һ���Թ����Թ����Կ�������n * n�ĸ����ɣ�ÿ�����ֻ��2��״̬��.��#��ǰ�߱�ʾ����ͨ�к��߱�ʾ����ͨ�С�ͬʱ��Extense����ĳ�����ʱ����ֻ���ƶ�����������(����˵��������)�ĸ�����֮һ�����ڸ���ϣ�Extense��Ҫ�ӵ�A�ߵ���B�����ڲ��߳��Թ���������ܲ��ܰ쵽������������յ���һ������ͨ��(Ϊ#)���򿴳��޷��쵽��
����
��1���ǲ������ݵ�����k���������k�����롣ÿ��������ݵĵ�1����һ��������n (1 <= n <= 100)����ʾ�Թ��Ĺ�ģ��n * n�ġ�
��������һ��n * n�ľ��󣬾����е�Ԫ��Ϊ.����#���ٽ�����һ����4������ha, la, hb, lb������A���ڵ�ha��, ��la�У�
B���ڵ�hb��, ��lb�С�ע�⵽ha, la, hb, lbȫ���Ǵ�0��ʼ�����ġ�
���
k�У�ÿ�������Ӧһ�����롣�ܰ쵽�������YES�������������NO����
��������
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
�������
YES
NO
*/
#include<iostream>
#include<cstdio>

using namespace std;

const int MAX = 101; 
char map[MAX][MAX];
bool lib[MAX][MAX]; //��Ǹõ��Ƿ��Ѿ����� 
int DicX[4] = {0, 1, 0, -1}; //���������ĸ������ƶ���x�����൱�������� 
int DicY[4] = {1, 0, -1, 0}; //���������ĸ������ƶ���y�����൱�������� 
int n, x0, y0, x1, y1;

bool DFS(int x, int y); 

int main() 
{
	int k;
	cin >> k;
	while (k-- > 0)
	{
		cin >> n;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cin >> map[i][j];
				lib[i][j] = 0; 
			}
		}
		cin >> x0 >> y0 >> x1 >> y1;
		
		if (map[x0][y0]=='#' || map[x0][y0]=='#')//���������յ���һ������ͨ��(Ϊ#)���򿴳��޷��쵽��
		{
			cout << "NO" << endl;
			continue;
		}
		
		lib[x0][y0] = 1;
		if (DFS(x0, y0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
    return 0;
}

bool DFS(int x, int y) //x��y�ֱ��ʾ��ǰ������������꣬�ҵ��յ㣬������
{
	if (x == x1 && y == y1)
	{
		return true;
	}
	
	int nx, ny;
	bool flag = false;
	for (int i=0; i<4; i++)
	{
		nx = x + DicX[i];
	    ny = y + DicY[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !lib[nx][ny] && map[nx][ny] == '.')
		{
			lib[nx][ny] = 1; //�߹��˾Ͳ������� 
			flag = DFS(nx, ny);
		}
	
		if (flag) //�ҵ��յ㣬������ 
			return true;
	}
	return false;	
}
