#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void ListInit(LinkList*list)
{
	assert(list != NULL);
	*list = (ListNode*)malloc(sizeof(ListNode));
	if (*list == NULL)
	{
		exit(-1);
	}
	(*list)->next = NULL;//*list为头结点
}
void ListDestory(LinkList*list)//不断删除头结点之后的节点，最后将头结点删除
{
	assert(list != NULL);
	ListNode* tmp = (*list)->next;//tmp指向即将被删除的节点，list之后的节点
	while (tmp)
	{
		(*list)->next = (*list)->next->next;
		free(tmp);
		tmp = (*list)->next;
	}
	free(*list);//释放头结点
	(*list) = NULL;
}
Status InsertList(LinkList*list, int i, ListDataType e)
{
	assert(list != NULL);
	if (i < 1)
	{
		return ERROR;//位置从1开始
	}
	int j = 0;
	ListNode*new = (ListNode*)malloc(sizeof(ListNode));
	ListNode*cur = (*list);//将头结点之后的节点作为第一个节点
	for (cur; cur&&j < i-1; cur = cur -> next,j++)
	{
		
	}
	if (j == i - 1)//当j=i-1时，cur的后继节点即就是要插入的节点new
	{
		new->data = e;
		new->next = cur->next;
		cur->next = new;
		return OK;//插入成功
	}
	else
	{
		return ERROR;//插入失败，i位置超过了链表的长度
	}
}
Status DeleteList(LinkList*list, int i, ListDataType *e)
{
	assert(list != NULL);
	int j = 0;
	ListNode* cur = (*list);
	ListNode*tmp=NULL;
	while (i>1&&cur!=NULL)
	{
		cur = cur->next;
		i--;
	}
	if (cur->next == NULL)
	{
		return ERROR;//未知错误，第i个位置不存在节点
	}
	else
	{
		tmp = cur->next;
		cur->next = cur->next->next;//删除节点cur->next
		*e = tmp->data;
		free(tmp);//释放节点
		return OK;
	}
}
void ListClear(LinkList*list)
{
	assert(list != NULL);
	ListNode*cur = (*list)->next;
	while (cur)
	{
		(*list)->next = (*list)->next->next;
		free(cur);
		cur = (*list)->next;
	}
}
Status ListIsEmpty(LinkList list)
{
	assert(list != NULL);
	return list->next == NULL ? TRUE : FALSE;
}
int GetListLength(LinkList list)
{
	int count = 0;
	ListNode*cur = list->next;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

ListDataType *GetListElem(LinkList list, int i, ListDataType *e)
{
	assert(list != NULL);
	ListNode* cur = list->next;
	while (cur && i > 1)
	{
		cur = cur->next;
		i--;
	}
	if (cur == NULL)
	{
		return NULL;//cur位置没有数据，i值超过链表长度
	}
	else
	{
		*e = cur->data;
		return e;
	}
}
Status Locate_exist_Elem(LinkList list, ListDataType e)
{
	ListNode*cur = list->next;
	while (cur)
	{
		if (cur->data == e)
		{
			return TRUE;
		}
		cur = cur->next;
	}
	return FALSE;
}

void PrintList(LinkList list)
{
	assert(list != NULL);
	ListNode*cur = list->next;
	printf("Head->");
	for (; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}

void SortInsertList(ListNode*pHead,ListDataType e)
{
	assert(pHead != NULL);
	ListNode*cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode*new = cur;
	cur->next = pHead;
	int flag = 0;
	while (cur->next!= NULL)
	{
		if (cur->next->data >= e)
		{
			ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
			newNode->data = e;
			newNode->next = cur->next;
			cur->next = newNode;
			flag = 1;
			break;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (flag == 0)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->data = e;
		newNode->next = NULL;
		cur->next = newNode;
	}
	free(new);
}
ListNode*combineLinkList(ListNode*list1,ListNode* list2)
{
	if (list1 == NULL || list2 == NULL)//如果一个为NULL,直接返回另一个链表
	{
		return list1 == NULL ? list2 : list1;
	}
	ListNode*cur = list1;
	while (list2!=NULL&&cur!=NULL)
	{
		if (!Locate_exist_Elem(cur, list2->data))//判断list2->data在list1中是否存在
		{
			SortInsertList(cur,list2->data);//插入该元素
		}
		list2 = list2->next;
	}
	return list1;
}