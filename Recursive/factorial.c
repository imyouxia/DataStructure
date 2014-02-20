/* 使用递归方式计算0到4整数的阶乘值 */

#include <stdio.h>
#include <stdlib.h>

/* 递归阶乘函数 */
int factorial(int j)
{
	int sum;   //阶乘总和变量
	if( j == 0)  //终止条件
		sum = 1;
	else
		sum = j * factorial(j - 1);   //递归阶乘函数调用
	return sum;
}

int main()
{
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("%d! = %d\n",i,factorial(i));  //递归阶乘函数调用
	}
	return 0;
}
