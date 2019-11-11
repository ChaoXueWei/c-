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
	return cur;//将cur结点返回
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
	QueuePush(&qu, root);//先将根据根节点入栈
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);//cru指向栈顶元素,
		putchar(cur->data);
		if (cur->lchild)//有左孩子，左孩子入栈
		{
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild)//有右孩子。右孩子入栈
		{
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);//cur指向的栈顶结点的左右孩子均已入栈，栈顶元素此时可以出栈
	}
	//这是一个老祖宗误入匪窝被劫持的故事，然后它的两个子孙们来相继换取人质的过程，子子孙孙，这里栈就是匪窝，父代想要出去，就得先让两个孩子进来。
	QueueDestory(&qu);
}

//非递归前中后序遍历
void BinaryTreePrevOrderNonR(BTNode* root)
{
	assert(root != NULL);
	Stack st;
	BTNode*cur = root;//从根节点开始
	StackInit(&st, 100);
	while (cur)
	{
		putchar(cur->data);//访问当前节点
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);//右孩子入栈
		}
		if (cur->lchild)//判断时间否还有左孩子
		{
			cur = cur->lchild;//左孩子不为空，继续访问左孩子
		}
		else
		{
			cur = StackTop(&st);//无左孩子，cur指向未访问到最底层的左孩子（即栈顶元素）
			if (cur != NULL && !StackIsEmpty(&st))
			{
				StackPop(&st);//栈顶元素已将cur指向，可以出栈
				//这里遍历完最后一个节点之后(取出栈中最后一个元素)，最后一个节点无左右孩子，cur为空,但是在本函数中cur无左右孩子时会执行出栈，此时栈中已无元素
			}
		}
	}
	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode*root)
//从当前节点及左孩子们并入栈
//直到左子树为空，取出栈顶并访问,
//如果有右孩子，访问右孩子，并回到1步骤
//没有右孩子，则执行步骤2。取栈顶
{
	assert(root != NULL);
	Stack st;
	BTNode*cur = root;//根节点先入栈，
	StackInit(&st,100);
	while (cur!=NULL || !StackIsEmpty(&st))
	{
		for (; cur; cur=cur->lchild)//将每个节点及它的左节点们入栈
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);//将cur指向未遍历到的最左节点打印
		putchar(cur->data);//访问cur指向的节点
		StackPop(&st);//访问完出栈
		cur = cur->rchild;//当上一步出栈
	}
	StackDestory(&st);
}
//void BinaryTreePostOrderNonR(BTNode* root)
////将根节点及左孩子们入栈（LT标记未访问），直至左子树为空，         ## LT:左子树访问标记，即代码中的tag数组
////取出栈顶，将它的LT标记，访问它的右子树，如果右子树存在，访问过程1，如果右子树不存在，进入过程3
////取出栈顶打印，然后检它的父节点的LT是否也被置位，如果是，则一并打印，直到找到第一个LT节点标记为清空状态时，然后回到过程2
////tips:如果是从1过程进入的过程2，那么意味着这个节点没有左子树，所以LT要置位。
////如果是过程3进入的过程2，那么意味着这个节点的左子树以及那个访问完毕，所以LT要置位，循环打印的原因是，如果父节点的LT也被置位，则意味着我当前处理的节点为父节点的右子树。所以左右子树都被处理完了，父节点可也可以打印了
//{
//	char tag[64];
//	BTNode * cur = root;
//	Stack st;
//	StackInit(&st, 100);
//	do
//	{
//		for (; cur; cur = cur->lchild)//类似中序，将当前节点及左孩子们入栈
//		{
//			StackPush(&st, cur);
//			tag[st.size - 1] = 0;//重置左子树访问标记，(LT)
//		}
//		while (!StackIsEmpty(&st) && tag[st.size - 1])//前面的条件只在最后一次循环跳出的时候生效
//			//后面的条件分为两个情况
//			//1.当cur为空，上面的for不进，此条件成立
//			//2.当cur不为空，上面的for进，则此条件不成立
//			//如果检测到当前
//		{
//			cur = StackTop(&st);
//			putchar(cur->data);
//			StackPop(&st);
//		}
//		if (!StackIsEmpty(&st))//此条件只在最后一次循环跳出时生效，整个树的根节点最先入栈，当栈为空时说明根节点已出，整棵树打印完，结束
//		{
//			cur = StackTop(&st);
//			//1.如果上面的while进了，那么证明左子树访问完毕，给LT置位
//			//2.如果上面的while没进，那么证明左子树不存在，给LT置位
//			tag[st.size - 1] = 1;
//			cur = cur->rchild;
//		}
//	}
//	while (!StackIsEmpty(&st));//由于后序遍历中根节点是后序出栈的
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
		for (; cur; cur=cur->lchild)//连续访问左孩子
		{
			StackPush(&st, cur);
			tag[st.size-1] = 0;
		}
		while (!StackIsEmpty(&st) && tag[st.size-1]==1)//st.size-1为1就意味着，该节点已经被将左右孩子都已访问过,
		{
			cur = StackTop(&st);
			putchar(cur->data);//对节点的操作，访问节点
			StackPop(&st);
		}
		if (!StackIsEmpty(&st))//回到上一层的右孩子上，并
		{
			cur = StackTop(&st);
			tag[st.size-1] = 1;//改变根节点的标记位，就是标记左孩子已访问过，再次遇到该根节点就可出栈访问
			cur = cur->rchild;//回到右孩子上，接下来以同样方式继续访问右孩子
		}
	}while (!StackIsEmpty(&st));//这里根节点是最先入栈，最后出栈的，所以当根节点出栈之后说明栈空，即二叉树访问完！
	StackDestory(&st);
}

