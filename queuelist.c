/* 使用链表创建队列
 * 使用链表创建队列就不需要检查是否队列全满，因为这是一种动态内存分配，
 * 除非内存不足，否则队列不会全满
 */
#include <stdlib.h>
#include <stdio.h>

struct queue_node   //队列结构的声明
{
	int data;   //数据
	struct queue_node *next;   //结构指针
};

typedef struct queue_node queue_list;  //定义队列类型
typedef queue_list *link;   //定义队列指针类型

link front = NULL;   //队列的对头
link rear = NULL;    //队列的队尾

/* 队列数据的存入 */
int enqueue(int value)
{
	link new_node;
	new_node = (link) malloc(sizeof(queue_list));
	if(!new_node)
	{
		printf("内存分配失败！\n");
		return -1;
	}
	new_node->data = value;   //存入队列结点
	new_node->next  = NULL;    //设置初值
	if(rear == NULL)   //是否是第一次存入
	{
		front = new_node;    //front指向new_node
	}
	else
	{
		rear->next = new_node;    //插入rear之后
	}
	rear = new_node;   //rear指向new_node
}

/* 队列数据的取出 */
int dequeue()
{
	link top;
	link temp;
	if( front != NULL)  //队列是否是空的
	{
		top = front;   //top指向front
		front = front->next;    //删除之前结点
		temp = top->data;       //取出数据
		free(top);              //释放内存
		return temp;         //队列取出
	}
	else
		return -1;   

}

int main()
{
	int input[100];    //存储输入的元素
	int output[100];   //存储取出的元素
	int select;      //选择项1，2或3
	int i_count = 0;   //数组input的索引
	int o_count = 0;    //数组output的索引
	int loop = 1;     
	int i,temp;

	while(loop)
	{
		printf("[1]输入 [2]取出 [3]退出 ==>");
		scanf("%d",&select);  
		switch(select)
		{
			case 1:
				printf("请输入存入队列的值(%d) ==>",i_count + 1);
				scanf("%d",&temp);
				if(enqueue(temp) == -1)
					printf("队列全满. \n");
				else
					input[i_count++] = temp;
				break;
			case 2:
				if((temp = dequeue()) == -1)
				{
					printf("队列是空的. \n");
				}
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
	printf("输入队列的元素：");
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

	while((temp = dequeue()) != -1)  //取出剩下队列元素
	{
		printf("[%d]",temp);
	}
	printf("\n");

}


