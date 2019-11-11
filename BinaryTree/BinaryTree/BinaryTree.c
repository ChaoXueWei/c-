#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"
#include<assert.h>
#include<stdlib.h>
BTNode* BinaryTreeCreate(BTDataType* src)
{
	assert(src != NULL);
	static int s_n = 0;
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	BTNode*cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;
	cur->lchild = BinaryTreeCreate(src);
	cur->rchild = BinaryTreeCreate(src);
	return cur;//��cur��㷵��
}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTNode*tmp = root;
	BinaryTreeDestory(root->lchild);
	BinaryTreeDestory(root->rchild);
	free(tmp);
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	putchar(root->data);
	BinaryTreePrevOrder(root->lchild);
	BinaryTreePrevOrder(root->rchild);
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->lchild);
	putchar(root->data);
	BinaryTreeInOrder(root->rchild);
}
void BinaryTreePostOrder(BTNode*root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->lchild);
	BinaryTreePostOrder(root->rchild);
	putchar(root->data);
}
void BinaryTreeLevelOrder(BTNode*root)
{
	assert(root != NULL);
	BTNode* cur = root;
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);//�Ƚ����ݸ��ڵ���ջ
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);//cruָ��ջ��Ԫ��,
		putchar(cur->data);
		if (cur->lchild)//�����ӣ�������ջ
		{
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild)//���Һ��ӡ��Һ�����ջ
		{
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);//curָ���ջ���������Һ��Ӿ�����ջ��ջ��Ԫ�ش�ʱ���Գ�ջ
	}
	//����һ��������������ѱ��ٳֵĹ��£�Ȼ��������������������̻�ȡ���ʵĹ��̣������������ջ���Ƿ��ѣ�������Ҫ��ȥ���͵������������ӽ�����
	QueueDestory(&qu);
}

//�ǵݹ�ǰ�к������
void BinaryTreePrevOrderNonR(BTNode* root)
{
	assert(root != NULL);
	Stack st;
	BTNode*cur = root;//�Ӹ��ڵ㿪ʼ
	StackInit(&st, 100);
	while (cur)
	{
		putchar(cur->data);//���ʵ�ǰ�ڵ�
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);//�Һ�����ջ
		}
		if (cur->lchild)//�ж�ʱ���������
		{
			cur = cur->lchild;//���Ӳ�Ϊ�գ�������������
		}
		else
		{
			cur = StackTop(&st);//�����ӣ�curָ��δ���ʵ���ײ�����ӣ���ջ��Ԫ�أ�
			if (cur != NULL && !StackIsEmpty(&st))
			{
				StackPop(&st);//ջ��Ԫ���ѽ�curָ�򣬿��Գ�ջ
				//������������һ���ڵ�֮��(ȡ��ջ�����һ��Ԫ��)�����һ���ڵ������Һ��ӣ�curΪ��,�����ڱ�������cur�����Һ���ʱ��ִ�г�ջ����ʱջ������Ԫ��
			}
		}
	}
	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode*root)
