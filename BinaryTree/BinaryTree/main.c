#include<stdio.h>
#include<Windows.h>
#include"BinaryTree.h"
#include"Queue.h"
BTNode* root;
void BinaryTreeTest()
{
	char src[] = "ABD##E#H##CF##G##";
	char src1[] = "ABDG##HJ####CE#IK##L##F##";
	root=BinaryTreeCreate(src1);
	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');
	BinaryTreePostOrder(root);
	putchar('\n');
	BinaryTreeLevelOrder(root);
	putchar('\n');
	BinaryTreePrevOrderNonR(root);
	putchar('\n');
	BinaryTreeInOrderNonR(root);
	putchar('\n');
	BinaryTreePostOrderNonR(root);
	putchar('\n');
	int n = 0;
	printf("该二叉树的总结点个数为：%d\n", BinaryTreeSize(root));
	printf("该二叉树的叶子节点个数为：%d\n",BinaryTreeLeafSize(root));
	printf("该二叉树的非叶子节点个数为：%d\n", BinaryTreeNotLeafSize(root));
	printf("输入要查看节点个数的层次：");
	scanf("%d", &n);
	printf("第%d层的节点个数为%d\n", n, BinaryTreeLevelKSize(root, n));
	BinaryTreeDestory(root);
}
int main()
{
	BinaryTreeTest();
	system("pause");
	return 0;
}
