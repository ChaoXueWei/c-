/*
������������������������С������
*/
#include <iostream>
#include <string>
using namespace std;
#if 0
//շת����������Լ��������С������
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