/* 循环链表内结点的删除
 * 删除操作有两种情况：
 * 一、将循环链表的第一个结点删除
 * 二、将循环链表的中间结点删除
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

/* 循环链表的遍历 */
clink findnode(clink head,int value)
{
	clink ptr;
	ptr = head;   //指向链表开始
	do    //链表遍历循环
	{
		if(ptr->data == value)  //比较值
			return ptr;  //找到值
		ptr = ptr->next;  //指向下一个结点
	}while(head != ptr && head != head->next);
	
	return NULL;   //没有找到值
}

/* 循环链表的输出 */
int printclist(clink head)
{
	clink ptr;
	ptr = head;   //指向链表开始
	do
	{
		printf("[%d]",ptr->data);   //输出结点数据
		ptr = ptr->next;   //指向下一个结点
	}while(head != ptr && head != head->next);
	printf("\n"); 
	return 0;
}

/* 循环链表的结点删除 */
clink deletenode(clink head,clink ptr)
{
	clink previous;   //前一结点指针
	if(head == NULL)   //如果链表是空的
	{
		return NULL;
	}

	previous = head;
	if(head != head->next)  //链表多于一个结点
	{
		while(previous->next != ptr) //找结点ptr的前结点
			previous = previous->next;   //移至下一个结点
	}

	if(ptr == head)    //如果是第一结点
	{
		//第一种情况：删除第一个结点
		head = head->next;  //移至下一个结点
		previous->next = ptr->next;   //前结点指向下结点
	}
	else
	{
		previous->next = ptr->next;     //前结点指向下结点
	}

	free(ptr);    //释放结点内存
	return head;   //返回链表起始指针
}

int main()
{
	clink head;   //循环链表指针
	clink find;   //找到的链表结点
	int list[6] = {9,7,3,4,5,6};  //数组内容
	int value;  //要查询值

	head = createclist(list,6);  //创建循环链表
	if(head == NULL)
	{
		printf("内存分配失败！\n"); //链表创建失败
		exit(1);
	}
	printf("链表内容是：");
	printclist(head);   //输出链表内容

	while(1) 
	{
		printf("请输入查询值 ==>");
		scanf("%d",&value);   //输入值
		if(value == -1)
		{
			printclist(head);   //输出删除后链表内容
			exit(1);
		}

		find = findnode(head,value);  //在链表中查询值
		if(find != NULL)
		{
			printf("删除值：%d\n",find->data); 
			head = deletenode(head,find);   //删除find结点
			printclist(head);  //输出链表内容
		}
		else
			printf("找不到搜索值\n");
	}
	return 0;
}

