#include <stdafx.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#if 0
//�����ַ�����󹫹��Ӵ��ĳ��ȣ��ַ������ִ�Сд
int getCommonStrLength(const char* pFristStr,const char* pSecondStr)
/*
�ȱ����õ�ȡ���϶̴��������Ӵ���Ȼ��ȥĸ���в���ƥ�䣬������data�����Ӵ�
���ҹ�����������data����С���Ӵ�ֱ�����������ձ�����data�еľ�����Ӵ�
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
			tmp = s1.substr(i, j);//iΪ��ʵ�±ꡣjΪ��ȡ���ȣ�������ֹ�±꣨�׻죩
			//if (tmp.size() <= data.size())
			//{
			//	break;//data�Ѿ��ȸò���Ӵ�����break ��ʹ��j>data.size()����
			//}
			//cout << tmp << endl;//����
			if (string::npos != s2.find(tmp))
			{
				data = tmp;
				break;//����ѭ������ƥ�䵽��ֻ��Խ��Խ�̣�so break
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