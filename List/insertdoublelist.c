/* 双向链表内结点的插入
 * 将结点插入双向链表的三种情况：
 * 一、将结点插在链表中第一个结点之前
 * 二、将结点插在链表的最后
 * 三、将结点插入链表的中间结点之间
 */

#include <stdio.h>
#include <stdlib.h>

struct dlist   //双向链表结构声明
{
	int data;   //结点数据
	struct dlist *front;   //指向下一结点的指针
	struct dlist *back;    //指向前一结点的指针
};

typedef struct dlist dnode;   //双向链表新类型
typedef dnode *dlink;    //双向链表指针新类型

/* 双向链表的输出 */
int printdlist(dlink head)
{
	while(head != NULL)
	{
		printf("[%d]",head->data);   //输出结点数据
		head = head->front;   //指向下一个结点
	}
	printf("\n");
	return 0;
}

/* 双向链表的结点插入 */
dlink insertnode(dlink head,dlink ptr,int value)
{
	dlink new_node;   //新结点的指针
	new_node = (dlink) malloc(sizeof(dnode));
	if(!new_node)  //检查内存指针
		return NULL;

	new_node->data = value; //创建结点内容
	new_node->front = NULL;  //设置指针初值
	new_node->back = NULL;   //设置指针初值

	if( head == NULL)  //如果链表是空的
		return new_node;   //返回新结点指针

	if(ptr == NULL)
	{
		//第一种情况：插在第一个结点之前，成为链表开始
		new_node->front = head;   //新结点指向链表开始
		head->back = new_node;   //原结点指向新结点
		head = new_node;   //新结点成为链表开始
	}

	else
	{
		if(ptr->front == NULL)  //是否有下一个结点
		{
			//第二种情况：插在链表的最后
			ptr->front = new_node;    //最后结点指向新结点
			new_node->back = ptr;   //新结点指回最后结点
		}
		else
		{
			//第三种情况：插入结点至链表中间结点内
			ptr->front->back = new_node; //下一结点指回新结点
			new_node->front = ptr->front;   //新结点指向下一结点
			new_node->back = ptr;   //新结点指回插入结点
			ptr->front = new_node;  //插入结点指向新结点			
		}
	}
	return head;  //返回链表起始指针
		
}

int main()
{
	dlink head = NULL;   //循环链表指针
	dlink tail = NULL;   //链表最后的指针
	int list[6] = {1,2,3,4,5,6};   //数组内容
	int i;

	head = insertnode(head,head,list[0]); //创建第一个结点
	printdlist(head);   //输出链表
	tail = head;   //保留链表最后指针

	//第一种情况：插在第一个结点之前
	head = insertnode(head,NULL,list[1]);
	printdlist(head);  //输出链表
	//第二种情况：插在链表的最后
	head = insertnode(head,tail,list[2]);
	printdlist(head);   //输出链表
	for(i = 3; i < 6; i++)  //创建链表结点
	{
		head = insertnode(head,head,list[i]);
		printdlist(head);  //输出链表
	}

	return 0;
}

