/* 斐波纳契的特性是树根是一个斐波纳契数，
 * 而且子结点与父结点差值的绝对值也是一个斐波纳契数 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 21   //最大数组容量

struct element  //记录结构声明
{
	int key;	
};

typedef struct element record;  //结构新类型
record data[MAX] = {
		2,5,7,9,17,21,25,
		33,46,89,100,121,127,139,
		237,279,302,356,455,467,500
};

/* 斐波纳契 - 计算斐波纳契数 */
int fib(int n)
{
	if(n <= 1)   //N是否小于1
	{
		return n;   //返回N
	}
	else
	{
		return fib(n-2) + fib(n-1);   //递归计算斐波纳契数
	}

}

/* 计算斐波纳契的n值 当 Fn < n+1 */
int fibindex(int n)
{
	int temp;

	temp = 1;   //设置temp值
	while(fib(temp) <= n + 1)   //比较循环
	{
		temp++;   //如果成立temp加1
	}
	return temp - 1;
}

/* 斐波纳契查找 */
int fibsearch(int n,int key)
{
	int index;       //斐波纳契数的n值
	int mid;		 //斐波纳契数的变量
	int fn1;		 //前一个斐波纳契数
	int fn2;		 //前二个斐波纳契数
	int temp;

	index = fibindex(n + 1);  //计算Fn <= n + 1
	mid = fib(index - 1);    //起始的斐波纳契数
	fn1 = fib(index - 2);    //前一个斐波纳契数
	fn2 = fib(index - 3);    //前二个斐波纳契数

	while(mid != 0)   //斐波纳契查找主函数
	{
		if(key < data[mid - 1].key)   //比较小
		{
			if(fn2 <= 0)
			{
				mid = 0;    //没有找到
			}
			else
			{
				mid = mid - fn2;   //左子树新斐波纳契数
				temp = fn1;
				fn1 = fn2;      //前一个斐波纳契数
				fn2 = temp - fn2;    //前二个斐波纳契数
			}
		}
		else
		{
			if(key > data[mid - 1].key)   //比较大
			{
				if(fn1 <= 1)
				{
					mid = 0;    //没有找打
				}
				else
				{
					mid = mid + fn2;   //右子树新斐波纳契数
					fn1 = fn1 - fn2;   //前一个斐波纳契数
					fn2 = fn2 - fn1;   //前二个斐波纳契数
				}
			}
			else
			{
				return mid - 1;   //找到了
			}
		}

	}
	return -1;
}

int main()
{
	int found;    //是否找到变量
	int value;    //查找值的内容

	while(1)
	{
		printf("\n请输入查找值（0-500） == >");
		scanf("%d",&value);   //导入查找值
		if(value != -1)
		{
			found = fibsearch(MAX,value);   //调用斐波纳契查找
			if(found != -1)
			{
				printf("找到查找值：%d[%d]\n",value,found);
			}
			else
			{
				printf("没有找到查找值：%d\n",value);
			}
		}
		else
			exit(1);
	}
	return 0;
}


