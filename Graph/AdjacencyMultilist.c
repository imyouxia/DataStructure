/* 邻接多重表表示法：
 *           /  1 \
 *          2  ——  3
 *	    |      |
 *          4  ——  5
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct edge    //图边结构声明
{
	int vertex1;    //顶点1数据
	int vertex2;    //顶点2数据
	struct edge *edge1;   //顶点1下一边
	struct edge *edge2;   //顶点2下一边
};

typedef struct edge *nextedge;    //图的边新类型

struct node
{
	int vertex;    //顶点数据
	struct edge *edge;   //顶点下一边
};
typedef struct node *graph;    //图的结构新类型

struct node head[6];   //图顶点结构数组

/* 创建图 */
void creategraph(int *node,int num)
{
	nextedge newnode;    //新边指针
	nextedge previous;   //前一边指针
	nextedge ptr;        //目前边指针

	int from;      //边的起点
	int to;        //边的终点

	int i;

	for(i = 0; i < num; i++)   //读取边的循环
	{
		from = node[i*2];   //边的起点
		to = node[i*2 + 1];  //边的终点

		/* 创建新边内存 */
		newnode = (nextedge)malloc(sizeof(struct edge));
		newnode->vertex1 = from;    //创建顶点内容
		newnode->vertex2 = to;      //创建顶点内容
		newnode->edge1 = NULL;    //设置指针初值
		newnode->edge2 = NULL;    //设置指针初值

		previous = NULL;   //前一边指针
		ptr = head[from].edge;   //目前边指针
		while(ptr != NULL)   //遍历到最后边
		{
			previous = ptr;    //保留前一边
			if(ptr->vertex1 == from)  //决定走的边
			{
				ptr = ptr->edge1;  //下一边
			}
			else
			{
				ptr = ptr->edge2;  //下一边
			}
		}

		if(previous == NULL) 
		{
			head[from].edge = newnode;   //设置顶点边指针
		}
		else
		{
			if(previous->vertex1 == from)   //决定走的边
			{
				previous->edge1 = newnode;   //连接下一边
			}
			else
			{
				previous->edge2 = newnode;   //连接下一边
			}
		}

		previous = NULL;    //前一边指针
		ptr = head[to].edge;     //目前边指针

		while(ptr != NULL)   //遍历到最右边
		{
			previous = ptr;    //保留前一边
			if(ptr->vertex1 == to)   //决定走的边
			{
				ptr = ptr->edge2;   //下一边
			}
			else
			{
				ptr = ptr->edge2;   //下一边
			}
		}

		if(previous == NULL)
		{
			head[to].edge = newnode;   //设置顶点边指针
		}
		else
		{
			if(previous->vertex1 == to)   //决定走的边
			{
				previous->edge1 = newnode;   //连接下一边
			}
			else
			{
				previous->edge2 = newnode;   //连接下一边
			}
		}
	}

}


int main()
{
	nextedge ptr;
	int node[6][2] = {
					{1,2},
					{1,3},
					{2,3},
					{2,4},
					{3,5},
					{4,5},
	};

	int i;
	for(i = 1; i <= 5; i++)
	{
		head[i].vertex = i;    //设置顶点值
		head[i].edge = NULL;
	}

	creategraph(node,6);   //创建图
	printf("图的邻接多重表内容：\n");
	for(i = 1; i <= 5; i++)
	{
		printf("顶点%d =>",head[i].vertex);   //顶点值
		ptr = head[i].edge;   //边位置
		while(ptr != NULL)   //遍历至链表尾
		{
			//输出边
			printf("(%d,%d)",ptr->vertex1,ptr->vertex2);
			//决定下一边指针
			if(head[i].vertex == ptr->vertex1)
			{
				ptr = ptr->edge1;   //下一个边
			}
			else
			{
				ptr = ptr->edge2;   //下一个边
			}
		}
		printf("\n");
	}
	return 0;
}

