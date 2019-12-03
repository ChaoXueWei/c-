#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#if 0 
class Gift
{
public:
	int getValue(vector<int> gifts, int n)//就是找出超过vector中出现次数超过size()的数据，如不存在返回0
	{
		// write code here
		int num = 0;
		sort(gifts.begin(), gifts.end());
		num=count(gifts.begin(), gifts.end(),gifts[gifts.size() / 2]);
		return (num > (gifts.size() / 2)) ? gifts[gifts.size() / 2]: 0;
	}
};
int main()
{

	int n;
	int num;
	vector<int> data;
	cin >> n;
	int tmp = n;
	Gift g;
	while (n--)
	{
		cin >> num;
		data.push_back(num);
	}
	n = tmp;
	cout << g.getValue(data, n) << endl;
	return 0;
}
#endif