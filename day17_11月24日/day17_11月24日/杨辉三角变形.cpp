#include <iostream>
#include <vector>
using namespace std;
//��n�е�һ��ż��
//��0��ʼ����0����
//1 3 5 7 9
//2n-1
#if 0
int test(int n)
{
	vector<int> data;
	vector<int> tmp;
	int i = 0;
	int j = 0;
	int k = 0;
	int pos = -1;
	data.push_back(0);
	data.push_back(0);
	data.push_back(1);//data( 0 0 1 )��һ��over
	data.resize(n * 2 + 1);//�������ռ�������ֹ����Խ��
	//��д��ʽa[i]=a[i-1]+a[i-2]+a[i];��һ������Ҫǰ������ 0
	for (i = 2; i <= n; i++)
	{
		tmp.clear();
		tmp.push_back(0);
		tmp.push_back(0);//��дʱ��ʽԽ�����
		for (j = 2; j < i * 2 + 1; j++)//0 0 ������Ҫ��д2*i-1����
		{
			tmp.push_back(data[j - 1] + data[j - 2] + data[j]);
		}
		for (k = 0; k < tmp.size(); k++)
		{
			data[k] = tmp[k];
			//cout << tmp[k] << ' ';
		}
		//cout << endl;
	}
	for (k = 2; k < data.size(); k++)
	{
		if (data[k] % 2 == 0)
		{
			pos = k - 1;
			break;
		}
	}
	return pos;
}
int main()
{
	int n;
	int pos = 0;
	while (cin>>n)
	{
		pos = test(n);
		cout << pos << endl;
	}
	return 0;
}
#endif
//�ܽᣬ��vector.resize()����ÿռ��С֮�󣬽���һ������tmp���䡮=����ʽ����ı�data�Ĵ�С������֮��data�Ĵ�С�ı�Ϊtmp�Ĵ�С��

//struct A
//{
//	long long a;
//	char *ch[32];
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	return 0;
//} 