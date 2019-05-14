#include<stdio.h>
#include<string.h>
#include<assert.h>
#if 0
int SodaConvert(int n)//n为空瓶数
{
	//每次产生的空瓶数为上一个空瓶数模2加上一个空瓶数的一半
	//每次喝的饮料数为上一个空瓶数的一半
	int count = n;//第一次喝的饮料等于第一次产生的空瓶数
	while (n>1)//当空瓶数为1时不再兑换饮料，退出循环
	{
		count += n / 2;
		n = n / 2 + n % 2;
	}
	return count;
}
int main()
{
	int k;
	printf("请输入您给的金额：");
	scanf("%d", &k);
	int t = SodaConvert(k);
	printf("%d块钱一共可以喝%d瓶饮料。\n", k, t);
	return 0;
}
#endif
#if 0
/*一个数组中只有两个数字是出现一次，
其他所有数字都出现了两次。
找出这两个只出现一次的数字，编程实现。 */
void BubbleSort(int *arr, int size)
{
	int i = 0, j = 0;
	int flag = 0;
	for (i = 0; i < size - 1; ++i)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; ++j)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 12, 4, 8, 9, 7, 6, 25, 8, 9, 7, 12, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	int i, j;
	if (arr[0] != arr[1])//判断排序后的第一个数是否是出现一次
	{
		printf("%d ", arr[0]);
	}
	if (arr[n - 2] != arr[n - 1])//判断排序后的最后一数是否是出现一次
	{
		printf("%d ", arr[n - 1]);
	}
	for (i = 1; i < n - 1; i++)//对中间的数进行判断，左右两边的数是否与他相等，两边均不相等说明只出现一次，
	{
		if ((arr[i] != arr[i - 1])
			&& (arr[i] != arr[i + 1]))
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}
#endif
char *my_strcpy(char* Dest, const char* Src)
{
	if (Src == NULL)
	{
		assert(Src);
	}
	if (Dest == NULL){
		assert(Dest);
	}
	while (*Dest++ = *Src++);
	*Dest = '\0';
	return Dest;
}
char* my_strcat(char* Dest, char* Src)
{
	assert(Dest != NULL);
	assert(Src != NULL);
	char *tmp = Dest + strlen(Dest);
	while (*tmp++ = *Src++);
	*tmp = '\0';
	return Dest;
}
int main()
{
	char arr[] = { "dkgjdio" };
	char arr1[20] = { "ABCDE" };
	my_strcat(arr1, arr);
 	my_strcpy(arr1, arr);
	return 0;
}