/*
实现一个函数，可以左旋字符串中的k个字符。
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/
#if 0
//char arr[5] = { 0 };
//char *left_hand_str(char*str, int n)
//{
//	char *tmp = str;
//	strcpy(arr, str + n);
//	char *p = (arr + strlen(str) - n);
//	while (n != 0)
//	{
//		*p++ = *tmp++;
//		--n;
//	}
//	return arr;
//}
char *left_hand_str(char* str, int n)//左旋函数
{
	char *p = str + strlen(str) - n;
	char *tmp = (char*)malloc(strlen(str));
	char *s = tmp;
	strcpy(tmp, str);
	strcpy(str, tmp + n);
	while (n != 0)
	{
		*p++ = *s++;
		--n;
	}
	//free(tmp);
	return str;
}//未释放tmp空间
int main()
{
	char str_arr[5] = "ABCD";
	int k;
	printf("请输入K的值：");
	scanf("%d", &k);
	printf("%s", left_hand_str(str_arr, k));
	return 0;
}
#endif
/*判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.

AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC

分析;旋转字符串特点有哪些？从特点入手，旋转前后长度不变，
*/
#if 1
char *left_hand_str(char* str, int n)//左旋函数
{
	char *p = str + strlen(str) - n;
	char *tmp = (char*)malloc(strlen(str));
	char *s = tmp;
	strcpy(tmp, str);
	strcpy(str, tmp + n);
	while (n != 0)
	{
		*p++ = *s++;
		--n;
	}
	//free(tmp);
	return str;
}
int leap_hand_str(char* str1, char* str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	int i = 0;
	for (i = 0; i < strlen(str1); ++i)
	{
		if (strcmp(str1, left_hand_str(str2, i)))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char str[] = "ABCD";
	char str1[] = "BCDA";
	scanf("%s", str);
	scanf("%s", str1);
	printf("%d\n", leap_hand_str(str, str1));
	return 0;
}
#endif