#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"SeqList.h"
void InitList(SeqList*L)
{
	assert(L != NULL);
	L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	L->length = MAXSIZE;
	L->size = 0;
}
void Destory(SeqList *L)
{
	assert(L != NULL);
	if (L->data != NULL)
	{
		free(L->data);
		L->data = NULL;
	}
	L->size = 0;
	L->length = 0;
}
void ClearList(SeqList *L)
{
	assert(L != NULL);
	L->size = 0;
}
Status ListEmpty(SeqList L)
{
	return L.size == 0 ? TRUE : FALSE;
}
int ListLength(SeqList L)
{
	return L.size;
}
ElemType* GetElem(SeqList *L, int i, ElemType *e)
{
	assert(L != NULL &&i<=L->size);
	*e=L->data[i - 1];
	return e;
}

//Status LocateElem(SeqList L, ElemType e, int(*compare)(ElemType,ElemType));//查找第一个和e元素满足compare关系的数据元素位序，不存在返回0
Status LocateElem(SeqList L, ElemType e)
{
	int i = 0;
	for (i = 0; i < L.size; i++)
	{
		if (L.data[i] == e)
		{
			return OK;//查找到与e相等的元素值
		}
	}
	return ERROR;//没有与e元素值相等的值
}
Status ListInsert(SeqList *L, int i, ElemType e)
{
	assert(L != NULL);
	if (L->size + 1 > L->length)
	{
		L->length+= MAXSIZE;
		ElemType* new = (ElemType*)realloc(L->data, sizeof(ElemType)*L->length);//扩容，增加分配空间
		if (new == NULL)
		{
			return ERROR;
		}
		L->data = new;
	}
	int j = L->size;
	for (j = L->size; j > i-1; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->size++;
	L->data[j] = e;
	return OK;
}
void ListDelete(SeqList *L, int i, ElemType *e)
{
	assert(L != NULL);
	if (i > L->size)
	{
		return;
	}
	int j = 0;
	*e = L->data[i - 1];
	for (j = i - 1; j <= L->size; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->size--;
}

void ListPrint(SeqList *L)
{
	assert(L != NULL);
	int i = 0;
	for (i = 0; i <L->size; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

