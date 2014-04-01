/* 循环链表的创建 */

#include <stdio.h>
#include <stdlib.h>

struct clist   //循环链表结构声明
{
	int data;   //结点数据
	struct clist *next;   //指向下一结点的指针
};

typedef struct clist cnode;    //循环链表新类型
typedef cnode *clink;     //循环链表指针新类型

/* 使用数组创建循环链表 */

clink createclist(int *array,int len)
{
	clink head;    //循环链表的指针
	clink before;   //前一结点的指针
	clink new_node;  //新结点的指针
	int i;

	/* 创建第一个结点
	 * 分配结点内存
	 */

	head = (clink)malloc(sizeof(cnode));
	if(!head)   //检查内存指针
	{
		return NULL;
	}
	head->data = array[0];      //创建结点内容
	head->next = NULL;          //设置指针初值
	before = head;       //指向第一个结点

	for(i = 1; i < len; i++)    //用循环创建其他结点
	{
		new_node = (clink)malloc(sizeof(cnode));
		if(!new_node)    //检查内存指针
		{
			return NULL;
		}
		new_node->data = array[i];   //创建结点内容
		new_node->next = NULL;    //设置指针初值
		before->next = new_node;    //将前结点指向新结点
		before = new_node;    //新结点成为前结点
	}

	new_node->next = head;    //创建环形链接
	return head;    //返回链表起始指针
}

int main()
{
	clink head;    //循环链表指针
	clink ptr;	  //输出用的链表指针
	int list[6] = {9,7,3,4,5,6};  //数组内容
	int i;

	head = createclist(list,6);   //创建循环链表
	if(head == NULL)
	{
		printf("内存分配失败! \n");   //链表创建失败
		exit(1);
	}
	
	printf("数组内容：");

	for(i = 0; i < 6; i++)
	{
		printf("[%d]",list[i]);   //输出数组内容  
	}

	printf("\n链表内容：");
	ptr = head;  //指向链表开始
	do
	{
		printf("[%d]",ptr->data);   //输出链表内容
		ptr = ptr->next;     //指向下一个结点
	}while(head != ptr);
	printf("\n");   //换行
	return 0;
}

