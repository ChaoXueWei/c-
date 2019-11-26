#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#if 0
bool matchString(string &s1,string &s2)
{
	int i = 0;
	int n = min(s1.size(), s2.size());
	const char *p1 = s1.c_str();
	const char *p2 = s2.c_str();
	while (*p1!='\0' && *p2!='\0')
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else if (*p1 == '*')
		{
			p1++;//这里要对p1和p2同时++，以防下种用例的出现
		  /*q*gho?ccebrpflus
			qgghozccebrpflus*/
			p2++;
			while ((*p1!='\0')&&(*p2!='\0') && (*p1 != *p2))
			{
				p2++;
			}
		}
		else if (*p1 == '?')
		{
			p1++;
			p2++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		//cout<<matchString(str1, str2) << endl;
		if (matchString(str1, str2))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	return 0;
}
#endif