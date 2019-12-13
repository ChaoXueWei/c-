/*

������������1

��֯�հ��ڴ��
����հ׿�

*/
#if 1
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
		//����������жϣ���ֹ������������ 0 100  50  30�����ڴ��ͻ�����
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
/*
�и����⣬���ڴ�����ֻ�ı���value��beginddr,��Ȼ��Ӱ�����ͨ�㷨�ķ��䣬���Ǻ��滻һ���㷨����ʱ�п��ܳ���
��û��ǽ�keyֵҲ�ı䣨ɾ���ٲ��룩��
*/
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
void cycleFirstFit(int appliSize)
{
	//���ҵ���һ����Ȼ����
	static map<int, memory>::iterator start_p = g_IdleMemory.begin();
	map<int, memory>::iterator pp = start_p;
	int i = g_IdleMemory.size();
	int mmflag = 0;
	cout << "����ǰ�Ŀհ��ڴ��" << endl;
	showMemory();
	for (; i >= 0;i--)
	{
		if (pp->second.mmSize >= appliSize)
		{
			mmflag = 1;
			if ((pp->second.mmSize - appliSize) >= g_minInterDeb)
			{
				pp->second.mmSize -= appliSize;
				pp->second.beginAddr += appliSize;
			}
			else
			{
				pp=g_IdleMemory.erase(pp);
				if (pp != g_IdleMemory.end())
				{
					break;
				}
			}
			/*if (pp == g_IdleMemory.end())
			{
			pp = g_IdleMemory.begin();
			}*/
		}
		if (pp != g_IdleMemory.end())
		{
			pp++;
			if (pp == g_IdleMemory.end())
			{
				pp = g_IdleMemory.begin();
			}
		}
		else
		{
			pp = g_IdleMemory.begin();
		}
		if (mmflag == 1)
		{
			break;
		}
	}
	start_p = pp;
	if (mmflag == 0)//����ʧ��
	{
		cout << "����ʧ��!" << endl;
	}
	else
	{
		cout << "�������ڴ��" << endl;
		showMemory();
	}
}
int menu()
{
	int clect;
	cout << "***********************************" << endl;
	cout << "********     1.FirstFit    ********" << endl;
	cout << "********     2.CycFirFit   ********" << endl;
	cout << "********     3.BestFit     ********" << endl;
	cout << "********     4.WorstFit    ********" << endl;
	cout << "********     0.Exit        ********" << endl;
	cout << "***********************************" << endl;
	cout << "Please enter your choice:" ;
	while (cin >> clect)
	{
		if (clect >= 0 && clect <= 4)
		{
			return clect;
		}
		else
		{
			cout << "����ʧ�ܣ����������룺";
		}
	}
	return clect;
}
int main()
{
	int appliSize;
	InitMem();
	int select;
	while (1)
	{
		select = menu();
		cout << "������Ҫ������ڴ��С��";
		cin >> appliSize;
		switch (select)
		{
		case 1 :
			fristFit(appliSize);
			break;
		case 2:
			cycleFirstFit(appliSize);
			break;
		case 3:
			bestFit(appliSize);
			break;
		case 4:
			worstFit(appliSize);
			break;
		case 0:
			exit(0);
			break;
		default:
			//
		}
	}
	return 0;
}
#endif