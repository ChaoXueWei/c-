#include<iostream>
#include<stack>
using namespace std;
class MinStack
{
	stack<int> m_st;
	stack<int> min_st;
public:
	/** initialize your data structure here. */
	MinStack()
	{

	}

	void push(int x)
	{
		m_st.push(x);
		if (min_st.size() == 0||min_st.top() >= x)
		{
			min_st.push(x);
		}
	}

	void pop()
	{
		int tmp = m_st.top();
		m_st.pop();
		if (min_st.top() == tmp)
		{
			min_st.pop();
		}
	}

	int top()
	{
		return m_st.top();
	}

	int getMin()
	{
		return min_st.top();
	}
};

//int main()
//{
//	MinStack minStack;
//	minStack.push(-3);
//	minStack.push(-2);
//	minStack.push(0);
//	minStack.push(-3);
//	cout<<minStack.getMin()<<endl;
//	minStack.pop();
//	cout<<minStack.top()<<endl;      
//	cout<<minStack.getMin()<<endl; 
//
//	return 0;
//}