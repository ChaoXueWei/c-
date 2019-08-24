#include"sort.h"
#include<stdlib.h>
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
			//for (j = i; j > 0 && src[j - 1]> tmp; j--)//jǰ�������Ѿ�����ֻ��Ҫ�ҵ���һ����tmpС�����ݣ�������֮��
			for (j = i; j > 0; j--)//jǰ�������Ѿ�����ֻ��Ҫ�ҵ���һ����tmpС�����ݣ�������֮��
			{
				src[j] = src[j - 1];
			}
			src[j] = tmp;
		}
	}
}


/*
ϣ������
ʱ�临�Ӷȣ� ---���O()  ---�O()  ---ƽ��O()
*/
void ShellSort(int* src, int n)//ϣ������:�������
{
	int k,gap = n / 2;
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

//void QuickSort(int* src, int n)//��������
//{
//
//}
