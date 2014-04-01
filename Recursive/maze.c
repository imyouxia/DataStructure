/* 应用递归走迷宫：
 * 数字 0 ：表示是可走的路径
 * 数字 1 ：表示是墙壁，不可走的路径
 * 数字 2 ：表示是走过的路径
 */

#include <stdio.h>
#include <stdlib.h>

int maze[7][10] = {
			1,1,1,1,1,1,1,1,1,1,
			1,0,1,0,1,0,0,0,0,1,
			1,0,1,0,1,0,1,1,0,1,
			1,0,1,0,1,1,1,0,0,1,
			1,0,1,0,0,0,0,0,1,1,
			1,0,0,0,1,1,1,0,0,1,
			1,1,1,1,1,1,1,1,1,1,	
};

/* 走迷宫的递归函数 */
int find_path(int x,int y)
{
	if(x == 1 && y == 1)  //是否是迷宫出口
	{
		maze[x][y] = 2;  //记录最后走过的路径
		return 1;
	}
	else
	{
		if(maze[x][y] == 0)   //是不是可以走
		{
			maze[x][y] = 2;    //记录已经走过的路径
			if((find_path(x-1,y) +	//调用递归函数往上
				find_path(x+1,y) +   //往下
	   		   	find_path(x,y-1) +   //往左
				find_path(x,y+1)) > 0  //往右
					)
				return 1;
			else
			{
				maze[x][y] = 0;    //此路不通取消记号
				return 0;
			}
		}
		else
			return 0;
	}

}

/* 主程序：用递归的方法在数组迷宫找出口 */
int main()
{
	int i,j;
	find_path(5,8);   //调用递归函数
	printf("迷宫的路径如下图所示：\n");
	for(i = 1; i < 6; i++)  //输出迷宫的图形
	{
		for(j = 1; j < 9; j++)
			printf("%d",maze[i][j]);   //输出各坐标
		printf("\n");
	}
	return 0;
}

