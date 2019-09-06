#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*
带头指针的头结点：统一第一个节点和后续节点的操作
动态实现单链表
*/
#define MAXSIZE 20//存储空间
#define OK 1//函数状态返回值,成功返回1,不成功返回0
#define ERROR 0//
#define TRUE 1//真假值，真为1,假为0
#define FALSE 0
typedef int Status;//Status是函数类型，其值是函数结果状态代码 
typedef int ListDataType;
//定义链表节点类型
typedef struct Node
{
	ListDataType data;
	struct Node *next;
}ListNode, *LinkList;
//typedef struct ListNode;
void ListInit(LinkList*list);//初始化链表
void ListDestory(LinkList*list);//销毁链表
Status InsertList(LinkList*list, int i, ListDataType e);//在第i个位置上插入元素
Status DeleteList(LinkList*list, int i, ListDataType *e);//删除第i位的元素，并将数据用e返回
void ListClear(LinkList*list);//清空链表
Status ListIsEmpty(LinkList list);//判断线性表是否为空
int GetListLength(LinkList list);//获取线性表长度
ListDataType *GetListElem(LinkList list, int i, ListDataType *e);//取第i个元素给e返回
Status Locate_exist_Elem(LinkList list, ListDataType e);//list链表中是否存在e元素
void PrintList(LinkList list);//打印链表函数
ListNode*combineLinkList(ListNode*list1, ListNode* list2);//合并


#endif
