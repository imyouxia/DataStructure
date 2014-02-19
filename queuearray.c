/* 使用数组创建队列
 * 队列有两种特性：
 * 一、从队列的一端读取数据，从另一端存入数据
 * 二、队列的数据都是使用先进先出（First In,First Out）的策略处理数据
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10   //队列的最大容量

int queue[MAXQUEUE];    //队列的数组声明
int front = -1;   //队列的队头
int rear = -1;    //队列的队尾

/* 队列数据的存入 */
int enqueue(int value)
{
	if(rear >= MAXQUEUE)   //检查队列是否全满
		return -1;
	rear++;    //队尾指针往前移
	queue[rear] = value;    //存入队列
}

/* 队列数据的取出 */
int dequeue()
{
	if(front == rear)  //检查队列是否是空
		return -1;   //无法取出

	front++;    //对头指针往前移
	return queue[front];   //队列取出
}

int main()
{
	int input[100];   //存储输入的元素
	int output[100];   //存储取出的元素
	int select;    //选项1，2或3
	int i_count = 0;    //数组input的索引
	int o_count = 0;    //数组output的索引
	int loop = 1;    //循环控制
	int i,temp;

	while(loop)   
	{
		printf("[1]输入 [2]取出 [3]退出 ==>");
		scanf("%d",&select);  
		switch(select)
		{
			case 1:
				printf("请输入存入列队的值(%d) ==>",i_count + 1);
				scanf("%d",&temp);
				if(enqueue(temp) == -1)
					printf("队列全满.\n");
				else
					input[i_count ++] = temp;
				break;
			//取出队列内容
			case 2:
				if((temp = dequeue()) == -1)
					printf("队列是空的.\n");
				else
				{
					printf("取出队列元素：%d\n",temp);
					output[o_count++] = temp;
				}
				break;
			case 3:
				loop = 0;
				break;
		}	
	
	}
	
	return 0;
}
