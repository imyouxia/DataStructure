/* 查找加权图的最短路径（Dijkstra方法）：
 * 一个顶点到多顶点的求法（Dijkstra法）
 */

/* 使用邻接矩阵存储加权图，无穷数使用常数MAXLEN代表 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000   //最长可能距离
int cost[7][7];       //图的邻接矩阵
int dist[7];          //路径长度数组

/* 创建加权图 */
void creategraph(int *node,int num)
{
	int from;    //边的起点
	int to;      //边的终点
	int i;
	for(i = 0; i < num; i++)  //读取边的循环
	{
		from = node[i*3];   //边的起点
		to = node[i*3 + 1]; //边的终点
		cost[from][to] = node[i*3 + 2];   //存入图

	}
}

/* 找寻某顶点到各顶点的最短距离 */
void shortestpath(int begin,int num)
{

	int selected[7];    //选择顶点数组
	int min;            //最短距离
	int s;              //最短距离的顶点
	int i,j;

	for(i = 2; i <= num; i++)   //初始数组循环
	{
		selected[i] = 0;  //清除数组内容
		dist[i] = cost[begin][i];    //初始距离
	}
	selected[begin] = 1;   //设置找过开始顶点
	dist[begin] = 0;      //设置开始顶点距离

	printf("顶点1    2     3     4     5     6 \n");
	for(j = 1; j <= num; j++)   //输出初始数组内容
	{
		printf(" %4d ",dist[j]);   //输出距离
	}
	printf("\n");; 
	for(i = 1; i <= num - 1; i++)
	{
		min = MAXLEN;   //先设为最长距离
		for(j = 1; j <= num; j++)   //找最短距离循环
		{
			//从数组查找最短距离顶点
			if(min > dist[j] && selected[j] == 0)
			{
				s = j;    //目前最短的顶点
				min = dist[j];    //记录最短距离
			}
			//selected[s] = 1; //设置已找过
			
		}
		selected[s] = 1; //设置已找过
		//计算开始顶点到各顶点最短距离数组循环
		for(j = 1; j <= num; j++)
		{
			if(selected[j] == 0 &&    //是否比较短
					dist[s] + cost[s][j] < dist[j])
			{
				//设为较短距离
				dist[j] = dist[s] + cost[i][j];
			//	printf(" %4d ",dist[j]);   //输出最短距离
			
			}
			
			printf(" %4d ",dist[j]);   //输出最短距离
			
		}

		printf("\n");
	}
}

int main()
{
	int node[7][3] = {
				{1,2,35},
				{2,3,45},
				{2,4,30},
				{3,5,25},
				{4,5,45},
				{4,6,130},
				{5,6,100}
	};
	int i,j;

	for(i = 1; i <= 6; i++)
	{
		for(j = 1; j <=6; j++)
		{
			cost[i][j] = MAXLEN;   //设置数组最长距离
		}
	
	}

	creategraph(node,7);    //创建加权图
	printf("加权图的邻接矩阵内容：\n");
	for(i = 1; i <= 6; i++)
	{
		for(j = 1; j <= 6; j++)
		{
			printf(" %4d ",cost[i][j]);  //输出加权数组内容
		}
		printf("\n");
	}
	printf("\n从顶点1到各顶点最近距离计算过程：\n");
	shortestpath(1,6);  //查找最短路径
	return 0;
}
