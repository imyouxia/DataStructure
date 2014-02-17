/* 双向链表的创建 */

#include <stdlib.h>
#include <stdio.h>

struct dlist   //双向链表结构声明
{
	int data;   //结点数据
	struct dlist *front;  //指向下一结点的指针
	struct dlist *back;   //指向前一结点的指针
};

typedef struct dlist dnode;   //双向链表新类型
typedef dnode *dlink;     //双向链表指针新类型

/* 使用数组值创建双向链表 */
dlink createdlist(int *array,int len)
{
	dlink head;   //双向链表的指针
	dlink before;   //前一结点的指针
	dlink new_node;   //新结点的指针
	int i;

	/* 创建第一个结点
	 * 分配结点内存
	 */
	head = (dlink) malloc(sizeof(dnode));
	if(!head)  //检查内存指针
	{
		return NULL;
	}

	head->data = array[0];   //创建结点内容
	head->front = NULL;   //设置指针初值
	head->back = NULL;    //设置指针初值
	before = head;    //指向第一个结点

	for(i = 1; i < len; i++)  //用循环创建其他结点
	{
		new_node = (dlink) malloc(sizeof(dnode));
		if(!new_node)   //检查内存指针
			return NULL;
		new_node->data = array[i];   //创建结点内容
		new_node->front = NULL;     //设置指针初值
		new_node->back = before;   //将新结点指向前结点
		before->front = new_node;   //将前结点指向新结点
		before = new_node;   //新结点成为前结点
	}
	return head;   //返回链表起始指针
}

/* 双向链表的输出 */
int printdlist(dlink head,dlink now)
{
	while(head != NULL)   //链表遍历循环
	{
		if(head == now)  //输出目录结点数据
		{
			printf("#%d#",head->data);   //输出结点数据
		}
		else
		{
			printf("[%d]",head->data);  //输出结点数据
		}
		head = head->front;   //指向下一个结点
	}
	printf("\n");
	return 0;
}

int main()
{
	dlink head;   //双向链表指针
	dlink now = NULL;    //目前结点指针
	int list[6] = {1,2,3,4,5,6};  //数组内容
	int select;   //选择项1，2或3

	head = createdlist(list,6);  //创建双向链表
	if(head == NULL)
	{
		printf("内存分配失败：\n");  
		exit(1);
	}

	now  = head;  //目前指向第一结点

	while(1)
	{
		printf("链表内容是：");
		printdlist(head,now);   //输出内容
		//选项内容
		printf("[1]往下移动 [2]往回移动 [3]离开 ==>");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				if(now->front != NULL)
					now = now->front;  //指向下一结点
					break;
			case 2:
				if(now->back != NULL)
					now = now->back;  //指向前一结点
					break;
			case 3:
					exit(1);
		}
	}
	
	return 0;
}


