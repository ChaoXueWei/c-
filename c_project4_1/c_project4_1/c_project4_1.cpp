// c_project4_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
//2019 4 1 愚人节 周一
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//int main()
//{
//	int i, j;
//	int n;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d\t", i, j, i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//void swap(int *px, int*py)
//{
//	*px = *px ^ (*py);
//	*py = *px^(*py);
//	*px = *px ^ (*py);
//}
//使用函数实现两个数的交换。 
//int main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	printf("x=%d y=%d\n", x, y);
//	swap(&x, &y);
//	printf("x=%d y=%d\n", x, y);
//	return 0;
//}
//实现一个函数判断year是不是润年。 
//int leap_year(int year)
//{
//	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
//}
//int main()
//{
//	int i = 0;
//	printf("1000-2000之间的闰年有：");
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (1 == leap_year(i))
//		{
//			printf("%d\t", i);
//		}
//		else
//		{
//			//不是闰年，不打印
//		}
//	}
//	return 0;
//}
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//void swap(int *px, int*py)
//{
//	*px = *px ^ (*py);
//	*py = *px^(*py);
//	*px = *px ^ (*py);
//}
//void init(int arr[],int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		arr[i] = i;
//	}
//}
//void empty(int arr[], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void reverse(int arr[], int n)
//{
//	int i = 0;
//	for (i = 0; i < n / 2; i++)
//	{
//		swap(&arr[i], &arr[n - i - 1]);
//	}
//}
//void print(int arr[], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d\t", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10];
//	int size = sizeof(arr) / sizeof(arr[0]);
//	print(arr, size);
//	init(arr, size);
//	print(arr, size);
//	reverse(arr, size);
//	print(arr, size);
//	empty(arr, size);
//	print(arr, size);
//	return 0;
//}
//bool judge_prime(int num)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(num); i++)
//	{
//		if (0 == num%i)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	int value = 0;
//	while (1)
//	{
//		scanf("%d", &value);
//		if (judge_prime(value))
//		{
//			printf("%d是素数\n",value);
//		}
//		else
//		{
//			//不是素数，不打印。
//		}
//	}
//	return 0;
//}
