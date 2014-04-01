/* 使用数组内容和递归方法创建基本链表和输出链表的内容 */

#include <stdio.h>
#include <stdlib.h>

struct list  //链表结构声明
{
	int data;   //结点数据
	struct list *next;   //指向下一结点
};

typedef struct list node;  //定义新类型
typedef node *link;   //定义新类型指针


/* 递归链表输出函数 */
int print_list(link ptr)
{
	if(ptr != NULL)  //终止条件
	{
		printf("[%d]",ptr->data);  //输出结点数据
		print_list(ptr->next);
	}
	return 0;
}

/* 递归链表创建函数 */
link create_list(int *array,int len,int pos)
{
	link head;   //链表结点的指针
	if(pos == len)  //终止条件
		return NULL;
	else
	{
		//创建结点内存
		head = (link)malloc(sizeof(node)); 
		if(!head)
			return NULL;
		head->data = array[pos];     //创建结点内容
		head->next = create_list(array,len,pos+1);
		return head;
	}

}

int main()
{
	int list[6] = {1,2,3,4,5,6};  //数组内容
	link head;   //指向链表开始

	head = create_list(list,6,0);  //创建链表

	if(!head)
	{
		printf("内存分配失败！\n");
		exit(1);
	}

	printf("链表的内容：\n");
	print_list(head);  //输出链表
	printf("\n");
	return 0;
}

