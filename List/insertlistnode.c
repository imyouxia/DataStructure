/* 链表的结点插入 */

#include <stdio.h>
#include <stdlib.h>

struct llist   //链表结构声明
{
	int num;   //邮寄编号
	struct llist *next;   //指向下一标签
};

typedef struct llist node;  //定义新类型
typedef node *llink;    //定义新类型指针

/* 链表的输出 */
int printllist(llink ptr)
{
	while(ptr != NULL)  //链表遍历循环
	{
		printf("[%d]",ptr->num);    //输出结点数据
		ptr = ptr->next;     //指向下一结点
	}
	printf("\n");  //结点
	return 0;
}

/* 链表的创建 */

llink createllist(int *array,int len)
{
	llink head;   //链表的开始指针
	llink ptr,ptr1;
	int i;

	//创建第一个结点
	head = (llink) malloc(sizeof(node));  //分配内存
	if(!head)    //检查指针
		return NULL;
	head->num = array[0];   //创建结点内容
	head->next = NULL;    //设置指针初值
	ptr = head;   //将ptr指向链表开始

	for(i = 1; i < len; i++)   //创建其他结点循环
	{
		ptr1 = (llink) malloc(sizeof(node));
		if(!ptr)
			return NULL;
		ptr1->num = array[i];  //创建结点内容
		ptr1->next = NULL;    //设置指针初值
		ptr->next = ptr1; //连接结点
		ptr = ptr->next;  //指向下一结点
	}

	return head;
}

/* 链表的结点遍历 */
llink findnode(llink head,int num)
{
	llink ptr;
	ptr = head;      //指向链表起始
	while(ptr != NULL)  //遍历链表
	{
		if(ptr->num == num)   //查找编号
		{
			return ptr;
		}
		ptr = ptr->next;   //指向下一结点
	}
	return ptr;
}
/*链表的结点插入 */
llink insertnode(llink head,llink ptr,int value)
{
	llink new;   //新结点指针变量

	new = (llink) malloc(sizeof(node));  //创建新结点
	if(!new)
	{
		return NULL;
	}
	new->num = value;   //创建结点内容
	new->next = NULL;   //设置指针初值

	if(ptr == NULL)    //指针ptr是否是NULL
	{	
		//插入第一个结点
		new->next = head;    //新结点成为链表开始
		return new;
	}

	else
	{
		if(ptr->next == NULL)  //是否是链表结束
				//链表结束
				ptr->next = new;   //最后指向新结点
		else
		{
			//中间结点
			new->next = ptr->next;  //新结点指向下一结点
			ptr->next = new;   //结点ptr指向新结点
		}
	}
	return head;
}


/* 链表的内存释放 */

int freellist(llink head)
{
	llink ptr;
	while(head != NULL)  //遍历链表循环
	{
		ptr = head;
		head = head->next; //指向下一结点
		free(ptr);   //释放结点内存
	}
	return 0;
}

int main()
{
	int llist1[6] = {1,2,3,4,5,6};   //数组内容
	llink head;    //指向链表开始
	llink ptr;
	int num;    //邮寄编号变量
	int value;   //新插入邮寄编号

	head = createllist(llist1,6);  //创建链表
	if(!head)
	{
		printf("内存分配失败！ \n");
		exit(1);
	}
	printf("原来的链表：\n");
	printllist(head);   //输出原来链表
	while(1)
	{
		printf("请输入要插入的邮寄编号 ==>");
		scanf("%d",&num);   //读取邮寄编号
		if(num != -1)
		{
			ptr = findnode(head,num);   //查找邮寄编号
			printf("请输入新插入的邮寄编号 ==>");
			scanf("%d",&value);    //读取邮寄编号
			/* 插入新结点至结点ptr之后，如果没找到邮寄编号则
			 * 插入成为链表的开始，因指针ptr是NULL。
			 */
			head = insertnode(head,ptr,value);
			if(!head)
			{
				printf("内存分配失败！\n");
				exit(1);
			}
			printf("插入后链表：");
			printllist(head);  //输出插入后链表
		}
		else
			exit(1);
	}
	
	freellist(head);   //释放链表内存
	return 0;
}

