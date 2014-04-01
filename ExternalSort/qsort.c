/* 文件的快速排序法 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 8   //最大文件长度
#define LEN sizeof(char)   //字符长度

/* 文件读取字符 */
char get_char(FILE *fp,long int pos)
{
	char c;

	fseek(fp,LEN*pos,0);	//文件中找字符
	fread(&c,LEN,1,fp);		//从文件中取字符
	return c;				//返回字符
}

/* 文件字符交换 */
void swap_char(FILE *fp,long int pos1,long int pos2)
{
	char c1,c2;
	fseek(fp,LEN*pos1,0);	//找第一个元素
	fread(&c1,LEN,1,fp);	//取第二个元素
	fseek(fp,LEN*pos2,0);	//找第二个元素
	fread(&c2,LEN,1,fp);	//取第二个元素

	fseek(fp,LEN*pos1,0);	//找第一个元素
	fwrite(&c2,LEN,1,fp);	//存第二个元素
	fseek(fp,LEN*pos2,0);	//找第二个元素
	fwrite(&c1,LEN,1,fp);	//存第一个元素
}

/* 快速排序法的递归处理 */
void q_sort(FILE *fp,long int left,long int right)
{
	char partition;			//分割元素
	int i,j;

	if(left < right)  //是否继续分割
	{
		i = left;		//分割的最左
		j = right + 1;	//分割的最右
		partition = get_char(fp,left);	//取第一个元素
		do
		{
			do  //从左往右找
			{
				i++;
			}while(get_char(fp,i) < partition);

			do
			{
				j--;
			}while(get_char(fp,j) > partition);

			if(i < j)
				swap_char(fp,i,j);	//交换数据
		
		}while(i < j);

		swap_char(fp,j,left);	//交换数据
		q_sort(fp,left,j-1);    //快速排序递归调用
		q_sort(fp,j+1,right);	//快速排序递归调用
	}

}

/* 快速排序法 */
void quick(FILE *fp,int n)
{
	q_sort(fp,0,(long)n-1);
}

int main()
{
	FILE *data;		//数据文件
	FILE *fp;		//主文件指针
	char c;
	int j;

	data = fopen("data.txt","r");  //打开数据文件
	if(data == NULL)
	{
		printf("数据文件打开错误！\n");
		exit(0);
	}

	fp = fopen("result.txt","r+");   //打开主文件

	if(fp == NULL)
	{
		printf("主文件打开错误！\n");
	}
	else
	{
		for(j = 0; j < MAX; j++)  //拷贝数据到主文件
		{
			c = getc(data);	//读取数据
			putc(c,fp);		//存入数据
		}
		fclose(data);		//关闭数据文件
		rewind(fp);			//重设文件指针
		printf("数据处理中，请等待。。。\n");
		quick(fp,MAX);		//文件的快速排序法
		printf("数据处理完成！\n");
		fclose(fp);
		
	}
	return 0;
}


