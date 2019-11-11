#ifndef _STACK_H_
#define _STACK_H_
#include"BinaryTree.h"
#include<stdio.h>
typedef BTNode* STDataType;
typedef struct StackNode
{
	STDataType* array;
	size_t size;
	size_t capicity;
}Stack;
void StackInit(Stack* psl, size_t capicity);
void StackDestory(Stack* psl);

void StackPush(Stack*psl, STDataType x);
void StackPop(Stack*psl);
STDataType StackTop(Stack*psl);
bool StackIsEmpty(Stack* psl);

#endif//end _STACK_H
