/* 直接归并排序法 */

#include <stdio.h>
#include <stdlib.h>
#define LEN 8   //最大元素个数

/* 直接归并排序 */
void merge_sort(FILE *merge,FILE *sort1,FILE *sort2,int len)
{
	int s1,s2;		//数据计数
	int i,j,k;
	char c,c1,c2;

	for(i = 1; i < len; i *= 2)
	{
		//分割文件
		for(j = 0; j < len / 2; j++)   //分割文件一
		{
			c = getc(merge);
			putc(c,sort1);
		}

		for(; j < len; j++)  //分到文件二
		{
			c = getc(merge);
			putc(c,sort2);
		}

		rewind(merge);	//重设文件指针
		rewind(sort1);
		rewind(sort2);

		for(k = 0; k < len / 2; k += i) //归并循环
		{
			c1 = getc(sort1);	//读取第一分割文件
			c2 = getc(sort2);	//读取第二分割文件
			s1 = s2 = 0;		//设置计数初值

			while(1)
			{
				if(c1 < c2)  //比较两个值
				{
					//第一分割文件小，存入主文件
					putc(c1,merge);
					s1++;  //计数加1
					if(s1 < i)  //是否未读完
						c1 = getc(sort1);	//读取第一分割文件
					else
						break;	//跳出循环
				}

				else
				{
					//第二分割文件小，存入主文件
					putc(c2,merge);
					s2++;  //计数加2
					if(s2 < i)   //是否未读完
					{
						c2 = getc(sort2);   //读取第一分割文件
					}
					else
					{
						break;  //跳出循环
					}
				
				}
			}

			//第一分割文件是否是最后一条
			if(s1 < i)  //处理最后一条
			{
				putc(c1,merge);  //存入主文件
				s1++;  //计数加1
			}

			//第二分割文件是否是最后一笔
			if(s2 < i)  //处理最后一笔
			{
				putc(c2,merge);	//存入主文件
				s2++;		//计数加1
			}

			//第一分割文件
			while(s1 < i)   //取出剩下的数据
			{
				c = getc(sort1);	//读取第一分割文件
				putc(c,merge);		//存入主文件
				s1++;		//计数加1
			}

			//第二分割文件
			while(s2 < i)  //取出剩下的数据
			{
				c =  getc(sort2);   //读取第二分割文件
				putc(c,merge);		//存入主文件
				s2++;		//计数加1
			}
		}
	
		rewind(merge);   //重设文件指针
		rewind(sort1);
		rewind(sort2);
	}
	
}

int main()
{
	FILE *data;	//数据文件
	FILE *fp;	//主文件指针
	FILE *fp1;	//第一分割文件指针
	FILE *fp2;	//第二分割文件指针
	char c;
	int j;

	data = fopen("data.txt","r");   //打开数据文件

	if(data == NULL)
	{
		printf("数据文件打开错误！\n");
		exit(0);
	}

	fp = fopen("result.txt","r+"); //打开主文件
	if(fp == NULL)
	{
		printf("主文件打开错误！\n");
	}
	else
	{
		for(j = 0; j < LEN; j++)  //拷贝数据到主文件
		{
			c = getc(data);  //读取数据
			putc(c,fp);		 //存入数据
		}
		fclose(data);		//关闭数据文件
		rewind(fp);			//重设文件指针
		fp1 = fopen("split1.txt","r+");	//打开第二分割文件
		if(fp1 == NULL)
		{
			printf("第一分割文件打开错误！\n");
		}
		else
		{
			fp2 = fopen("split2.txt","r+");  //打开第二分割文件
			if(fp2 == NULL)
			{
				printf("第二分割文件打开错误！\n");
			}
			else
			{
				printf("数据处理中，请稍待。。。\n");
				merge_sort(fp,fp1,fp2,LEN);  //直接归并排序法
				printf("数据处理完成！\n");
				fclose(fp);
				fclose(fp1);
				fclose(fp2);
			}
		}	

	}
	return 0;
}

