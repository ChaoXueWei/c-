#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*
��̬�������Ա�˳��洢�ṹ
����ṹ:�洢�ṹ����
����ֱ���������ĳ���ڵ�
*/

#define MAXSIZE 20//�洢�ռ�
#define OK 1//����״̬����ֵ,�ɹ�����1,���ɹ�����0
#define ERROR 0//
#define TRUE 1//���ֵ����Ϊ1,��Ϊ0
#define FALSE 0
typedef int Status;//Status�Ǻ������ͣ���ֵ�Ǻ������״̬���� 
typedef int ElemType;
typedef struct
{
	ElemType *data;
	size_t length;
	size_t size;
}SeqList;
void InitList(SeqList*L);//��ʼ�����Ա�
void Destory(SeqList *L);//�������Ա�
void ClearList(SeqList *L);//�������Ա�
Status ListEmpty(SeqList L);//���Ա��Ƿ�Ϊ��
int ListLength(SeqList L);//�������Ա���Ԫ�صĸ���
ElemType *GetElem(SeqList *L, int i, ElemType *e);//ȡ��i��Ԫ�ص�ֵ���ظ�e
//Status LocateElem(SeqList L, ElemType e, int(*compare)(ElemType,ElemType));//���ҵ�һ����eԪ������compare��ϵ������Ԫ��λ�򣬲����ڷ���0
Status LocateElem(SeqList L, ElemType e);//��L�в��Һ�eԪ��ֵ��ȵ�����Ԫ�أ������ڷ���0���ɹ����ز��ҳɹ�
Status ListInsert(SeqList *L, int i, ElemType e);//�����Ա�L�е�i��λ�ò�����Ԫ��e
void ListDelete(SeqList *L, int i, ElemType *e);//ɾ�����Ա�L�е�i��λ��Ԫ��e
void ListPrint(SeqList *L);


#endif
