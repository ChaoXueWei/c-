#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include"game.h"
#define ROW 3//��
#define COL 3//��
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
	if ((board[i][i] == board[i + 1][i + 1]) && (board[i + 1][i + 1] == board[i + 1][i + 2]))//���Խ����γ�Ӯ��
	{
		return board[i][i];
	}
	else if ((board[i][COL - 1] == board[i + 1][COL - 2]) && (board[i + 1][COL - 2] == board[i + 2][COL - 3]))
		//���Խ����γ�Ӯ��
	{
		return board[i][COL - 1];
	}
	for (i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][2] == board[i][1]))//��i���γ�Ӯ��
		{
			return board[i][0];
		}
		else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))//��i���γ�Ӯ��
		{
			return board[0][i];
		}
	}
	return -1;
}
bool boardFull(char board[][COL])//�ж������Ƿ����
//�ѷ���������true,δ������false
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
	printf("��������Ҫ�ߵ��������꣺");
	while (1)
	{
		scanf("%d%d", &row, &col);//����Ϸ������ͨ�û���ע��row�ķ�Χ
		if ((row > ROW) || (row<1) || (col<1) || (col > COL))
		{
			printf("�����������Ƿ������������룺");
		}
		else if (board[row - 1][col - 1] == ' ')//��Ϊ�����飬����ע��ʹ���û�����ֵʱҪ��1��
		{
			board[row - 1][col - 1] = 'X';
			break;
		}
		else
		{
			printf("������������ѱ�ռ��,���������룺");
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
		printf("�������ѡ��");
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
					printf("����Ӯ��\n");
					break;
				}
				else if (boardFull(arr))
				{
					printf("ƽ���ˣ�\n");
					break;
				}
				player(arr);
				printBoard(arr);
				if ('X' == leapWin(arr))
				{
					printf("��Ӯ�ˣ�\n");
					break;
				}
				else if (boardFull(arr))
				{
					printf("ƽ���ˣ�\n");
					break;
				}
			}
		}
		else
		{
			printf("����������\n");
		}
	}
	return 0;
}

