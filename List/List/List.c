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
	(*list)->next = NULL;//*listΪͷ���
}
void ListDestory(LinkList*list)//����ɾ��ͷ���֮��Ľڵ㣬���ͷ���ɾ��
{
	assert(list != NULL);
	ListNode* tmp = (*list)->next;//tmpָ�򼴽���ɾ���Ľڵ㣬list֮��Ľڵ�
	while (tmp)
	{
		(*list)->next = (*list)->next->next;
		free(tmp);
		tmp = (*list)->next;
	}
	free(*list);//�ͷ�ͷ���
	(*list) = NULL;
}
Status InsertList(LinkList*list, int i, ListDataType e)
{
	assert(list != NULL);
	if (i < 1)
	{
		return ERROR;//λ�ô�1��ʼ
	}
	int j = 0;
	ListNode*new = (ListNode*)malloc(sizeof(ListNode));
	ListNode*cur = (*list);//��ͷ���֮��Ľڵ���Ϊ��һ���ڵ�
	for (cur; cur&&j < i-1; cur = cur -> next,j++)
	{
		
	}
	if (j == i - 1)//��j=i-1ʱ��cur�ĺ�̽ڵ㼴����Ҫ����Ľڵ�new
	{
		new->data = e;
		new->next = cur->next;
		cur->next = new;
		return OK;//����ɹ�
	}
	else
	{
		return ERROR;//����ʧ�ܣ�iλ�ó����������ĳ���
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
		return ERROR;//δ֪���󣬵�i��λ�ò����ڽڵ�
	}
	else
	{
		tmp = cur->next;
		cur->next = cur->next->next;//ɾ���ڵ�cur->next
		*e = tmp->data;
		free(tmp);//�ͷŽڵ�
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
		return NULL;//curλ��û�����ݣ�iֵ������������
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