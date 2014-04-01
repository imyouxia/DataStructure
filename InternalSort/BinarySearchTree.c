/* 二叉查找树排序法 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 创建二叉树查找树 */

void createbtree(int *btree,int *data,int len)
{
	int level;  //树的层次
	int i;

	btree[1] = data[1];   //创建根结点
	for(i = 2; i <= len; i++)  //用循环创建其他结点
	{
		level = 1;  //从层次1开始
		while(btree[level] != 0)  //是否有子树
		{
			if(data[i] > btree[level])  //是左或右子树
			{
				level = level * 2 + 1;  //右子树
			}
			else
			{
				level = level * 2;   //左子树
			}
		}
		btree[level] = data[i];		//存入结点数据
	}
}

/* 二叉树中序遍历 */
void inorder(int *btree,int pos)
{
	if(btree[pos] != 0 && pos < 16)  //终止条件
	{
		inorder(btree,pos*2);	//左子树
		printf("[%d]",btree[pos]);	//输出结点内容
		inorder(btree,pos*2 + 1);		//右子树
	}
}

int main()
{
	int btree[16];		//二叉树数组
	//二叉树结点数据
	int data[10] = {0,5,6,4,8,2,3,7,1,9};
	int i;

	for(i = 1; i < 16; i++)  //清除二叉树数组
		btree[i] = 0;

	createbtree(btree,data,9);		//创建二叉查找树
	printf("二叉查找树的内容：");

	for(i = 1; i < 16; i++)  //输出二叉查找树
	{
		printf("[%d]",btree[i]);
	}
	printf("\n输出的排序结果：");
	inorder(btree,1);	//输出排序结果
	printf("\n");
	return 0;
}


