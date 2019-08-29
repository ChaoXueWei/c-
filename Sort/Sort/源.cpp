#include<iostream>
using namespace std;
struct A 
{ 
	int a[10000];
};
int test1(int &a)
{
	return a;
}
int &test2(int& a)
{
	return a;
}
//int main()
//{
//	/*int ming = 4;
//	int &xiaoming = ming;
//	printf("%p\n", &ming);
//	printf("%p\n", &xiaoming);*/
//	//const int a = 10;
//	////int &ra = a;
//
//	//double b = 1.23;
//	//const int &rb = b;
//	int a = 3;
//	cout << test1(a) << endl;
//	cout << test2(a) << endl;
//
//	cout << (test2(a)=4) << endl;
//
//	return 0;
//}