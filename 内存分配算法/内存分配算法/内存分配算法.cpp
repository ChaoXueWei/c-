#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;
#if 0
int const MAX = 1024;//ʹ�ô����ڴ��С
int SIZE[MAX];//tip:��ʼλ��Ϊ0;
class subAreaNode
{
public:
	int addr;// ��ʼ��ַ
	int end;//��ֹ��ַ
	int size;// ������С
	string taskId;// ��ҵ��
};
class NULLArea
{
public:
	int ID;
	int size;
	int begin;
	int end;
};
list<subAreaNode>s;
list<NULLArea>n;
bool comp_BestFit(const NULLArea &lhs, const NULLArea &rhs)
{
	return lhs.size < rhs.size;
}
bool comp_WorstFit(const NULLArea &lhs, const NULLArea &rhs)
{
	return lhs.size > rhs.size;
}
int Fitcount = 1;
string Fitstring = "Fit";
void cleansize()
{
	for (int i = 0; i < MAX; i++)
		SIZE[i] = 0;
}
subAreaNode setsize(int addr, int size, string taskId)
{
	subAreaNode a;
	for (int i = addr; i < size + addr; i++)
	{
		SIZE[i] = 1;
	}
	a.addr = addr;
	a.size = size;
	a.taskId = taskId;
	a.end = addr + size - 1;
	return a;
}
NULLArea setNULLarea(int begin, int end, int size, int ID)
{
	NULLArea b;
	b.begin = begin;
	b.end = end;
	b.size = size;
	b.ID = ID;
	return b;
}
void ShowAllsubAreaNode()
{
	cout << "������ռ���ڴ������" << endl;
	if (s.size() == 0)
	{
		cout << "tip:�ڴ���û�н���" << endl;
		cout << "��ʼ��ַΪ0";
		cout << "��ֹ��ַΪ" << MAX - 1 << endl;
		return;
	}
	cout << setw(6) << "begin" << setw(6) << "end" << setw(6) << "size" << setw(6) << "ID" << setw(6) << endl;
	for each (subAreaNode a in s)
	{
		cout << setw(6) << a.addr << setw(6) << a.end << setw(6) << a.size << setw(6) << a.taskId << endl;
	}
}
void ShowAllNullArea()
{
	cout << "�����ڴ���(ID������С�����˳������)" << endl;
	if (n.size() == 0)
	{
		cout << "�ڴ����޿�������";
		return;
	}
	cout << setw(6) << "begin" << setw(6) << "end" << setw(6) << "size" << setw(6) << "ID" << endl;
	for each (NULLArea a  in n)
	{
		cout << setw(6) << a.begin << setw(6) << a.end << setw(6) << a.size << setw(6) << a.ID << endl;
	}
}
void loadNullArea()
{
	n.clear();//
	int number = 1;
	int c, i;
	for (i = 0; i < MAX; i++)
	{
		if (SIZE[i] == 0)
		{
			for (c = i; c < MAX; c++)
			{
				if (SIZE[c] == 1)
				{

					n.push_back(setNULLarea(i, c - 1, c - i, number));
					number++;
					i = c;
					break;
				}
				if ((c == MAX - 1) && (SIZE[c] == 0))
				{
					n.push_back(setNULLarea(i, c - 1, c - i, number));
					number++;
					return;
				}
			}
		}
	}
}
bool cleanAREA(string taskID)
{
	list<subAreaNode>::iterator itor;
	for (itor = s.begin(); itor != s.end(); itor++)
	{
		if (itor->taskId == taskID)
		{
			for (int i = itor->addr; i < itor->addr + itor->size; i++)
			{
				SIZE[i] = 0;
			}
			itor = s.erase(itor);
			return true;
		}
	}
	if (s.end()->taskId == taskID)
	{
		for (int i = s.end()->addr; i < s.end()->size; i++)
		{
			SIZE[i] = 0;
		}
		s.erase(s.end());
		return true;
	}
	return false;
}
subAreaNode searchAreaNode(int addr, int size)
{
	subAreaNode a;
	ostringstream ss;
	string taskID;
	ss << Fitstring << Fitcount;
	Fitcount++;
	taskID = ss.str();
	for (int i = addr; i < size + addr; i++)
	{
		SIZE[i] = 1;
	}
	a.addr = addr;
	a.size = size;
	a.taskId = taskID;
	a.end = addr + size - 1;
	return a;
}
bool searchNullArea(int a)
{
	list<NULLArea>::iterator itor;
	for (itor = n.begin(); itor != n.end(); ++itor)
	{
		if (itor->size >= a)
		{
			for (int i = itor->begin; i < itor->begin + a; i++)
			{
				SIZE[i] = 1;
			}
			s.push_back(searchAreaNode(itor->begin, a));
			itor->begin = itor->begin + a;
			itor->size = itor->size - a;
			return true;
		}
	}
	return false;
}
bool searchNullArea(int a, int &number)//Ϊnextfit���صĺ���
{
	list<NULLArea>::iterator itor;
	for (itor = n.begin(); itor != n.end(); ++itor)
	{
		if (itor->size >= a)
		{
			for (int i = itor->begin; i < itor->begin + a; i++)
			{
				SIZE[i] = 1;
			}
			number = itor->ID;
			s.push_back(searchAreaNode(itor->begin, a));
			itor->begin = itor->begin + a;
			itor->size = itor->size - a;
			return true;
		}
	}
	return false;
}
void sortforNextFit(int &number)
{
	while (number != n.begin()->ID)
	{
		n.push_back(n.front());
		n.pop_front();
	}
}
void firstFit()
{
	cout << "------------First Fit------------------" << endl;
	while (1)
	{
		loadNullArea();
		ShowAllsubAreaNode();
		cout << "����ǰ���õĿռ��ڴ����������" << endl;
		ShowAllNullArea();
		int a, b;
		cout << "������Ҫ����ĵ�ַ�ռ�" << endl;
		cin >> a;
		bool c;
		c = searchNullArea(a);
		if (c == true)	cout << "����ɹ�";
		else cout << "����ʧ�ܣ�û�п��ÿռ䣡";
		cout << "��ǰ�շ���������" << endl;
		ShowAllNullArea();
		cout << "�Ƿ��������?0�˳���������";
		cin >> b;
		if (b == 0) break;
	}
	cout << "�˳�First Fit��" << endl;
}
void bestFit()
{
	cout << "--------------Best Fit-----------------" << endl;
	while (1)
	{
		loadNullArea();
		ShowAllsubAreaNode();
		n.sort(comp_BestFit);
		cout << "����ǰ���õĿռ��ڴ����������" << endl;
		ShowAllNullArea();
		int a, b;
		cout << "������Ҫ����ĵ�ַ�ռ�" << endl;
		cin >> a;
		bool c;
		c = searchNullArea(a);
		if (c == true)	cout << "����ɹ�";
		else cout << "����ʧ�ܣ�û�п��ÿռ䣡";
		cout << "��ǰ�շ���������" << endl;
		ShowAllNullArea();
		cout << "�Ƿ��������?������0�˳�������ֵ����";
		cin >> b;
		if (b == 0) break;
	}
	cout << "�˳�Best Fit��" << endl;
}
void worstFit()
{
	cout << "--------------Worst Fit----------------" << endl;
	while (1)
	{
		loadNullArea();
		ShowAllsubAreaNode();
		n.sort(comp_WorstFit);
		cout << "����ǰ���õĿռ��ڴ����������" << endl;
		ShowAllNullArea();
		int a, b;
		cout << "������Ҫ����ĵ�ַ�ռ�" << endl;
		cin >> a;
		bool c;
		c = searchNullArea(a);
		if (c == true)	cout << "����ɹ�";
		else cout << "����ʧ�ܣ�û�п��ÿռ䣡";
		cout << "��ǰ�շ���������" << endl;
		ShowAllNullArea();
		cout << "�Ƿ��������?������0�˳�������ֵ����";
		cin >> b;
		if (b == 0) break;
	}
	cout << "�˳�Worst Fit��" << endl;
}
void nextFit()
{
	cout << "--------------next  Fit----------------" << endl;
	int number = 1;
	int count;
	while (1)
	{
		loadNullArea();
		count = n.size();
		if (number > count)
		{
			number = 1;
		}
		sortforNextFit(number);
		ShowAllsubAreaNode();
		cout << "------------------------------------------------" << endl;
		cout << "����ѭ���״���Ӧ�㷨���δӵ�" << number << "�鿪ʼѰ��" << endl;
		cout << "����ǰ���õĿռ��ڴ����������" << endl;
		ShowAllNullArea();
		int a, b;
		cout << "������Ҫ����ĵ�ַ�ռ�" << endl;
		cin >> a;
		bool c;
		c = searchNullArea(a, number);
		number++;
		if (c == true)
		{
			if (number > count)
			{
				number = 1;
			}
			cout << "����ɹ����´ν���ӵ�" << number << "�鿪ʼ����";
		}
		else cout << "����ʧ�ܣ�û�п��ÿռ䣡";
		cout << "��ǰ�շ���������" << endl;
		ShowAllNullArea();
		cout << "�Ƿ��������?������0�˳�������ֵ����";
		cin >> b;
		if (b == 0)
		{
			int d;
			cout << "����:����˳�Next Fit �´�Ѱ�ҽ����1��ʼ.";
			cout << "ȷ���˳����ٴ�����0������0�˳�������ֵ����:";
			cin >> d;
			if (d == 0) break;
		}

	}
	cout << "�˳�Next Fit��" << endl;
}
int main()
{
	cleansize();//���
	while (1)
	{
		loadNullArea();
		int a;
		system("cls");
		cout << "��������Ҫ���е��㷨����Ҫ���еĲ���\n"
			"1.�����ڴ�\n""2.�����ڴ�\n""3.First Fit\n""4.Next Fit\n""5.Best Fir\n""6.Worst Fit\n""7.clean size(ɾ��ȫ������)\n""8.show details\n""9.exit\n";
		cout << "�����룺";
		cin >> a;
		if (a == 1)
		{
			ShowAllsubAreaNode();//��ӡ��ռ���ڴ�
			if (n.size() != 0)
			{
				int addr, size;
				string taskId;
				cout << "��������̿�ʼ��ַ(������-1ֱ�ӷ���):";
				cin >> addr;
				if (addr == -1)  continue;
				cout << "�������ڴ��С:";
				cin >> size;
				cout << "��������ҵ��(����ʹ��Fit��Ϊ��ͷ):";
				cin >> taskId;
				s.push_back(setsize(addr, size, taskId));
				loadNullArea();
				cout << "����ɹ�" << endl;
			}
			else cout << "�޿��÷���ռ䣡" << endl;
			system("pause");
		}
		if (a == 2)
		{
			ShowAllsubAreaNode();
			string taskId;
			cout << "��������ҵ��(������-1ֱ�ӷ���):";
			cin >> taskId;
			if (taskId == "-1") continue;
			cleanAREA(taskId);
			system("pause");
		}
		if (a == 3)
		{
			firstFit();
			system("pause");
		}
		if (a == 4)
		{
			nextFit();
			system("pause");
		}
		if (a == 5)
		{
			bestFit();
			system("pause");
		}
		if (a == 6)
		{
			worstFit();
			system("pause");
		}
		if (a == 7)
		{
			int a7; cout << "ȷ��ɾ��ô?����0ɾ��\n������:"; cin >> a7;
			if (a7 != 0) continue;
			s.clear();
			n.clear();
			cleansize();
			Fitcount = 0;
			cout << "����ɹ�";
			system("pause");
		}
		if (a == 8)
		{
			int num = 0;
			for (int i = 0; i < MAX; i++)
				cout << SIZE[i];
			for (int i = 0; i < MAX; i++)
			{
				if (SIZE[i] == 1)
				{
					num++;
				}
			}
			cout << num << endl;
			system("pause");
		}
		if (a == 9)
		{
			exit(0);
			system("pause");
		}
	}
	return 0;
}
#endif