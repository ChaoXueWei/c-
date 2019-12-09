#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
#if 0
typedef struct Memory
{
	int size;
	int head;
	int tail;
}Memory;

bool compare(const Memory &a, const Memory &b)
{
	return a.head < b.head;
}

bool comparelarge(const Memory &a, const Memory &b)
{
	return a.size< b.size;
}

bool compareless(const Memory &a, const Memory &b)
{
	return a.size> b.size;
}

class MemoryAllocation
{
public:
	MemoryAllocation(){}
	void init_oldlist(Memory tmp,int num)//Ϊ�жϳ�ʼ����ʽ�Ƿ���ȷ
	{
		oldlist.push_back(tmp);
		if(num==0)
		{
			cout<<"��ʼ�����"<<endl;
			newlist=oldlist;
			this->tmp=newlist.begin();
		}

	}
	void Showoldlist()
	{
		cout<<"***********��ʼʱ����״̬************"<<endl;
		for(auto it=oldlist.begin();it!=oldlist.end();++it)
		{
			cout<<"�׵�ַ:"<<it->head<<"  �ռ��С:"<<it->size<<"  β��ַ:"<<it->tail<<endl;
		}
		cout<<"***********����ʱ����״̬************"<<endl;
		for(auto it=newlist.begin();it!=newlist.end();++it)
		{
			cout<<"�׵�ַ:"<<it->head<<"  �ռ��С:"<<it->size<<"  β��ַ:"<<it->tail<<endl;
		}
	}
	void First_Fit(int size)
	{
		newlist.sort(compare);
		bool flag=false;
		for(auto it=newlist.begin();it!=newlist.end();++it)
		{
			if(it->size>=size)
			{
				it->size-=size;
				it->tail-=size;
				flag=true;
				if(it->size==0)
				{
					it=newlist.erase(it);
				}
				break;
			}
		}
		if(flag==false)
		{
			cout<<"����ʧ��"<<endl;
		}
	}
	void Next_Fit(int size)
	{
		newlist.sort(compare);
		bool flag=false;
		auto it=this->tmp;
		for(;it!=newlist.end();++it)
		{
			if(it->size>=size)
			{
				it->size-=size;
				it->tail-=size;
				flag=true;
				if(it->size==0)
				{
					it=newlist.erase(it);
				}
				this->tmp=it;
				break;
			}
		}
		if(it==newlist.end())
		{
			for(auto it=newlist.begin();it!=this->tmp;++it)
			{
				if(it->size>=size)
				{
					it->size-=size;
					it->tail-=size;
					flag=true;
					if(it->size==0)
					{
						it=newlist.erase(it);
					}
					this->tmp=it;
					break;
				}
			}
		}
		if(flag==false)
		{
			cout<<"����ʧ��"<<endl;
		}
	}
	void Best_Fit(int size)
	{
		newlist.sort(comparelarge);
		bool flag=false;
		for(auto it=newlist.begin();it!=newlist.end();++it)
		{
			if(it->size>=size)
			{
				it->size-=size;
				it->tail-=size;
				flag=true;
				if(it->size==0)
				{
					it=newlist.erase(it);
				}
				break;
			}
		}
		if(flag==false)
		{
			cout<<"����ʧ��"<<endl;
		}
	}
	void Worst_Fit(int size)
	{
		newlist.sort(compareless);
		bool flag=false;
		for(auto it=newlist.begin();it!=newlist.end();++it)
		{
			if(it->size>=size)
			{
				it->size-=size;
				it->tail-=size;
				flag=true;
				if(it->size==0)
				{
					it=newlist.erase(it);
				}
				break;
			}
		}
		if(flag==false)
		{
			cout<<"����ʧ��"<<endl;
		}
	}
private:
	list<Memory> oldlist;
	list<Memory> newlist;
	list<Memory>::iterator tmp;
};

int main()
{
	MemoryAllocation MA;
	cout<<"***********�����б�:***********"<<endl;
	cout<<"1.��ʼ���հ׷�����С"<<endl;
	cout<<"2.�״���Ӧ�㷨��First Fit��"<<endl;
	cout<<"3.ѭ���״���Ӧ�㷨��Next Fit��"<<endl;
	cout<<"4.�����Ӧ�㷨��Best Fit��"<<endl;
	cout<<"5.���Ӧ�㷨��Worst Fit��"<<endl;
	cout<<"6.��ʾ�հ׷�����"<<endl;
	cout<<"0.�˳�"<<endl;
	while(1)
	{
		int x;
		cin>>x;
		switch(x)
		{
		case 1:
			int num;
			cout<<"������հ׷����ĸ���:";
			cin>>num;
			while(num--)
			{
				Memory tmp;
				cout<<"�����׵�ַ��";
				cin>>tmp.head;
				cout<<"�����С��";
				cin>>tmp.size;
				tmp.tail=tmp.head+tmp.size;
				MA.init_oldlist(tmp,num);
			}
			break;
		case 2:
			cout<<"�������ռ�Ĵ�С:";
			int size1;
			cin>>size1;
			MA.First_Fit(size1);
			break;
		case 3:
			cout<<"�������ռ�Ĵ�С:";
			int size2;
			cin>>size2;
			MA.Next_Fit(size2);
			break;
		case 4:
			cout<<"�������ռ�Ĵ�С:";
			int size3;
			cin>>size3;
			MA.Best_Fit(size3);
		case 5:
			cout<<"�������ռ�Ĵ�С:";
			int size4;
			cin>>size4;
			MA.Best_Fit(size4);
		case 6:
			MA.Showoldlist();
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}
#endif