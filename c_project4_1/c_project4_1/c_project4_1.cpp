// c_project4_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
//2019 4 1 ���˽� ��һ
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
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
//ʹ�ú���ʵ���������Ľ����� 
//int main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	printf("x=%d y=%d\n", x, y);
//	swap(&x, &y);
//	printf("x=%d y=%d\n", x, y);
//	return 0;
//}
//ʵ��һ�������ж�year�ǲ������ꡣ 
//int leap_year(int year)
//{
//	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
//}
//int main()
//{
//	int i = 0;
//	printf("1000-2000֮��������У�");
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (1 == leap_year(i))
//		{
//			printf("%d\t", i);
//		}
//		else
//		{
//			//�������꣬����ӡ
//		}
//	}
//	return 0;
//}
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
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
//			printf("%d������\n",value);
//		}
//		else
//		{
//			//��������������ӡ��
//		}
//	}
//	return 0;
//}
