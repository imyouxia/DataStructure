/* 包含头结点的链表 */

#include <stdio.h>
#include <stdlib.h>

struct llist      //链表结构声明
{ 
	int num;	  //邮寄编号
	struct llist *next;   //指向下一标签
};

typedef struct llist node; //定义新类型
typedef node *llink;   //定义新类型指针

/* 链表的输出 */

int printllist(llink head)
{
	llink ptr;
	ptr = head->next;    //指向真正的起始
	while(ptr != NULL)   //链表遍历循环
	{
		printf("[%d]",ptr->num);   //输出结点数据
		ptr = ptr->next;    //指向下一结点
	}
	printf("\n");
	return 0;
}

/* 链表的创建 */
llink createllist(int *array,int len)
{
	llink head;    //链表的开始指针
	llink ptr,ptr1;
	int i;
	
	//创建头结点
	head = (llink)malloc(sizeof(node)); //分配内存
	if(!head)   //检查指针
	{
		return NULL;
	}	
	ptr = head;    //将ptr指向链表开始
	for(i = 0; i < len ; i++)   //创建其他结点循环
	{
		ptr1 = (llink)malloc(sizeof(node));
		if( !ptr1 )
			return NULL;
		ptr1->num = array[i];  //创建结点内容
		ptr1->next = NULL;   //设置指针初值
		ptr->next = ptr1; //连接结点
		ptr = ptr->next; //指向下一结点
	}	
		
	return head;
}

/* 链表的结点插入 */
llink insertnode(llink head,llink ptr,int value)
{
	llink new;  //创建新结点
	new = (llink)malloc(sizeof(node));   //创建新结点
	if(!new)
	{
		return NULL;
	}
	new->num = value;   //创建结点内容
	new->next = NULL;  //设置指针初值

	//如果ptr等于头结点则是插入第一个结点
	new->next = ptr->next;      //新结点指向下一结点
	ptr->next = new;   //结点ptr指向新结点

	return head;	
}

/* 链表的结点的删除 */
llink deletenode(llink head,llink ptr)
{
	llink previous;

	previous =  head;
	while(previous->next != ptr )   //找结点ptr前一结点
	{
		previous = previous->next;
	}

	previous->next = ptr->next;   //删除中间结点
	free(ptr);   //释放结点内存
	return head;
}

int main()
{
	int llist1[6] = {1,2,3,4,5,6};
	llink head;

	head = createllist(llist1,6);

	if(!head)
	{
		printf("内存分配失败！\n");
		exit(1);
	}
	//删除链表内结点
	head = deletenode(head,head->next->next->next);
	printf("最后的链表：");
	printllist(head); 
	return 0;
}

