/*

输入空闲链表块1

组织空白内存块
分配空白块

*/
#if 01

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;
const int mmIDSize = 20;
const int g_minInterDeb = 5;//G参数，最小内部碎片

typedef struct memory
{
	int beginAddr;//起始地址
	int endAddr;//结束地址
	int mmSize;//内存块大小
};
map<int, memory> g_IdleMemory;//空白分区链
//int *g_IdleMemory;
map<int, memory> g_OcuMemory;
void InitMem()
{
	int count;//空白分区块个数
	memory mm;
	cout << "输入空白分区块个数:" << endl;
	cin >> count;
	int errFlag = 0;
	cout << "首地址  大小" << endl;
	map<int, memory>::iterator pp;
	while (count--)
	{
		errFlag = 0;
		cin >> mm.beginAddr >> mm.mmSize;
		mm.endAddr = mm.beginAddr + mm.mmSize;
		g_IdleMemory.insert(pair<int, memory>(mm.beginAddr, mm));
		/*pp=g_IdleMemory.find(mm.beginAddr);
		map<int, memory>::iterator pre=--pp;
		pp++;
		pp++;
		map<int, memory>::iterator next=pp;
		if (pre->second.endAddr >= mm.beginAddr || next->second.beginAddr <= mm.endAddr)
		{
			cout << "分区输入有误，请重新输入：" << endl;
			count++;
			g_IdleMemory.erase(mm.beginAddr);
		}*/
	}
}
void showMemory()
{
	cout << "beginaddr " << "mmsize " << "endaddr" << endl;
	for (auto i : g_IdleMemory)
	{
		cout << setw(9) << i.second.beginAddr << " " << setw(6) << i.second.mmSize << " " << setw(7) << i.second.endAddr << endl;
	}
}
//首次适应算法
void fristFit(int appliSize)
{
	int flag = 0;
	map<int, memory>::iterator apl;
	cout << "分配前的空白内存表：" << endl;
	showMemory();
	for (auto i : g_IdleMemory)
	{
		if (i.second.mmSize >= appliSize)
		{
			flag = 1;
			apl = g_IdleMemory.find(i.first);//拿到首次适应空白内存块的首地址
			break;
		}
	}
	if (flag == 0)
	{
		cout << "内存分配失败" << endl;
		return;
	}
	if (((*apl).second.mmSize - appliSize) < g_minInterDeb)//块内剩余不足参数G的大小
	{
		g_IdleMemory.erase(apl);
	}
	else
	{
		(*apl).second.beginAddr += appliSize;
		(*apl).second.mmSize -= appliSize;
		//(*apl).first += appliSize;//改变首地址
	}
	cout << "分配后的空白内存表：" << endl;
	showMemory();
}

//最佳适应算法
void bestFit(int appliSize)
{
	map<int, memory>::iterator p;
	map<int, memory*> mmsizeOrder;
	for (auto &i : g_IdleMemory)
	{
		mmsizeOrder.insert(pair<int, memory*>(i.second.mmSize,&(i.second)));
	}
	cout << "分配前的空白内存表：" << endl;
	showMemory();
	for (auto i : mmsizeOrder)
	{
		if (i.first >= appliSize)//找到最佳适应内存块
		{
			p = g_IdleMemory.find((*i.second).beginAddr);
			if (((*i.second).mmSize - appliSize) < g_minInterDeb)//产生的外部碎片和参数G的比较
			{
				g_IdleMemory.erase(p);
			}
			else
			{
				(*i.second).mmSize -= appliSize;
				(*i.second).beginAddr += appliSize;
				memory mm;//这里需要对空白内存链表进行修改，但是map容器g_IdleMemory的键值可改吗(当第一次从这块内存中分配掉一块内存之后，第二次在这块内存中分配空间时删除这片空间时，找不到对应键值，因为g_IdleMemory不存在修改后的键值)？我们对修改前的进行删除，然后对分配后的剩余部分内存块进行插入
				mm.beginAddr = (*i.second).beginAddr;
				mm.mmSize = (*i.second).mmSize;
				mm.endAddr = mm.beginAddr + mm.mmSize;//mm作为新插入的newvalue，mm.beginAddr作为newkey
				g_IdleMemory.erase(p);//删除旧节点
				g_IdleMemory.insert(pair<int,memory>(mm.beginAddr,mm));//插入pair(newkey,value)
			}
			cout << "分配后的空白内存表:" << endl;
			showMemory();
			return;
		}
	}
	cout << "内存分配失败！"<<endl;
}

//最差适应算法
void worstFit(int appliSize)
{
	map<int, memory>::iterator p;
	map<int, memory*> mmsizeOrder;
	for (auto &i : g_IdleMemory)
	{
		mmsizeOrder.insert(pair<int, memory*>(i.second.mmSize, &(i.second)));//这里有出现相同的key，不过没关系，第二个key不插入不影响，即出现相同的时会默认分配第一个匹配到的内存块
	}
	cout << "分配前的空白内存表：" << endl;
	showMemory();
	map<int, memory*>::iterator pp=mmsizeOrder.end();
	pp--;
	if (pp->second->mmSize < appliSize)
	{
		cout << "内存分配失败！" << endl;
		return;
	}
	else
	{
		if ((pp->second->mmSize - appliSize) < g_minInterDeb)//剩余内存块和参数G比较
		{
			g_IdleMemory.erase(pp->second->beginAddr);//删除键值为pp->second->beginAddr的元素
		}
		else
		{
			p=g_IdleMemory.find(pp->second->beginAddr);//保存要删除的节点，后面删除
			pp->second->mmSize -= appliSize;
			pp->second->beginAddr += appliSize;
			memory mm;
			mm.beginAddr = pp->second->beginAddr;
			mm.mmSize = pp->second->mmSize;
			mm.endAddr = mm.beginAddr + mm.mmSize;//mm作为新插入的newvalue，mm.beginAddr作为newkey
			g_IdleMemory.erase(p);//删除旧节点
			g_IdleMemory.insert(pair<int, memory>(mm.beginAddr, mm));//插入pair(newkey,value)
		}
		cout << "分配后的内存表：" << endl;
		showMemory();
	}
}

//首次循环适应算法
void cycleFirstFit(int application)
{

}
int main()
{
	int appliSize;
	InitMem();
	while (1)
	{
		cout << "请输入要申请的内存大小：";
		cin >> appliSize;
		//fristFit(appliSize);
		//bestFit(appliSize);
		worstFit(appliSize);
	}
	return 0;
}
#endif