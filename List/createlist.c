/* 基本链表的创建 */

#include <stdio.h>
#include <stdlib.h>

struct llist              //链表结构声明
{
	int num;              //邮寄编号
	char name[10];		  //邮寄姓名
	struct llist *next;   //指向下一标签
};

typedef struct llist node;   //定义新类型
typedef node *llink;       //定义新类型指针

int main()
{
	llink head;            //链表的开始指针
	llink ptr,ptr1;
	int i;

	//创建第一个结点
	head = (llink) malloc(sizeof(node));  //分配内存

	if(!head)    //检查指针
	{
		printf("内存分配失败！\n");
		exit(1);
	}
	
	printf("输入六项邮寄数据：\n");
	printf("请输入编号 ==>");
	scanf("%d",&head->num);   //读取编号
	printf("请输入编号（%d）的姓名 ==>",head->num);
	scanf("%s",head->name);     //读取姓名
	head->next = NULL;  //设置指针初值
	ptr = head;    //将ptr指向链表开始

	for(i = 1; i < 6; i++)
	{
		ptr1 = (llink)malloc(sizeof(node));
		if(!ptr1)
		{
			printf("内存分配失败！\n");
			exit(1);
		}

		printf("请输入编号 ==>");
		scanf("%d",&ptr1->num);  //读取编号
		printf("请输入编号（%d）的姓名 ==>",ptr1->num);
		scanf("%s",ptr1->name);  //读取姓名
		ptr1->next = NULL;   //设置指针初值
		ptr->next = ptr1;    //连接结点
		ptr = ptr->next;    //指向下一结点
		
	}

	printf("邮寄资料：\n");   //输出数据内容
	ptr = head;    //将ptr指向链表开始
	for(i = 0; i< 6; i++)    //输出循环
	{
		printf("编号：%d\n",ptr->num);
		printf("姓名：%s\n",ptr->name);
		ptr = ptr->next;      //指向下一结点
	}
	return 0;
}

