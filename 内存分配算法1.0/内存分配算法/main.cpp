/*

������������1

��֯�հ��ڴ��
����հ׿�

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
const int g_minInterDeb = 5;//G��������С�ڲ���Ƭ

typedef struct memory
{
	int beginAddr;//��ʼ��ַ
	int endAddr;//������ַ
	int mmSize;//�ڴ���С
};
map<int, memory> g_IdleMemory;//�հ׷�����
//int *g_IdleMemory;
map<int, memory> g_OcuMemory;
void InitMem()
{
	int count;//�հ׷��������
	memory mm;
	cout << "����հ׷��������:" << endl;
	cin >> count;
	int errFlag = 0;
	cout << "�׵�ַ  ��С" << endl;
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
			cout << "���������������������룺" << endl;
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
//�״���Ӧ�㷨
void fristFit(int appliSize)
{
	int flag = 0;
	map<int, memory>::iterator apl;
	cout << "����ǰ�Ŀհ��ڴ��" << endl;
	showMemory();
	for (auto i : g_IdleMemory)
	{
		if (i.second.mmSize >= appliSize)
		{
			flag = 1;
			apl = g_IdleMemory.find(i.first);//�õ��״���Ӧ�հ��ڴ����׵�ַ
			break;
		}
	}
	if (flag == 0)
	{
		cout << "�ڴ����ʧ��" << endl;
		return;
	}
	if (((*apl).second.mmSize - appliSize) < g_minInterDeb)//����ʣ�಻�����G�Ĵ�С
	{
		g_IdleMemory.erase(apl);
	}
	else
	{
		(*apl).second.beginAddr += appliSize;
		(*apl).second.mmSize -= appliSize;
		//(*apl).first += appliSize;//�ı��׵�ַ
	}
	cout << "�����Ŀհ��ڴ��" << endl;
	showMemory();
}

//�����Ӧ�㷨
void bestFit(int appliSize)
{
	map<int, memory>::iterator p;
	map<int, memory*> mmsizeOrder;
	for (auto &i : g_IdleMemory)
	{
		mmsizeOrder.insert(pair<int, memory*>(i.second.mmSize,&(i.second)));
	}
	cout << "����ǰ�Ŀհ��ڴ��" << endl;
	showMemory();
	for (auto i : mmsizeOrder)
	{
		if (i.first >= appliSize)//�ҵ������Ӧ�ڴ��
		{
			p = g_IdleMemory.find((*i.second).beginAddr);
			if (((*i.second).mmSize - appliSize) < g_minInterDeb)//�������ⲿ��Ƭ�Ͳ���G�ıȽ�
			{
				g_IdleMemory.erase(p);
			}
			else
			{
				(*i.second).mmSize -= appliSize;
				(*i.second).beginAddr += appliSize;
				memory mm;//������Ҫ�Կհ��ڴ���������޸ģ�����map����g_IdleMemory�ļ�ֵ�ɸ���(����һ�δ�����ڴ��з����һ���ڴ�֮�󣬵ڶ���������ڴ��з���ռ�ʱɾ����Ƭ�ռ�ʱ���Ҳ�����Ӧ��ֵ����Ϊg_IdleMemory�������޸ĺ�ļ�ֵ)�����Ƕ��޸�ǰ�Ľ���ɾ����Ȼ��Է�����ʣ�ಿ���ڴ����в���
				mm.beginAddr = (*i.second).beginAddr;
				mm.mmSize = (*i.second).mmSize;
				mm.endAddr = mm.beginAddr + mm.mmSize;//mm��Ϊ�²����newvalue��mm.beginAddr��Ϊnewkey
				g_IdleMemory.erase(p);//ɾ���ɽڵ�
				g_IdleMemory.insert(pair<int,memory>(mm.beginAddr,mm));//����pair(newkey,value)
			}
			cout << "�����Ŀհ��ڴ��:" << endl;
			showMemory();
			return;
		}
	}
	cout << "�ڴ����ʧ�ܣ�"<<endl;
}

//�����Ӧ�㷨
void worstFit(int appliSize)
{
	map<int, memory>::iterator p;
	map<int, memory*> mmsizeOrder;
	for (auto &i : g_IdleMemory)
	{
		mmsizeOrder.insert(pair<int, memory*>(i.second.mmSize, &(i.second)));//�����г�����ͬ��key������û��ϵ���ڶ���key�����벻Ӱ�죬��������ͬ��ʱ��Ĭ�Ϸ����һ��ƥ�䵽���ڴ��
	}
	cout << "����ǰ�Ŀհ��ڴ��" << endl;
	showMemory();
	map<int, memory*>::iterator pp=mmsizeOrder.end();
	pp--;
	if (pp->second->mmSize < appliSize)
	{
		cout << "�ڴ����ʧ�ܣ�" << endl;
		return;
	}
	else
	{
		if ((pp->second->mmSize - appliSize) < g_minInterDeb)//ʣ���ڴ��Ͳ���G�Ƚ�
		{
			g_IdleMemory.erase(pp->second->beginAddr);//ɾ����ֵΪpp->second->beginAddr��Ԫ��
		}
		else
		{
			p=g_IdleMemory.find(pp->second->beginAddr);//����Ҫɾ���Ľڵ㣬����ɾ��
			pp->second->mmSize -= appliSize;
			pp->second->beginAddr += appliSize;
			memory mm;
			mm.beginAddr = pp->second->beginAddr;
			mm.mmSize = pp->second->mmSize;
			mm.endAddr = mm.beginAddr + mm.mmSize;//mm��Ϊ�²����newvalue��mm.beginAddr��Ϊnewkey
			g_IdleMemory.erase(p);//ɾ���ɽڵ�
			g_IdleMemory.insert(pair<int, memory>(mm.beginAddr, mm));//����pair(newkey,value)
		}
		cout << "�������ڴ��" << endl;
		showMemory();
	}
}

//�״�ѭ����Ӧ�㷨
void cycleFirstFit(int application)
{

}
int main()
{
	int appliSize;
	InitMem();
	while (1)
	{
		cout << "������Ҫ������ڴ��С��";
		cin >> appliSize;
		//fristFit(appliSize);
		//bestFit(appliSize);
		worstFit(appliSize);
	}
	return 0;
}
#endif