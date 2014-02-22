/* 使用递归方式创建二叉树 */

#include <stdio.h>
#include <stdlib.h>

struct tree  //树的结构声明
{
	int data;   //结点数据
	struct tree *left;     //指向左子树的指针
	struct tree *right;    //指向右子树的指针
};
typedef struct tree treenode;
typedef treenode * btree;  //声明树结点指针类型

/* 创建树状结构 */
btree createbtree(int *data,int pos)
{
	btree newnode;   //新结点指针
	if(data[pos] == 0 || pos > 15)  //终止条件
		return NULL;
	else
	{
		//创建新结点内存
		newnode = (btree)malloc(sizeof(treenode));
		newnode->data = data[pos];    //创建结点内容
		//创建左子树的递归调用
		newnode->left = createbtree(data,2*pos);
		//创建右子树的递归调用
		newnode->right = createbtree(data,2*pos + 1);
		return newnode;
	}
}

/* 二叉树的中序遍历递归输出 */
void printbtree(btree ptr)
{
	if(ptr != NULL)   //终止条件
	{
		printbtree(ptr->left);   //左子树
		printf("[%2d]",ptr->data);   //输出结点内容
	 	printbtree(ptr->right);  //右子树	
	}
}

int main()
{
	btree root = NULL;   //树根指针
	int i;

	/* 二叉树结点数据 */
	int data[16] = {0,5,4,6,2,0,0,8,1,
					3,0,0,0,0,7,9};
	root = createbtree(data,1);    //创建树状结构
	printf("数组的结点内容\n");
	
	for(i = 1; i < 16; i++)
		printf("[%2d]",data[i]);   //输出结点内容
	printf("\n");
	printf("树的结点内容\n");
	printbtree(root);   //输出结点内容
	printf("\n");
	return 0;
}

