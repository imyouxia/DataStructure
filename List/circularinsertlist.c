/* 循环链表内结点的插入
 * 分为两种情况：
 * 一、直接将结点插在第一个结点之前成为链表的开始
 * 二、将结点插在任意结点之后
 */

#include <stdio.h>
#include <stdlib.h>

struct clist   //循环链表结构声明
{
	int data;   //结点数据
	struct clist *next;   //指向下一结点的指针
};

typedef struct clist cnode;    //循环链表新类型
typedef cnode *clink;     //循环链表指针新类型

/* 循环链表的输出 */
int printclist(clink head)
{
	clink ptr;
	ptr = head;   //指向链表开始
	do
	{
		printf("[%d]",ptr->data);   //输出结点数据
		ptr = ptr->next;    //指向下一个结点
	}while(head != ptr && head != head->next);  //判断是不是只有一个结点
	printf("\n");    //换行
	return 0;
}

clink insertnode(clink head,clink ptr,int value)
{
	clink new_node;    //新结点的指针
	clink previous;    //前一结点指针

	//创建新结点分配结点内存
	new_node = (clink) malloc(sizeof(cnode));
	if( !new_node )   //检查内存指针
	{
		return NULL;
	}

	new_node->data = value;     //创建结点内容
	new_node->next = NULL;     //设置指针初值

	if(head == NULL)  //如果链表是空的
	{
		new_node->next = new_node;   //指向自身结点
		return new_node;   //返回新结点指针
	}

	if(ptr == NULL) 
	{
		//第一种情况：插在第一结点之前且成为链表开始
		new_node->next = head;
		previous = head;
		while(previous->next != head)  //找最后一个结点
		{
			previous = previous->next;  //指向下一个结点
		}
		previous->next = new_node;   //前一结点指向新结点
		head = new_node;    //成为链表的开始

	}
	else
	{
		new_node->next = ptr->next;   //新结点指向下一结点
		ptr->next = new_node;     //前一结点指向新结点
	}
	return head;   //返回链表起始指针
}


int main()
{
	clink head = NULL;
	int list[6] = {1,2,3,4,5,6};  //数组内容
	int i;

	head = insertnode(head,head,list[0]);  //创建第一个结点
	printclist(head);   //输出结点
	
	//第一种情况：插在第一结点之前且成为链表开始
	head = insertnode(head,NULL,list[1]);
	printclist(head);   //输出链表
	
	for(i = 2; i < 6; i++)
	{
		//第二种情况：插入第一结点之后
		head = insertnode(head,head,list[i]);
		printclist(head);    //输出链表
	}	

	return 0;
}

