#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;

}BTNode;
//二叉树的创建和销毁
BTNode* BinaryTreeCreate(BTDataType* src);
void BinaryTreeDestory(BTNode* root);

//二叉树的前中后三种递归遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode*root);

//非递归遍历
//层次遍历
void BinaryTreeLevelOrder(BTNode*root);

//非递归前中后序遍历
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeSize(BTNode* root); 
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeNotLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);

BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root);
#endif
