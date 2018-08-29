/*
	Name: ���̸�������
	Copyright: 
	Author: 
	Date: 10-01-18 22:28
	Description:
���̸�������Ҫ����2^k * 2^k ��������ɵ������У����������һ������㣬��һ�ַ���ʵ�ֶԳ�������������ʵ��ȫ���ǡ� 
��������������÷��η������������̷ֳ�4���֣�������������ĳһ���֣����Ǿ�ȥ�ݹ�����
�������ĳһ���֣����Ǽ���һ����Ϊ����㣬ͬ���ݹ���ȥ��ֱ��ȫ���ǡ�
ÿ��ݹ鶼Ҫ����4���ӷ��飬ͬ���ӷ����3���������ⷽ��ʹ����ͬ��ɫ��ɫ�鸲�ǣ�ǡ�ù���һ��L�͹��� �� 
���Ͻǵ������̣������������ⷽ�񣩣��򽫸����������½ǵ��Ǹ��������Ϊ���ⷽ��
���Ͻǵ������̣������������ⷽ�񣩣��򽫸����������½ǵ��Ǹ��������Ϊ���ⷽ��
���½ǵ������̣������������ⷽ�񣩣��򽫸����������Ͻǵ��Ǹ��������Ϊ���ⷽ��
���½ǵ������̣������������ⷽ�񣩣��򽫸����������Ͻǵ��Ǹ��������Ϊ���ⷽ��
*/
#include<iostream>  
using namespace std;  
  
const int MAX = 8;  
int tile = 1;  
int board[MAX][MAX] = {0};  
  
void ChessBoard(int tr, int tc, int dr, int dc, int size)  
{  
    if (size == 1)  
        return;  
  
    int t = tile++;   //L�͹��ƺţ���ɫ�� 
    int sz = size / 2; //�ָ�����
  
    if (dr < tr+sz && dc < tc+sz)//���ⷽ�������Ͻ�������  
    {
		ChessBoard(tr, tc, dr, dc, sz);  
	}
    else //������һ�����������㣬�ݹ�ò���  
	{  
        board[tr+sz-1][tc+sz-1] = t;  
        ChessBoard(tr, tc, tr+sz-1, tc+sz-1, sz);  
    }  
  
    if (dr < tr+sz && dc >= tc+sz) //���ⷽ�������Ͻ�������  
    {
		ChessBoard(tr, tc+sz, dr, dc, sz);  
	}
    else
	{  
        board[tr+sz-1][tc+sz] = t;  
        ChessBoard(tr, tc+sz, tr+sz-1, tc+sz, sz);  
    }  
  
    if (dr >= tr+sz && dc < tc+sz)  //���ⷽ�������½�������  
    {
		ChessBoard(tr+sz, tc, dr, dc, sz);  
	}
    else
	{  
        board[tr+sz][tc+sz-1] = t;  
        ChessBoard(tr+sz, tc, tr+sz, tc+sz-1, sz);  
    }  
  
    if (dr >= tr+sz && dc >= tc+sz) //���ⷽ�������½�������  
    {
		ChessBoard(tr+sz, tc+sz, dr, dc, sz);  
	}
    else
	{  
        board[tr+sz][tc+sz] = t;                       
        ChessBoard(tr+sz, tc+sz, tr+sz, tc+sz, sz);     
    }  
}  
  
void PrintChessBoard()  
{  
    cout.setf(ios::left);     //�����  
    for (int i=0; i<MAX; ++i)
	{  
        for (int j=0; j<MAX; ++j)
		{  
            cout.width(3);    //��ӡ���Ϊ3  
            cout << board[i][j];  
        }  
        cout << endl;  
    }  
}  
  
int main()  
{  
    ChessBoard(0, 0,0, 1, MAX);  
    PrintChessBoard();  
    return 0;  
}  
