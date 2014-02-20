/* 输出限制性双队列 */

#include <stdlib.h>
#include <stdio.h>

struct queue_node   //队列结构的声明
{
	int data;
	struct queue_node *next;
};

typedef struct queue_node queue_list;   //定义队列类型
typedef queue_list *link;  //定义队列指针类型

link front = NULL;   //队列的队头
link rear = NULL;    //队列的队尾

/* 队列数据的存入（从队尾）*/
int enqueue_rear(int value)
{
	link new_node;

	new_node = (link)malloc(sizeof(queue_list));
	if(!new_node)
	{
		printf("内存分配失败！\n");
		return -1;
	}

	new_node->data = value;   //存入队列结点
	new_node->next = NULL;
	if(rear == NULL)    //是否是第一次插入
		front = new_node;   //front指向new_node
	else
		rear->next = new_node;   //插入rear之后

	rear = new_node;   //rear指向new_node

}

/* 队列数据的存入（从队头）*/
int enqueue_front(int value)
{
	link new_node;
	
	new_node = (link)malloc(sizeof(queue_list));
	if(!new_node)
	{
		printf("内存分配失败！\n");
		return -1;
	}
	new_node->data = value;   //存入队列结点
	if(front == NULL)
	{
		new_node->next = NULL;
		rear = new_node;    //rear指向new_node
	}
	else
	{
		new_node->next = front;   //插入front之前
	}
	front = new_node;    //front指向new_node

}

int dequeue()
{
	link top;
	int temp;

	if(front != NULL)   //队列是否是空的
	{
		top = front;   //top指向front
		front = front->next;   //删除之前结点
		temp = top->data;    //取出数据
		free(top);    //释放内存
		return temp;
	}
	else
		return -1;
}

int main()
{
	int input_list[6] = {1,2,3,4,5,6};
	int select;
	int i,temp,pos = 0;

	for(i = 0; i < 6; i++)
	{
		printf("[1]从后存入 [2]从前存入  ==>");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				enqueue_rear(input_list[i]);
				break;
			case 2:
				enqueue_front(input_list[i]);
				break;
			default:
				enqueue_rear(input_list[i]);
				break;
		}
	}

	printf("原来数组的顺序：");
	for(i = 0; i < 6; i++)
		printf("[%d]",input_list[i]);
	printf("\n队列取出的顺序");
	while((temp = dequeue()) != -1)  //取出剩下队列的元素
	{
		printf("[%d]",temp);
	}
	printf("\n");
	return 0;

}
