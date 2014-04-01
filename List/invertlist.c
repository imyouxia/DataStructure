/* 链表的链接 : 3个指针，后、中、前 */

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

/* 链表的反转 */
llink invertllist(llink head)
{
	llink mid,last;
	mid = NULL;    //mid是head的前端点
	while(head != NULL)
	{
		last = mid;   //last是mid的前端点
		mid = head;
		head = head->next;  //下一个结点
		mid->next = last;   //mid指向前结点last
	}

	return mid;
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
	
	head = createllist(llist1,6);  //创建链表
	if(!head)
	{
		printf("内存分配失败！ \n");
		exit(1);
	}
	printf("原来的链表：\n");
	printllist(head);   //输出原来链表
	head = invertllist(head);   //反转链表

	printf("反转后链表：");
	printllist(head);   //输出反转后链表
	freellist(head);   //释放链表内存
	return 0;
}

