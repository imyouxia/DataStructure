/* 二叉树的结点删除：
 * 一、结点没有左子树
 * 二、结点没有右子树
 * 三、结点具有左子树和右子树
 */

#include <stdio.h>
#include <stdlib.h>

struct tree  //树的结构声明
{
	int data;    //结点数据
	struct tree *left;   //指向左子树的指针
	struct tree *right;  //指向右子树的指针
};

typedef struct tree treenode;   //树的结构新类型
typedef treenode *btree;     //声明树结点指针类型

/* 创建二叉树 */
btree createbtree(int *data,int pos)
{
	btree newnode;   //新结点指针
	if(data[pos] == 0 || pos > 15)   //终止条件
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

/* 二叉树查找 */
btree btreefind(btree ptr,int value,int *pos)
{
	btree previous;    //父结点指针
	
	previous = ptr;    //设置指针初值
	*pos = 0;    //设置位置初值
	while(ptr != NULL)   
	{
		if(ptr->data == value)  //找到了
			return previous;  //返回父结点指针
		else
		{
			previous = ptr;   //保留父结点指针
			if(ptr->data > value)  //比较数据
			{
				ptr = ptr->left;    //左子树
				*pos = -1;   
			}
			else
			{
				ptr = ptr->right;   //右子树
				*pos = 1;
			}
		
		}

	}
	return NULL;   
}

/* 二叉树结点删除 */
btree deletenode(btree root,int value)
{
	btree previous;    //父结点指针
	btree ptr;         //删除的结点指针
	btree next;        //子结点指针
	int pos;           //删除位置

	/* 寻找结点值的父结点指针 */
	previous = btreefind(root,value,&pos);
	if(previous == NULL) 
	{
		return root;
	}
	switch(pos)   //删除位置
	{
		case -1:
			ptr = previous->left;  //左子结点
			break;
		case 1:
			ptr = previous->right;  //右子结点
			break;
		case 0:
			ptr = previous;  //根结点
			break;

	}
		
	/* 第一种情况：没有左子树 */
	if(ptr->left == NULL)
	{
		if(previous != ptr)   //是否是根结点
		{
			//不是，父结点的右子结点指向目前结点的右子结点
			previous->right = ptr->right;
		}
		else
		{
			root = root->right;    //根结点指向右子结点
		}
		free(ptr);   //释放结点内存
		return root;  //返回根结点
	}

	/* 第二种情况：没有右子树 */
	if(ptr->right == NULL)
	{
		if(previous != ptr)  //是否是根结点
			/* 不是，父结点的左子结点指向目前结点的左结点 */
			previous->left = ptr->left;
		else
			root = root->left;   //根结点指向左子结点
		free(ptr);    //释放结点内存
		return root;  //返回根结点
	}

	/* 第三种情况：有左子树和右子树 */
	previous = ptr;    //父结点指向目前结点
	next = ptr->left;  //设置子结点
	while(next->right != NULL)   //找到最右的叶结点
	{
		previous = next;  //保留父结点指针
		next = next->right;    //往右子树走
	}
	ptr->data = next->data;   //设置成叶结点数据
	if(previous->left == next)  //创建链表
	{
		previous->left = next->left;   //是左子结点
	}
	else
	{
		previous->right = next->right;    //是最右的叶结点
	}
	free(next);  //释放结点内存
	return root;   //返回根结点
}

/* 二叉树中序输出 */
void printbtree(btree ptr)
{
	if(ptr != NULL)
	{
		printbtree(ptr->left);
		printf("[%2d]",ptr->data);
		printbtree(ptr->right);
	
	}

}

/* 主程序：创建二叉树后删除一结点 */
int main()
{
	btree root = NULL;   //树根指针
	int value;    //结点值

	/* 二叉树结点数据 */
	int data[16] = {0,5,4,6,2,0,0,8,1,
					3,0,0,0,0,7,9};
	root = createbtree(data,1);   //创建树状结构
	printbtree(root);    //中序输出二叉树
	printf("\n请输入寻找结点数据 ==>");
	scanf("%d",&value);  //读取结点数据
	root = deletenode(root,value);   //删除结点值是value
	printf("删除后树的结点内容\n");
	printbtree(root);   //中序输出二叉树
	printf("\n");
	return 0;
}

