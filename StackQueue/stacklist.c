/* 使用链表创建栈 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stack_node  //栈的结构声明
{
	int data;    //栈数据
	struct stack_node *next;  //指向下一结点
};

typedef struct stack_node stack_list;   //链表新类型
typedef stack_list *link;   //链表指针新类型

link stack = NULL;   //栈指针

/* 栈数据的存入 */
int push(int value)
{
	link new_node;   //新结点指针
	new_node = (link)malloc(sizeof(stack_list));
	if(!new_node)
	{
		printf("内存分配失败！\n");
		return -1;   //存入失败
	}
	new_node->data = value;   //创建结点内容
	new_node->next = stack;   //新结点指向原开始
	stack = new_node;   //新结点成为栈开始
	return 0;
}

/* 栈数据的取出 */
int pop()
{
	link top;   //指向栈顶端
	int temp;   
	if(stack != NULL)  //栈是否是空的
	{
		top = stack;   //指向栈顶端
		stack = stack->next;  //栈指针指向下结点
		temp = top->data;   //取出数据
		free(top);  //释放结点内存
		return temp;  //栈取出
	}
	else
		return -1;
}

int empty()
{
	if(stack == NULL)  //是否为空
	{
		return 1;
	}
	else
		return 0; 
}

/* 主程序：洗牌后，将牌发给4个人
 * 红心：数组  0 ～ 12
 * 方块：数组 13 ～ 25
 * 梅花：数组 26 ～ 38
 * 黑桃：数组 39 ～ 51
 */

int main()
{
	int card[52];   //扑克牌数组
	int pos;    //牌代码
	int i,temp;
	long temptime;
	srand(time(&temptime) % 60);  //使用时间初始随机数
	for(i = 0; i < 52; i++)
	{
		card[i] = 0;   //清楚扑克牌数组
	}

	i = 0;
	while(i != 52)  //洗牌循环
	{
		pos =  rand() % 52;   //随机数取值 0 ～ 51
		if(card[pos] == 0)  //是否是未洗牌
		{
			push(pos);   //存此张牌进栈
			card[pos] = 1;  //设置此张牌洗过
			i++;  //下一张牌
		}
	}
	printf("1 2 3 4\n");
	printf("=================\n");
	for(i = 0; i < 5; i++)  //发牌给四人的循环
	{
		temp = pop();  //取出栈数据
		printf("[%c%2d]",temp / 13 + 3,temp % 13 +1);
		temp = pop();  //取出栈数据
		printf("[%c%2d]",temp / 13 + 3,temp % 13 +1);
		temp = pop();  //取出栈数据
		printf("[%c%2d]",temp / 13 + 3,temp % 13 +1);
		temp = pop();  //取出栈数据
		printf("[%c%2d]",temp / 13 + 3,temp % 13 +1);
		printf("\n");
	}
	return 0;
}
