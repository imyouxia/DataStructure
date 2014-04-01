/* 汉诺塔问题：
 * 使用递归结出 n = 3 的汉诺塔问题
 * 第一次调用递归要将n-1个盘子从木桩1搬移到木桩2，第二次调用则是从木桩2将n-1个盘子搬移到木桩3
 */

#include <stdio.h>
#include <stdlib.h>

int hanoi(int dishs,int peg1,int peg2,int peg3)
{
	if(dishs == 1)   //终止条件
		printf("盘子从%d移到%d\n",peg1,peg3);
	else
	{
		hanoi(dishs - 1,peg1,peg3,peg2); //第一步骤
		printf("盘子从%d移到%d\n",peg1,peg3);  
		hanoi(dishs - 1,peg2,peg1,peg3);   //第三步骤
	}
	return 0;
}

int main()
{
	hanoi(3,1,2,3);   //调用递归函数
}

