/*
ʵ��һ�����������������ַ����е�k���ַ���
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
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
char *left_hand_str(char* str, int n)//��������
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
}//δ�ͷ�tmp�ռ�
int main()
{
	char str_arr[5] = "ABCD";
	int k;
	printf("������K��ֵ��");
	scanf("%d", &k);
	printf("%s", left_hand_str(str_arr, k));
	return 0;
}
#endif
/*�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.

AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAABC

����;��ת�ַ����ص�����Щ�����ص����֣���תǰ�󳤶Ȳ��䣬
*/
#if 1
char *left_hand_str(char* str, int n)//��������
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