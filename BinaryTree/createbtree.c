/* 使用数组创建二叉树:
 * 比父结点大的存储在右边，小的放在左边，被称为“二叉查找树”
 */

#include <stdio.h>
#include <stdlib.h>

void createbtree(int *btree,int *data,int len)
{
	int level;     //树的层数
	int i;

	btree[1] = data[1];    //创建根结点

	for(i = 2; i <= len; i++)   //用循环创建其他结点
	{
		level = 1;  //从层数1开始
		while(btree[level] != 0)   //是否有子树
		{
			if(data[i] > btree[level])   //是左或右子树
			{
				level = level * 2 + 1;   //是右子树
			}
			else
			{
				level = level * 2;   //是左子树
			}
		}
		btree[level] = data[i];    //存入结点数据

	}
}

int main()
{
	int btree[16];   //二叉树数组
	//二叉树结点数据
	int data[10] = {0,5,6,4,8,2,3,7,1,9};
	int i;

	for(i = 1; i < 16; i++)   //清除二叉树数组
	{
		btree[i] = 0;
	}

	createbtree(btree,data,9);     //创建二叉树
	for(i = 1; i < 16; i++)
	{
		printf("%2d：[%d]\n",i,btree[i]);
	}
	return 0;
}

