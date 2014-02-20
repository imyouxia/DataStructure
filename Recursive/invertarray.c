/* 使用递归反向输出数组 */

#include <stdio.h>
#include <stdlib.h>

int list[6] = {1,2,3,4,5,6};

int invert_array(int j)
{
	if( j < 6)  //终止条件
	{
		//递归链表输出函数调用
		invert_array(j + 1);
		printf("[%d]",list[j]);   //输出元素数据
	}
	return 0;
}

int main()
{
	int i;
	printf("数组的内容：\n");
	for(i = 0; i < 6; i++)
		printf("[%d]",list[i]);
	printf("\n");
	printf("递归输出数组的内容：\n");
	invert_array(0);  //调用输出函数
	printf("\n");
	return 0;
}
