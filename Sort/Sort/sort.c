#include"sort.h"
#include<stdlib.h>
#include"queue.h"

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
稳定
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
			for (j = i; j > 0 && src[j - 1]> tmp; j--)//j前面数据已经有序，只需要找到第一个比tmp小的数据，插在它之后
			//for (j = i; j > 0; j--)//j前面数据已经有序，只需要找到第一个比tmp小的数据，插在它之后
			{
				src[j] = src[j - 1];
			}
			src[j] = tmp;
		}
	}
}


/*
希尔排序
时间复杂度： ---最好O(nlog)  ---最坏O(n^2)  ---平均O(nlogn)~O(n^2)
不稳定 
*/
void ShellSort(int* src, int n)//希尔排序:分组插排
{
	int gap = n / 2;
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

/*
归并排序
时间复杂度： ---最好O(nlogn)  ---最坏O(n^2)  ---平均O(nlogn)
稳定
*/
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

void SwapArgs(int* a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



/*
堆排序
时间复杂度： ---最好O(nlogn)  ---最坏O(nlogn)  ---平均O(nlogn)
稳定性：不稳定

*/
//向下调整算法，将下标为i的节点向下调整
void adjustDown(int* arr, int size, int n)//n为下标c
{
	int cur = n;
	while ((cur + 1) * 2 <= size)//只要有左孩子存在就要进入循环
	{
		if ((cur + 1) * 2 + 1 > size)
		{
			n = cur * 2 + 1;//没有右孩子，左孩子为孩子节点的最大值
		}
		else
		{
			if (arr[cur * 2 + 1] > arr[cur * 2 + 2])//找出右节点和左节点中的较大节点，并用n标记
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (arr[cur] < arr[n])//当左右孩子节点大于该节点时，向下调整该节点，否则，就已经形成大顶根，不再继续循环
		{
			int tmp = arr[cur];
			arr[cur] = arr[n];
			arr[n] = tmp;
			cur = n;//每次交换完之后将cur更新到n下标,使后面继续向下调整
		}
		else
		{
			break;//孩子节点均小于根节点，已经构成大顶堆
		}
	}
}
void HeapPrint(int* _a, int n)//打印树形结构
{
	int rn = 0;
	int bin = 1;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", _a[i]);
		if (i == rn)
		{
			putchar('\n');
			bin = bin * 2;
			rn += bin;
		}
	}
	putchar('\n');
}
void HeapSort(int* src, int n)
{
	int i = n / 2 + 1;
	//int j ;
	for (i = n / 2-1; i >= 0; i--)
	{
		adjustDown(src, n, i);
	}
	HeapPrint(src, n);
	for (i = n - 1; i > 0; i--)
	{
		SwapArgs(src + i, src);
		adjustDown(src, --n, 0);//每次对交换后的节点向下调整，n--
	}
}
/*
快速排序:基础版，双指针法，三数取中法（霍尔法），取消不必要交换版
时间复杂度： ---最好O(nlogn)  ---最坏O(n^2)  ---平均O(nlogn)
b不稳定
*/

int PointerWay(int* src, int start, int end)
{
	int point = src[start];
	while (start<end)
	{
		while (start< end && src[end] >= point)
		{
			end--;
		}
		SwapArgs(&src[start], &src[end]);
		while ( start<end && src[start] <= point)
		{
			start++;
		}
		SwapArgs(&src[start], &src[end]);
	}
	return start;
}
int doublePointerWay(int *src, int start, int end)
{
	int point = src[start];
	int* p = src+start;//指向操作数组最左处
	int* q = src + end;//指向操作数组最右处，即最后一个操作数据
	while (p < q)
	{
		while (p<q && *q >= point)
		{
			q--;
		}
		while (p<q && *p <= point)
		{
			p++;
		}
		SwapArgs(p, q);//p<q&&p指向左边大于point的数，q指向右边小于point的数，两者交换
	}
	//q指针只能停在*q<=point的数据上，除非q走到了p的指向，这时q,p的指向均指向p的指向，而*p<=point,
	//若从q的while循环跳出，则说明，p遇到了q，而q的while()执行在前，除非遇到*q<=point,否则q一直向前，直到遇到p,
	//因此无论这两种情况的哪一种，p,q的最终指向都小于等于point，故最后指向的数据只能放在左边，刚好和src[start]交换
	SwapArgs(&src[start], p);//将point换到p和q的交叉位置，左边
	return p - src;
}
int HoareWay(int* src, int start, int end)
{
	int mid = start + (end - start) / 2;
	if (src[mid] > src[end])
	{
		SwapArgs(&src[mid], &src[end]);
	}
	if (src[start] > src[end])
	{
		SwapArgs(&src[start], &src[end]);
	}
	if (src[mid] > src[start])
	{
		SwapArgs(&src[start], &src[mid]);
	}//使得三个数中start下标为三个数中间大小的那个数
	int point = src[start];
	while (start<end)
	{
		while (start < end && src[end] >= point)
		{
			end--;
		}
		SwapArgs(&src[start], &src[end]);
		while (start < end && src[start] <= point)
		{
			start++;
		}
		SwapArgs(&src[start], &src[end]);
	}
	return start;
}
int DigWay(int* src, int start, int end)//挖坑法减少不必要交换，结合霍尔法
{
	int mid = start + (end - start) / 2;
	if (src[mid] > src[end])
	{
		SwapArgs(&src[mid], &src[end]);
	}
	if (src[start] > src[end])
	{
		SwapArgs(&src[start], &src[end]);
	}
	if (src[mid] > src[start])
	{
		SwapArgs(&src[start], &src[mid]);
	}//使得三个数中start下标为三个数中间大小的那个数
	int tmp = src[start];//保存基准值
	while (start < end)
	{
		while (start < end &&src[end] >= tmp)
		{
			end--;
		}
		src[start] = src[end];
		while (start < end && src[start] <= tmp)
		{
			start++;
		}
		src[end] = src[start];
	}
	src[start] = tmp;
	return start;
}
void Quicking(int*src, int start, int end)
{
	int mid;//作为基准点
	if (start +8 < end)//满足条件，快速排序递归调用
	{
		//mid = PointerWay(src,start,end);
		//mid = doublePointerWay(src,start,end);
		//mid = HoareWay(src,start,end);
		mid = DigWay(src, start, end);
		Quicking(src, start, mid-1);
		Quicking(src, mid + 1, end);
	}
	else
	{
		InsertSort(src + start, end - start + 1);
	}
}
void QuickSort(int* src, int n)//快速排序
{
	Quicking(src, 0, n - 1);
}

//非递归实现
void QuickingNonR(int*src, int n)
{
	Queue qu;//定义一个队列
	int mid = n / 2;
	int start, end;
	QueueInit(&qu);//初始化队列
	QueuePush(&qu, 0);//首下标入队
	QueuePush(&qu, n-1);//尾下标入队
	while (!QueueIsEmpty(&qu))
	{
		start = QueueTop(&qu);//取队头元素（首元素下标），
		QueuePop(&qu);//出队，
		end = QueueTop(&qu);//取队头元素，（尾元素下标）
		QueuePop(&qu);//出队，
		mid = DigWay(src, start, end);//调用函数，将mid的左右调整并mid接收下标值
		if (start < mid-1)//将mid分开的数组左部分，首尾入队
		{
			QueuePush(&qu, start);
			QueuePush(&qu, mid-1);
		}
		if (mid+1 < end)//将mid右半部分首尾下标入队
		{
			QueuePush(&qu, mid+1);
			QueuePush(&qu, end);
		}
	}
	QueueDestory(&qu);//队列销毁
}

