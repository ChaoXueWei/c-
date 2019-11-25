#include <iostream>
#include <cstdio>
using namespace std;
#if 0
//template<class T>
//struct sum
//{
//	static void foo(T op1, T op2)
//	{
//		cout << op1<<op2;
//	}
//};
//sum<int>::foo(1, 3);

class A
{
public:
	A()
	{
		p();
	}
	virtual void p()
	{
		cout << 'A';
	}
	virtual ~A()
	{
		p();
	}
};
class B : public A
{
public:
	B()
	{
		p();
	}
	void p()
	{
		cout << 'B';
	}
	~B()
	{
		p();
	}
};
int main()
{
	/*long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);*/
	A *a = new B();
	delete a;
	return 0;
}
#endif