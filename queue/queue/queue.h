#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef int QUDataType;
//实现无头不循环队列
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;
void QueueInit(Queue* pq);//初始化队列
void QueueDestory(Queue* pq);//销毁队列
void QueuePush(Queue*pq, QUDataType x);//入队列
void QueuePop(Queue*pq);//出队列
QUDataType QueueFront(Queue* pq);//取对首元素
QUDataType QueueBack(Queue*pq);//取队尾元素
int QueueEmpty(Queue*pq);//队列是否为空
int QueueSize(Queue*pq);//队列元素个数
void TestQueue();

#endif}
