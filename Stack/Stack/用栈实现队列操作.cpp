#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class MyQueue
{
	stack<int> m_st1;
public:
	/** Initialize your data structure here. */
	MyQueue()
	{
		
	}
	/** Push element x to the back of queue. */
	void push(int x)
	{
		//入队列
		m_st1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		stack<int> m_st2;
		//出队列
		while (!m_st1.empty())
		{
			m_st2.push(m_st1.top());
			m_st1.pop();
		}
		int tmp;
		if (!m_st2.empty())
		{
			tmp = m_st2.top();
			m_st2.pop();
		}
		while (!m_st2.empty())
		{
			m_st1.push(m_st2.top());
			m_st2.pop();
		}
		return tmp;
	}

	/** Get the front element. */
	int peek()
	{
		stack<int> m_st2;
		//出队列
		while (!m_st1.empty())
		{
			m_st2.push(m_st1.top());
			m_st1.pop();
		}
		int tmp = m_st2.top();
		while (!m_st2.empty())
		{
			m_st1.push(m_st2.top());
			m_st2.pop();
		}
		return tmp;
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return m_st1.empty();
	}
};
void stackQueueTest()
{
	queue<int> qu;
	MyQueue qu1;
	qu.push(1);
	qu1.push(1);
	cout<<qu.front()<<endl;
	cout<<qu1.peek()<<endl;
	qu.pop();
	qu1.pop();
}