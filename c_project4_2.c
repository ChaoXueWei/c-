#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
//2019 4 2 �ܶ�
//��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
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
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���
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
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//void reverse_string(char* string)//����ʹ��static����
//{
//	if (*string!='\0')
//	{
//		reverse_string(string + 1);
//		//(++string)������������ã��ı�string��ָ�򣬺�����ӡʱ��ʧ��Ϣ
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
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
//int myStrlenNoRecursive(char *string)//�ǵݹ�ʵ��
//{
//	int count = 0;
//	while (*string++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int myStrlenRecursive(char *string)//�ݹ�
//{
//	if (*string == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + myStrlenRecursive(string+1);
//		//���ﲻ��ʹ��string++����Ϊstring++����ʹ�ú�++
//	}
//}
//int main()
//{
//	char *p = "dfghjk";
//	printf("�ǵݹ飺%d\n", myStrlenNoRecursive(p));
//	printf("�ݹ飺%d\n", myStrlenRecursive(p));
//	return 0;
//}
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 
//int facRecursive(int n)//�ݹ�ʵ��
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
//int facNoRecursive(int n)//�ǵݹ�ʵ��
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
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
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