#include <iostream>
#include <iomanip>
#include <vector>
#include "bankerAlgorithm.h"
using namespace std;
//������N ��Դ��M 
// Allocation Need Request
//Request > Need  ���󳬳��Ϸ���Χ��������ںϷ����󣬷���
//Request > Available ϵͳ��ǰ������Դ�������������󣬽�������
//Request �Է��䣬

//Request������ͨ��֮����������������֮��ִ���˳��ͷ�������ռ����Դ

//��ȫ����������Է����������

/*    ��Ҫ����Ķ���    */
vector<vector<int> > Allocation;
vector<vector<int> > Need;
vector<int> Available;

bool matrixGreatAndEqualsJudgment(vector<int> mat1, vector<int> mat2)//�����ڰ�ȫ���㷨��work��need[i]�����С���ж�
{
	//mat1>=mat2ʱ����true,�����������false
	int i = 0;
	for (i = 0; i < mat1.size(); i++)
	{
		if (mat1[i] < mat2[i])
		{
			return false;//��mat1��С��mat2ʱ������false
		}
	}
	return true;
}
bool matrixGreatJudgment(vector<int> mat1, vector<int> mat2)//���������м��㷨�ж���request�����need[pos]�����available������ж�
{
	int i = 0;
	for (i = 0; i < mat1.size(); i++)
	{
		if (mat1[i] > mat2[i])
		{
			return true;//����mat1����mat2ʱ������true
		}
	}
	return false;
}

vector<int>& addMatrix(vector<int>& mat1, vector<int>& mat2)
//��mat2�ӵ�mat1���Ϻ󷵻�mat1
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
	cout << "���������������Դ������Ŀ��";
	cin >> N >> M;
	Available.resize(M);
	Allocation.resize(N);
	Need.resize(N);
	cout << "��ʼ��Allocation����" << endl;
	for (auto &i : Allocation)
	{
		i.resize(M);
		for (auto &k : i)
		{
			cin >> k;
		}
	}
	cout << "��ʼ��Need����" << endl;
	for (auto &i : Need)
	{
		i.resize(M);
		for (auto &k : i)
		{
			cin >> k;
		}
	}
	cout << "��ʼ��Available����" << endl;
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
	cout << " Need ����" << endl;
	for (auto &i : need)
	{
		for (auto &k : i)
		{
			cout << setw(3) << k;
		}
		cout << endl;
	}*/
	cout << "-----------------------------" << endl;
	cout << " Available����";
	for (auto&i : avail)
	{
		cout << i << ' ';
	}
	cout << endl;
	cout << "-----------------------------" << endl;
}
bool bankerAlgorithm()
//���м��㷨���Է��䣬�����ж�
{
	int pos;
	int i = 0;
	int flag = 0;
	vector<int> request;
	vector<vector<int> > ::iterator p;
	request.resize(Available.size());
	printMatrix(Allocation, Need, Available);
	cout << "������������Դ�Ľ��̺ţ�";
	cin >> pos;
	cout << "������" << pos << "���̵ĸ�����Դ���������";
	for (auto &i : request)
	{
		cin >> i;
	}
	if (matrixGreatJudgment(request, Need[pos]))
	{
		cout << "������ںϷ�����" << endl;
		return false;
	}
	else if (matrixGreatJudgment(request, Available))
	{
		cout << "ϵͳ��ǰ������Դ������������" << endl;
		return false;
	}

	/******             �Է���            ************/
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
	if (flag == 0)//��ǰ�������Դ����lpos���̵��������������н�����������Դ �����̳���
	{
		bankAvailable=addMatrix(bankAvailable, bankAll[pos]);//������Դ
		bankAll.erase(bankAll.begin() + pos);//���̳���
		bankNeed.erase(bankNeed.begin() + pos);//���̳���
	}
	//�Է������
	cout << "�Է�������" << endl;
	printMatrix(bankAll, bankNeed, bankAvailable);
	if (securityAlgorithm(bankAll, bankNeed, bankAvailable))
	{
		cout << "�������������!����֮��ľ���״̬Ϊ��"<<endl;
		Need = bankNeed;
		Allocation = bankAll;
		Available = bankAvailable;
		printMatrix(Allocation, Need, Available);
		return true;
	}
	else
	{
		printMatrix(bankAll, bankNeed, bankAvailable);
		cout << "���������ʹ���벻��ȫ״̬��������������!" << endl;
		return false;
	}
}

/***********************��ȫ���㷨********************************/
//��ȫ���㷨��
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
	}while(flag == 1);//�˳�˵����ĳ�α�����û���ҵ�work>=need[i]
	if (Sequence.size() == Finish.size())
	{
		cout << "״̬��ȫ����ȫ����Ϊ�� ";
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
		cout << "���� '1'����������'0'�˳� ��" ;
	}while (cin >> n);
	return 0;
}