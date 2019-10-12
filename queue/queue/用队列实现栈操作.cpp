#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class MyStack
{
	queue<int> m_qu;
public:
	/** Initialize your data structure here. */
	MyStack()
	{

	}

	/** Push element x onto stack. */
	void push(int x)
	{
		m_qu.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		queue<int> qu;
		while (m_qu.size()>1)
		{
			qu.push(m_qu.front());
			m_qu.pop();
		}
		int tmp = m_qu.front();
		m_qu = qu;//和用栈实现队列不同，这里可以直接拷贝构造，不影响其中元素的相对位置
		return tmp;
	}
	/** Get the top element. */
	int top()
	{
		queue<int> qu;
		while (m_qu.size() > 1)
		{
			qu.push(m_qu.front());
			m_qu.pop();
		}
		int tmp = m_qu.front();
		qu.push(m_qu.front());
		m_qu = qu;
		return tmp;
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return m_qu.empty();
	}
};
void queueStackTest()
{
	stack<int> qu1;
	MyStack qu2;
	qu1.push(1);
	qu2.push(1);
	cout << qu1.top() << endl;
	cout << qu2.top() << endl;
	qu1.pop();
	qu2.pop();
}
//int main()
//{
//	queueStackTest();
//	return 0;
//}
