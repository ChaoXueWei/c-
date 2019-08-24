#include"sort.h"
#include<stdlib.h>
/*
冒泡排序算法
时间复杂度：---最好:O(n)   ---最坏:O(n^2)  ---平均O(n^2)
稳定性：稳定
*/
void BubbleSort(int*src, int n)//冒泡
{
	int i, j, flag = 0;
	for (i = 0; i < n-1; i++)//最后一次不需要，因为出最后最后只剩一个元素待排
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (src[j] > src[j + 1])
			{
				int tmp = src[j];
				src[j] = src[j + 1];
				src[j + 1] = tmp;
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}

/*
选择排序
时间复杂度： ----最好O(n^2)  ---最坏O(n^2)  ---平均O(n^2)
*/
void SelectSort(int* src, int n)//选择排序
{
	int i, j;
	int min;//始终标记接下来遍历中最小的数据下标
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i; j < n; j++)
		{
			if (src[min] > src[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int tmp = src[i];
			src[i] = src[min];
			src[min] = tmp;
		}
	}
}
/*
直接插入排序算法
时间复杂度：  ----最好O(n) ----最坏O(n^2) ---平均O(n)
稳定性：稳定
*/
void InsertSort(int*src, int n)//插入排序
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int tmp = src[i];
		if (src[i - 1] > tmp)//前面已经有序，如果当i-1小于等于tmp，则说明前面所有数据均小于等于tmp，故不用找位置插入
		{
			//for (j = i; j > 0 && src[j - 1]> tmp; j--)//j前面数据已经有序，只需要找到第一个比tmp小的数据，插在它之后
			for (j = i; j > 0; j--)//j前面数据已经有序，只需要找到第一个比tmp小的数据，插在它之后
			{
				src[j] = src[j - 1];
			}
			src[j] = tmp;
		}
	}
}


/*
希尔排序
时间复杂度： ---最好O()  ---最坏O()  ---平均O()
*/
void ShellSort(int* src, int n)//希尔排序:分组插排
{
	int k,gap = n / 2;
	int i, j;
	for (gap=n /2; gap >= 1; gap /= 2)//gap为每次分的组数
	{
		for (i = gap; i < n; i++)
		{
			int tmp = src[i];
			for (j = i; j - gap >= 0 && src[j -gap] > tmp; j -= gap)
			{
				src[j] = src[j-gap];
			}
			src[j] = tmp;
		}
	}
}


void Merging(int* src,int* tmp,int start,int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = start + (end - start) / 2;
	int i = start, j = mid+1;
	int k = start;
	Merging(src, tmp, start, mid );
	Merging(src,tmp,mid+1,end);
	while (i<=mid && j<=end)
	{
		if (src[i] < src[j])
		{
			tmp[k] = src[i];
			i++;
			k++;
		}
		else
		{
			tmp[k] = src[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		tmp[k] = src[i];
		i++;
		k++;
	}
	while (j <= end)
	{
		tmp[k] = src[j];
		k++;
		j++;
	}
	for (i = start; i <= end; i++)//将合并好的数据回执到src内
		//这里end最后的下标，start是第一个下标，下标范围易错
	{
		src[i] = tmp[i];
	}
}
void MergeSort(int* src, int n)//归并排序
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	Merging(src, tmp, 0, n-1);
	free(tmp);
}

//void QuickSort(int* src, int n)//快速排序
//{
//
//}
