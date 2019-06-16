#ifndef _MY_STRING_C
#define _MY_STRING_C
#include<assert.h>
#include<stdlib.h>
int my_strncmp(const char *str1, const char*str2, size_t n)
{
	assert(str1 != NULL && str2 != NULL);
	while (*str1 == *str2
		&&*str1 != '\0'
		&&*str2 != '\0'
		&& n - 1 > 0//前n个数据比较，偏移量为0到n-1
		)
	{
		str1++;
		str2++;
		n--;
	}
	//退出循环时说明前面n个以字符比较完
	//或者两个数据不想等，或者其中一个已经走到'\0'

	//直接返回结果的差
	return *str1 - *str2;
	//返回+-1，和源码保持一致
	//if (n == 0)
	//{
	//	return 0;//n为0,说明前n个数据均相等
	//}
	//else
	//{
	//	return (*str1 - *str2) ? 1 : -1;//这里说明前n位还没比较完就出现了不相等，返回不相等的结果
	//}
}

char * my_strncat(char *dest, const char *src, size_t n)
{
	char *addrs = dest;
	assert(dest != NULL&&&src != NULL);
	while (*addrs)
	{
		addrs++;
	}
	while (n--)
	{
		*addrs++ = *src++;
	}
	return dest;
}

char* my_strncpy(char* dest, const char* src, size_t count)
{
	assert(dest != NULL&&src != NULL);
	char *addrs = dest;
	while (count--)
	{
		*addrs++ = *src++;
	}
	//如果当strlen(dest)<count时，这里需要对拷贝完后面的原数据进行清空,这里库中没有涉及到,如果需要去掉下面注释即可
	/*while (*addrs != '\0')
	{
	*addrs = '\0';
	}*/
	return dest;
}

size_t my_strlen(char *str)
{
	assert(str != NULL);
	char *p = str;
	while (*p)
	{
		++p;
	}
	return p - str;
}

char* my_strcpy(char* Dest, const char* Src)
{
	assert(Dest != NULL&&Src != NULL);
	char* temp = Dest;
	while (*Dest++ = *Src++);
	//这里当Src指向\0时，先将\0赋给Src后再判断是否退出循环
	return temp;//链式表达式：该函数返回值作为变量参加另一个函数的参数
}

char* my_strcat(char* Dest, const char* Src)
//在调用该函数之前考虑Dest存储空间是否充足
{
	char* address = Dest;
	assert(Dest != NULL&&Src != NULL);
	while (*address)
	{
		address++;
	}//此时address指向\0,这里如果直接while(*dest++);会导致dest指针找到‘\0’后移动到\0之后导致追加的字符串和源字符串之间多了一个'\0’
	while (*address++ = *Src++);
	return Dest;
}

char* my_strstr(const char *str1, const char*str2)
{
	//分析：当str2走完说明匹配成功，
	//对应位置不相同则直接对str1++，且记录str1的记录
	//对应字符比较，直到*str2=='\0'，否则回到上一步
	char *s1 = (char*)str1;
	const char *start = str1;
	const char *s2 = str2;
	assert(str1 != NULL&&str2 != NULL);
	while (*str1 != '\0')
	{
		str1 = s1;
		str2 = s2;
		while (*str1 != '\0'&& *str2 != '\0'&&*str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
		{
			return s1;
		}
		/*if (*str1 == '\0')
		{
		return NULL;
		}*/
		s1++;
	}
	return NULL;
}
//int my_strcmp(const char* Src,const char* Dest)
//{
//	assert(Src != NULL&&Dest != NULL);
//	while ((*Src == *Dest)&&((*Src)!= '\0')&&(*Dest!='\0'))
//		//当SrcDest指向的内容不相等时或者Dest还是Src某一个指向了结束符时退出
//	{
//		++Src;
//		++Dest;
//	}
//	return (*Src - *Dest);
//}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL&&str2 != NULL);
	while (*str1 == *str2
		&& (*str1) != '\0'
		&& (*str2) != '\0')
	{
		str1++;
		str2++;
	};
	if (*str1 == *str2)
	{
		return 0;
	}
	return ((*str1 - *str2>0) ? 1 : -1);//源码只返回了+-1，保持与源码一直;
	//return (*str1-*str2);//更直接的返回正负数，
}

void* my_memcpy(void* Dest, const void* Src, size_t len)
//将类型转化为char型,然后再一个字节一个字节的拷贝；可能出现内存重叠导致出现拷贝错误
{
	assert(Dest != NULL&&Src != NULL);
	char* dest = (char*)Dest;
	const char* src = (char*)Src;
	while (len-->0)
	{
		*dest++ = *src++;
	}
	return Dest;
}

void* my_memove(void* Dest, const void* Src, size_t len)
//内存移动解决了内存重叠带来的错误，解决办法在Dest和Src的头指针相隔len个字节长度的前提下从后向前拷贝
{
	assert(Dest != NULL&&Src != NULL);
	char* dest = (char*)Dest;
	char* src = (char*)Src;
	if (dest <= src || dest >= src + len)//满足条件说明不会发生内存重叠,则可以从头向后正常拷贝
	{
		while (len--)
		{
			*dest++ = *src++;
		}
	}
	else//不满足上述条件，则说明可能会出现内存重叠，因此需要从尾部向前反向拷贝
	{
		dest = (char*)Dest + len - 1;
		src = (char*)Src + len - 1;
		while (len--)
		{
			*dest-- = *src--;
		}
	}
	return Dest;
}
#endif _MY_STRING_C