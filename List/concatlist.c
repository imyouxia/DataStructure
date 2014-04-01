/* 链表的链接 */

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

/* 链表的链接 */

llink concatllist(llink ptr1,llink ptr2)
{
	llink ptr;

	ptr = ptr1;  //指向链表1的开始
	while(ptr->next != NULL)   //找链表1的结束
		ptr = ptr->next;   //指向下一结点
	ptr->next = ptr2;   //链接链表2
	return ptr1;
}

int main()
{
	int llist1[6] = {1,2,3,4,5,6};   //数组内容
	int llist2[5] = {8,9,11,21,31};  //数组内容

	llink ptr,ptr1,ptr2;

	ptr1 = createllist(llist1,6);  //创建链表1
	if(ptr1 == NULL)
	{
		printf("内存分配失败！ \n");
		exit(1);
	}

	ptr2 = createllist(llist2,5);   //创建链表2
	if(ptr2 == NULL)
	{
		printf("内存分配失败！ \n");
		exit(1);
	}

	ptr = concatllist(ptr1,ptr2);  //创建量链表
	printllist(ptr);    //输出链接链表
	return 0;
}

