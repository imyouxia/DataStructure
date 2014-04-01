/* 双队列：
 * 输入限制性双队列：
 * 输入限制性双队列是限制存入只能在一端，取出却可以在两端的任何一端。因为两端都可以输出，所以队列输出的组合就有很多种
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10    //队列的最大容量

int queue[MAXQUEUE];   //队列的数组声明
int front = -1;    //队列的队头
int rear = -1;     //队列的队尾

/* 队列数据的存入 */

int enqueue(int value)
{
	if(rear + 1 == front ||   //检查队列是否全满
		(rear == (MAXQUEUE - 1) && front <= 0))
		return -1;
	rear++;   //队尾指针往前移
	if(rear == MAXQUEUE)  //是否超过界限
		rear = 0;   
	queue[rear] = value;   //存入队列
}

/* 队列数据的取出（从队尾）*/
int dequeue_rear()
{
	int temp;
	if(front == rear)    //检查队列是否是空
	{
		return -1;
	}

	temp = queue[rear];
	rear--;   //队尾指针往前移

	if(rear < 0 && front != -1)  //是否超过界限
		rear = MAXQUEUE - 1;   //从最大值开始
	return temp;        //队列取出
}

/* 队列数据的取出（从队头）*/
int dequeue_front()
{
	if(front == rear)   //检查队列是否是空
		return -1;
	front++;   //队头指针往前移
	if(front == MAXQUEUE)   //是否超过界限
		front = 0;
	return queue[front];   //队列取出
}

int main() 
{
	int input_list[6] = {1,2,3,4,5,6};  //存储输入的元素
	int output_list[6];   //存储取出的元素
	int select;
	int i,temp,pos = 0;

	for(i = 0; i < 6; i++)
	{
		enqueue(input_list[i]);
	}

	while(front != rear)
	{
		printf("[1]从后取出 [2]从前取出");
		scanf("%d",&select); 
		switch(select)
		{
			//从队尾取出队列的内容
			case 1:
				temp = dequeue_rear();
				output_list[pos++] = temp;
				break;
			//从队头取出队列的内容
			case 2:
				temp = dequeue_front();
				output_list[pos++] = temp;
				break;
		}
	}
	printf("原来数组的顺序：");
	for(i = 0; i < 6; i++)
	{
		printf("[%d]",input_list[i]);
	}
	printf("\n队列取出的顺序");
	for(i = 0; i < 6; i++)
	{
		printf("[%d]",output_list[i]);
	}
	printf("\n");
	return 0;
}
