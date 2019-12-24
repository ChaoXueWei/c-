#include <iostream>
#include <iomanip>
#include <vector>
#include "bankerAlgorithm.h"
using namespace std;
//进程数N 资源数M 
// Allocation Need Request
//Request > Need  请求超出合法范围，请求大于合法需求，返回
//Request > Available 系统当前可用资源数不足满足需求，进程阻塞
//Request 试分配，

//Request在申请通过之后若满足所有需求之后。执行退出释放所有以占有资源

//安全序列输出，试分配结果输出，

/*    重要矩阵的定义    */
vector<vector<int> > Allocation;
vector<vector<int> > Need;
vector<int> Available;

bool matrixGreatAndEqualsJudgment(vector<int> mat1, vector<int> mat2)//用于在安全性算法中work和need[i]矩阵大小的判断
{
	//mat1>=mat2时返回true,其余情况返回false
	int i = 0;
	for (i = 0; i < mat1.size(); i++)
	{
		if (mat1[i] < mat2[i])
		{
			return false;//当mat1有小于mat2时，返回false
		}
	}
	return true;
}
bool matrixGreatJudgment(vector<int> mat1, vector<int> mat2)//用于在银行家算法中对于request矩阵和need[pos]矩阵和available矩阵的判断
{
	int i = 0;
	for (i = 0; i < mat1.size(); i++)
	{
		if (mat1[i] > mat2[i])
		{
			return true;//当有mat1大于mat2时，返回true
		}
	}
	return false;
}

vector<int>& addMatrix(vector<int>& mat1, vector<int>& mat2)
//将mat2加到mat1是上后返回mat1
{
	int i = 0;
	for (i = 0; i < mat1.size(); i++)
	{
		mat1[i] += mat2[i];
	}
	return mat1;
}

void InitMatrix()
{
	int N, M;
	cout << "请输入进程数，资源种类数目：";
	cin >> N >> M;
	Available.resize(M);
	Allocation.resize(N);
	Need.resize(N);
	cout << "初始化Allocation矩阵：" << endl;
	for (auto &i : Allocation)
	{
		i.resize(M);
		for (auto &k : i)
		{
			cin >> k;
		}
	}
	cout << "初始化Need矩阵：" << endl;
	for (auto &i : Need)
	{
		i.resize(M);
		for (auto &k : i)
		{
			cin >> k;
		}
	}
	cout << "初始化Available矩阵：" << endl;
	for (auto &i : Available)
	{
		cin >> i;
	}
}
void printMatrix(vector<vector<int> > All,vector<vector<int> > need,vector<int> avail)
{
	cout << "-----------------------------" << endl;
	cout << setw(avail.size() * 3) << "Allocation" << setw(-2) << "|" << setw(avail.size() * 3) << " Need " << endl;
	cout << "-----------------------------" << endl;
	int i = 0;
	for (i = 0; i < All.size(); i++)
	{
		for (auto &k : All[i])
		{
			cout << setw(3) << k;
		}
		cout << setw(2) << "|";
		for (auto &k : need[i])
		{
			cout << setw(3) << k;
		}
		cout << endl;
	}
	/*for (auto &i: All)
	{
		for (auto &k : i)
		{
			cout << setw(3) << k;
		}
		cout << endl;
	}*/
	/*cout << "-----------------------------" << endl;
	cout << " Need 矩阵：" << endl;
	for (auto &i : need)
	{
		for (auto &k : i)
		{
			cout << setw(3) << k;
		}
		cout << endl;
	}*/
	cout << "-----------------------------" << endl;
	cout << " Available矩阵：";
	for (auto&i : avail)
	{
		cout << i << ' ';
	}
	cout << endl;
	cout << "-----------------------------" << endl;
}
bool bankerAlgorithm()
//银行及算法，试分配，三种判断
{
	int pos;
	int i = 0;
	int flag = 0;
	vector<int> request;
	vector<vector<int> > ::iterator p;
	request.resize(Available.size());
	printMatrix(Allocation, Need, Available);
	cout << "请输入申请资源的进程号：";
	cin >> pos;
	cout << "请输入" << pos << "进程的各个资源申请个数：";
	for (auto &i : request)
	{
		cin >> i;
	}
	if (matrixGreatJudgment(request, Need[pos]))
	{
		cout << "请求大于合法需求！" << endl;
		return false;
	}
	else if (matrixGreatJudgment(request, Available))
	{
		cout << "系统当前可用资源数不满足需求！" << endl;
		return false;
	}

	/******             试分配            ************/
	vector<vector<int> >bankAll = Allocation;
	vector<vector<int> >bankNeed = Need;
	vector<int> bankAvailable = Available;

	addMatrix(bankAll[pos], request);

	for (i = 0; i < bankNeed[pos].size(); i++)
	{
		bankNeed[pos][i] -= request[i];
		bankAvailable[i] -= request[i];
	}

	for (auto &k : bankNeed[pos])
	{
		if (k != 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)//当前申请的资源满足lpos进程的运行条件，运行结束，回收资源 ，进程撤销
	{
		bankAvailable=addMatrix(bankAvailable, bankAll[pos]);//回收资源
		bankAll.erase(bankAll.begin() + pos);//进程撤销
		bankNeed.erase(bankNeed.begin() + pos);//进程撤销
	}
	//试分配结束
	cout << "试分配后矩阵：" << endl;
	printMatrix(bankAll, bankNeed, bankAvailable);
	if (securityAlgorithm(bankAll, bankNeed, bankAvailable))
	{
		cout << "该申请可以满足!满足之后的矩阵状态为："<<endl;
		Need = bankNeed;
		Allocation = bankAll;
		Available = bankAvailable;
		printMatrix(Allocation, Need, Available);
		return true;
	}
	else
	{
		printMatrix(bankAll, bankNeed, bankAvailable);
		cout << "满足需求会使陷入不安全状态，不能满足需求!" << endl;
		return false;
	}
}

/***********************安全性算法********************************/
//安全性算法，
bool securityAlgorithm(vector<vector<int> > All,vector<vector<int> > need,vector<int> work)
{
	vector<bool> Finish(need.size(), false);
	vector<int> Sequence;

	int i = 0;
	int flag = 0;
	do 
	{
		flag = 0;
		for (i = 0;i<need.size(); i++)
		{
			if (Finish[i] == false && matrixGreatAndEqualsJudgment(work, need[i]))
			{
				work =addMatrix(work, All[i]);
				Finish[i] = true;
				Sequence.push_back(i);
				flag = 1;
			}
		}
	}while(flag == 1);//退出说明在某次遍历中没有找到work>=need[i]
	if (Sequence.size() == Finish.size())
	{
		cout << "状态安全！安全序列为： ";
		for (auto &q : Sequence)
		{
			cout << q << " ";
		}
		cout << endl;
		return true;
	}
	return false;
}

int main()
{
	int n=1;
	InitMatrix();
	securityAlgorithm(Allocation,Need,Available);
	do
	{
		if (n == 0)
		{
			break;
		}
		bankerAlgorithm();
		cout << "输入 '1'继续，输入'0'退出 ：" ;
	}while (cin >> n);
	return 0;
}