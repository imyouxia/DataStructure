/* 归并排序法 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 4  //最大元素个数

/* 归并排序 */
void merge(FILE *merge,FILE *sort1,FILE *sort2,int len)
{
	int s1,s2;		//数据计数
	char c,c1,c2;

	c1 = getc(sort1);		//读取第一个文件
	c2 = getc(sort2);		//读取第二个文件

	s1 = s2 = 0;   //设置计数初值

	while(1)
	{
		if(c1 < c2)  //比较两个值
		{
			putc(c1,merge);  //第一个文件小，存入主文件
			s1++;   //计数加1
			if(s1 < len)  //是否未读完
				c1 = getc(sort1);   //读取第一个文件
			else
				break;
		}
		else
		{
			//第二个文件小，存入主文件
			putc(c2,merge);
			s2++;
			if(s2 < len)  //是否未读完
				c2 = getc(sort2);   //读取第一个文件
			else
				break;   //跳出循环

		}
	
	}

	//第一个文件是否是最后一笔
	if(s1 < len)   //处理最后一笔
	{
		putc(c1,merge);	//存入主文件
		s1++;			//计数加1
	}

	//第二个文件是否是最后一笔
	if(s2 < len)
	{
		putc(c2,merge);  //存入主文件
		s2++;   //计数加1
	}

	//第一个文件
	while(s1 < len)  //取出剩下的数据
	{
		c = getc(sort1);   //读取第一个文件
		putc(c,merge);		//存入主文件
		s1++;  //计数加1
	}

	//第二个文件
	while(s2 < len) //取出剩下的数据
	{
		c = getc(sort2);  //读取第二个文件
		putc(c,merge);	//存入主文件
		s2++;		//计数加1
	}
}

int main()
{
	FILE *fp;		//主文件指针
	FILE *fp1;		//第一数据文件指针
	FILE *fp2;		//第二个数据文件指针

	fp = fopen("result.txt","r+");  //打开主文件
	if(fp == NULL)
	{
		printf("主文件打开错误！\n");
	}
	else
	{
		fp1 = fopen("sort1.txt","r+"); //打开第一数据文件
		if(fp1 == NULL)
		{
			printf("第一数据文件打开错误！\n");
		}
		else
		{
			fp2 = fopen("sort2.txt","r+");
			if(fp2 == NULL)
				printf("第二数据文件打开错误！\n");
			else
			{
				printf("数据处理中，请稍等。。。\n");
				merge(fp,fp1,fp2,LEN);		//归并排序法
				printf("数据处理完成！\n");
				fclose(fp);
				fclose(fp1);
				fclose(fp2);
			}
		}
	}
	return 0;
}

