#include<stdio.h>
#include<string.h>
#include<assert.h>
#if 0
int SodaConvert(int n)//nΪ��ƿ��
{
	//ÿ�β����Ŀ�ƿ��Ϊ��һ����ƿ��ģ2����һ����ƿ����һ��
	//ÿ�κȵ�������Ϊ��һ����ƿ����һ��
	int count = n;//��һ�κȵ����ϵ��ڵ�һ�β����Ŀ�ƿ��
	while (n>1)//����ƿ��Ϊ1ʱ���ٶһ����ϣ��˳�ѭ��
	{
		count += n / 2;
		n = n / 2 + n % 2;
	}
	return count;
}
int main()
{
	int k;
	printf("�����������Ľ�");
	scanf("%d", &k);
	int t = SodaConvert(k);
	printf("%d��Ǯһ�����Ժ�%dƿ���ϡ�\n", k, t);
	return 0;
}
#endif
#if 0
/*һ��������ֻ�����������ǳ���һ�Σ�
�����������ֶ����������Ρ�
�ҳ�������ֻ����һ�ε����֣����ʵ�֡� */
void BubbleSort(int *arr, int size)
{
	int i = 0, j = 0;
	int flag = 0;
	for (i = 0; i < size - 1; ++i)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; ++j)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 12, 4, 8, 9, 7, 6, 25, 8, 9, 7, 12, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	int i, j;
	if (arr[0] != arr[1])//�ж������ĵ�һ�����Ƿ��ǳ���һ��
	{
		printf("%d ", arr[0]);
	}
	if (arr[n - 2] != arr[n - 1])//�ж����������һ���Ƿ��ǳ���һ��
	{
		printf("%d ", arr[n - 1]);
	}
	for (i = 1; i < n - 1; i++)//���м���������жϣ��������ߵ����Ƿ�������ȣ����߾������˵��ֻ����һ�Σ�
	{
		if ((arr[i] != arr[i - 1])
			&& (arr[i] != arr[i + 1]))
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}
#endif
char *my_strcpy(char* Dest, const char* Src)
{
	if (Src == NULL)
	{
		assert(Src);
	}
	if (Dest == NULL){
		assert(Dest);
	}
	while (*Dest++ = *Src++);
	*Dest = '\0';
	return Dest;
}
char* my_strcat(char* Dest, char* Src)
{
	assert(Dest != NULL);
	assert(Src != NULL);
	char *tmp = Dest + strlen(Dest);
	while (*tmp++ = *Src++);
	*tmp = '\0';
	return Dest;
}
int main()
{
	char arr[] = { "dkgjdio" };
	char arr1[20] = { "ABCDE" };
	my_strcat(arr1, arr);
 	my_strcpy(arr1, arr);
	return 0;
}