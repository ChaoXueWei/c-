#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"
void StackInit(Stack* psl, size_t capicity)
{
	assert(psl != NULL);
	psl->array = (STDataType*)malloc(sizeof(STDataType)*capicity);
	psl->capicity = capicity;
	psl->size = 0;
}
void StackDestory(Stack* psl)
{
	assert(psl != NULL);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
	}
	psl->size = 0;
}
void CheckCapicity(Stack* psl)
{
	assert(psl != NULL);
	psl->capicity *= 2;
	psl->array = (STDataType*)realloc(psl->array, psl->capicity*sizeof(STDataType));
}
void StackPush(Stack*psl, STDataType x)
{
	assert(psl != NULL);
	if (psl->capicity == psl->size )//ÅÐ¶ÏÕ»ÊÇ·ñÂú
	{
		CheckCapicity(psl);//À©ÈÝ
	}
	psl->array[psl->size] = x;
	psl->size++;
}
void StackPop(Stack*psl)
{
	assert(psl != NULL && psl->size!=NULL);
	psl->size--;
}
STDataType StackTop(Stack*psl)
{
	assert(psl != NULL);
	if (StackIsEmpty(psl))
	{
		return (STDataType)0;
	}
	return psl->array[psl->size - 1];
}
bool StackIsEmpty(Stack* psl)
{
	assert(psl != NULL);
	return psl->size == 0;
}