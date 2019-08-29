#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"
#define BUFSIZE 10000

int main()
{
#if 0

	int src[10] = { 3,8,5,9,7,3,6,4,2,0};
	//BubbleSort(src, 10);
	//SelectSort(src, 10);
	//InsertSort(src, 10);
	//ShellSort(src, 10); 
	//MergeSort(src, 10);
	QuickSort(src, 10);
	//QuickingNonR(src, 10);
	//HeapSort(src, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", src[i]);
	}
#else
	int i = 0;
	int src[BUFSIZE] = { 0 };
	srand(time(NULL));
	for (i = 0; i < BUFSIZE; i++)
	{
		src[i] = rand() % 6000 + 1;
	}
	//BubbleSort(src, BUFSIZE);//229ms
	//for (i = 0; i < BUFSIZE; i++)
	//{
	//	src[i] = rand() % 6000 + 1;
	//}
	//SelectSort(src, BUFSIZE);//119ms
	//for (i = 0; i < BUFSIZE; i++)
	//{
	//	src[i] = rand() % 6000 + 1;
	//}
	//InsertSort(src, BUFSIZE);//62ms
	//ShellSort(src, BUFSIZE);
	//MergeSort(src, BUFSIZE);
	QuickSort(src, BUFSIZE);
	//QuickingNonR(src, BUFSIZE);
	//HeapSort(src, BUFSIZE);

	for (i = 0; i < BUFSIZE; i++)
	{
		printf("%d ", src[i]);
	}
#endif
	printf("\n");
	system("pause");
	return 0;
}
