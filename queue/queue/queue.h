#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef int QUDataType;
//ʵ����ͷ��ѭ������
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
void QueueInit(Queue* pq);//��ʼ������
void QueueDestory(Queue* pq);//���ٶ���
void QueuePush(Queue*pq, QUDataType x);//�����
void QueuePop(Queue*pq);//������
QUDataType QueueFront(Queue* pq);//ȡ����Ԫ��
QUDataType QueueBack(Queue*pq);//ȡ��βԪ��
int QueueEmpty(Queue*pq);//�����Ƿ�Ϊ��
int QueueSize(Queue*pq);//����Ԫ�ظ���
void TestQueue();

#endif}
