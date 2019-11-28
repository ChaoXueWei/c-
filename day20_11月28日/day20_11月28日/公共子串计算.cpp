#include <stdafx.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#if 0
//计算字符串最大公共子串的长度，字符不区分大小写
int getCommonStrLength(const char* pFristStr,const char* pSecondStr)
/*
先暴力得到取到较短串的所有子串，然后去母串中查找匹配，存在用data保存子串
查找过程中遇到比data长度小的子串直接跳过，最终保存在data中的就是最长子串
*/
{
	int i, j;
	string s1(pFristStr), s2(pSecondStr);
	string tmp;
	string data;
	if (s1.size() > s2.size())
	{
		swap(s1, s2);
	}
	for (i = 0; i < s1.size(); i++)
	{
		for (j = s1.size()-i; j >0 && j>data.size(); j--)
		{
			tmp = s1.substr(i, j);//i为其实下标。j为截取长度，而非终止下标（易混）
			//if (tmp.size() <= data.size())
			//{
			//	break;//data已经比该层最长子串长，break ，使用j>data.size()代替
			//}
			//cout << tmp << endl;//测试
			if (string::npos != s2.find(tmp))
			{
				data = tmp;
				break;//本层循环后续匹配到的只会越来越短，so break
			}
		}
	}
	return data.size();
}
int main()
{
	string str1,str2;
	cin >> str1 >> str2;
	cout<<getCommonStrLength(str1.c_str(),str2.c_str());
	return 0;
}
#endif