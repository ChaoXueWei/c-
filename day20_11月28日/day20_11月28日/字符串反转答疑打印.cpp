// day20_11月28日.cpp : 定义控制台应用程序的入口点。
//
#include <stdafx.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#if 0
void printStr(const char* p)
{
	if (*p == '\0')
	{
		return;
	}
	printStr(p+1);
	cout << *p;
}
int main()
{
	string str;
	while (cin >> str)
	{
		printStr(str.c_str());
		cout << endl;
		reverse(str.begin(), str.end());
		cout <<str<< endl;
	}
	return 0;
}

#endif