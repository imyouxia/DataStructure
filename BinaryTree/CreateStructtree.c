/* 使用结构数组表示法创建二叉树 */

#include <stdio.h>
#include <stdlib.h>

struct tree   //树的结构声明
{
	int data;    //结点数据
	int left;    //指向左子树的位置
	int right;   //指向右子树的位置
};

typedef struct tree treenode;   //树的结构新类型
treenode btree[15];          //声明树的结构数组

/* 创建二叉树 */
void createsbtree(int *data,int len)
{
	int level;     //树的层数
	int pos;       //-1是左树，1是右数
	int i;

	btree[0].data = data[0];   //创建树根结点
	for(i = 1; i < len; i++)  //用循环遍历其他结点
	{
		btree[i].data = data[i];   //创建结点内容
		level = 0;    //从树根开始
		pos = 0;   //设置pos值
		while(pos == 0)
		{
			//比较是左或右子树
			if( data[i] > btree[level].data)
			{
				//右树是否有下一层树
				if(btree[level].right != -1)
					level = btree[level].right;
				else
					pos = -1;   //是右树
			}
			else
			{
				//左树是否有下一层树
				if(btree[level].left != -1)
					level = btree[level].left;
				else
					pos = 1;    //是左树
				
			}

		}
		if(pos == 1)   //创建结点左右位置
		{
			btree[level].left = i;   //连接左子树
		}
		else
		{
			btree[level].right = i;  //连接右子树
		}

	}

}

/* 创建结构数组的二叉树状结构
 * 数字-1表示没有下一层数
 */

int main()
{
	int data[10] = {5,6,4,8,2,3,7,1,9};
	int i;

	for(i = 0; i < 15; i++)   //清除树状结构数组
	{
		btree[i].data = 0;    	//设置初始内容
		btree[i].left = -1;  	//设置初始内容
	   	btree[i].right = -1;  	//设置初始内容
	
	}	

	createsbtree(data,9);   //创建二叉树
	printf("左 数据 右 \n");
	printf("--------------------\n");
	for(i = 0; i < 15; i++)   //输出二叉树内容
	{
		if(btree[i].data != 0)   //是否是树的结点
		{
			printf("%2d:[%2d] [%2d] [%2d]\n",i,btree[i].left,btree[i].data,btree[i].right);
		}
	}
	return 0;
}

