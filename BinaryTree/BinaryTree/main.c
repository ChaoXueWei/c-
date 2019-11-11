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
	printf("�ö��������ܽ�����Ϊ��%d\n", BinaryTreeSize(root));
	printf("�ö�������Ҷ�ӽڵ����Ϊ��%d\n",BinaryTreeLeafSize(root));
	printf("�ö������ķ�Ҷ�ӽڵ����Ϊ��%d\n", BinaryTreeNotLeafSize(root));
	printf("����Ҫ�鿴�ڵ�����Ĳ�Σ�");
	scanf("%d", &n);
	printf("��%d��Ľڵ����Ϊ%d\n", n, BinaryTreeLevelKSize(root, n));
	BinaryTreeDestory(root);
}
int main()
{
	BinaryTreeTest();
	system("pause");
	return 0;
}
