/* 二叉查找树查找法 */

#include <stdio.h>
#include <stdlib.h>

struct tree    //树的结构声明
{
	int data;       //结点数据
	struct tree *left;      //指向左子树的指针
	struct tree *right;     //指向右子树的指针
};
typedef struct tree treenode;   //树的结构新类型
typedef treenode *btree;      //声明树结点指针类型

/* 插入二叉树的结点  */
btree insertnode(btree root,int value)
{
	btree newnode;   //树根指针
	btree current;    //目前树结点指针
	btree back;      //父结点指针

	//创建新结点内存
	newnode = (btree)malloc(sizeof(treenode));
	newnode->data = value;    //创建结点内容
	newnode->left = NULL;    //设置指针初值
	newnode->right = NULL;   //设置指针初值
	if(root == NULL)
	{
		return newnode;   //返回新结点位置
	}
	else
	{
		current = root;    //保留目前树指针
		while(current != NULL) 
		{
			back = current;    //保留父结点指针
			if(current->data > value)  //比较结点值
			{
				current = current->left;  //左子树
			}
			else
			{
				current = current->right;  //右子树
			}

		}

		if(back->data > value)  //接起父子的链接
		{
			back->left = newnode;   //左子树
		}
		else
		{
			back->right = newnode;  //右子树
		}

	}

	return root;   //返回树根指针
}

/* 创建二叉树 */
btree createbtree(int *data,int len)
{
	btree root = NULL;  //树根指针
	int i;
	for(i = 0; i < len; i++)   //用循环创建树状结构
	{
		root = insertnode(root,data[i]);
	}
	return root;
}

/* 使用二叉查找树运行查找 */
btree btreesearch(btree ptr,int value)
{
	while(ptr != NULL) 
	{
		if(ptr->data == value)  
		{
			return ptr;    //返回结点指针
		}
		else
		{
			if(ptr->data > value)  //比较数据
			{
				ptr = ptr->left;  //左子树
			}
			else
			{
				ptr = ptr->right;   //右子树
			}
		}
	}
	return NULL;
}

/* 主程序：使用二叉查找树运行查找 */
int main()
{
	btree root = NULL;   //树根指针
	btree ptr = NULL;    //树指针
	int value;   //结点值

	int data[9] = {55,61,41,87,24,35,79,11,99};
	root = createbtree(data,9);    //创建树状结构
	while(1)
	{
		printf("请输入查找数据（0-99）==>");
		scanf("%d",&value);   //读取数据
		if(value != -1)
		{
			ptr = btreesearch(root,value);   //使用二叉查找树运行查找
			if(ptr != NULL)
			{
				printf("二叉查找树查找：结点数据是[%d]\n",ptr->data);
			}
			else
			{
				printf("二叉查找树查找：没有找到\n");
			}
		}
		else
			exit(1);
	}
	return 0;
}

