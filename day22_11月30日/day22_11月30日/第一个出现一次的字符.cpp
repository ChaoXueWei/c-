#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#if 0 
int main()
{
	string str;
	while (cin >> str)
	{
		char setArr[1024] = { 0 };
		int i = 0;
		int flag = 0;
		for (auto i : str)
		{
			setArr[i - 'A']++;
		}
		for (auto i : str)
		{
			if (setArr[i - 'A'] == 1)
			{
				cout << i << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
#endif