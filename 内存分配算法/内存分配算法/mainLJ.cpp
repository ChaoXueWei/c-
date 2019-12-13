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
	void init_oldlist(Memory tmp,int num)//为判断初始化格式是否正确
	{
		oldlist.push_back(tmp);
		if(num==0)
		{
			cout<<"初始化完成"<<endl;
			newlist=oldlist;
			this->tmp=newlist.begin();
		}

	}
	void Showoldlist()
	{
		cout<<"***********开始时链表状态************"<<endl;
		for(auto it=oldlist.begin();it!=oldlist.end();++it)
		{
			cout<<"首地址:"<<it->head<<"  空间大小:"<<it->size<<"  尾地址:"<<it->tail<<endl;
		}
		cout<<"***********结束时链表状态************"<<endl;
		for(auto it=newlist.begin();it!=newlist.end();++it)
		{
			cout<<"首地址:"<<it->head<<"  空间大小:"<<it->size<<"  尾地址:"<<it->tail<<endl;
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
			cout<<"分配失败"<<endl;
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
			cout<<"分配失败"<<endl;
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
			cout<<"分配失败"<<endl;
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
			cout<<"分配失败"<<endl;
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
	cout<<"***********功能列表:***********"<<endl;
	cout<<"1.初始化空白分区大小"<<endl;
	cout<<"2.首次适应算法（First Fit）"<<endl;
	cout<<"3.循环首次适应算法（Next Fit）"<<endl;
	cout<<"4.最佳适应算法（Best Fit）"<<endl;
	cout<<"5.最坏适应算法（Worst Fit）"<<endl;
	cout<<"6.显示空白分区链"<<endl;
	cout<<"0.退出"<<endl;
	while(1)
	{
		int x;
		cin>>x;
		switch(x)
		{
		case 1:
			int num;
			cout<<"请输入空白分区的个数:";
			cin>>num;
			while(num--)
			{
				Memory tmp;
				cout<<"输入首地址：";
				cin>>tmp.head;
				cout<<"输入大小：";
				cin>>tmp.size;
				tmp.tail=tmp.head+tmp.size;
				MA.init_oldlist(tmp,num);
			}
			break;
		case 2:
			cout<<"输入分配空间的大小:";
			int size1;
			cin>>size1;
			MA.First_Fit(size1);
			break;
		case 3:
			cout<<"输入分配空间的大小:";
			int size2;
			cin>>size2;
			MA.Next_Fit(size2);
			break;
		case 4:
			cout<<"输入分配空间的大小:";
			int size3;
			cin>>size3;
			MA.Best_Fit(size3);
		case 5:
			cout<<"输入分配空间的大小:";
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