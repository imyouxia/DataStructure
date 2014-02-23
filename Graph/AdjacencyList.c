/* 邻接表表示法：
 * 邻接表表示法是使用基本链表来链接每个顶点的邻接顶点。
 *           /  1 \
 *          2  ——  3
 *			|      |
 *          4  ——  5
 * 顶点 1 ——> 2 ——> 3 ——> NULL
 * 顶点 2 ——> 1 ——> 3 ——> 4 ——> NULL
 * 顶点 3 ——> 1 ——> 2 ——> 5 ——> NULL
 * 顶点 4 ——> 3 ——> 5 ——> NULL
 * 顶点 5 ——> 3 ——> 4 ——> NULL
 */

#include <stdio.h>
#include <stdlib.h>

struct node   //图顶点结构声明
{
	int vertex;    //顶点数据
	struct node *nextnode;   //指下一顶点的指针
};
typedef struct node *graph;    //图的结构新类型
struct node head[6];    //图顶点结构数组

/* 创建图 */
void creategraph(int *node,int num)
{
	graph newnode;    //新顶点指针
	graph ptr; 
	int from;         //边的起点
	int to; 		  //边的终点
	int i;	

	for(i = 0; i < num; i++)  //读取边的循环
	{
		from = node[i*2];    //边的起点
		to = node[i*2 + 1];  //边的终点
		//创建新顶点内存
		newnode = (graph)malloc(sizeof(struct node));
		newnode->vertex = to;   //创建顶点内容
		newnode->nextnode = NULL;   //设置指针初值
		ptr = &(head[from]);    //顶点位置
		while(ptr->nextnode != NULL)   //遍历至链表尾
			ptr = ptr->nextnode;   //下一个顶点
		ptr->nextnode = newnode;   //插入结尾
	
	}
}
 

int main()
{
	graph ptr;
	int node[12][2] = {
						{1,2},{2,1},
						{1,3},{3,1},
						{2,3},{3,2},
						{2,4},{4,2},
						{3,5},{5,3},
						{4,5},{5,4}
	};

	int i;

	for(i = 1; i <= 5; i++)
	{
		head[i].vertex = i;   //设置顶点值
		head[i].nextnode = NULL;   //清除图指针
	}
	creategraph(node,12);   //创建图
	printf("图的邻接表内容：\n");
	for(i = 1; i <= 5; i++)
	{
		printf("顶点%d =>",head[i].vertex);   //顶点值
		ptr = head[i].nextnode;  //顶点位置
		while(ptr != NULL)
		{
			printf(" %d ",ptr->vertex);   //输出顶点内容
			ptr = ptr->nextnode;    //下一个顶点
		}
		printf("\n");
	}
	return 0;
}

