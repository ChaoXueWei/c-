#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_COUNT 10
int Menu();//��ӡ�˵�������ѡ����
void Init(char show_map[][MAX_COL], char mine_map[][MAX_COL]);//��ʼ�����飬��show_mapȫ����ʼ��Ϊ*��mine_mapȫ����ʼ��Ϊ0
void ProLand(char mine_map[][MAX_COL]);//��ʼ�����׺�������mine_map[][]���������MAX_COUNT������,�����������׵ĵط��޸�Ϊ1
void Print(char show_map[][MAX_COL]);//��ӡ����������������鰴��ʽ��ӡ����
int MineNum(const char mine_map[][MAX_COL], int row, int col);//����mine_map[row][col]��Χ�ĵ�����
int LeapMine(char show_map[][MAX_COL]);//����δ�ŵ��ĸ�����������δ�ų��ĵ��ף�
void Game();//��Ϸ����
void PrintOver(char mine_map[][MAX_COL]);//���׺��ӡ�����׵�λ��