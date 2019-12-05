/*
操作系统进程调度算法实现：
文件状态：实现基本功能：空间及时间复杂度有待优化
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <list>
#include <queue>
using namespace std;
const int JOB_NAEM_MAX = 20;//进程名称
typedef struct process
{
	char m_num[JOB_NAEM_MAX];//进程编号
	int m_ArrivalT;//到达时间
	int m_ServiceT;//服务时间
	int m_Priority;//优先级

	//未给出，通过调用算法实现
	int m_RunT;//已运行时间
	int m_OverT;   //结束时间
	int m_Turnover;//周转时间
	float m_TurRighT;//带权周转时间
};
process* InitPro(int n)
{
	int i = 0;
	process* p = (process*)malloc(sizeof(process)*n);
	process* cur = p;
	cout << " job " << "T到达 " << "T服务 " << "优先级 " << endl;
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

//先到先服务算法
void FCFS(process* pro, int n)
{
	int time = 0;
	int num = n;
	float averTurnTime = 0;
	float averWeightTurnTime = 0;

	multimap<int, process> p;
	while (n--)//按照到达时间排序插入
	{
		p.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	n = num;
#if 0
	cout << "num " << "T到达 " << "T服务 " << "优先级 " << endl;
	
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
	cout << "num " << "T到达 " << "T服务 " << "优先级 " <<"T完成 " <<"T周转 "<<"T带权周转 "<<endl;
	for (auto i : p)
	{
		printf("%4s %5d %5d %5d %5d %5d   %5.3f \n", i.second.m_num, i.second.m_ArrivalT, i.second.m_ServiceT, i.second.m_Priority, i.second.m_OverT, i.second.m_Turnover, i.second.m_TurRighT);
		averTurnTime += i.second.m_Turnover;
		averWeightTurnTime += i.second.m_TurRighT;
	}
	averTurnTime /= (float)p.size();
	averWeightTurnTime /=(float) p.size();
	printf("平均周转时间为：%f\n", averTurnTime);
	printf("平均带权周转时间为：%f\n", averWeightTurnTime);
}


//短作业算法
void SJF(process* pro, int n)
{
	int time = 0;//系统运行时间
	int num = n;
	float averTurnTime = 0;
	float averWeightTurnTime = 0;
	multimap<int, process> p;
	multimap<int, process> readyQue;//已进入内存中的进程，并按短作业优先级排序
	vector<process> data;
	while (n--)//按照到达时间排序插入
	{
		p.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	multimap<int,process>::iterator pp = p.begin();
	multimap<int, process>::iterator tmp;
	for (; pp !=p.end() || readyQue.size()>0;)//退出条件为两个后备容器中的数据均被执行完
	{
		while (pp!=p.end() && pp->second.m_ArrivalT<=time)
		{
			readyQue.insert(pair<int, process>(pp->second.m_ServiceT, pp->second));
			pp++;
		}
		//每次只能执行当前优先级最高的一个,执行后删除
		if (readyQue.empty())
		{
			time = pp->second.m_ArrivalT;
		}
		if (!readyQue.empty())
		{
			tmp = readyQue.begin();
			time += (tmp->second.m_ServiceT);//运行
			tmp->second.m_OverT = time;
			tmp->second.m_Turnover = time - (tmp->second.m_ArrivalT);
			tmp->second.m_TurRighT = (float)(tmp->second.m_Turnover) / (float)(tmp->second.m_ServiceT);
			data.push_back(tmp->second);
			readyQue.erase(tmp);
		}
	}
	cout << "num " << "T到达 " << "T服务 " << "优先级 " << "T完成 " << "T周转 " << "T带权周转 " << endl;
	for (auto i : data)
	{
		printf("%4s %5d %5d %5d %5d %5d    %5.3f \n", i.m_num, i.m_ArrivalT, i.m_ServiceT, i.m_Priority, i.m_OverT, i.m_Turnover, i.m_TurRighT);
		averTurnTime += i.m_Turnover;
		averWeightTurnTime += i.m_TurRighT;
	}
	averTurnTime /= (float)data.size();
	averWeightTurnTime /= (float)data.size();
	printf("平均周转时间为：%f\n", averTurnTime);
	printf("平均带权周转时间为：%f\n", averWeightTurnTime);
}

//时间片轮转算法
#if 0
void RoundRobin(process* pro,int n)
{
	int time = 0;//数轴线
	int num = n;
	float averTurnTime = 0;
	float averWeightTurnTime = 0;
	multimap<int, process> data;
	vector<process> jobQu;
	multimap<int, process>::iterator dd;
	int i = 0;
	int tmp = 0;
	int addflag = 0;
	int runflag = 0;//当某次内存中进程执行完，但后备队列中还存在队列未进入内存时，flag不改变，time++
	int RR = 2;//时间片
	cout << "请输入时间片：";
	cin >> RR;
	while (n--)
	{
		data.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	dd = data.begin();
	time = (*dd).second.m_ArrivalT;//time的起始时间应该为第一道作业进入内存的时间
	while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//问题：当时间出现断点，进入内存中的作业全部执行完之后，就绪队列中的作业还未进入内存的情况
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
			if (jobQu[i].m_RunT < jobQu[i].m_ServiceT)//未完成的作业进入轮转
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
				if (jobQu[i].m_RunT >= jobQu[i].m_ServiceT)//这里需要对时间处理？问题：当时间片未结束时，作业完成，作业退出时间时作业完成时间还是时间片周期完成时间
				{
					jobQu[i].m_OverT = time;
					jobQu[i].m_Turnover = jobQu[i].m_OverT - jobQu[i].m_ArrivalT;
					jobQu[i].m_TurRighT = (float)jobQu[i].m_Turnover / (float)jobQu[i].m_ServiceT;
					num--;
				}
			}
			i++;
			while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//问题：当时间出现断点，进入内存中的作业全部执行完之后，就绪队列中的作业还未进入内存的情况
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
	cout<< "num " << "T到达 " << "T服务 " << "优先级 " << "T完成 " << "T周转 " << "T带权周转 " << endl;
	for (auto i : jobQu)
	{
		printf("%4s %5d %5d %5d %5d %5d    %5.3f \n", i.m_num, i.m_ArrivalT, i.m_ServiceT, i.m_Priority, i.m_OverT, i.m_Turnover, i.m_TurRighT);
		averTurnTime += i.m_Turnover;
		averWeightTurnTime += i.m_TurRighT;
	}
	averTurnTime /= (float)data.size();
	averWeightTurnTime /= (float)data.size();
	printf("平均周转时间为：%f\n", averTurnTime);
	printf("平均带权周转时间为：%f\n", averWeightTurnTime);
}
#endif
void RoundRobin(process* pro, int n)
{
	int time = 0;//数轴线
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
	int RR = 2;//时间片
	cout << "请输入时间片：";
	cin >> RR;
	while (n--)
	{
		data.insert(pair<int, process>(pro->m_ArrivalT, *pro));
		pro++;
	}
	dd = data.begin();
	time = (*dd).second.m_ArrivalT;//time的起始时间应该为第一道作业进入内存的时间
	while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//问题：当时间出现断点，进入内存中的作业全部执行完之后，就绪队列中的作业还未进入内存的情况
	{
		jobQu.push_back((*dd).second);
		dd++;
	}
	for (; num>0;)
	{
		for (pp = jobQu.begin(); pp != jobQu.end(); )
		{
			addflag = 0;
			if ((*pp).m_RunT < (*pp).m_ServiceT)//未完成的作业进入轮转
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
				if ((*pp).m_RunT >= (*pp).m_ServiceT)//这里需要对时间处理？问题：当时间片未结束时，作业完成，作业退出时间时作业完成时间还是时间片周期完成时间
				{
					(*pp).m_OverT = time;
					(*pp).m_Turnover = (*pp).m_OverT - (*pp).m_ArrivalT;
					(*pp).m_TurRighT = (float)(*pp).m_Turnover / (float)(*pp).m_ServiceT;
					num--;
					overJob.insert(pair<string, process>((*pp).m_num, (*pp)));
					while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//问题：当时间出现断点，进入内存中的作业全部执行完之后，就绪队列中的作业还未进入内存的情况
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
					while (dd != data.end() && (time >= (*dd).second.m_ArrivalT))//问题：当时间出现断点，进入内存中的作业全部执行完之后，就绪队列中的作业还未进入内存的情况
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
		if (runflag==0)//当某次内存中进程执行完，但后备队列中还存在队列未进入内存时，flag不改变，time++
		{
			time++;
		}
	}
	cout << "num " << "T到达 " << "T服务 " << "优先级 " << "T完成 " << "T周转 " << "T带权周转 " << endl;
	for (auto i : overJob)
	{
		printf("%4s %5d %5d %5d %5d %5d    %5.3f \n", i.second.m_num, i.second.m_ArrivalT, i.second.m_ServiceT, i.second.m_Priority, i.second.m_OverT, i.second.m_Turnover, i.second.m_TurRighT);
		averTurnTime += i.second.m_Turnover;
		averWeightTurnTime += i.second.m_TurRighT;
	}
	averTurnTime /= (float)data.size();
	averWeightTurnTime /= (float)data.size();
	printf("平均周转时间为：%f\n", averTurnTime);
	printf("平均带权周转时间为：%f\n", averWeightTurnTime);
}

void PrintPro(process* pro,int n)
{
	cout << "num " << "T到达 " << "T服务 " << "优先级 " << endl;
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
			cout << "输入有误，请重新输入你的选择：";
		}
	}
	return choose;
}
int main()
{
	int n;
	int celect = -1;
	cout << "要执行的进程数：" << endl;
	cin >> n;
	process* npro=InitPro(n);
	while (1)
	{
		celect = menu();
		switch (celect)
		{
		case 1:
			cout << "时间片轮转算法执行结果：" << endl;
			RoundRobin(npro, n);
			break;
		case 2:
			cout << "短作业优先算法执行结果：" << endl;
			SJF(npro, n);
			break;
		case 3:
			cout << "先到先服务算法执行结果：" << endl;
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