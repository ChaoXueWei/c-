/*
С����˾�����ս�������һ��6*6�ľ���Board��ÿ�����Ӷ�Ӧһ�����ÿ�������Ӧһ���ļ�ֵС�������Ͻǵ����½ǣ�����Ҫ��õ�����ֵ
�ʻ�õ�����ֵ
*/

#include <iostream>
#include <vector>
#include <algorithm>
#if 0
using namespace std;
class Bonus
{
public:
	int getMost(vector<vector<int> > board)
	{
		// write code here
		int i, j;
		for (i = 0; i < board.size(); i++)
		{
			for (j = 0; j < board[i].size(); j++)
			{
				if (i == 0 && j == 0)
				{
					//
				}
				else if (i == 0)
				{
					board[i][j] += board[i][j - 1];
				}
				else if (j == 0)
				{
					board[i][j] += board[i - 1][j];
				}
				else
				{
					board[i][j] += max(board[i][j - 1], board[i - 1][j]);
				}
			}
		}
		return board[i-1][j-1];
	}
};

int main()
{
	Bonus s;
	vector<vector<int>> board;
	board.resize(6);
	int ward = 0;
	for (auto &i : board)
	{
		i.resize(6);
	}
	for (auto &i : board)
	{
		for (auto &u : i)
		{
			cin >> u;
		}
	}
	ward=s.getMost(board);
	cout << ward << endl;
	return 0;
}
#endif