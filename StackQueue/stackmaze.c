/* 应用栈来走迷宫 */

#include <stdio.h>
#include <stdlib.h>

struct stack_node   //栈的结构声明
{
	int x;   //路径坐标x
	int y;   //路径左边y
	struct stack_node *next;  //指向下一结点
};

typedef struct stack_node stack_list;   //链表新类型
typedef stack_list *link;    //链表指针新类型

link path = NULL;   //路径栈指针

/* 栈数据的存入 */
link push(link stack,int x,int y)
{
	link new_node;   //新结点指针
	//分配结点内存
	new_node = (link)malloc(sizeof(stack_list));
	if(!new_node)
	{
		printf("内存分配失败！\n");
		return NULL;
	}
	
	new_node->x = x;  //存入路径坐标x
	new_node->y = y;   //存入路径坐标y
	new_node->next = stack;   //新结点指向原开始
	stack = new_node;   //新结点成为栈开始
	return stack;   
}

/* 栈数据的取出 */
link pop(link stack,int *x,int *y)
{
	link top;    //指向栈顶端
	if(stack != NULL)
	{
		top = stack;   //指向栈顶端
		stack = stack->next;    //栈指针指向下结点
		*x = stack->x;   //取出路径坐标x
		*y = stack->y;   //取出路径坐标y
		free(top);    //释放结点内存
		return stack;    //返回栈指针
	}
	else
		*x = -1;
	return 0;	
}

/* 主程序：用回溯的方法在数组迷宫找出口
 * 数字 0：表示是可走的路
 * 数字 1：表示墙壁，不可走的路
 * 数字 2：表示是走过的路
 * 数字 3：表示是回溯的路
 */

int main()
{
	//迷宫的数组
	int maze[7][10] = {
				1,1,1,1,1,1,1,1,1,1,
				1,0,1,0,1,0,0,0,0,1,
				1,0,1,0,1,0,1,1,0,1,
				1,0,1,0,1,1,1,0,0,1,
				1,0,1,0,0,0,0,0,1,1,
				1,0,0,0,1,1,1,0,0,1,
				1,1,1,1,1,1,1,1,1,1
	};
			
	int i,j;
	int x = 5;   //迷宫的入口坐标
	int y = 8;

	while(x != 1 || y != 1)   //是否是迷宫出口
	{
		maze[x][y] = 2;    //标示走过的路
		if(maze[x - 1][y] <= 0)   //往上走过的路
		{
			x = x - 1;   //坐标x减1
			path = push(path,x,y);   //存入路径
		}
		else
		{
			if(maze[x + 1][y] <= 0)  //往下方走
			{
				x = x + 1;   //坐标x加1
				path = push(path,x,y);   //存入路径
			}
			else
			{
				if(maze[x][y - 1] <= 0)   //往左方走
				{
					y = y - 1;   //坐标y减1
					path = push(path,x,y);   //存入路径
				}
				else
				{
					if(maze[x][y + 1] <= 0)  //往右方走
					{
						y = y + 1;   //坐标y加1
						path = push(path,x,y);  //存入路径
					}
					else
					{
						maze[x][y] = 3;  //表示回溯的路
						path = pop(path,&x,&y);   //退回一步
					}
				}
			}
		}
	
	
	}
	maze[x][y] = 2;  //表示最后一步
	printf("迷宫的路径如下图所示：\n");
	for(i = 1; i < 6; i++)   //输出迷宫的图形
	{
		for(j = 1; j < 9; j++)
		{
			printf("%d",maze[i][j]);   //输出各坐标
		}
		printf("\n"); 
	}
	return 0;
}