//统计节点个数
//int BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	return BinaryTreeSize(root->lchild) + BinaryTreeSize(root->rchild)+1;//类似于斐波那契数列的递归实现，对栈空间的开销较大，也可以非递归实现
//}
int BinaryTreeSize(BTNode* root)//层序遍历方法实现所有节点的个数统计
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
//统计非叶子节点的个数
//int BinaryTreeNotLeafSize(BTNode* root)
//{
//	if (root == NULL)//对于叶子节点的后节点直接返回0
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

//非递归前序遍历的形式统计非叶子节点的个数
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

//统计叶子节点的个数
//int BinaryTreeLeafSize(BTNode* root)
//{
//	if (root->lchild != NULL && root->rchild != NULL)//左右孩子均不为空，返回左右子树的叶子节点个数
//	{
//		return BinaryTreeLeafSize(root->lchild) + BinaryTreeLeafSize(root->rchild);
//	}
//	if (root->lchild == NULL && root->rchild == NULL)//找到叶子节点，返回1
//	{
//		return 1;
//	}
//	else if (root->lchild==NULL)//左孩子为空，那么右孩子一定不为空，返回右子树的叶子节点个数
//	{
//		return BinaryTreeLeafSize(root->rchild);
//	}
//	else
//	{
//		return BinaryTreeLeafSize(root->lchild);//左孩子不为空，返回左子树的叶子节点个数
//	}
//}

//非递归中序遍历统计叶子节点的个数
int BinaryTreeLeafSize(BTNode* root)
{
	assert(root != NULL);
	int count = 0;
	Stack st;
	StackInit(&st,100);
	BTNode*cur = root;
	while (cur!=NULL || !StackIsEmpty(&st))//这里进入循环的条件cur!=NULL为第一次进入循环的条件
	{
		for (; cur; cur = cur->lchild)
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);//每次取到的都是未遍历到的最左边节点（中序遍历的特点）
		if (cur->lchild == NULL && cur->rchild == NULL)
		{
			count++;
		}
		cur = cur->rchild;//不断向右移动（当cur->rchild为空时从左孩子移动到父节点后遍历到父节点；当cur->rchild不为空时从父节点移动到右孩子）
		StackPop(&st);
	}
	StackDestory(&st);
	return count;
}

//统计二叉树上某一层的节点个数
int BinaryTreeLevelKSize(BTNode * pRoot, int k)
{
	if (pRoot == NULL || k < 1)
		return 0;
	if (k == 1)
		return 1;
	int numLeft = BinaryTreeLevelKSize(pRoot->lchild, k - 1); // 左子树中k-1层的节点个数
	int numRight = BinaryTreeLevelKSize(pRoot->rchild, k - 1); // 右子树中k-1层的节点个数
	return (numLeft + numRight);
}
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	assert(root != NULL);
//	int curcount=1, nextcount=0;//本层的节点个数，及下一层的节点个数（本层遍历中入队的个数）
//	int count=1;//根节点，第一层的节点个数
//	Queue qu;
//	QueueInit(&qu);
//	BTNode* cur = root;
//	QueuePush(&qu,root);
//	while (!QueueIsEmpty(&qu))
//	{
//		if (count == k)//判断层数
//		{
//			return curcount;//此时nextcount和curcount保存的都是count层的节点个数
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
//		curcount--;//本层出栈，本层节点数减一
//		if (curcount == 0)//当前层已出完，
//		{
//			count++;//遍历下一层
//			curcount = nextcount;//将下一层的节点个数给上一层
//			nextcount = 0;//nextcount 继续统计下一层未入队的节点个数
//		}
//	}
//	QueueDestory(&qu);
//	return -1;
//}