#include <iostream>
#include <cstdio>
using namespace std;
#if 0
#pragma pack(8)
struct unknown
{
	int a;//4
	char b;//8
	int c;//12
	long d;//16
	char e;//20
};
struct unknown
{
	char b;
	char e;//2
	int a;//8
	int c;//12
	long d;//16 or 24(64位系统)
};
//output : 32
#pragma pack()

int main()
{
	/*printf("%lu\n", sizeof(struct unknown));
	printf("%lu\n", sizeof(struct unknown1));*/

	return 0;
}
#endif

#if 0
//#pragma pack(4)
struct A
{
	int a1;
	char a2;
	int a3;
	long a4;
	char a5;
};
struct child
{
	char c;
	int i;
	int d;
};
struct parent
{
	char d;
	struct child cd;
	long e;
};

int main()
{
	struct A a;
	//printf("int  a1:%d\n", (unsigned int)(void*)&a.a1 - (unsigned int)(void*)&a);
	//printf("char a2:%d\n", (unsigned int)(void*)&a.a2 - (unsigned int)(void*)&a);
	//printf("int  a3:%d\n", (unsigned int)(void*)&a.a3 - (unsigned int)(void*)&a);
	//printf("long a4:%d\n", (unsigned int)(void*)&a.a4 - (unsigned int)(void*)&a);
	//printf("char a5:%d\n", (unsigned int)(void*)&a.a5 - (unsigned int)(void*)&a);
	//printf("sizeof(long):%d\n", sizeof(long));
	//printf("sizeof(A):%d\n", sizeof(a));

	//发生结构体嵌套时的对齐
	struct parent ps;
	printf("ps.cd:%d\n", (unsigned int)(void*)&ps.cd - (unsigned int)(void*)&ps);//cd对齐的默认对齐参数为ps结构中使用的最大对齐参数（4）
	printf("ps.e:%d\n", (unsigned int)(void*)&ps.e - (unsigned int)(void*)&ps);//
	printf("sizeof(struct child):%d\n", sizeof(struct child));
	printf("sizeof(struct parent):%d\n",sizeof(struct parent));
	return 0;
}
//#pragma pack()
#endif


//位域的存储方式
struct A
{
	unsigned a : 19;
	unsigned b : 11;
	unsigned c : 4;
	unsigned d : 29;
	char index;
};
/*
还有一种常见的情况，结构体中含位域字段。位域成员不能单独被取sizeof值。C99规定int、unsigned int和bool可以作为位域类型，但编译器几乎都对此作了扩展，允许其它类型类型的存在。

使用位域的主要目的是压缩存储，其大致规则为：
	1) 如果相邻位域字段的类型相同，且其位宽之和小于类型的sizeof大小，则后面的字段将紧邻前一个字段存储，直到不能容纳为止；
	2) 如果相邻位域字段的类型相同，但其位宽之和大于类型的sizeof大小，则后面的字段将从新的存储单元开始，其偏移量为其类型大小的整数倍；
	3) 如果相邻的位域字段的类型不同，则各编译器的具体实现有差异，gcc通常采用压缩的方式；
	4) 如果位域字段之间穿插着非位域字段，则不进行压缩；
	5) 整个结构体的总大小为对齐方式的整数倍。对齐方式取最宽基本类型成员大小和默认对齐方式的较小者。
	本文链接：https://blog.csdn.net/nape1006/article/details/19427095
*/

/*
另一篇博文，更加详细：
一。内存对齐
————————————————
版权声明：本文为CSDN博主「xing_hao」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xing_hao/article/details/6678048
*/
int main()
{

	return 0;
}