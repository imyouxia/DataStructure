/* 一维数组的遍历
 *
 * 输入查询的成绩，然后输出符合成绩条件的第一位学生学号。
 */

#include <stdio.h>

int main()
{
	int score[10] = {76,85,90,67,59,79,82,
						95,91,65}; /* 学生成绩数组 */
	int num;   /* 学生学号变量 */
	int grade; /* 学生成绩变量 */
	int i;
	
	num = -1;
	printf("请输入学生成绩（0到100）.==>");
	scanf("%d",&grade);  /* 读取成绩 */
	
	for( i = 0; i < 10; i++) /* 遍历成绩数组 */
	{
		if(score[i] == grade) /* 找到此成绩 */
		{
			num = i;      /* 存入学号变量 */
			break;        /* 结束遍历 */
		}
	}

	if(num != -1)      /* 是否有此成绩 */
		printf("学生学号是：%d\n",num); /* 输出学号 */
	else
		printf("没有此成绩的学生\n");
	return 0;
}
