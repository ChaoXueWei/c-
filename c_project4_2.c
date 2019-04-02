#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
//2019 4 2 周二
//编写一个函数实现n^k，使用递归实现 
//int recursive(int n, int k)
//{
//	if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return n*recursive(n, k - 1);
//	}
//}
//int main()
//{
//	int a, x;
//	scanf("%d%d", &a, &x);
//	printf("%d\n", recursive(a, x));
//	return 0;
//}
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是
//int DigitSum(int n)
//{
//	if (n>9)
//	{
//		return (n % 10 + DigitSum(n / 10));
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	printf("%d\n",DigitSum(num));
//	return 0;
//}
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//void reverse_string(char* string)//可以使用static变量
//{
//	if (*string!='\0')
//	{
//		reverse_string(string + 1);
//		//(++string)会产生附带作用，改变string的指向，后续打印时丢失信息
//	}
//	printf("%c", *string);
//}
//int main()
//{
//	char *p = "hellow vhkgiul";
//	reverse_string(p);
//	printf("\n");
//	system("pause");
//	return 0;
//}
//5.递归和非递归分别实现strlen 
//int myStrlenNoRecursive(char *string)//非递归实现
//{
//	int count = 0;
//	while (*string++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int myStrlenRecursive(char *string)//递归
//{
//	if (*string == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + myStrlenRecursive(string+1);
//		//这里不能使用string++，因为string++是先使用后++
//	}
//}
//int main()
//{
//	char *p = "dfghjk";
//	printf("非递归：%d\n", myStrlenNoRecursive(p));
//	printf("递归：%d\n", myStrlenRecursive(p));
//	return 0;
//}
//6.递归和非递归分别实现求n的阶乘 
//int facRecursive(int n)//递归实现
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*fac(n - 1);
//	}
//}
//int facNoRecursive(int n)//非递归实现
//{
//	int num;
//	int i;
//	for (i = 1; i <=n; i++)
//	{
//		num *= i;
//	}
//	return num;
//}
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	printf("%d\n", fac(num));
//	return 0;
//}
//递归方式实现打印一个整数的每一位 
//void printNum(int num)
//{
//	if (num == 0)
//	{
//		return;
//	}
//	printNum(num / 10);
//	printf("%d ", num % 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printNum(n);
//	return 0;
//}