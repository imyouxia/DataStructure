/* 使用数组来构建栈
 * 这次的扑克游戏只洗5张牌，然后使用循环检查empty()函数将牌全部发出。函数empty()只是检查栈指针是否为-1，如果是，表示栈已经空了。
 */

#include <stdlib.h>
#include <stdio.h>

#define MAXSTACK 100    //最大栈容量
int stack[MAXSTACK];   //栈的数组声明
int top = -1;     //栈的顶端

/* 栈数据的存入 */
int push(int value)
{
	if(top >= MAXSTACK)  //是否超过容量
	{
		printf("栈内容全满\n");
		return -1;   //存入失败
	}
	top++;   //栈指针加1
	stack[top] = value;   //存入栈
	return 0;
}

/* 栈数据的取出 */
int pop()
{
	int temp;
	if(top < 0)  //是否栈是空
	{
		printf("栈内容是空的\n");
		return -1;   //取出失败
	}
	temp = stack[top];   //取出数据
	top--;    //栈指针减一
	return temp;   //栈取出
}

/* 检查栈是否是空的 */
int empty()
{
	if(top == -1)  //是否是空
	{
		return 1;   //空的
	}
	else
		return 0;   //不是空的
}

/* 主程序：运行empty()检查牌是否发完
 * 红心：数组  0 ~12
 * 方块：数组 13 ~ 25
 * 梅花：数组 26 ~ 38
 * 黑桃：数组 39 ~ 51
 */

int main()
{
	int card[52];    //扑克牌数组
	int pos;      //牌代码
	int i,temp;
	long temptime;
	srand(time(&temptime) % 60);   //使用时间初始随机数
	for(i = 0; i < 52;i++)
	{
		card[i] = 0;   //清楚扑克牌数组
	}
	i = 0;  
	while(i != 5)  //洗5张牌循环
	{
		 pos = rand() % 52;   //随机数取值 0 ~ 51;
		 if(card[pos] == 0)  //是否是未洗牌
		 {
		 	push(pos);    //存此张牌进栈
			card[pos] = 1; //设置此张牌洗过
			i++;             //下一张牌
		 }
	}

	while(!empty())   //发完栈全部的牌
	{
		temp = pop();   //取出栈数据
		printf("[%c%2d]",temp / 13 + 3,temp % 13 + 1);
	}
	printf("\n");
	return 0;
}

