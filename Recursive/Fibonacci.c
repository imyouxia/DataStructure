/* 迭代：(注意与递归的区别)
 * 斐波那契数列
 * 1，1，2，3，5，8...
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 13
int main()
{
	int i;
	long fib[NUM] = {1,1};

	for(i = 2; i < NUM; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}

	for(i = 0; i < NUM; i++)
	{
		printf("%dN:%ld\n",i,fib[i]);
	}
	
	return 0;
}

