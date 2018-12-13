/*
	Name: 
	Copyright: 
	Author: 
	Date: 11-07-17 14:47
	Description: 156:LETTERS
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
A single-player game is played on a rectangular board divided in R rows and C columns.
 There is a single uppercase letter (A-Z) written in every position in the board.
Before the begging of the game there is a figure in the upper-left corner of the board (first row, first column). 
In every move, a player can move the figure to the one of the adjacent positions (up, down,left or right). 
Only constraint is that a figure cannot visit a position marked with the same letter twice.
The goal of the game is to play as many moves as possible.
Write a program that will calculate the maximal number of positions in the board the figure can visit in a single game.
����
The first line of the input contains two integers R and C, separated by a single blank character, 1 <= R, C <= 20.
The following R lines contain C characters each. Each line represents one row in the board.
���
The first and only line of the output should contain the maximal number of position in the board the figure can visit.
���룺
����������һ��R*C�Ĵ�д��ĸ���󣬿�ʼ��λ��Ϊ���Ͻǣ�����������������ĸ������ƶ��������ܷ���ͬһ��ĸ���Ρ�
���������ƶ�����λ�ã��������Է��ʼ�����ĸ�� 
���룺��һ�У�������ĸ���������R������C��1 <= R, C <= 20��
�������R��C����ĸ����
����������Է��ʵ���ĸ������
 
��������
3 6
HFDFFB
AJHGDH
DGAGEH
�������
6

�㷨˼�룺
���͵Ļ����㷨������㿪ʼ���Ⱥ����������ĸ�����ǰ������ǰ����һֱǰ��������ǰ���򷵻���һ�񣬻����������ǰ����ֱ�����з��򶼲���ǰ��Ϊֹ��
����һ��ȫ�ֱ���m������¼�����Է��ʵ���ĸ������������letter[26]�ж�ĳ����ĸ�Ƿ��Ѿ������ʣ�
Ϊ�����±�Խ�磬��������letter[map[x][y]-'A']��ʾ��д��ĸmap[x][y]�ļ��ɡ�
*/

#include<iostream>
#include<cstdio>

using namespace std;
 
const int N = 20; 
char map[N][N];
bool letter[26]; //�ж�26����ĸ��ĳ����ĸ�Ƿ��Ѿ������� 
int X[4]={0,1,0,-1}, Y[4]={1,0,-1,0}; //���������ĸ������ƶ��������������ı仯ֵ 
int m = 0;//��������ĸ�� 
int R, C; 

void DFS(int r, int c, int s);

int main() 
{
	cin >> R >> C;
	for (int i=0; i<R; i++)
	{
		for (int j=0; j<C; j++)
		{
			cin >> map[i][j];
		}
	}
	
	letter[map[0][0]-'A'] = 1; //��ע������ĸ�Ѿ������ʹ� 
	DFS(0, 0, 1);
	
	cout << m << endl;
	
    return 0;
}

void DFS(int r, int c, int s) 
{
    if (s > m) //������ಽ�� 
    	m = s;
    
    for (int i=0; i<4; i++)//�ֱ���������ǰ��һ��ѭ���������˻���һ�� 
	{
		int x = r + X[i];
		int y = c + Y[i];
		
		if (x >= 0 && x < R && y >= 0 && y < C && !letter[map[x][y]-'A'])//�������������ǰ�� 
		{
			letter[map[x][y]-'A'] = 1;
			DFS(x, y, s+1);
			letter[map[x][y]-'A'] = 0;
		}
	} 
}

