#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#define STACK_SIZE 20
typedef int STDataType;
typedef struct Stack 
{
	STDataType* _a;
	int _top;       // ջ��
	int _capacity;  // ���� 
}Stack;

void StackInit(Stack* ps);//��ʼ��ջ
void StackDestory(Stack* ps);//����
void StackPush(Stack* ps, STDataType x);//��ջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);//ȡջ��Ԫ��
int StackEmpty(Stack* ps);//�ж��Ƿ�Ϊ	��ջ
int StackSize(Stack* ps);//����ջ��Ԫ�ظ���
void TestStack();//���Ժ���

void StackPrint(Stack* ps);//��ӡջ
#endif
