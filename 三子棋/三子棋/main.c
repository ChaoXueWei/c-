#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include"game.h"
#define ROW 3//行
#define COL 3//列
void menu()
{
	printf("**********************************\n");
	printf("*********     1.play    **********\n");
	printf("**********************************\n");
	printf("*********     0.exit    **********\n");
	printf("**********************************\n");
}
void initBoard(char board[][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void printBoard(char arr[][COL])
{
	int i = 0;
	printf("-----------\n");
	for (i = 0; i <ROW; i++)
	{
		printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
		printf("-----------\n");
	}
}
char leapWin(char board[][COL])
{
	int i = 0;
	if ((board[i][i] == board[i + 1][i + 1]) && (board[i + 1][i + 1] == board[i + 1][i + 2]))//正对角线形成赢局
	{
		return board[i][i];
	}
	else if ((board[i][COL - 1] == board[i + 1][COL - 2]) && (board[i + 1][COL - 2] == board[i + 2][COL - 3]))
		//反对角线形成赢局
	{
		return board[i][COL - 1];
	}
	for (i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][2] == board[i][1]))//第i行形成赢局
		{
			return board[i][0];
		}
		else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))//第i列形成赢局
		{
			return board[0][i];
		}
	}
	return -1;
}
bool boardFull(char board[][COL])//判断棋盘是否放满
//已放满，返回true,未满返回false
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}
void comMove(char board[][COL])
{
	while (1)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		if (board[row][col] == ' ')
		{
			board[row][col] = '0';
			break;
		}
	}
}
void player(char board[][COL])
{
	int row, col;
	printf("请输入你要走的棋子坐标：");
	while (1)
	{
		scanf("%d%d", &row, &col);//玩游戏的是普通用户，注意row的范围
		if ((row > ROW) || (row<1) || (col<1) || (col > COL))
		{
			printf("您输入的坐标非法，请重新输入：");
		}
		else if (board[row - 1][col - 1] == ' ')//因为是数组，所以注意使用用户输入值时要减1，
		{
			board[row - 1][col - 1] = 'X';
			break;
		}
		else
		{
			printf("您输入的坐标已被占用,请重新输入：");
		}
	}
}
int main()
{
	char arr[ROW][COL] = { 0 };
	srand((unsigned int)time(NULL));
	int x;
	while (1)
	{
		menu();
		printf("输入你的选择：");
		scanf("%d", &x);
		if (0 == x)
		{
			break;
		}
		else if (1 == x)
		{
			initBoard(arr);
			while (1)
			{
				system("cls");
				comMove(arr);
				printBoard(arr);
				if ('0' == leapWin(arr))
				{
					printf("电脑赢！\n");
					break;
				}
				else if (boardFull(arr))
				{
					printf("平局了！\n");
					break;
				}
				player(arr);
				printBoard(arr);
				if ('X' == leapWin(arr))
				{
					printf("你赢了！\n");
					break;
				}
				else if (boardFull(arr))
				{
					printf("平局了！\n");
					break;
				}
			}
		}
		else
		{
			printf("你输入有误。\n");
		}
	}
	return 0;
}

