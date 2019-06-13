#include<stdio.h>
//int main()
//{
//	//对于一个函数内部来说，先声明的变量地址高
//	//44332211 4433 44 对应变量a,b,c在内存中的存储形式
//	//栈内空间，先声明的变量在栈底，地址高
//
//	int a = 0x11223344;
//	// 44 33 22 11  小端存放
//	short int b = a;
//	//44 33 从前向后截取两位
//	char c = a;
//	//44 从前向后截取一位，小段
//	printf("%x,%x,%x\n", a, b, c);
//	return 0;
//}
//int check_sys1()//大小端判断
//{
//	int i = 0x1;
//	return  *(char*)&i;//char*类型指向低地址，然后返回低地址一个字节的数据
//}
//int check_sys2()//大小端判断函数
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	int ret = check_sys1();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0; 
//}