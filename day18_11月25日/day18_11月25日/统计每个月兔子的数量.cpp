#include <iostream>
using namespace std; 
#if 0
//쳲����������⡣��̬�滮����
int getTotalCount(int monthCount)
{
	if (monthCount <= 2)
	{
		return 1;
	}
	return getTotalCount(monthCount - 1) + getTotalCount(monthCount - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << getTotalCount(n)<<endl;
	}
	return 0;
}
#endif