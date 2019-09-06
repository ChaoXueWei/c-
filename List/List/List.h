#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*
��ͷָ���ͷ��㣺ͳһ��һ���ڵ�ͺ����ڵ�Ĳ���
��̬ʵ�ֵ�����
*/
#define MAXSIZE 20//�洢�ռ�
#define OK 1//����״̬����ֵ,�ɹ�����1,���ɹ�����0
#define ERROR 0//
#define TRUE 1//���ֵ����Ϊ1,��Ϊ0
#define FALSE 0
typedef int Status;//Status�Ǻ������ͣ���ֵ�Ǻ������״̬���� 
typedef int ListDataType;
//��������ڵ�����
typedef struct Node
{
	ListDataType data;
	struct Node *next;
}ListNode, *LinkList;
//typedef struct ListNode;
void ListInit(LinkList*list);//��ʼ������
void ListDestory(LinkList*list);//��������
Status InsertList(LinkList*list, int i, ListDataType e);//�ڵ�i��λ���ϲ���Ԫ��
Status DeleteList(LinkList*list, int i, ListDataType *e);//ɾ����iλ��Ԫ�أ�����������e����
void ListClear(LinkList*list);//�������
Status ListIsEmpty(LinkList list);//�ж����Ա��Ƿ�Ϊ��
int GetListLength(LinkList list);//��ȡ���Ա���
ListDataType *GetListElem(LinkList list, int i, ListDataType *e);//ȡ��i��Ԫ�ظ�e����
Status Locate_exist_Elem(LinkList list, ListDataType e);//list�������Ƿ����eԪ��
void PrintList(LinkList list);//��ӡ������
ListNode*combineLinkList(ListNode*list1, ListNode* list2);//�ϲ�


#endif
