#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*
动态分配线性表顺序存储结构
物理结构:存储结构相连
便于直接随机访问某个节点
*/

#define MAXSIZE 20//存储空间
#define OK 1//函数状态返回值,成功返回1,不成功返回0
#define ERROR 0//
#define TRUE 1//真假值，真为1,假为0
#define FALSE 0
typedef int Status;//Status是函数类型，其值是函数结果状态代码 
typedef int ElemType;
typedef struct
{
	ElemType *data;
	size_t length;
	size_t size;
}SeqList;
void InitList(SeqList*L);//初始化线性表
void Destory(SeqList *L);//销毁线性表
void ClearList(SeqList *L);//重置线性表
Status ListEmpty(SeqList L);//线性表是否为空
int ListLength(SeqList L);//返回线性表中元素的个数
ElemType *GetElem(SeqList *L, int i, ElemType *e);//取第i个元素的值返回给e
//Status LocateElem(SeqList L, ElemType e, int(*compare)(ElemType,ElemType));//查找第一个和e元素满足compare关系的数据元素位序，不存在返回0
Status LocateElem(SeqList L, ElemType e);//在L中查找和e元素值相等的数据元素，不存在返回0，成功返回查找成功
Status ListInsert(SeqList *L, int i, ElemType e);//在线性表L中第i个位置插入新元素e
void ListDelete(SeqList *L, int i, ElemType *e);//删除线性表L中第i个位置元素e
void ListPrint(SeqList *L);


#endif