//�ӵ�ǰ�ڵ㼰�����ǲ���ջ
//ֱ��������Ϊ�գ�ȡ��ջ��������,
//������Һ��ӣ������Һ��ӣ����ص�1����
//û���Һ��ӣ���ִ�в���2��ȡջ��
{
	assert(root != NULL);
	Stack st;
	BTNode*cur = root;//���ڵ�����ջ��
	StackInit(&st,100);
	while (cur!=NULL || !StackIsEmpty(&st))
	{
		for (; cur; cur=cur->lchild)//��ÿ���ڵ㼰������ڵ�����ջ
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);//��curָ��δ������������ڵ��ӡ
		putchar(cur->data);//����curָ��Ľڵ�
		StackPop(&st);//�������ջ
		cur = cur->rchild;//����һ����ջ
	}
	StackDestory(&st);
}
//void BinaryTreePostOrderNonR(BTNode* root)
////�����ڵ㼰��������ջ��LT���δ���ʣ���ֱ��������Ϊ�գ�         ## LT:���������ʱ�ǣ��������е�tag����
////ȡ��ջ����������LT��ǣ�����������������������������ڣ����ʹ���1����������������ڣ��������3
////ȡ��ջ����ӡ��Ȼ������ĸ��ڵ��LT�Ƿ�Ҳ����λ������ǣ���һ����ӡ��ֱ���ҵ���һ��LT�ڵ���Ϊ���״̬ʱ��Ȼ��ص�����2
////tips:����Ǵ�1���̽���Ĺ���2����ô��ζ������ڵ�û��������������LTҪ��λ��
////����ǹ���3����Ĺ���2����ô��ζ������ڵ���������Լ��Ǹ�������ϣ�����LTҪ��λ��ѭ����ӡ��ԭ���ǣ�������ڵ��LTҲ����λ������ζ���ҵ�ǰ����Ľڵ�Ϊ���ڵ���������������������������������ˣ����ڵ��Ҳ���Դ�ӡ��
//{
//	char tag[64];
//	BTNode * cur = root;
//	Stack st;
//	StackInit(&st, 100);
//	do
//	{
//		for (; cur; cur = cur->lchild)//�������򣬽���ǰ�ڵ㼰��������ջ
//		{
//			StackPush(&st, cur);
//			tag[st.size - 1] = 0;//�������������ʱ�ǣ�(LT)
//		}
//		while (!StackIsEmpty(&st) && tag[st.size - 1])//ǰ�������ֻ�����һ��ѭ��������ʱ����Ч
//			//�����������Ϊ�������
//			//1.��curΪ�գ������for����������������
//			//2.��cur��Ϊ�գ������for�����������������
//			//�����⵽��ǰ
//		{
//			cur = StackTop(&st);
//			putchar(cur->data);
//			StackPop(&st);
//		}
//		if (!StackIsEmpty(&st))//������ֻ�����һ��ѭ������ʱ��Ч���������ĸ��ڵ�������ջ����ջΪ��ʱ˵�����ڵ��ѳ�����������ӡ�꣬����
//		{
//			cur = StackTop(&st);
//			//1.��������while���ˣ���ô֤��������������ϣ���LT��λ
//			//2.��������whileû������ô֤�������������ڣ���LT��λ
//			tag[st.size - 1] = 1;
//			cur = cur->rchild;
//		}
//	}
//	while (!StackIsEmpty(&st));//���ں�������и��ڵ��Ǻ����ջ��
//	StackDestory(&st);
//}

void BinaryTreePostOrderNonR(BTNode* root)
{
	assert(root != NULL);
	Stack st;
	BTNode* cur = root;
	char tag[64];
	StackInit(&st,100);
	do
	{
		for (; cur; cur=cur->lchild)//������������
		{
			StackPush(&st, cur);
			tag[st.size-1] = 0;
		}
		while (!StackIsEmpty(&st) && tag[st.size-1]==1)//st.size-1Ϊ1����ζ�ţ��ýڵ��Ѿ��������Һ��Ӷ��ѷ��ʹ�,
		{
			cur = StackTop(&st);
			putchar(cur->data);//�Խڵ�Ĳ��������ʽڵ�
			StackPop(&st);
		}
		if (!StackIsEmpty(&st))//�ص���һ����Һ����ϣ���
		{
			cur = StackTop(&st);
			tag[st.size-1] = 1;//�ı���ڵ�ı��λ�����Ǳ�������ѷ��ʹ����ٴ������ø��ڵ�Ϳɳ�ջ����
			cur = cur->rchild;//�ص��Һ����ϣ���������ͬ����ʽ���������Һ���
		}
	}while (!StackIsEmpty(&st));//������ڵ���������ջ������ջ�ģ����Ե����ڵ��ջ֮��˵��ջ�գ��������������꣡
	StackDestory(&st);
}

