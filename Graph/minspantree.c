/* 最小生成树 */

#include <stdlib.h>
#include <stdio.h>

struct edge   //图边结构声明
{
	int from;  //开始顶点数据
	int to;	   //终点顶点数据
	int weight; //权值
	struct edge *nextedge;   //指下一边的指针
};

typedef struct edge *edgelist;   //边的结构新类型
edgelist list = NULL;    //边链表开始指针
int node[6];             //顶点数组

/* 创建边链表 */
edgelist createedgelist(edgelist list,int *edges,int num)
{
	edgelist newnode;   //新边结点指针
	edgelist last;      //最后边结点指针
	int i;

	for(i = 0; i < num; i++)
	{
		//创建新边内存
		newnode = (edgelist)malloc(sizeof(struct edge));
		newnode->from = edges[3*i];   //边的起点
		newnode->to = edges[3*i+1];   //边的终点
		newnode->weight = edges[3*i + 2];  //创建成本内容
		newnode->nextedge = NULL;    //设置指针初值

		if(list == NULL)    //第一个结点
		{
			list = newnode;    //创建链表开始指针
			last = list; 	   //保留最后结点指针
		}
		else
		{
			last->nextedge = newnode;    //链接到最后结点
			last = newnode;    //保留最后结点指针
		}
	}
	return list;    //返回链表开始指针
}

/* 结合成同一集合 */
int uniongroup(int from,int to)
{
	int to_root;
	to_root = to;      //从终点顶点找

	while(node[to_root] > 0)
	{
		to_root = node[to_root];
	}

	node[to_root] = from;   //结合两个顶点
	return 0;
}

/* 是否存在同一集合 */
int samegroup(int from,int to)
{
	int from_root;
	int to_root;
	
	from_root = from;   //从开始顶点找
	while(node[from_root] > 0)
	{
		from_root = node[from_root];
	}
	to_root = to;   //从终点顶点找

	while(node[to_root] > 0)
	{
		to_root = node[to_root];
	}

	if(from_root == to_root)   //是否同一集合
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

/* 图的最小生成树 */
void minspantree()
{
	edgelist ptr;
	ptr = list;   //指向链表开始

	while(ptr != NULL)
	{
		//是否存在同一集合
		if(!samegroup(ptr->from,ptr->to))
		{
			//输出最小权值的
			printf(" 从顶点： %d 到：%d 权值：%d\n",ptr->from,ptr->to,ptr->weight);
			uniongroup(ptr->from,ptr->to);  //结合成同一集合
		}
		ptr = ptr->nextedge;  //下一边
	}
}

/* 主程序：图的最小生成树 */
int main()
{
	int edges[8][3] = {
				{1,2,2},
				{2,4,3},
				{1,4,4},
				{3,5,5},
				{2,5,6},
				{2,3,8},
				{3,4,10},
				{4,5,15}
	};
	
	int i;
	list = createedgelist(list,edges,8);   //创建边链表
	for(i = 1; i <= 5; i++)
	{
		node[i] = -1;
	}
	printf("图的最小生成树：\n");
	minspantree();    //创建最小生成树
	printf("顶点数组内容：\n");
	for(i = 1; i <= 5; i++)
	{
		printf("[%d]",node[i]);   //输出顶点数组
	}
	printf("\n");
	return 0;
}

