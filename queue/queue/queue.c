#include"queue.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void QueueInit(Queue* pq)
{
	assert(pq != NULL);
	pq->_front = pq->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq != NULL);
	QueueNode*tmp =NULL;
	while (pq->_front->_next)
	{
		tmp = pq->_front;
		pq->_front = pq->_front->_next;
		free(tmp);
		tmp = NULL;
	}
}
void QueuePush(Queue*pq, QUDataType x)
{
	assert(pq != NULL);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (!newNode)
	{
		return;//插入失败
	}
	newNode->_data = x;
	newNode->_next = NULL;
	if (pq->_front == pq->_rear&&pq->_front==NULL)//这里注意入队第一个节点和后续节点的方式不同
	{
		pq->_front = pq->_rear = newNode;
	}
	else
	{
		pq->_rear->_next = newNode;
		pq->_rear = newNode;
	}
}
void QueuePop(Queue*pq)
{
	assert(pq != NULL);
	QueueNode*cur = pq->_front;
	pq->_front = pq->_front->_next;
	free(cur);
	cur = NULL;
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq != NULL);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue*pq)
{
	assert(pq != NULL);
	return pq->_rear->_data;
}
int QueueEmpty(Queue*pq)
{
	assert(pq != NULL);
	return pq->_front == pq->_rear;
}
int QueueSize(Queue*pq)
{
	assert(pq != NULL);
	int count = 0;
	QueueNode*cur = pq->_front;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

void QueuePrint(Queue*pq)
{
	assert(pq != NULL);
	QueueNode*cur = pq->_front;
	while (cur)
	{
		printf("%d ->", cur->_data);
		cur = cur->_next;
	}
	printf("rear\n");
}
void TestQueue()
{
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	QueuePush(&qu, 4);
	QueuePush(&qu, 5);
	printf("queue首元素：%d\n", QueueFront(&qu));
	printf("queue未元素：%d\n", QueueBack(&qu));
	printf("queue中元素个数：%d\n", QueueSize(&qu));
	QueuePrint(&qu);

	QueuePop(&qu);
	printf("queue首元素：%d\n", QueueFront(&qu));
	printf("queue未元素：%d\n", QueueBack(&qu));
	printf("queue中元素个数：%d\n", QueueSize(&qu));
	QueuePrint(&qu);
	
	QueuePop(&qu);
	printf("queue首元素：%d\n", QueueFront(&qu));
	printf("queue未元素：%d\n", QueueBack(&qu));
	printf("queue中元素个数：%d\n", QueueSize(&qu));
	QueuePrint(&qu);
	

	

	QueueDestory(&qu);
}
int main()
{
	TestQueue();
	return 0;
}
