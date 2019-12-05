/*
����ϵͳ���̵����㷨ʵ�֣�
�ļ�״̬��ʵ�ֻ������ܣ��ռ估ʱ�临�Ӷ��д��Ż�
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <list>
#include <queue>
using namespace std;
const int JOB_NAEM_MAX = 20;//��������
typedef struct process
{
	char m_num[JOB_NAEM_MAX];//���̱��
	int m_ArrivalT;//����ʱ��
	int m_ServiceT;//����ʱ��
	int m_Priority;//���ȼ�

	//δ������ͨ�������㷨ʵ��
	int m_RunT;//������ʱ��
	int m_OverT;   //����ʱ��
	int m_Turnover;//��תʱ��
	float m_TurRighT;//��Ȩ��תʱ��
};
process* InitPro(int n)
{
	int i = 0;
	process* p = (process*)malloc(sizeof(process)*n);
	process* cur = p;
	cout << " job " << "T���� " << "T���� " << "���ȼ� " << endl;
	while (n--)
	{
		cout << i<<":";
		memset(cur->m_num, 0, sizeof(cur->m_num));
		cin >> cur->m_num >> cur->m_ArrivalT >> cur->m_ServiceT >> cur->m_Priority;
		cur->m_RunT = 0;
		cur++;
		i++;
	}
	return p;
}

//�ȵ��ȷ����㷨
void FCFS(process* pro, int n)
{
	int time = 0;
	int num = n;
	float averTurnTime = 0;
	float averWeightTurnTime = 0;

	multimap<int, process> p;
	while (n--)//���յ���ʱ���������
	{
		p.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	n = num;
#if 0
	cout << "num " << "T���� " << "T���� " << "���ȼ� " << endl;
	
	for (auto i : p)
	{
		printf("%2d %5d %5d %5d\n", i.second.m_num, i.second.m_ArrivalT, i.second.m_ServiceT, i.second.m_Priority);
	}
#endif
	for (auto &i : p)
	{
		if (time < i.second.m_ArrivalT)
		{
			time = i.second.m_ArrivalT;
		}
		i.second.m_OverT = time + i.second.m_ServiceT;
		i.second.m_Turnover = i.second.m_OverT - i.second.m_ArrivalT;
       	i.second.m_TurRighT = (float)i.second.m_Turnover / (float)i.second.m_ServiceT;
		time = i.second.m_OverT;
	}
	cout << "num " << "T���� " << "T���� " << "���ȼ� " <<"T��� " <<"T��ת "<<"T��Ȩ��ת "<<endl;
	for (auto i : p)
	{
		printf("%4s %5d %5d %5d %5d %5d   %5.3f \n", i.second.m_num, i.second.m_ArrivalT, i.second.m_ServiceT, i.second.m_Priority, i.second.m_OverT, i.second.m_Turnover, i.second.m_TurRighT);
		averTurnTime += i.second.m_Turnover;
		averWeightTurnTime += i.second.m_TurRighT;
	}
	averTurnTime /= (float)p.size();
	averWeightTurnTime /=(float) p.size();
	printf("ƽ����תʱ��Ϊ��%f\n", averTurnTime);
	printf("ƽ����Ȩ��תʱ��Ϊ��%f\n", averWeightTurnTime);
}


//����ҵ�㷨
void SJF(process* pro, int n)
{
	int time = 0;//ϵͳ����ʱ��
	int num = n;
	float averTurnTime = 0;
	float averWeightTurnTime = 0;
	multimap<int, process> p;
	multimap<int, process> readyQue;//�ѽ����ڴ��еĽ��̣���������ҵ���ȼ�����
	vector<process> data;
	while (n--)//���յ���ʱ���������
	{
		p.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	multimap<int,process>::iterator pp = p.begin();
	multimap<int, process>::iterator tmp;
	for (; pp !=p.end() || readyQue.size()>0;)//�˳�����Ϊ�����������е����ݾ���ִ����
	{
		while (pp!=p.end() && pp->second.m_ArrivalT<=time)
		{
			readyQue.insert(pair<int, process>(pp->second.m_ServiceT, pp->second));
			pp++;
		}
		//ÿ��ֻ��ִ�е�ǰ���ȼ���ߵ�һ��,ִ�к�ɾ��
		if (readyQue.empty())
		{
			time = pp->second.m_ArrivalT;
		}
		if (!readyQue.empty())
		{
			tmp = readyQue.begin();
			time += (tmp->second.m_ServiceT);//����
			tmp->second.m_OverT = time;
			tmp->second.m_Turnover = time - (tmp->second.m_ArrivalT);
			tmp->second.m_TurRighT = (float)(tmp->second.m_Turnover) / (float)(tmp->second.m_ServiceT);
			data.push_back(tmp->second);
			readyQue.erase(tmp);
		}
	}
	cout << "num " << "T���� " << "T���� " << "���ȼ� " << "T��� " << "T��ת " << "T��Ȩ��ת " << endl;
	for (auto i : data)
	{
		printf("%4s %5d %5d %5d %5d %5d    %5.3f \n", i.m_num, i.m_ArrivalT, i.m_ServiceT, i.m_Priority, i.m_OverT, i.m_Turnover, i.m_TurRighT);
		averTurnTime += i.m_Turnover;
		averWeightTurnTime += i.m_TurRighT;
	}
	averTurnTime /= (float)data.size();
	averWeightTurnTime /= (float)data.size();
	printf("ƽ����תʱ��Ϊ��%f\n", averTurnTime);
	printf("ƽ����Ȩ��תʱ��Ϊ��%f\n", averWeightTurnTime);
}

//ʱ��Ƭ��ת�㷨
#if 0
void RoundRobin(process* pro,int n)
{
	int time = 0;//������
	int num = n;
	float averTurnTime = 0;
	float averWeightTurnTime = 0;
	multimap<int, process> data;
	vector<process> jobQu;
	multimap<int, process>::iterator dd;
	int i = 0;
	int tmp = 0;
	int addflag = 0;
	int runflag = 0;//��ĳ���ڴ��н���ִ���꣬���󱸶����л����ڶ���δ�����ڴ�ʱ��flag���ı䣬time++
	int RR = 2;//ʱ��Ƭ
	cout << "������ʱ��Ƭ��";
	cin >> RR;
	while (n--)
	{
		data.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	dd = data.begin();
	time = (*dd).second.m_ArrivalT;//time����ʼʱ��Ӧ��Ϊ��һ����ҵ�����ڴ��ʱ��
	while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//���⣺��ʱ����ֶϵ㣬�����ڴ��е���ҵȫ��ִ����֮�󣬾��������е���ҵ��δ�����ڴ�����
	{
		jobQu.push_back((*dd).second);
		dd++;
	}
	for (;num>0;)
	{
		runflag = 0;
		if (i >= jobQu.size())
		{
			i %= jobQu.size();
		}
  		for (; i < jobQu.size();)
		{
			addflag = 0;
			if (jobQu[i].m_RunT < jobQu[i].m_ServiceT)//δ��ɵ���ҵ������ת
			{
				runflag = 1;
				if ((jobQu[i].m_ServiceT - jobQu[i].m_RunT) >= RR)
				{
					time += RR;
					jobQu[i].m_RunT += RR;
				}
				else
				{
					time += (jobQu[i].m_ServiceT - jobQu[i].m_RunT);
					jobQu[i].m_RunT += (jobQu[i].m_ServiceT - jobQu[i].m_RunT);
				}
				if (jobQu[i].m_RunT >= jobQu[i].m_ServiceT)//������Ҫ��ʱ�䴦�����⣺��ʱ��Ƭδ����ʱ����ҵ��ɣ���ҵ�˳�ʱ��ʱ��ҵ���ʱ�仹��ʱ��Ƭ�������ʱ��
				{
					jobQu[i].m_OverT = time;
					jobQu[i].m_Turnover = jobQu[i].m_OverT - jobQu[i].m_ArrivalT;
					jobQu[i].m_TurRighT = (float)jobQu[i].m_Turnover / (float)jobQu[i].m_ServiceT;
					num--;
				}
			}
			i++;
			while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//���⣺��ʱ����ֶϵ㣬�����ڴ��е���ҵȫ��ִ����֮�󣬾��������е���ҵ��δ�����ڴ�����
			{
				jobQu.push_back((*dd).second);
				dd++;
				addflag = 1;
			}
			/*if (addflag == 1)
			{
				break;
			}*/
		}
		tmp = i;
		if (runflag == 0)
		{
			time++;
		}
	}
	cout<< "num " << "T���� " << "T���� " << "���ȼ� " << "T��� " << "T��ת " << "T��Ȩ��ת " << endl;
	for (auto i : jobQu)
	{
		printf("%4s %5d %5d %5d %5d %5d    %5.3f \n", i.m_num, i.m_ArrivalT, i.m_ServiceT, i.m_Priority, i.m_OverT, i.m_Turnover, i.m_TurRighT);
		averTurnTime += i.m_Turnover;
		averWeightTurnTime += i.m_TurRighT;
	}
	averTurnTime /= (float)data.size();
	averWeightTurnTime /= (float)data.size();
	printf("ƽ����תʱ��Ϊ��%f\n", averTurnTime);
	printf("ƽ����Ȩ��תʱ��Ϊ��%f\n", averWeightTurnTime);
}
#endif
void RoundRobin(process* pro, int n)
{
	int time = 0;//������
	int num = n;
	float averTurnTime = 0;
	float averWeightTurnTime = 0;
	multimap<int, process> data;
	map<string, process> overJob;

	list<process> jobQu;
	multimap<int, process>::iterator dd;
	list<process>::iterator pp;
	process tmp;
	int addflag = 0;
	int runflag = 0;
	int RR = 2;//ʱ��Ƭ
	cout << "������ʱ��Ƭ��";
	cin >> RR;
	while (n--)
	{
		data.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	dd = data.begin();
	time = (*dd).second.m_ArrivalT;//time����ʼʱ��Ӧ��Ϊ��һ����ҵ�����ڴ��ʱ��
	while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//���⣺��ʱ����ֶϵ㣬�����ڴ��е���ҵȫ��ִ����֮�󣬾��������е���ҵ��δ�����ڴ�����
	{
		jobQu.push_back((*dd).second);
		dd++;
	}
	for (; num>0;)
	{
		for (pp = jobQu.begin(); pp != jobQu.end(); )
		{
			addflag = 0;
			if ((*pp).m_RunT < (*pp).m_ServiceT)//δ��ɵ���ҵ������ת
			{
				runflag = 1;
				if (((*pp).m_ServiceT - (*pp).m_RunT) >= RR)
				{
					time += RR;
					(*pp).m_RunT += RR;
				}
				else
				{
					time += ((*pp).m_ServiceT - (*pp).m_RunT);
					(*pp).m_RunT += ((*pp).m_ServiceT - (*pp).m_RunT);
				}
				if ((*pp).m_RunT >= (*pp).m_ServiceT)//������Ҫ��ʱ�䴦�����⣺��ʱ��Ƭδ����ʱ����ҵ��ɣ���ҵ�˳�ʱ��ʱ��ҵ���ʱ�仹��ʱ��Ƭ�������ʱ��
				{
					(*pp).m_OverT = time;
					(*pp).m_Turnover = (*pp).m_OverT - (*pp).m_ArrivalT;
					(*pp).m_TurRighT = (float)(*pp).m_Turnover / (float)(*pp).m_ServiceT;
					num--;
					overJob.insert(pair<string, process>((*pp).m_num, (*pp)));
					while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//���⣺��ʱ����ֶϵ㣬�����ڴ��е���ҵȫ��ִ����֮�󣬾��������е���ҵ��δ�����ڴ�����
					{
						jobQu.push_back((*dd).second);
						dd++;
						addflag = 1;
					}
					jobQu.pop_front();
				}
				else
				{
					memcpy(&tmp, &(*pp), sizeof(process));
					jobQu.pop_front();
					while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//���⣺��ʱ����ֶϵ㣬�����ڴ��е���ҵȫ��ִ����֮�󣬾��������е���ҵ��δ�����ڴ�����
					{
						jobQu.push_back((*dd).second);
						dd++;
						addflag = 1;
					}
					jobQu.push_back(tmp);
				}
			}
			break;
		}
		if (runflag==0)//��ĳ���ڴ��н���ִ���꣬���󱸶����л����ڶ���δ�����ڴ�ʱ��flag���ı䣬time++
		{
			time++;
		}
	}
	cout << "num " << "T���� " << "T���� " << "���ȼ� " << "T��� " << "T��ת " << "T��Ȩ��ת " << endl;
	for (auto i : overJob)
	{
		printf("%4s %5d %5d %5d %5d %5d    %5.3f \n", i.second.m_num, i.second.m_ArrivalT, i.second.m_ServiceT, i.second.m_Priority, i.second.m_OverT, i.second.m_Turnover, i.second.m_TurRighT);
		averTurnTime += i.second.m_Turnover;
		averWeightTurnTime += i.second.m_TurRighT;
	}
	averTurnTime /= (float)data.size();
	averWeightTurnTime /= (float)data.size();
	printf("ƽ����תʱ��Ϊ��%f\n", averTurnTime);
	printf("ƽ����Ȩ��תʱ��Ϊ��%f\n", averWeightTurnTime);
}

void PrintPro(process* pro,int n)
{
	cout << "num " << "T���� " << "T���� " << "���ȼ� " << endl;
	while (n--)
	{
		printf("%2s %5d %5d %5d\n", pro->m_num, pro->m_ArrivalT, pro->m_ServiceT, pro->m_Priority);
		pro++;
	}
}
int menu()
{
	int choose = -1;
	cout << "*****************************" << endl;
	cout << "*******  1.RR    ************" << endl;
	cout << "*******  2.SJF   ************" << endl;
	cout << "*******  3.FCFS  ************" << endl;
	cout << "*******  4.pjob  ************" << endl;
	cout << "*******  0.exit  ************" << endl;
	cout << "*****************************" << endl;
	while (cin >> choose)
	{
		if (choose <=4 && choose >= 0)
		{
			break;
		}
		else
		{
			cout << "���������������������ѡ��";
		}
	}
	return choose;
}
int main()
{
	int n;
	int celect = -1;
	cout << "Ҫִ�еĽ�������" << endl;
	cin >> n;
	process* npro=InitPro(n);
	while (1)
	{
		celect = menu();
		switch (celect)
		{
		case 1:
			cout << "ʱ��Ƭ��ת�㷨ִ�н����" << endl;
			RoundRobin(npro, n);
			break;
		case 2:
			cout << "����ҵ�����㷨ִ�н����" << endl;
			SJF(npro, n);
			break;
		case 3:
			cout << "�ȵ��ȷ����㷨ִ�н����" << endl;
			FCFS(npro, n);
			break;
		case 4:
			PrintPro(npro,n);
			break;
		case 0:
			exit(0);
			break;
		default:
			;
			//
		}
	}
	//RoundRobin(npro, n);
	free(npro);
	return 0;
}