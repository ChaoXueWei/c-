#include<stdbool.h>
#include<stdlib.h>
#include"List.h"
#include"SeqList.h"
#if 0
void TestList()
{
	SeqList sq;
	ElemType val = 0;
	InitList(&sq);
	ListPrint(&sq);
	bool b = ListEmpty(sq);
	printf("bool b:%d \n", b);
	ListInsert(&sq, 1, 1);
	ListInsert(&sq, 2, 2);
	ListInsert(&sq, 3, 3);
	ListInsert(&sq, 4, 4);
	ListInsert(&sq, 5, 5);
	ListPrint(&sq);
	ListInsert(&sq, 3, 8);
	ListPrint(&sq);
	ListDelete(&sq, 2, &val);
	printf("删除元素的数据为：%d\n", val);
	ListPrint(&sq);
	int n = ListLength(sq);
	printf("sq中的元素个数为：%d\n", n);
	b = ListEmpty(sq);
	printf("bool b；%d\n", b);
	b = LocateElem(sq, 10);
	printf("bool b；%d\n", b);
	b = LocateElem(sq, 4);
	printf("bool b；%d\n", b);
	Destory(&sq);
}
#endif

void TestLink()
{
	LinkList list;
	ListDataType e;
	int length;
	bool empty;
	ListInit(&list);
	length = GetListLength(list);
	printf("链表长度为：%d\n", length);
	empty = ListIsEmpty(&list);
	printf("链表为空？%d\n", empty);
	InsertList(&list, 1, 1);
	InsertList(&list, 1, 2);
	InsertList(&list, 1, 3);
	InsertList(&list, 1, 4);
	InsertList(&list, 4, 5);
	InsertList(&list, 6, 6);
	InsertList(&list, 7, 7);
	PrintList(list);
	empty = Locate_exist_Elem(list, 9);
	printf("链表中存在9？%d\n", empty);
	empty = Locate_exist_Elem(list, 5);
	printf("链表中存在5？%d\n", empty);
	empty = ListIsEmpty(&list);
	printf("链表为空？%d\n", empty);
	length = GetListLength(list);
	printf("链表长度为：%d\n", length);
	PrintList(list);
	DeleteList(&list, 1, &e);
	length = GetListLength(list);
	printf("链表长度为：%d\n", length);
	printf("删除第1个的元素值为%d\n", e);
	empty = Locate_exist_Elem(list, e);
	printf("链表中存在%d？%d\n", e,empty);
	PrintList(list);
	DeleteList(&list, 4, &e);
	length = GetListLength(list);
	printf("链表长度为：%d\n", length);
	printf("删除第4个的元素值为%d\n", e);
	GetListElem(&list, 2, &e);
	PrintList(list);
	ListClear(&list);
	length = GetListLength(list);
	printf("链表长度为：%d\n", length);
	PrintList(list);
	ListDestory(&list);
}


int main()
{
	//TestList();
	TestLink();

	return 0;
}