#include"sort.h"
#include<stdlib.h>
#include"queue.h"

/*
ð�������㷨
ʱ�临�Ӷȣ�---���:O(n)   ---�:O(n^2)  ---ƽ��O(n^2)
�ȶ��ԣ��ȶ�
*/
void BubbleSort(int*src, int n)//ð��
{
	int i, j, flag = 0;
	for (i = 0; i < n-1; i++)//���һ�β���Ҫ����Ϊ��������ֻʣһ��Ԫ�ش���
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
ѡ������
ʱ�临�Ӷȣ� ----���O(n^2)  ---�O(n^2)  ---ƽ��O(n^2)
�ȶ�
*/
void SelectSort(int* src, int n)//ѡ������
{
	int i, j;
	int min;//ʼ�ձ�ǽ�������������С�������±�
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
ֱ�Ӳ��������㷨
ʱ�临�Ӷȣ�  ----���O(n) ----�O(n^2) ---ƽ��O(n)
�ȶ��ԣ��ȶ�
*/
void InsertSort(int*src, int n)//��������
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int tmp = src[i];
		if (src[i - 1] > tmp)//ǰ���Ѿ����������i-1С�ڵ���tmp����˵��ǰ���������ݾ�С�ڵ���tmp���ʲ�����λ�ò���
		{
			for (j = i; j > 0 && src[j - 1]> tmp; j--)//jǰ�������Ѿ�����ֻ��Ҫ�ҵ���һ����tmpС�����ݣ�������֮��
			//for (j = i; j > 0; j--)//jǰ�������Ѿ�����ֻ��Ҫ�ҵ���һ����tmpС�����ݣ�������֮��
			{
				src[j] = src[j - 1];
			}
			src[j] = tmp;
		}
	}
}


/*
ϣ������
ʱ�临�Ӷȣ� ---���O(nlog)  ---�O(n^2)  ---ƽ��O(nlogn)~O(n^2)
���ȶ� 
*/
void ShellSort(int* src, int n)//ϣ������:�������
{
	int gap = n / 2;
	int i, j;
	for (gap=n /2; gap >= 1; gap /= 2)//gapΪÿ�ηֵ�����
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
�鲢����
ʱ�临�Ӷȣ� ---���O(nlogn)  ---�O(n^2)  ---ƽ��O(nlogn)
�ȶ�
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
	for (i = start; i <= end; i++)//���ϲ��õ����ݻ�ִ��src��
		//����end�����±꣬start�ǵ�һ���±꣬�±귶Χ�״�
	{
		src[i] = tmp[i];
	}
}
void MergeSort(int* src, int n)//�鲢����
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
������
ʱ�临�Ӷȣ� ---���O(nlogn)  ---�O(nlogn)  ---ƽ��O(nlogn)
�ȶ��ԣ����ȶ�

*/
//���µ����㷨�����±�Ϊi�Ľڵ����µ���
void adjustDown(int* arr, int size, int n)//nΪ�±�c
{
	int cur = n;
	while ((cur + 1) * 2 <= size)//ֻҪ�����Ӵ��ھ�Ҫ����ѭ��
	{
		if ((cur + 1) * 2 + 1 > size)
		{
			n = cur * 2 + 1;//û���Һ��ӣ�����Ϊ���ӽڵ�����ֵ
		}
		else
		{
			if (arr[cur * 2 + 1] > arr[cur * 2 + 2])//�ҳ��ҽڵ����ڵ��еĽϴ�ڵ㣬����n���
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (arr[cur] < arr[n])//�����Һ��ӽڵ���ڸýڵ�ʱ�����µ����ýڵ㣬���򣬾��Ѿ��γɴ󶥸������ټ���ѭ��
		{
			int tmp = arr[cur];
			arr[cur] = arr[n];
			arr[n] = tmp;
			cur = n;//ÿ�ν�����֮��cur���µ�n�±�,ʹ����������µ���
		}
		else
		{
			break;//���ӽڵ��С�ڸ��ڵ㣬�Ѿ����ɴ󶥶�
		}
	}
}
void HeapPrint(int* _a, int n)//��ӡ���νṹ
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
		adjustDown(src, --n, 0);//ÿ�ζԽ�����Ľڵ����µ�����n--
	}
}
/*
��������:�����棬˫ָ�뷨������ȡ�з�������������ȡ������Ҫ������
ʱ�临�Ӷȣ� ---���O(nlogn)  ---�O(n^2)  ---ƽ��O(nlogn)
b���ȶ�
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
	int* p = src+start;//ָ�������������
	int* q = src + end;//ָ������������Ҵ��������һ����������
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
		SwapArgs(p, q);//p<q&&pָ����ߴ���point������qָ���ұ�С��point���������߽���
	}
	//qָ��ֻ��ͣ��*q<=point�������ϣ�����q�ߵ���p��ָ����ʱq,p��ָ���ָ��p��ָ�򣬶�*p<=point,
	//����q��whileѭ����������˵����p������q����q��while()ִ����ǰ����������*q<=point,����qһֱ��ǰ��ֱ������p,
	//��������������������һ�֣�p,q������ָ��С�ڵ���point�������ָ�������ֻ�ܷ�����ߣ��պú�src[start]����
	SwapArgs(&src[start], p);//��point����p��q�Ľ���λ�ã����
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
	}//ʹ����������start�±�Ϊ�������м��С���Ǹ���
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
int DigWay(int* src, int start, int end)//�ڿӷ����ٲ���Ҫ��������ϻ�����
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
	}//ʹ����������start�±�Ϊ�������м��С���Ǹ���
	int tmp = src[start];//�����׼ֵ
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
	int mid;//��Ϊ��׼��
	if (start +8 < end)//������������������ݹ����
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
void QuickSort(int* src, int n)//��������
{
	Quicking(src, 0, n - 1);
}

//�ǵݹ�ʵ��
void QuickingNonR(int*src, int n)
{
	Queue qu;//����һ������
	int mid = n / 2;
	int start, end;
	QueueInit(&qu);//��ʼ������
	QueuePush(&qu, 0);//���±����
	QueuePush(&qu, n-1);//β�±����
	while (!QueueIsEmpty(&qu))
	{
		start = QueueTop(&qu);//ȡ��ͷԪ�أ���Ԫ���±꣩��
		QueuePop(&qu);//���ӣ�
		end = QueueTop(&qu);//ȡ��ͷԪ�أ���βԪ���±꣩
		QueuePop(&qu);//���ӣ�
		mid = DigWay(src, start, end);//���ú�������mid�����ҵ�����mid�����±�ֵ
		if (start < mid-1)//��mid�ֿ��������󲿷֣���β���
		{
			QueuePush(&qu, start);
			QueuePush(&qu, mid-1);
		}
		if (mid+1 < end)//��mid�Ұ벿����β�±����
		{
			QueuePush(&qu, mid+1);
			QueuePush(&qu, end);
		}
	}
	QueueDestory(&qu);//��������
}

