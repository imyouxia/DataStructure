/* 链表的遍历 */

#include <stdio.h>
#include <stdlib.h>

struct llist            //链表结构声明
{
	int num;            //邮寄编号
	char name[10];		//邮寄姓名
	struct llist *next; //指向下一个标签
};

typedef struct llist node;    //定义新类型
typedef node *llink;          //定义新类型指针

/* 链表的创建 */

llink createllist()
{
	llink head;    //链表的开始指针
	llink ptr,ptr1;
	int i;
	//创建第一个结点
	head = (llink) malloc(sizeof(node));   //分配内存
	if(!head)                    //检查指针
	{
		return NULL;	
	}
	printf("输入六项邮寄数据：\n");
	printf("请输入编号 ==>");
	scanf("%d",&head->num);     //读取编号
	printf("请输入编号（%d）的姓名 ==>",head->num);
	scanf("%s",head->name);   //读取姓名
	head->next = NULL;      //设置指针初值
	ptr = head;     //将ptr指向链表开始

	for( i = 1; i < 6; i++)  //创建其他结点循环
	{
		ptr1 = (llink) malloc(sizeof(node));
		if(!ptr1)
			return NULL;
		printf("请输入编号 ==>");
		scanf("%d",&ptr1->num);    //读取编号
		printf("请输入编号（%d）的姓名 ==>",ptr1->num);
		scanf("%s",ptr1->name);    //读取姓名
		ptr1->next = NULL;     //设置指针初值
		ptr->next = ptr1;    //连接结点
		ptr = ptr->next;   //指向下一结点
	}

	return head;
}

/* 链表的遍历 */
llink findnode(llink head,int num)
{
	llink ptr;

	ptr = head;         //指向链表起始
	while(ptr != NULL)   //遍历链表
	{
		if(ptr->num == num) //查找编号
		{
			return ptr;
		}
		ptr = ptr->next;   //指向下一结点
	}
	return ptr;
}

/* 输入编号查找邮寄姓名 */

int main()
{
	llink head;    //链表的开始指针
	llink ptr;
	int num;   //邮寄编号变量
	
	head = createllist();  //创建链表
	if(!head)
	{
		printf("内存分配失败！\n");
		exit(1);
	}

	while(1)
	{
		printf("请输入要查找的邮寄编号 ==>");
		scanf("%d",&num);   //读取邮寄编号
		if(num != 0)
		{
			ptr = findnode(head,num);   //链表遍历
			if(!ptr)
				printf("没有找到\n");
			else
				printf("姓名：%s\n",ptr->name);
		}
		else
			exit(1); 

	}
	return 0;
}
