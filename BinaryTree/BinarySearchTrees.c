/*二叉查找树：
 * 每一个结点的值都不同，也就是整棵树中的每一个结点都拥有不同的值
 * 每一个结点的数据大于左子树结点（如果有的话）的数据，但是小于右子树结点（如果有的话）的数据
 * 左、右两部分的子树，也是一颗二叉查找树
 */

#include <stdio.h>
#include <stdlib.h>

struct tree   //树的结构声明
{
	int data;   //结点数据
	struct tree *left;    //指向左子树的指针
	struct tree *right;   //指向右子树的指针
};
typedef struct tree treenode;    //树的结构新类型
typedef treenode *btree;    //声明树结点指针类型

/* 创建二叉树  */
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

/* 二叉查找树的查找 */
btree btreefind(btree ptr,int value)
{
	while(ptr != NULL)  //主循环
	{
		if(ptr->data == value)  //找到了
			return ptr;   //返回结点指针
		else
		{
			if(ptr->data > value)  //比较数据
				ptr = ptr->left;  //左子树
			else
				ptr = ptr->right;  //右子树
		}	
	}
	return NULL;
}

/* 二叉树遍历查找 */
btree btreesearch(btree ptr,int value)
{
	btree ptr1,ptr2;
	
	if(ptr != NULL)   //终止条件
	{
		if(ptr->data == value) //找到了
			return ptr;   //返回结点指针
		else
		{
			//往左子树找
			ptr1 = btreesearch(ptr->left,value);
			//往右子树找
			ptr2 = btreesearch(ptr->right,value);

			if(ptr1 != NULL)
				return ptr1;  //在左子树
			else
			{
				if(ptr2 != NULL)
					return ptr2;  //在右子树
				else
					return NULL;   //没有找到

			}
		
		}
	}
	else
		return NULL;    //是叶结点
	
}

int main()
{
	btree root = NULL;  //树根指针
	btree ptr = NULL;   //树根指针
	int value;   //结点值

	/* 二叉树结点数据 */
	int data[16] = {0,5,4,6,2,0,0,8,1,
						3,0,0,0,0,7,9};

	root = createbtree(data,1);   //创建树状结构
	printf("请输入寻找结点数据（1-9）==>");
	scanf("%d",&value);   //读取结点数据
	ptr = btreefind(root,value);   //二叉查找树
	if(ptr != NULL)
		printf("二叉查找树：结点数据是[%d]\n",ptr->data);
	else
		printf("二叉查找树：没有找到\n");
	ptr = btreesearch(root,value);   //遍历查找
	if(ptr != NULL)
		printf("遍历查找：结点数据是[%d]\n",ptr->data);
	else
		printf("遍历查找：没有找到\n");
	return 0;
}

