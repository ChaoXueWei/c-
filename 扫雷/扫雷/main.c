#include"game.h"
int Menu()
{
	printf("=============================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("=============================\n");
	printf("���������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Init(char show_map[][MAX_COL], char mine_map[][MAX_COL])
{
	int row = 0;
	int col = 0;
	for (row = 0; row < MAX_ROW; ++row)
	{
		for (col = 0; col < MAX_COL; ++col)
		{
			show_map[row][col] = '*';//��ʼ��show_map[][]���������Ľ��
			mine_map[row][col] = '0';//��ʼ��mine_map[][]����ʼ������
		}
	}
}
void ProLand(char mine_map[][MAX_COL])//��mine_map[][]���������MAX_COUNT������,�����������׵ĵط��޸�Ϊ1
{
	int count = MAX_COUNT;
	while (count)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '0')
		{
			mine_map[row][col] = '1';
			--count;
		}
	}
}
void Print(char show_map[][MAX_COL])//��ӡ
{
	int row = 0;
	int col = 0;
	printf(" |");
	for (int i = 0; i < MAX_COL; ++i)
	{
		printf("%d ", i);
	}
	printf("\n----------------------");
	for (row = 0; row < MAX_ROW; ++row)
	{
		printf("\n%d|", row);
		for (col = 0; col < MAX_COL; ++col)
		{
			printf("%c ", show_map[row][col]);
		}
	}
	printf("\n");
}
void PrintOver(char mine_map[][MAX_COL])
{
	int i, j;
	printf("  |");
	for (i = 0; i < MAX_COL; ++i)
	{
		printf(" %d ", i);
	}
	printf("\n-------------------------------");
	for (i = 0; i < MAX_ROW; ++i)
	{
		printf("\n%d |", i);
		for (j = 0; j < MAX_COL; ++j)
		{
			if (mine_map[i][j] == '1')
			{
				printf(" ��");
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
}
int MineNum(const char mine_map[][MAX_COL], int row, int col)//����mine_map[row][col]��Χ�ĵ�����
{
	int count = 0;
	if ((row - 1 > 0) && (col - 1 > 0) && (mine_map[row - 1][col - 1] == '1'))//�������Ͻ�
	{
		++count;
	}
	if ((row - 1 > 0) && (mine_map[row - 1][col] == '1'))//�������Ϸ�
	{
		++count;
	}
	if ((row - 1 > 0) && (col + 1 < MAX_COL) && (mine_map[row - 1][col + 1] == '1'))//�������Ϸ�
	{
		++count;
	}
	if ((col - 1 > 0) && (mine_map[row][col - 1] == '1'))//�������
	{
		++count;
	}
	if ((col + 1 < MAX_COL) && (mine_map[row][col + 1] == '1'))//�����ұ�
	{
		++count;
	}
	if ((row + 1<MAX_ROW) && (col - 1 > 0) && (mine_map[row + 1][col - 1] == '1'))//��������
	{
		++count;
	}
	if ((row + 1 < MAX_ROW) && (mine_map[row + 1][col] == '1'))//��������
	{
		++count;
	}
	if ((row + 1 < MAX_ROW) && (col + 1 < MAX_COL) && (mine_map[row + 1][col + 1] == '1'))//��������
	{
		++count;
	}
	return count;
}
int LeapMine(char show_map[][MAX_COL])//����δ�ŵ��ĸ�����������δ�ų��ĵ��ף�
{
	int count = 0;
	int row, col;
	for (row = 0; row < MAX_ROW; ++row)
	{
		for (col = 0; col < MAX_COL; ++col)
		{
			if (show_map[row][col] != '*')
			{
				++count;
			}
		}
	}
	return MAX_ROW*MAX_COL - count;
}
void Game()
{
	int row, col;
	srand((unsigned)time(NULL));
	char show_map[MAX_ROW][MAX_COL];//��������ʾ������������ǰȫ��ʼ��Ϊ*
	char mine_map[MAX_ROW][MAX_COL];//�������׵ĵط��޸�Ϊ1.û�е��׵ĵط�ȫ����ʼ��Ϊ0
	Init(show_map, mine_map);
	ProLand(mine_map);
	while (1)
	{
		system("cls");
		Print(show_map);
		//printf("\n\n");
		//Print(mine_map);//���д������ڲ���
		printf("��������Ҫ���������꣺");
		while (1)
		{
			scanf("%d%d", &row, &col);
			if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
			{
				printf("���������Ƿ������������룺");
				continue;
			}
			else if (show_map[row][col] != '*')
			{
				printf("������������ѱ����������������룺");
				continue;
			}
			else
			{
				break;
			}
		}
		if (mine_map[row][col] == '1')
		{
			printf("������,game over!\n");
			PrintOver(mine_map);
			break;
		}
		else
		{
			show_map[row][col] = MineNum(mine_map, row, col) + '0';
		}
		if (LeapMine(show_map) == MAX_COUNT)
		{
			printf("��ϲ��ʿ���ɹ��ŵ����е��ף�\n");
			break;
		}
	}
}
int main()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			Game();
		}
		else if (choice == 0)
		{
			printf("goodbye!\n");
			break;
		}
		else
		{
			printf("����������\n");
		}
	}
	system("pause");
	return 0;
}