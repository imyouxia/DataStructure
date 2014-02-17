/* 循环双向链表
 * 最后一个结点指向第一个结点，而第一个结点的指针同样指向最后一个结点
 * 这种循环双向链表结构继承循环链表的优点，在处理插入和删除的操作上只有两种情况，如下所示：
 * 一、插入或删除第一个结点
 * 二、插入或删除中间的结点
 */

#include <stdio.h>
#include <stdlib.h>

struct cdlist  //循环双向链表声明
{
	int data;   //结点数据
	struct cdlist *front;   //指向下一个结点的指针
	struct cdlist *back;   //指向前一结点的指针
};

typedef struct cdlist cdnode;  //循环双向链表新类型
typedef cdnode *cdlink;   //链表指针新类型

/* 循环双向链表的输出 */

int printcdlist(cdlink head,cdlink now)
{
	cdlink ptr;

	if(head != NULL)  //链表是空的
	{
		ptr = head;   //指向链表开始
		do
		{
			if(ptr == now)  //输出目前结点数据
			{
				printf("#%d#",ptr->data);  //输出结点数据
			}
			else
			{
				printf("[%d]",ptr->data);   //输出结点数据
			}
			ptr = ptr->front;   //指向下一个结点
				
		}while(head != ptr && head != head->front);
		printf("\n");
	}
	return 0;
}

/* 循环双向链表的结点删除 */
cdlink deletenode(cdlink head,cdlink ptr)
{
	if(head == NULL)
		return NULL;

	if(ptr == head) //如果是第一结点
	{
		//第一种情况：删除第一个结点
		head = head->front;   //移至下一个结点
		ptr->back->front = ptr->front;   //前结点指向下结点
		ptr->front->back = ptr->back;   //下结点指向前结点
	}
	else
	{
		//第二种情况：删除中间结点
		ptr->back->front = ptr->front;  //前结点指向下结点
		ptr->front->back = ptr->back;   //下结点指向前结点
	}

	free(ptr);   //释放结点内存
	return head;   //返回链表起始指针
}

/* 循环双向链表的结点插入 */
cdlink insertnode(cdlink head,cdlink ptr,int value)
{
	cdlink new_node;  //新结点的指针
	//创建新结点分配结点内存
	new_node = (cdlink)malloc(sizeof(cdnode));
	if(!new_node)
		return NULL;
	new_node->data = value;   //创建结点内容

	if(head == NULL)
	{
		new_node->front = new_node; //指向自身结点
		new_node->back = new_node;  //指向自身结点
		return new_node;  //返回新结点指针
	}

	if(ptr == NULL)
	{
		//第一种情况：插在第一结点之前且成为链表开始
		head->back->front = new_node;  //前一结点指回新结点
		new_node->front = head;   //新结点指向开始结点
		new_node->back = head->back;  //新结点指回前一结点
		head->back = new_node;   //开始结点指向新结点
		head = new_node;   //成为链表的开始

	}
	else
	{
		//第二种情况：插在结点之后
		ptr->front->back = new_node;  //下一结点指回新结点
		new_node->front = ptr->front;   //新结点指向下一结点
		new_node->back = ptr;   //新结点指回插入结点
		ptr->front = new_node;  //插入结点指向新结点
	}
	return head;  //返回链表起始指针
}

int main()
{
	cdlink head = NULL;   //循环双向链表指针
	cdlink now = NULL;  //目前结点指针
	int list[6] = {1,2,3,4,5,6}; //数组内容
	int select;   //选择项1～6
	int value = 7; //插入内容计数
	int i;

	for(i = 0; i < 6; i++)  //创建双向链表
	{
		head = insertnode(head,NULL,list[i]);
	}

	while(1)
	{
		if(now == NULL)
			now = head;   //目前指向第一结点
		printf("链表内容是：");
		printcdlist(head,now);  //输出内容

		printf("[1]往下移动 [2]往回移动 [3]删除结点");
		printf("\n[4]插入开始结点 [5]插入结点后 [6]离开 ==>");
		scanf("%d",&select);  //输入选项
		switch(select)
		{
			//往下移动
			case 1:
				now = now->front;  //指向下一结点
				break;
			case 2:
				now = now->back;
				break;
			case 3:
				if(head != NULL)
				{
					head = deletenode(head,now);
					now = head;
				}
				else
					printf("链表是空的\n");
					break;
			//将value的内容插入目前结点前
			case 4:
					head = insertnode(head,NULL,value);
					value++;  //插入值加1
					break;
			//将value的内容插入目前结点后
			case 5:
					head = insertnode(head,now,value);
					value++;
					break;
			case 6:
					exit(1);
		}
	}

	return 0;
}

