#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define BRAND_NUM 54//�ƶѵ�����
#define HAND_NUM 18//���Ƶ�����Ŀ

//1������һ���˿����࣬ӵ�з��������뻨ɫ�͵��������˿��ơ���ӡ�˿��ơ�
//2������һ������࣬ÿ��ӵ��18���˿��ơ�ӵ�з������������ƣ����ƣ���չʾ���ƣ�����չʾ����Ҫ��������չʾ��
//��ɳ���
//1���������18���˿��ƣ�����һ����ҵ����ơ�
//2����54�Ų�ͬ���˿��ƹ����ƶѣ�����3����ҡ�


class Poick
{
private:
	char m_Color;
	int m_Point;

public:
	void  Init(char color = 0, int point = 0)
	{
		if (color == 5)//��ʼ���ƶ�ʱ������С������ʱcolorΪ5.pointΪ1��2���Դ˽��д���
		{
			point += 13;
		}
		if (point > 13)
		{
			m_Point = point;
			m_Color = 0;
		}
		else
		{
			m_Point = point;
			m_Color = color;
		}
	}
	int Poick_Point()
	{
		return m_Point;
	}
	int Poick_Color()
	{
		return m_Color;
	}
	void SetPoick(char color = 0, int point = 0)
	{
		m_Point = point;
		m_Color = color;
	}
	void Print();

};

void Poick::Print()
{
	char *point[16] = { " ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };
	char *color[5] = { "  ", "����", "÷��", "��Ƭ", "����" };
	if (m_Point <= 13)
	{
		printf("%4s%1s ", color[m_Color], point[m_Point]);
	}
	else
	{
		printf("%s ", point[m_Point]);
	}
}

class Player
{
private:
	static int m_n;//��ұ��
	Poick m_card[HAND_NUM];//������е���

public:
	Player()
	{
		//m_n++;
	}
	void Init()
	{
		for (auto &i : m_card)
		{
			i.Init(rand() % 4 + 1, rand() % 15 + 1);
		}
		m_n++;
	}
	void GetCard(Poick *Brand_heap)
	{
		int i, j;
		for (j = 0; j < HAND_NUM; j++)
		{
			i = rand() % BRAND_NUM;
			while (i<BRAND_NUM)
			{
				if (Brand_heap[i].Poick_Point() != -1 && Brand_heap[i].Poick_Color() != -1)//��i����δ����
				{
					m_card[j] = Brand_heap[i];
					Brand_heap[i].SetPoick(-1, -1);//���ƶ����±�Ϊi�������ñ��
					break;
				}
				else
				{
					i++;
				}
			}
		}
	}
	void Insert_m_card()//�����Ʋ�������
	{
		int i, j;
		Poick tmp;
		for (i = 1; i < HAND_NUM; i++)
		{
			tmp = m_card[i];
			if (tmp.Poick_Point()>m_card[i - 1].Poick_Point())
			{
				for (j = i; j > 0 && tmp.Poick_Point()>m_card[j - 1].Poick_Point(); j--)
				{
					m_card[j] = m_card[j - 1];
				}//end of for
				m_card[j] = tmp;
			}//end of if
		}
	}
	void ShowCard()
	{
		cout << "���" << m_n << "����:";
		for (auto i : m_card)
		{
			i.Print();
		}
		cout << endl;
	}
};
int Player::m_n = 0;
int main()
{
	//Poick po[5];
	int i;
	Poick Brand_heap[BRAND_NUM];
	srand(time(NULL));
	//for (auto &i : po)
	//{
	//	i.Init(rand() % 4 + 1, rand() % 15 + 1);
	//	i.Print();
	//}
	/*for (auto i : po)
	{
	i.Print();
	}*/
	for (i = 0; i < 54; i++)
	{
		Brand_heap[i].Init(i / 13 + 1, i % 13 + 1);
	}
	for (auto i : Brand_heap)
	{
		i.Print();
	}
	Player py[3];
	cout << endl;
	for (auto i : py)
	{
		i.Init();
		i.GetCard(Brand_heap);
		i.Insert_m_card();
		i.ShowCard();
		cout << endl;
	}
	/*py.Init();
	py.ShowCard();*/
	return 0;
}