/* 使用含头结点的循环链表处理多项式相加的问题 
 * A(X) = 7X^4 + 3X^2 + 4
 * B(X) = 6X^5 + 5X^4 + X^2 + 7X + 9
 */

#include <stdio.h>
#include <stdlib.h>

struct plist   //多项式结构声明
{	
	int coef;   //多项式的系数
	int exp;    //多项式的指数
	struct plist *next;    //指向下一结点的指针	
};

typedef struct plist pnode;    //多项式新类型
typedef pnode *plink;   //多项式指针新类型

/* 多项式含头结点的循环链表的输出 */

int printpoly(plink poly)
{
	plink ptr;

	ptr = poly->next;  //指向链表开始
	while(poly != ptr)   //链表遍历循环
	{
		//输出结点数据
		printf("%dX^%d",ptr->coef,ptr->exp);
		ptr = ptr->next;   //指向下一个结点
		if(poly != ptr)
			printf("+");
	}

	printf("\n");
	return 0;
}

/* 使用数组值创建多项式 */
plink createpoly(int *array,int len)
{
	plink head;    //循环链表的指针
	plink before;    //前一结点的指针
	plink new_node;   //新结点的指针
	int i;

	/* 创建头结点
	 * 分配结点内存
	 */

	head = (plink) malloc(sizeof(pnode));
   	if(!head)	  //检查内存指针
	{
		return NULL;
	}
	head->exp = -1;  //创建结点内存
	before = head;    //指向第一个结点

	for(i = len-1; i >= 0; i--)
	{
		if(array[i] != 0)
		{
			//分配结点内存
			new_node = (plink) malloc(sizeof(pnode));
			if(!new_node)  //检查内存指针
				return NULL;
			new_node->coef = array[i];   //创建系数内容
			new_node->exp = i;  //创建指数内容
			new_node->next = NULL;   //设置指针初值
			before->next = new_node;    //将前结点指向新结点
			before = new_node;   //新结点成为前结点
		}
	}
	new_node->next = head;   //创建环状链接
	return head;    //返回链表起始指针
}

/* 多项式相加 */
plink polyadd(plink poly1,plink poly2)
{
	plink head1;   //多项式1的开始
	plink head2;    //多项式2的开始
	plink result;   //多项式的结果
	plink before;   //前一结点的指针
	plink new_node;   //新结点的指针

	head1 = poly1->next;   //指向多项式1的开始
	head2 = poly2->next;   //指向多项式2的开始

	//创建头结点且分配结点内存
	result = (plink)malloc(sizeof(pnode));
	if(!result)
		return NULL;
	result->exp = -1;   //创建结点内容
	before = result;    //指向第一个结点

	while(poly1 != head1 || poly2 != head2)
	{
		//分配结点内存
		new_node = (plink)malloc(sizeof(pnode));
		if(!new_node)
			return NULL;
		if(head1->exp < head2->exp)  //多项式2的指数大
		{
			new_node->coef = head2->coef;  //设置系数
			new_node->exp = head2->exp;   //设置指数
			head2 = head2->next;   //指向下一结点
		}
		else
		{	if(head1->exp > head2->exp)   //多项式1的指数大
			{
				new_node->coef = head1->coef;   //设置系数
				new_node->exp = head1->exp;   //设置指数
				head1 = head1->next;   //指向下一结点
			}
			else   //多项式的指数相等
			{
				//系数相加
				new_node->coef = head1->coef + head2->coef;
				new_node->exp = head1->exp;  //设置指数
				head1 = head1->next;  //指向下一结点
				head2 = head2->next;   //指向下一结点	
			}
		}
		before->next = new_node;   //将前结点指向新结点
		before = new_node;      //新结点成为前结点

	}
	new_node->next = result;   //创建环状链接
	return result;   //返回多项式的指针
}

/* 多项式相加 */
int main()
{
	plink poly1;   //多项式1的指针
	plink poly2;   //多项式2的指针
	plink result;   //多项式结果的指针
	int list1[6] = {4,0,3,0,7,0};  //数组1内容
	int list2[6] = {9,7,1,0,5,6};  //数组2内容

	poly1 = createpoly(list1,6); //创建多项式1
	printf("多项式1内容：");
	printpoly(poly1);  //输出多项式1
	poly2 = createpoly(list2,6);  //创建多项式2
	printf("多项式2内容：");
	printpoly(poly2);   //输出多项式2

	result = polyadd(poly1,poly2);  //多项式相加
	printf("多项式相加结果：");
	printpoly(result);  //输出多项式结果

	return 0;

}



