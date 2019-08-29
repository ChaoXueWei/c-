#ifndef _QUEUE_H
#define _QUEUE_H
//#include"BinaryTree.h"
//#include"Stack.h"
#include<stdbool.h>
//实现无头不循环队列
typedef int QUDataType;
typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode*_next;
}QueueNode;
typedef struct SList
{
	QueueNode *_head;
	QueueNode *_rear;//队尾指针
}Queue;
void QueuePop(Queue*Qu);//出队
void QueuePush(Queue*Qu, QUDataType x);//入队
bool QueueIsEmpty(Queue*Qu);//
void QueueInit(Queue*Qu);//
void QueueDestory(Queue*Qu);//
QUDataType QueueTop(Queue*Qu);
//QueueNode* QueueTop(Queue*Qu);
#endif