/* 二叉树的复制 */

#include <stdio.h>
#include <stdlib.h>

struct tree   //树的结构声明
{
	int data;    //结点数据
	struct tree *left;    //指向左子树的指针
	struct tree *right;   //指向右子树的指针
};

typedef struct tree treenode;    //树的结构新类型
typedef treenode *btree;    //声明树结点指针类型

/* 创建二叉树 */
btree createbtree(int *data,int pos)
{
	btree newnode;    //新结点指针
	if(data[pos] == 0 || pos > 15)  //终止条件
		return NULL;
	else
	{
		//创建新结点内存
		newnode = (btree)malloc(sizeof(treenode));
		newnode->data = data[pos];   //创建结点内容
		//创建左子树的递归调用
		newnode->left = createbtree(data,2*pos);
		//创建右子树的递归调用
		newnode->right = createbtree(data,2*pos + 1);
		return newnode;
	}
}

/* 二叉树复制 */

btree copytree(btree root)
{
	btree newnode;    //新结点指针
	if(root == NULL)  //终止条件
		return NULL;
	else
	{
		newnode = (btree)malloc(sizeof(treenode));
		newnode->data = root->data;    //创建结点内容
		//复制左子树
		newnode->left = copytree(root->left);
		newnode->right = copytree(root->right);
		return newnode;
	}

}

/* 二叉树中序输出 */
void printbtree(btree ptr)
{
	if(ptr != NULL)   //终止条件
	{
		printbtree(ptr->left);   //左子树
		printf("[%2d]",ptr->data);   //输出结点内容
		printbtree(ptr->right);   //右子树
	}
		
}

/* 主程序：创建二叉树后备份它 */
int main()
{
	btree root = NULL;    //原二叉树指针
	btree backup = NULL;  //复制二叉树指针

	/* 二叉树结点数据 */
	int data[16] = {0,5,4,6,2,0,0,8,1,
					3,0,0,0,0,7,9};
	root = createbtree(data,1);   //创建树状结构
	backup = copytree(root);   //复制二叉树
	printf("原二叉树的结点内容\n");
	printbtree(root);  //中序输出二叉树
	printf("\n备份二叉树的结点内容\n");
	printbtree(backup);   //中序输出二叉树
	printf("\n");
	return 0;
}

