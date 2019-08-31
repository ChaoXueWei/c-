#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define BRAND_NUM 54//牌堆的牌数
#define HAND_NUM 18//手牌的总数目

//1、声明一个扑克牌类，拥有方法：传入花色和点数生成扑克牌、打印扑克牌。
//2、声明一个玩家类，每人拥有18张扑克牌。拥有方法：增加手牌（摸牌）、展示手牌，其中展示手牌要求降序排序展示。
//完成程序：
//1、随机生成18张扑克牌，当做一个玩家的手牌。
//2、用54张不同的扑克牌构成牌堆，发给3个玩家。


class Poick
{
private:
	char m_Color;
	int m_Point;

public:
	void  Init(char color = 0, int point = 0)
	{
		if (color == 5)//初始化牌堆时，大王小王进来时color为5.point为1和2，对此进行处理
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
	char *point[16] = { " ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };
	char *color[5] = { "  ", "红桃", "梅花", "方片", "黑桃" };
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
	static int m_n;//玩家编号
	Poick m_card[HAND_NUM];//玩家手中的牌

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
				if (Brand_heap[i].Poick_Point() != -1 && Brand_heap[i].Poick_Color() != -1)//第i张牌未发，
				{
					m_card[j] = Brand_heap[i];
					Brand_heap[i].SetPoick(-1, -1);//将牌堆中下标为i的牌设置标记
					break;
				}
				else
				{
					i++;
				}
			}
		}
	}
	void Insert_m_card()//对手牌插入排序
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
		cout << "玩家" << m_n << "手牌:";
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