#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#if 0
int calStringDistance(string charA,string charB)
{
	vector<vector<int>> data;
	int k = 0;
	int j = 0;
	int minNum = 0;
	data.resize(charB.size()+1);
	for (auto &i : data)
	{
		i.resize(charA.size() + 1); 
		i[0] = k++;
	}
	k = 0;
	for (auto &i : data[0])
	{
		i = k++;
	}
	//边框填表
	for (j = 1; j < charB.size() + 1; j++)
	{
		for (k = 1; k < charA.size() + 1; k++)
		{
			if (charA.size()>=k && charB.size()>=j)
			{
				if (charA[k-1] == charB[j-1])
				{
					data[j][k] = data[j - 1][k - 1];
				}
				else
				{
					 minNum= min(data[j - 1][k], min(data[j - 1][k - 1], data[j][k - 1]));
					 data[j][k] = minNum+1;
				}
			}
			else
			{
				minNum = min(data[j - 1][k], min(data[j - 1][k - 1], data[j][k - 1]));
				data[j][k] = minNum+1;
			}
		}
	}
	return data[charB.size()][charA.size()];
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << calStringDistance(str1,str2) << endl;
	}

	return 0;
}
#endif

//动态规划问题首先先解决填表问题，之后在表格中寻找规律，找出递推规律
//本题中的递推公式为
/*
       charA[j]==charB[k]时，data[j][k]=data[j-1][k-1];//相等就退化
	   charA[j]！=charB[k]时，data[j][k]=min(data[j-1][k-1],data[j-1][k],data[j][k-1])+1;
*/