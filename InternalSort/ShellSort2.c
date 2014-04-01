/* 希尔排序法（自定增量）：
 * 可以让用户自行定义间隔数列，只需最后一次的分割间隔分别为1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20    //最大字符串长度

/* 希尔排序法 */

void shell(char *string,int count)
{
	int offset_a[6] = {11,7,5,3,
							2,1};   //设置处理增量

	int pos;   //处理位置
	int offset;
	int i,j;
	char temp;

	for(i = 0; i < 6; i++)   //处理六次增量
	{
		offset = offset_a[i]; 	//创建位移量
		for(j = offset; j < count; j++)  //交换循环
		{
			temp = string[j];		//保留其值
			pos = j - offset;		//计算处理位置
			while(temp < string[pos] &&
					pos >= 0 && j <= count)
			{
				//交换其值
				string[pos + offset] = string[pos];
				pos = pos - offset;	//下一个处理位置
			}
			string[pos + offset] = temp;	//与最后元素交换
		}
	}
	printf("输出结果：[%s]\n",string);  //输出处理字符串
}

int main()
{
	char string[MAX];   //字符串数组
	int count;		//字符串长度

	printf("输入将排序的字符串 ==>");
	gets(string);   //读取字符串
	count = strlen(string);  //计算字符串长度
	shell(string,count);   //希尔排序法
	//输出排序后字符串
	printf("\n输出排序结果：[%s]\n",string);
	return 0;
}

