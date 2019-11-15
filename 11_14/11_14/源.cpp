/*
输入两个数，求两个数的最小公倍数
*/
#include <iostream>
#include <string>
using namespace std;
#if 0
//辗转相减法求最大公约数后求最小公倍数
int main()
{
	int x, y;
	int i;
	while (cin >> x >> y)
	{
		if (x < y)
		{
			x = x^y;
			y = x^y;
			x = x^y;
		}
		i = x*y;
		while (x!=y)
		{
			if (x < y)
			{
				y = y - x;
			}
			else
			{
				x = x - y;
			}
		}
		cout << i / x << endl;
		
	}
	return 0;
}
#endif