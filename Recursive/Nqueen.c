/* 应用递归来解N皇后问题 */

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEEN 8  //最大放置的皇后数

int palce(int x,int y);

int pad[MAXQUEEN][MAXQUEEN] = {  //N*N的棋盘
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0, };


/* 放N个皇后的递归函数 */
int put_queen(int x,int y,int times)
{
	int i,j,result = 0;
	if(times > MAXQUEEN)   //终止条件
		return 1;
	
	else
	{
		if( place(x,y) )   //检查是否可放置皇后
		{
			pad[x][y] = 1; //放置皇后
			
			for(i = 0; i < MAXQUEEN; i++)
			{
				for(j = 0; j < MAXQUEEN; j++)
				{
					//递归调用放置下一个皇后
					result += put_queen(i,j,times + 1);
					if(result > 0)
						break;
				}
			}

			if(result > 0)   //找到
				return 1;
			else
			{
				pad[x][y] = 0;   //清除皇后
				return 0;
			}
		
		}
		else
			return 0;
	}

}

//检查皇后是否有相互攻击
int place(int x,int y)
{
	int x1,y1;
	if(pad[x][y] != 0)   //已放置皇后
	{
		return 0;
	}

	x1 = x - 1;  //检查左上方
	y1 = y - 1;
	while(x1 >= 0 && y1 >= 0)
	{
		if(pad[x1--][y1--] != 0)
			return 0;
	}
	
	x1 = x + 1;   //检查右下方
	y1 = y + 1;
	while(x1 < MAXQUEEN && y1 < MAXQUEEN)
	{
		if(pad[x1++][y1++] != 0)
			return 0;
	}
	
	x1 = x + 1;    //检查右上方
	y1 = y - 1;
	while(x1 < MAXQUEEN && y1 >= 0)
	{
		if(pad[x1++][y1--] != 0)
			return 0;
	}

	x1 = x - 1;   //检查左下方
	y1 = y + 1;   
	while(x1 >= 0 && y1 < MAXQUEEN)
	{
		if(pad[x1--][y1++] != 0)
			return 0;
	}

	x1 = x;   //检查下方
	y1 = y + 1;
	while(y1 < MAXQUEEN)
	{
		if(pad[x1][y1++] != 0)
			return 0;
	}

	x1 = x;   //检查上方
	y1 = y - 1;
	while(y1 >= 0)
	{
		if(pad[x1][y1--] != 0)
			return 0;
	}

	x1 = x + 1;  //检查右方
	y1 = y;
	while(x1 < MAXQUEEN)
	{
		if(pad[x1++][y1] != 0)
			return 0;
	}
	
	x1 = x - 1;   //检查左方
	y1 = y;
	while(x1 >= 0)
	{
		if(pad[x1--][y1] != 0)
			return 0;
	}
	return 1;
}

/* 用递归的方法解 N = 8 皇后问题 */

int main()
{
	int i,j;
	put_queen(0,0,1);   //调用递归函数
	printf("放置八皇后的棋盘图形：\n");
	for(i = 0; i < MAXQUEEN; i++)  //输出棋盘的图形
	{
		for(j = 0; j < MAXQUEEN; j++)
			printf("%d",pad[i][j]);   //输出各坐标值
		printf("\n");
	}
	return 0;
}

 





