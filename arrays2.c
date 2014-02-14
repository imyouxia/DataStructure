/* array.c需要从头到尾遍历数组，这是一种相当没有效率的方法。
 * 其实只要将这些数据重新组合，使用空间换取时间的技术，就可以提升效率
 * 因为学生的成绩范围是从 0 到 100，所以我们可以声明一个长度为 101 个元素的数组pointer，它的声明方式，如下所示：int pointer[101];
 * 上述的pointer数组使用成绩的范围作为其索引值，如果这个成绩不存在，数组元素内容是-1。反之内容就是score数组中此成绩元素的索引值，也就是学生的学号。
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int score[10] = {76,85,90,67,59,79,82,
						95,91,65}; /* 学生成绩数组 */
	int pointer[101];  /* 指针数组 */
	int index;         /* 数组索引变量 */
	int grade;		       /* 学生成绩变量 */
	int i;

	/* 第一部分：创建指针数组 */
	for(i = 0; i <= 101; i++)
		pointer[i] = -1;    /* 设置数组初值为 -1 */

	for(i = 0; i < 10; i++) /* 遍历成绩数组 */
	{
		index = score[i];
		pointer[index] = i; /* 创建pointer数组 */
	}

	/* 第二部分：查询学生学号 */
	while(1)
	{
		printf("请输入学生成绩（0到100）.==>");
		scanf("%d",&grade);         /* 读取学生成绩 */
		if(grade != -1)
		{
			index = pointer[grade]; /* 查询学号 */
			if(index != -1)
				printf("学生学号是：%d\n",index);
			else
				printf("没有此成绩的学生\n");
		}
		else
			exit(1); /* 结束循环退出 */
	}
	return 0;
}
