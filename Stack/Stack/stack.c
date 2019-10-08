#include"stack.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*STACK_SIZE);
	if (!ps->_a)
	{
		return;//�ڴ����ʧ�ܣ�
	}
	memset(ps->_a, 0, STACK_SIZE);
	ps->_capacity = STACK_SIZE;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps != NULL);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
	}
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps != NULL);
	if (ps->_capacity == ps->_top + 1)
	{
		STDataType*tmp = (STDataType*)realloc(ps->_a, ps->_capacity * 2);//ջ�ռ䲻�㣬����
		if (tmp == NULL)
		{
			return;//����ʧ�ܣ����أ���ջʧ�ܣ�
		}
		ps->_a = tmp;
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps != NULL && ps->_top!=0);
	ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps != NULL && ps->_top != 0);
	return ps->_a[ps->_top-1];
}
int StackEmpty(Stack* ps)
{
	assert(ps != NULL);
	return ps->_top == 0;
}
int StackSize(Stack* ps)
{
	assert(ps != NULL);
	return ps->_top;
}
void StackPrint(Stack* ps)
{
	assert(ps != NULL);
	for (int i = ps->_top-1; i>=0; i--)
	{
		printf("| %d |\n", ps->_a[i]);
		printf("-----\n");
	}
	putchar('\n');
}
void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPrint(&st);
	printf("�Ƿ�Ϊ��ջ�� %d\n", StackEmpty(&st));
	printf("ջ��Ԫ�ظ���Ϊ��%d\n", StackSize(&st));
	StackPush(&st, 0);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPrint(&st);
	StackPop(&st);
	StackPrint(&st);
	printf("ջ��Ԫ��Ϊ��%d\n", StackTop(&st));
	printf("�Ƿ�Ϊ��ջ�� %d\n", StackEmpty(&st));
	printf("ջ��Ԫ�ظ���Ϊ��%d\n", StackSize(&st));
	StackDestory(&st);
}
int main()
{
	TestStack();
	return 0;
}