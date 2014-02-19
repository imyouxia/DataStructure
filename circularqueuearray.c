/* 使用数组创建循环队列：
 * 指针rear和指针front会相隔一个元素空间，队列实际的存储空间将是最大容量减1
 * 这样的涉及可以避免队列已空和全满时指针指向相同位置的问题
 * (rear == (MAXQUEUE-1) && front <= 0):
 * 上述条件是在刚好指针rear指向数组的最后一个元素，此时必需检查指针front是否刚好停在第一个或是指针front等于-1。
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10   //队列的最大容量
int queue[MAXQUEUE];   //队列的数组声明
int front = -1;   //队列的队头
int rear = -1;    //队列的队尾

/* 队列数据的存入 */
int enqueue(int value)
{
	if(rear + 1 == front || //检查队列是否全满
			(rear == (MAXQUEUE - 1) && front <= 0))
		return -1;  //无法存入
	rear++;   //队尾指针往前移
	if(rear == MAXQUEUE)  //是否超过界限
		rear = 0;  //从头开始
	queue[rear] = value;   //存入队列

	return 0;
}

/* 队列数据的取出 */
int dequeue()
{
	if(front == rear)   //检查队列是否是空
		return -1;
	front++;   //对头指针往前移
	if(front == MAXQUEUE)  //是否超过界限
		front = 0;   //从头开始
	return queue[front];
}

int main()
{
	int input[100];   //存储输入的元素
	int output[100];    //存储取出的元素
	int select;       //选择项1，2或3
	int i_count = 0;   //数组input的索引
	int o_count = 0;   //数组output的索引
	int loop = 1;
	int i,temp;
	
	while(loop)
	{
		printf("[1]输入 [2]输出 [3]列出全部内容 ==>");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				printf("请输入存入队列的值(%d) ==>",i_count + 1);
				scanf("%d",&temp);
				if(enqueue(temp) == -1)
					printf("队列全满.\n");
				else
					input[i_count++] = temp;
				break;
			case 2:
				if((temp == dequeue()) == -1)
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
		printf("输入队列的元素："); //输出结果
		for(i = 0; i < i_count; i++)
		{
			printf("[%d]",input[i]);
		}

		printf("\n取出队列的元素：");
		for(i = 0; i < o_count; i++)
		{
			printf("[%d]",output[i]);
		}
		printf("\n剩下队列的元素：");
		while((temp = dequeue()) != -1)  //取出剩下的队列元素
			printf("[%d]",temp);
		printf("\n");
		
	}
	return 0;
}
