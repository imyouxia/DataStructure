/* 使用链表创建散列表 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10   //最大数组容量
#define NUM 10   //随机数生成的个数

struct list  //链表结构声明
{
	int key;    //关键码
	struct list *next;    //指向下一结点
};
typedef struct list node;   //定义新类型
typedef node *link;   //定义新类型指针

node hashtable[MAX];   //散列表声明

/* 散列函数 */
int hashfunc(int value)
{
	return value % MAX;  //余数
}

/* 链表的散列查找 */
int linkhash(int key)
{
	link ptr;   //开始指针
	int pos;    //位置变量

	//调用散列函数计算位置
	pos = hashfunc(key);
	ptr = hashtable[pos].next;  //取得开始指针
	while(ptr != NULL)  //线性探测循环
	{
		if(ptr->key == key)
		{
			return 1;
		}
		else
		{
			ptr = ptr->next;  //下一个结点
		}
	}
	return 0;
}

/* 创建散列表 */
void createtable(int key)
{
	link ptr;   //开始指针
	link new;   //链表的开始指针
	int pos;    //位置变量

	//创建一个结点
	new = (link)malloc(sizeof(node));   //分配内存
	new->key = key;    //存入散列表
	new->next = NULL;   //创建指针初值

	//调用散列函数计算位置
	pos = hashfunc(key);
	ptr = hashtable[pos].next;  //取得开始指针

	if(ptr != NULL)  //查找存入位置
	{
		new->next = ptr;   //插入结点
		hashtable[pos].next = new;   //链接结点
	}
	else
	{
		hashtable[pos].next = new;   //链接结点
	}
}

/* 主程序：散列表找法 */
int main()
{
	link ptr;  //开始指针
	int checked[50];    //检查数组
	int i,temp;
	long temptime;
	for(i = 0; i < MAX; i++)
	{
		hashtable[i].next = NULL;  //清除散列表
	}
	for(i = 0; i < 50; i++)
	{
		checked[i] = 0;   //清除检查数组
	}

	srand(time(&temptime) % 60);   //使用时间初始随机数
	i = 0;
	while(i != NUM)  //生成数组值的循环
	{
		temp = rand() % 50;  //随机数取值 0 ～ 49
		if(checked[temp] == 0)   //是否是已有的值
		{
			createtable(temp);  //创建散列表
			checked[temp] = 1;  //设置此值生成过
			i++;
		}
	}
	printf("散列表内容：\n");
	for(i = 0; i < MAX; i++)
	{
		printf("\n%2d == >",i);
		ptr = hashtable[i].next;   //取得开始指针
		while(ptr != NULL)  //输出链表循环
		{
			printf("[%2d]",ptr->key);   //输出内容
			ptr = ptr->next;   //下一结点
		}
	}

	while(1)
	{
		printf("\n请输入查找值（0-49）==>");
		scanf("%d",&temp);  //导入查找值
		if(temp != -1)
		{
			i = linkhash(temp);  //调用散列查找
			if(i != 0)
			{
				printf("找到查找值：%d\n",temp);
			}
			else
			{
				printf("没有找到查找值：%d\n",temp);
			}
		}
		else
			exit(1);
		
	}
	return 0;
}

