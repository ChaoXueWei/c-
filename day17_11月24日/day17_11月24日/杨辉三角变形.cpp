#include <iostream>
#include <vector>
using namespace std;
//找n行第一个偶数
//以0开始，以0结束
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
	data.push_back(1);//data( 0 0 1 )第一行over
	data.resize(n * 2 + 1);//多两个空间用来防止访问越界
	//填写公式a[i]=a[i-1]+a[i-2]+a[i];第一个数需要前面两个 0
	for (i = 2; i <= n; i++)
	{
		tmp.clear();
		tmp.push_back(0);
		tmp.push_back(0);//填写时方式越界访问
		for (j = 2; j < i * 2 + 1; j++)//0 0 后续需要填写2*i-1个数
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
//总结，当vector.resize()分配好空间大小之后，将另一个容器tmp给其‘=’方式（会改变data的大小）复制之后，data的大小改变为tmp的大小，

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