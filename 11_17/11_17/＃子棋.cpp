#include <iostream>
#include <vector>
using namespace std; 
#if 0
class Board
{
public:
	bool checkWon(vector<vector<int> > board)
	{
		// write code here
		int i = 0;
		int j = 0;
		for (i = 0; i < 3; i++)
		{
			if (board[i][0]== 1 &&board[i][0] == board[i][1] && board[i][2] == board[i][1])
			{
				return true;
			}
			if (board[0][i] == 1 && board[0][i] == board[1][i] && board[2][i] == board[1][i])
			{
				return true;
			}
		}
		if (board[0][0] == 1 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			return true;
		}
		if (board[0][2] == 1 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			return true;
		}
		return false;
	}
};
int main()
{
	vector<vector<int> > data;
	vector<int> row;
	int x = 3;
	int y = 3;
	int flag = 0;
	while (x--)
	{
		y = 3;
		row.clear();
		while (y--)
		{
			cin >> flag;
			row.push_back(flag);
		}
		data.push_back(row);
	}
	for (auto v : data)
	{
		for (auto v1 : v)
		{
			cout << v1 << " ";
		}
		cout << endl;
	}
	Board d;
	cout<<d.checkWon(data)<<endl;

	
	return 0;
}
#endif