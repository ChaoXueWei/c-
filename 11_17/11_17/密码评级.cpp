#include <iostream>
#include <string>
using namespace std;
#if 0
int PwdSizeLevel(const string s)
{
	if (s.size() <= 4)
	{
		return 5;
	}
	else if (s.size() <= 7)
	{
		return 10;
	}
	else
	{
		return 25;
	}
}
int PwdLetterLevel(const string& pwdstr)
{
	int Capfalg = 0;//´óÐ´±ê¼Ç
	int lowerflag = 0;//Ð¡Ð´±ê¼Ç
	for (auto s : pwdstr)
	{
		if (s >= 'A'&&s <= 'Z')
		{
			Capfalg = 1;//´óÐ´×Ö·û´æÔÚ
		}
		if (s >= 'a'&&s <= 'z')
		{
			lowerflag = 1;//Ð¡Ð´×Ö·û´æÔÚ
		}
		if (Capfalg == 1 && lowerflag == 1)
		{
			return 20;
		}
	}
	if (Capfalg == 1 || lowerflag == 1)
	{
		return 10;
	}
	else
	{
		return 0;
	}
}
int PwdExitNum(const string &s)
{
	int count = 0;//Êý×Ö¸öÊý
	for (auto i : s)
	{
		if (i <= '9'&&i >= '0')
		{
			count++;
		}
		if (count > 1)
		{
			return 20;
		}
	}
	if (count == 1)
	{
		return 10;
	}
	return 0;
}
int PwdExitSymbol(const string &s)
{
	int Symcount = 0;//·ûºÅ¸öÊý
	for (auto i : s)
	{
		if ((i >= 0x21 && i <= 0x2F)
			|| (i >= 0x3A && i <= 0x40)
			|| (i >= 0x5B && i <= 0x60)
			|| (i >= 0x7B && i <= 0x7E)
			)
		{
			Symcount++;
		}
		if (Symcount > 1)
		{
			return 25;
		}
	}
	if (Symcount == 1)
	{
		return 10;
	}
	return 0;
}
int PwdLevelreward(const string &s)
{
	if ((PwdLetterLevel(s) >= 20) &&
		(PwdExitNum(s) > 0) &&
		(PwdExitSymbol(s) > 0)
		)
		//ÃÜÂëÖÐ´æÔÚ´óÐ¡Ð´ÒÔ¼°·ûºÅºÍÊý×Ö
	{
		return 5;
	}
	if ((PwdLetterLevel(s) > 0) &&
		(PwdExitNum(s) > 0) &&
		(PwdExitSymbol(s) > 0)
		)
		//´æÔÚ×Ö·û¡¢×ÖÄ¸¡¢·ûºÅ
	{
		return 3;
	}
	if ((PwdLetterLevel(s) > 0) && (PwdExitNum(s) > 0))
		//´æÔÚ×ÖÄ¸ºÍÊý×Ö
	{
		return 2;
	}
	return 0;
}

int GetPwdSecurityLevel(const string s)
{
	int PwdSource = 0;
	PwdSource += PwdSizeLevel(s);//¸ù¾ÝÃÜÂë³¤¶ÈÅÐ¶Ï
	PwdSource += PwdLetterLevel(s);//ÃÜÂë×ÖÄ¸ÅÐ¶¨
	PwdSource += PwdExitNum(s);//ÃÜÂëÊý×ÖÅÐ¶¨
	PwdSource += PwdExitSymbol(s);//ÃÜÂë·ûºÅÅÐ¶¨
	PwdSource += PwdLevelreward(s);//ÃÜÂë½±ÀøÅÐ¶¨
	return PwdSource;
}
int main()
{
	int sum = 0; 
	string str;
	char PwdOut[][15] = { "VERY_WEAK", "WEAK", "AVERAGE", "STRONG", "VERY_STRONG", "SECURE", "VERY_SECURE" };
	int PwdLevel = 0;
	while (cin >> str)
	{
		/*cout << "ÃÜÂë³¤¶ÈÅÐ¶¨£º"<<PwdSizeLevel(str) << endl;
		cout << "ÃÜÂë×ÖÄ¸ÅÐ¶¨£º" << PwdLetterLevel(str) << endl;
		cout << "ÃÜÂëÊý×ÖÅÐ¶¨£º" << PwdExitNum(str) << endl;
		cout << "ÃÜÂë·ûºÅÅÐ¶¨£º" << PwdExitSymbol(str) << endl;
		cout << "ÃÜÂë½±ÀøÅÐ¶¨£º" << PwdLevelreward(str) << endl;*/
		/*for (int i = 0; i < 7; i++)
		{
			cout << PwdOut[i] << endl;
		}
		cout << "ÃÜÂëµÈ¼¶×Ü¼Æ£º" << GetPwdSecurityLevel(str) << endl;*/
		PwdLevel = GetPwdSecurityLevel(str);
		if (PwdLevel >= 90)
		{
			cout << PwdOut[6] << endl;
		}
		else if (PwdLevel >= 80)
		{
			cout << PwdOut[5] << endl;
		}
		else if (PwdLevel >= 70)
		{
			cout << PwdOut[4] << endl;
		}
		else if (PwdLevel >= 60)
		{
			cout << PwdOut[3] << endl;
		}
		else if (PwdLevel >= 50)
		{
			cout << PwdOut[2] << endl;
		}
		else if (PwdLevel >= 25)
		{
			cout << PwdOut[1] << endl;
		}
		else
		{
			cout << PwdOut[0] << endl;
		}
	}

	return 0;
}

#endif