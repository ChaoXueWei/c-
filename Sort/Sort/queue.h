#ifndef _QUEUE_H
#define _QUEUE_H
//#include"BinaryTree.h"
//#include"Stack.h"
#include<stdbool.h>
//ʵ����ͷ��ѭ������
typedef int QUDataType;
typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode*_next;
}QueueNode;
typedef struct SList
{
	QueueNode *_head;
	QueueNode *_rear;//��βָ��
}Queue;
void QueuePop(Queue*Qu);//����
void QueuePush(Queue*Qu, QUDataType x);//���
bool QueueIsEmpty(Queue*Qu);//
void QueueInit(Queue*Qu);//
void QueueDestory(Queue*Qu);//
QUDataType QueueTop(Queue*Qu);
//QueueNode* QueueTop(Queue*Qu);
#endif