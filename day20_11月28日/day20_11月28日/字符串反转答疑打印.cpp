// day20_11��28��.cpp : �������̨Ӧ�ó������ڵ㡣
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