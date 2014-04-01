/* 线性探测法的散列查找 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10     //最大数组容量
#define NUM 8		//随机数生成的个数
#define BLANK -1   //空白空间

int hashtable[MAX];    //散列表声明

/* 散列函数 */
int hashfunc(int value)
{
	return value % MAX;   //余数
}

/* 线性探测法 */
int linehash(int key)
{
	int pos;    //位置变量
	int temp;

	//调用散列函数计算位置
	pos = hashfunc(key);
	temp = pos;      //保留开始位置
	
	while(hashtable[temp] != key &&    //线性探测循环
			hashtable[temp] != BLANK)
	{
		//使用余数将数组变成环状
		temp = (temp + 1) % MAX;   //下一个位置
		if(pos == temp)  //查询结束
		{
			return -1;   //没有找到
		}
	
	}
	if(hashtable[temp] == BLANK) //是否是空白
		return -1;
	else
		return temp;   //找到了

}

/* 创建散列表 */
void createtable(int key)
{
	int pos;    //位置变量
	int temp;
	//调用散列函数计算位置
	pos = hashfunc(key);
	temp = pos;				//保留开始位置
	while(hashtable[temp] != BLANK)   //找寻存入位置
	{
		temp = (temp + 1) % MAX;  //下一个位置
		if(pos == temp)  //散列表是否已满
		{
			printf("散列表已满！\n");
			return;
		}
	}
	hashtable[temp] = key;   //存入散列表
}

/* 主程序：散列查找法 */
int main()
{
	int checked[50];   //检查数组
	int i,j,temp;
	long temptime;
	for(i = 0; i < MAX; i++)
	{
		hashtable[i] = BLANK;   //清除散列表
	}

	for(i = 0; i < 50; i++)
	{
		checked[i] = 0;   //清除检查数组
	}

	printf("散列表内容：\n");
	srand(time(&temptime) % 60);    //使用时间初始随机数
	i = 0;
	while(i != NUM)   //生成数组值的循环
	{
		temp = rand() % 50;   //随机数取值0 -49
		if(checked[temp] == 0)   //是否是已有的值
		{
			createtable(temp);    //创建散列表
			printf("%2d = >",temp);
			for(j = 0; j < MAX; j++)  //输出散列表
			{
				printf("[%2d]",hashtable[j]);
			}
			printf("\n");   
			checked[temp] = 1;   //设置此值生成过
			i++;				//下一个数组值
		}
	}

	while(1)  
	{
		printf("\n请输入查找值（0-49） ==>");
		scanf("%d",&temp);   //导入查找值
		if(temp != -1)
		{
			i = linehash(temp);   //调用散列查找
			if(i != -1)
			{
				printf("找到查找值：%d[%d]\n",temp,i);
			}
			else
			{
				printf("没有找到差好值：%d\n",temp);
			}
		}
		else
			exit(1);
	}

}

