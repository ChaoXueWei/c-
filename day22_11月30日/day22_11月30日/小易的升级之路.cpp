/*
С�׵ĳ�ʼ����Ϊn,�����������
����������ֵ��������ֵ������֮��С�׵�����ֵֵ����bi��С������ֵ����c������ķ������������Լ��ֵ
�������ֵС��С�׵�����ֵ����ô�ڴ�ܹ���֮�������ֵ���ӹ���ķ���ֵ
*/
#include <iostream>
#include <vector>
using namespace std;
#if 0
//�����Լ��
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
	int num, phyValue;//numΪ����ĸ�����phyValueΪ��ʼʱС�׵�����ֵ
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