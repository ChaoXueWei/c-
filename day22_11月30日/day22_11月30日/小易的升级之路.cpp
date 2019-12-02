/*
小易的初始能力为n,接下来打怪物
如果怪物防御值大于体力值，则打败之后小易的体力值值增加bi（小易体力值）和c（怪物的防御力）的最大公约数值
怪物防御值小于小易的体力值，那么在打败怪物之后的体力值增加怪物的防御值
*/
#include <iostream>
#include <vector>
using namespace std;
#if 0
//求最大公约数
int Gcd(int a,int b)
{
	while (a!=b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return b;
}


int main()
{
	int num, phyValue;//num为怪物的个数，phyValue为初始时小易的体力值
	vector<int> data;
	int n;
	while (cin >> num >> phyValue)
	{
		while (num--)
		{
			cin >> n;
			data.push_back(n);
		}
		for (auto i : data)
		{
			if (phyValue >= i)
			{
				phyValue += i;
			}
			else
			{
				phyValue+=Gcd(phyValue, i);
			}
		}
		data.clear();
		cout << phyValue << endl;
	}
	return 0;
}
#endif