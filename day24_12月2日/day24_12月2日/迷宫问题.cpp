#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<vector<int>> g_path_tmp;
vector<vector<int>> g_path_best_short;
void findPath(vector<vector<int>> &maze,int i,int j)
{
	maze[i][j] = 1;
	g_path_tmp.push_back({i,j});
	if (i == (maze.size() - 1) && j == (maze[0].size() - 1))
	{
		if (g_path_tmp.size() < g_path_best_short.size() || g_path_best_short.size() == 0)
		{
			g_path_best_short = g_path_tmp;//�������·��
		}
	}
	//���������ĸ������ƶ�
	if (i - 1 >= 0 && maze[i-1][j] == 0)//����
	{
		findPath(maze, i - 1, j);
	}
	if (j - 1 >= 0 && maze[i][j-1] == 0)//����
	{
		findPath(maze, i, j-1);
	}
	if (i + 1 < maze.size() && maze[i+1][j] == 0)//����
	{
		findPath(maze, i+1, j);
	}
	if (j + 1 < maze[0].size() && maze[i][j+1] == 0)//����
	{
		findPath(maze, i, j + 1);
	}
	maze[i][j] = 0;
	g_path_tmp.pop_back();
}


int main()
{
	int row, col;
	vector<vector<int>> maze;
	while (cin >> row >> col)
	{
		g_path_tmp.clear();
		g_path_best_short.clear();
		maze.resize(row);
		for (auto &i : maze)
		{
			i.resize(col);
		}
		for (auto &i : maze)
		{
			for (auto &u : i)
			{
				cin >> u;
			}
		}
		findPath(maze, 0, 0);
		for (auto &i : g_path_best_short)
		{
			cout << '(' << i[0] << "," << i[1] << ')' << endl;
		}
	}
	
	return 0;
}