//ͳ�ƽڵ����
//int BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	return BinaryTreeSize(root->lchild) + BinaryTreeSize(root->rchild)+1;//������쳲��������еĵݹ�ʵ�֣���ջ�ռ�Ŀ����ϴ�Ҳ���Էǵݹ�ʵ��
//}
int BinaryTreeSize(BTNode* root)//�����������ʵ�����нڵ�ĸ���ͳ��
{
	assert(root != NULL);
	int count = 0;
	Queue qu;
	BTNode*cur = root;
	QueueInit(&qu);
	QueuePush(&qu, cur);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		count++;
		if (cur->lchild)
		{
			QueuePush(&qu,cur->lchild);
		}
		if (cur->rchild)
		{
			QueuePush(&qu,cur->rchild);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return count;
}
//ͳ�Ʒ�Ҷ�ӽڵ�ĸ���
//int BinaryTreeNotLeafSize(BTNode* root)
//{
//	if (root == NULL)//����Ҷ�ӽڵ�ĺ�ڵ�ֱ�ӷ���0
//	{
//		return 0;
//	}
//	if (root->lchild == NULL && root->rchild == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return BinaryTreeNotLeafSize(root->lchild) + BinaryTreeNotLeafSize(root->rchild) + 1;
//	}
//}

//�ǵݹ�ǰ���������ʽͳ�Ʒ�Ҷ�ӽڵ�ĸ���
int BinaryTreeNotLeafSize(BTNode*root)
{
	assert(root != NULL);
	int count=0;
	Stack st;
	BTNode* cur = root;
	StackInit(&st,100);
	StackPush(&st, root);
	while (!StackIsEmpty(&st))
	{
		if (cur->lchild != NULL || cur->rchild != NULL)
		{
			count++;
		}
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild)
		{
			cur=cur->lchild;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
	return count;
}

//ͳ��Ҷ�ӽڵ�ĸ���
//int BinaryTreeLeafSize(BTNode* root)
//{
//	if (root->lchild != NULL && root->rchild != NULL)//���Һ��Ӿ���Ϊ�գ���������������Ҷ�ӽڵ����
//	{
//		return BinaryTreeLeafSize(root->lchild) + BinaryTreeLeafSize(root->rchild);
//	}
//	if (root->lchild == NULL && root->rchild == NULL)//�ҵ�Ҷ�ӽڵ㣬����1
//	{
//		return 1;
//	}
//	else if (root->lchild==NULL)//����Ϊ�գ���ô�Һ���һ����Ϊ�գ�������������Ҷ�ӽڵ����
//	{
//		return BinaryTreeLeafSize(root->rchild);
//	}
//	else
//	{
//		return BinaryTreeLeafSize(root->lchild);//���Ӳ�Ϊ�գ�������������Ҷ�ӽڵ����
//	}
//}

//�ǵݹ��������ͳ��Ҷ�ӽڵ�ĸ���
int BinaryTreeLeafSize(BTNode* root)
{
	assert(root != NULL);
	int count = 0;
	Stack st;
	StackInit(&st,100);
	BTNode*cur = root;
	while (cur!=NULL || !StackIsEmpty(&st))//�������ѭ��������cur!=NULLΪ��һ�ν���ѭ��������
	{
		for (; cur; cur = cur->lchild)
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);//ÿ��ȡ���Ķ���δ������������߽ڵ㣨����������ص㣩
		if (cur->lchild == NULL && cur->rchild == NULL)
		{
			count++;
		}
		cur = cur->rchild;//���������ƶ�����cur->rchildΪ��ʱ�������ƶ������ڵ����������ڵ㣻��cur->rchild��Ϊ��ʱ�Ӹ��ڵ��ƶ����Һ��ӣ�
		StackPop(&st);
	}
	StackDestory(&st);
	return count;
}

//ͳ�ƶ�������ĳһ��Ľڵ����
int BinaryTreeLevelKSize(BTNode * pRoot, int k)
{
	if (pRoot == NULL || k < 1)
		return 0;
	if (k == 1)
		return 1;
	int numLeft = BinaryTreeLevelKSize(pRoot->lchild, k - 1); // ��������k-1��Ľڵ����
	int numRight = BinaryTreeLevelKSize(pRoot->rchild, k - 1); // ��������k-1��Ľڵ����
	return (numLeft + numRight);
}
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	assert(root != NULL);
//	int curcount=1, nextcount=0;//����Ľڵ����������һ��Ľڵ�����������������ӵĸ�����
//	int count=1;//���ڵ㣬��һ��Ľڵ����
//	Queue qu;
//	QueueInit(&qu);
//	BTNode* cur = root;
//	QueuePush(&qu,root);
//	while (!QueueIsEmpty(&qu))
//	{
//		if (count == k)//�жϲ���
//		{
//			return curcount;//��ʱnextcount��curcount����Ķ���count��Ľڵ����
//		}
//		cur = QueueTop(&qu);
//		if (cur->lchild != NULL)
//		{
//			QueuePush(&qu, cur->lchild);
//			nextcount++;
//		}
//		if (cur->rchild != NULL)
//		{
//			QueuePush(&qu, root->rchild);
//			nextcount++;
//		}
//		QueuePop(&qu);
//		curcount--;//�����ջ������ڵ�����һ
//		if (curcount == 0)//��ǰ���ѳ��꣬
//		{
//			count++;//������һ��
//			curcount = nextcount;//����һ��Ľڵ��������һ��
//			nextcount = 0;//nextcount ����ͳ����һ��δ��ӵĽڵ����
//		}
//	}
//	QueueDestory(&qu);
//	return -1;
//}