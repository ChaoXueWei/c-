/*
n个字符串：判断是根据字符串长度排序还是根据字典序排序
还两种都不符合或者均符合
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#if 0
using namespace std;
int main()
{
	int n;
	string str;
	vector<string> dataStr;
	map<string, int> m;//根据字典序排序
	map<int, string> strSizeData;//根据str长度排序
	int flagSzie = 0;
	int flagS = 0;
	int i = 0;
	//vector<string> strSizeData;//根据长度排序
	cin >> n;
	while (n--)
	{
		cin >> str;
		dataStr.push_back(str);
		m.insert(pair<string,int>(str,str.size()));
		strSizeData.insert(pair<int, string>(str.size(),str));
	}
	for (auto s : strSizeData)
	{
		if (s.second != dataStr[i])
		{
			flagSzie = 1;
			break;
		}
		i++;
	}
	i = 0;
	for (auto s : m)
	{
		if (s.first != dataStr[i])
		{
			flagS = 1;
			break;
		}
		i++;
	}
	if (flagS == 0 && flagSzie == 0)
	{
		cout << "both" << endl;
	}
	else if (flagS == 0)
	{
		cout << "lexicographically" << endl;
	}
	else if (flagSzie == 0)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	return 0;
}
#endif