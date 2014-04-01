/* 顺序查找法
 * 需要检查数组的边界
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100  //最大数组容量

struct element   //记录结构声明
{
	int key;   //查找关键码
};

typedef struct element record;   //结构新类型
record data[MAX];     //结构数组声明

/* 顺序查找 */
int seq_search(int key)
{
	int pos;   //数组索引
	pos = 0;   //从头开始找

	while(pos < MAX)   //顺序查找主循环
	{
		if(key == data[pos].key)  //是否找到
			return pos;
		pos++;   //下一个元素

	}
	return -1;
}

/* 主程序：用随机数来生成数组元素，接着输入值用顺序查找来找值 */

int main()
{
	int checked[300];    //检查数组
	int i,temp;
	long temptime;
	srand(time(&temptime) % 60);   //使用时间初始随机数
	for(i = 0; i < 300; i++)
	{
		checked[i] = 0;   //清除检查数组
	}
	i = 0;
	while(i != MAX)  //生成数组值的循环
	{
		temp = rand() % 300;   //随机数取值 0 ~ 299
		if(checked[temp] == 0)   //是否是已有的值
		{
			data[i].key = temp;   //存入数组中
			checked[temp] = 1;    //设置此值生成过
			i++;
		}
	}

	while(1)
	{
		printf("\n请输入查找值（0-299）==>");
		scanf("%d",&temp);     //导入查找值
		if(temp != -1)
		{
			i = seq_search(temp);    //调用顺序查找
			if(i != -1)
			{
				printf("找到查找值：%d[%d]\n",temp,i);
			}
			else
			{
				printf("没有找到查找值：%d\n",temp);
			}
		}
		else
			exit(1);
	
	}
	return 0;

}

