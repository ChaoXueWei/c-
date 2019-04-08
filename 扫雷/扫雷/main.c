#include"game.h"
int Menu()
{
	printf("=============================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=============================\n");
	printf("请输入你的选择：");
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
			show_map[row][col] = '*';//初始化show_map[][]，即翻开的结果
			mine_map[row][col] = '0';//初始化mine_map[][]，初始化地雷
		}
	}
}
void ProLand(char mine_map[][MAX_COL])//在mine_map[][]上随机产生MAX_COUNT个地雷,并将产生地雷的地方修改为1
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
void Print(char show_map[][MAX_COL])//打印
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
				printf(" 雷");
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
}
int MineNum(const char mine_map[][MAX_COL], int row, int col)//返回mine_map[row][col]周围的地雷数
{
	int count = 0;
	if ((row - 1 > 0) && (col - 1 > 0) && (mine_map[row - 1][col - 1] == '1'))//坐标左上角
	{
		++count;
	}
	if ((row - 1 > 0) && (mine_map[row - 1][col] == '1'))//坐标正上方
	{
		++count;
	}
	if ((row - 1 > 0) && (col + 1 < MAX_COL) && (mine_map[row - 1][col + 1] == '1'))//坐标右上方
	{
		++count;
	}
	if ((col - 1 > 0) && (mine_map[row][col - 1] == '1'))//坐标左边
	{
		++count;
	}
	if ((col + 1 < MAX_COL) && (mine_map[row][col + 1] == '1'))//坐标右边
	{
		++count;
	}
	if ((row + 1<MAX_ROW) && (col - 1 > 0) && (mine_map[row + 1][col - 1] == '1'))//坐标左下
	{
		++count;
	}
	if ((row + 1 < MAX_ROW) && (mine_map[row + 1][col] == '1'))//坐标正下
	{
		++count;
	}
	if ((row + 1 < MAX_ROW) && (col + 1 < MAX_COL) && (mine_map[row + 1][col + 1] == '1'))//坐标右下
	{
		++count;
	}
	return count;
}
int LeapMine(char show_map[][MAX_COL])//返回未排掉的格子数（包括未排出的地雷）
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
	char show_map[MAX_ROW][MAX_COL];//翻开后显示地雷数，翻开前全初始化为*
	char mine_map[MAX_ROW][MAX_COL];//产生地雷的地方修改为1.没有地雷的地方全部初始化为0
	Init(show_map, mine_map);
	ProLand(mine_map);
	while (1)
	{
		system("cls");
		Print(show_map);
		//printf("\n\n");
		//Print(mine_map);//该行代码用于测试
		printf("请输入你要翻开的坐标：");
		while (1)
		{
			scanf("%d%d", &row, &col);
			if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
			{
				printf("输入的坐标非法，请重新输入：");
				continue;
			}
			else if (show_map[row][col] != '*')
			{
				printf("您输入的坐标已被翻开，请重新输入：");
				continue;
			}
			else
			{
				break;
			}
		}
		if (mine_map[row][col] == '1')
		{
			printf("踩雷了,game over!\n");
			PrintOver(mine_map);
			break;
		}
		else
		{
			show_map[row][col] = MineNum(mine_map, row, col) + '0';
		}
		if (LeapMine(show_map) == MAX_COUNT)
		{
			printf("恭喜勇士，成功排掉所有地雷！\n");
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
			printf("您输入有误！\n");
		}
	}
	system("pause");
	return 0;
}