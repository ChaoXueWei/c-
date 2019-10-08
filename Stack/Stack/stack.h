#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#define STACK_SIZE 20
typedef int STDataType;
typedef struct Stack 
{
	STDataType* _a;
	int _top;       // 栈顶
	int _capacity;  // 容量 
}Stack;

void StackInit(Stack* ps);//初始化栈
void StackDestory(Stack* ps);//销毁
void StackPush(Stack* ps, STDataType x);//入栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);//取栈顶元素
int StackEmpty(Stack* ps);//判断是否为	空栈
int StackSize(Stack* ps);//返回栈中元素个数
void TestStack();//测试函数

void StackPrint(Stack* ps);//打印栈
#endif
