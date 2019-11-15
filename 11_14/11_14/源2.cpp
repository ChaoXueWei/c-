#include <iostream>
#include <cstdio>
using namespace std;



#if 1

/*
函数重写，虚函数调用
*/
class A
{
public:
	A() :m_ival(0)
	{
		test();
	}
	virtual void func()
	{
		cout << m_ival << " ";
	}
	void test()
	{
		func();
	}

public:
	int m_ival;
};
class B :public A
{
public:
	B()
	{
		test();
	}
	virtual void func()
	{
		++m_ival;
		cout << m_ival << " ";
	}
};
int main()
{
	A*p = new B;
	p->test();
	return 0;
}
#endif


#if 0

/*
||和&&运算符问题
*/
int main()
{
	int a = 1, b =0 , c = -1, d = 0;
	d = ++a || ++b && ++c;
	cout << d << endl;
	return 0;
}
#endif

#if 0

/*
if else的使用
*/
int main()
{
	int a = 1, b = 2, c = 3, d = 0;
	if (a == 1 && b++ == 2)
	if (b!=2||c--!=3)
		printf("%d,%d,%d\n", a, b, c);
	else
		printf("%d,%d.%d\n", a, b, c);
	else
		printf("%d,%d.%d\n", a, b, c);
	return 0;
}
#endif