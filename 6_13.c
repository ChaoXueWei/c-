#include<stdio.h>
//int main()
//{
//	//����һ�������ڲ���˵���������ı�����ַ��
//	//44332211 4433 44 ��Ӧ����a,b,c���ڴ��еĴ洢��ʽ
//	//ջ�ڿռ䣬�������ı�����ջ�ף���ַ��
//
//	int a = 0x11223344;
//	// 44 33 22 11  С�˴��
//	short int b = a;
//	//44 33 ��ǰ����ȡ��λ
//	char c = a;
//	//44 ��ǰ����ȡһλ��С��
//	printf("%x,%x,%x\n", a, b, c);
//	return 0;
//}
//int check_sys1()//��С���ж�
//{
//	int i = 0x1;
//	return  *(char*)&i;//char*����ָ��͵�ַ��Ȼ�󷵻ص͵�ַһ���ֽڵ�����
//}
//int check_sys2()//��С���жϺ���
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
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0; 
//}