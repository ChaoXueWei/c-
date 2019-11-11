#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;

}BTNode;
//�������Ĵ���������
BTNode* BinaryTreeCreate(BTDataType* src);
void BinaryTreeDestory(BTNode* root);

//��������ǰ�к����ֵݹ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode*root);

//�ǵݹ����
//��α���
void BinaryTreeLevelOrder(BTNode*root);

//�ǵݹ�ǰ�к������
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeSize(BTNode* root); 
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeNotLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);

BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root);
#endif
