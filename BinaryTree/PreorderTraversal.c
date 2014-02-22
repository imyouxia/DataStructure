/* 二叉树前序遍历方式 */

#include <stdio.h>
#include <stdlib.h>

struct tree   //树的结构声明
{
	int data;   //结点数据
	struct tree *left;     //指向左子树的指针
	struct tree *right;    //指向右子树的指针
};

typedef struct tree treenode;   //树的结构新类型
typedef treenode *btree;   //声明树结点指针类型

/* 插入二叉树的结点 */
btree insertnode(btree root,int value)
{
	btree newnode;  	 //树根指针
	btree current; 		 //目前树结点指针
	btree back;  		 //父结点指针

	/* 创建新结点内存 */
	newnode = (btree)malloc(sizeof(treenode));
	newnode->data = value;    //创建结点内容
	newnode->left = NULL;     //设置指针初值
	newnode->right = NULL;    //设置指针初值

	if(root == NULL)  //是否是根结点
	{
		return newnode;   //返回新结点位置
	}

	else
	{
		current = root;   //保留目前树指针
		while(current != NULL)
		{
			back = current;    //保留父结点指针
			if(current->data > value)  //比较结点值
				current = current->left;  //左子树
			else
				current = current->right;   //右子树
		
		}

		if(back->data > value)  //接起父子的连接
		{
			back->left = newnode;   //左子树
		}
		else
		{
			back->right = newnode;   //右子树
		}
	}
	return root;   //返回树根指针
}

/* 创建二叉树 */
btree createbtree(int *data,int len)
{
	btree root = NULL;   //树根指针
	int i;

	for(i = 0; i < len; i++)
	{
		root = insertnode(root,data[i]);
	}
	return root;
}


/* 二叉树前序遍历 */
void preorder(btree ptr)
{
	if(ptr != NULL)  //终止条件
	{
		printf("[%2d]\n",ptr->data);   //输出结点内容
		preorder(ptr->left);  //左子树
		preorder(ptr->right);   //右子树
	}
}

/* 主程序：创建二叉树且用前序遍历输出 */
int main()
{
	btree root = NULL;   //树根指针

	/* 二叉树结点数据 */
	int data[9] = {5,6,4,8,2,3,7,1,9};
	root = createbtree(data,9);
	printf("树的结点内容\n");
	preorder(root);   //前序遍历二叉树
	return 0;

}


