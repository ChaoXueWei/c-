#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_COUNT 10
int Menu();//打印菜单并返回选择函数
void Init(char show_map[][MAX_COL], char mine_map[][MAX_COL]);//初始化数组，将show_map全部初始化为*，mine_map全部初始化为0
void ProLand(char mine_map[][MAX_COL]);//初始化地雷函数，在mine_map[][]上随机产生MAX_COUNT个地雷,并将产生地雷的地方修改为1
void Print(char show_map[][MAX_COL]);//打印函数，将传入的数组按格式打印出来
int MineNum(const char mine_map[][MAX_COL], int row, int col);//返回mine_map[row][col]周围的地雷数
int LeapMine(char show_map[][MAX_COL]);//返回未排掉的格子数（包括未排出的地雷）
void Game();//游戏函数
void PrintOver(char mine_map[][MAX_COL]);//踩雷后打印所有雷的位置