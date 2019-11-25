#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#if 0
string AddLongInteger(string addend, string augend)
{
	if (augend.size() == 0)
	{
		addend = augend;
		return addend;
	}
	int c = 0; //表示进位
	char ch;
	int i = 0;
	string tmp;
	reverse(addend.begin(),addend.end());
	reverse(augend.begin(), augend.end());
	int minNum = min(addend.size(), augend.size());
	int maxNum = max(addend.size(), augend.size());
	for (i = 0; i < minNum; i++)
	{
		ch = ((addend[i] - '0') + (augend[i] - '0')+c) % 10+'0';//相加模10的余数
		c = ((addend[i] - '0') + (augend[i] - '0') + c) / 10;//有无进位
		tmp.push_back(ch);
	} 
	while (addend.size()>minNum && i < maxNum)
	{
		ch = (addend[i] - '0'+c) % 10+'0';
		c = (addend[i] - '0' + c) / 10;
		tmp.push_back(ch);
		i++;
	}
	while (augend.size()>minNum && i < maxNum)
	{
		ch = (augend[i] - '0' + c) % 10 + '0';
		c = (augend[i] - '0' + c) / 10;
		tmp.push_back(ch);
		i++;
	}
	reverse(tmp.begin(), tmp.end());
	addend = tmp;
	return addend;
}
//99999999999999999999999999999999999999999999999999
//1

int main()
{
	string add;
	string aug;
	while (cin >> add >> aug)
	{
		cout << AddLongInteger(add, aug) << endl;
	}
	return 0;
}
#endif

//包含在algorithm中的reverse(iterator begin(),iterator end())该函数可以对容器进行逆置