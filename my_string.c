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
		&& n - 1 > 0//ǰn�����ݱȽϣ�ƫ����Ϊ0��n-1
		)
	{
		str1++;
		str2++;
		n--;
	}
	//�˳�ѭ��ʱ˵��ǰ��n�����ַ��Ƚ���
	//�����������ݲ���ȣ���������һ���Ѿ��ߵ�'\0'

	//ֱ�ӷ��ؽ���Ĳ�
	return *str1 - *str2;
	//����+-1����Դ�뱣��һ��
	//if (n == 0)
	//{
	//	return 0;//nΪ0,˵��ǰn�����ݾ����
	//}
	//else
	//{
	//	return (*str1 - *str2) ? 1 : -1;//����˵��ǰnλ��û�Ƚ���ͳ����˲���ȣ����ز���ȵĽ��
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
	//�����strlen(dest)<countʱ��������Ҫ�Կ���������ԭ���ݽ������,�������û���漰��,�����Ҫȥ������ע�ͼ���
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
	//���ﵱSrcָ��\0ʱ���Ƚ�\0����Src�����ж��Ƿ��˳�ѭ��
	return temp;//��ʽ���ʽ���ú�������ֵ��Ϊ�����μ���һ�������Ĳ���
}

char* my_strcat(char* Dest, const char* Src)
//�ڵ��øú���֮ǰ����Dest�洢�ռ��Ƿ����
{
	char* address = Dest;
	assert(Dest != NULL&&Src != NULL);
	while (*address)
	{
		address++;
	}//��ʱaddressָ��\0,�������ֱ��while(*dest++);�ᵼ��destָ���ҵ���\0�����ƶ���\0֮����׷�ӵ��ַ�����Դ�ַ���֮�����һ��'\0��
	while (*address++ = *Src++);
	return Dest;
}

char* my_strstr(const char *str1, const char*str2)
{
	//��������str2����˵��ƥ��ɹ���
	//��Ӧλ�ò���ͬ��ֱ�Ӷ�str1++���Ҽ�¼str1�ļ�¼
	//��Ӧ�ַ��Ƚϣ�ֱ��*str2=='\0'������ص���һ��
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
//		//��SrcDestָ������ݲ����ʱ����Dest����Srcĳһ��ָ���˽�����ʱ�˳�
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
	return ((*str1 - *str2>0) ? 1 : -1);//Դ��ֻ������+-1��������Դ��һֱ;
	//return (*str1-*str2);//��ֱ�ӵķ�����������
}

void* my_memcpy(void* Dest, const void* Src, size_t len)
//������ת��Ϊchar��,Ȼ����һ���ֽ�һ���ֽڵĿ��������ܳ����ڴ��ص����³��ֿ�������
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
//�ڴ��ƶ�������ڴ��ص������Ĵ��󣬽���취��Dest��Src��ͷָ�����len���ֽڳ��ȵ�ǰ���´Ӻ���ǰ����
{
	assert(Dest != NULL&&Src != NULL);
	char* dest = (char*)Dest;
	char* src = (char*)Src;
	if (dest <= src || dest >= src + len)//��������˵�����ᷢ���ڴ��ص�,����Դ�ͷ�����������
	{
		while (len--)
		{
			*dest++ = *src++;
		}
	}
	else//������������������˵�����ܻ�����ڴ��ص��������Ҫ��β����ǰ���򿽱�
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