/* 插入排序法：
 * 是先将排序元素的前两个元素排序，然后将第三个元素插入已经排序好的两个元素中，所以这三个元素仍然是从小到大排序。
 * 与扑克牌相似。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20    //最大字符串长度

/*
 * 插入排序法
 */

void insert(char *string,int count)
{
	int i,j;
	char temp;

	for(i = 1; i < count; i++)  
	{
		temp = string[i];	//创建初值
		j = i - 1;   //开始位置

		//空出插入位置
		while(j >= 0  && temp < string[j])
		{
			string[j+1] = string[j];
			j--;
		}

		string[j+1] = temp;   //插入字符
		printf("输出结果：[%s]\n",string);  //输出交换后字符串
	}
}

int main()
{
	char string[MAX];     //字符串数组
	int count;			  //字符串长度

	printf("输入将排序的字符串 == >");
	gets(string);    //读取字符串
	count = strlen(string);   //计算字符串长度
	insert(string,count);	 //插入排序法
	//输出排序后字符串
	printf("\n输出排序结果：[%s]\n",string);
	return 0;
}


