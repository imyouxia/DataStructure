/* 选择排序法是从排序的元素中选出最小的一个元素，然后和第一个元素交换。
 * 然后从剩下的元素中选出最小的元素和第二个元素交换，重复这种处理方法，直到最后一个元素为止。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20   //最大字符串长度

/* 选择排序法 */
void selectsort(char *string,int count)
{
	int pos;    //目前最小的字符
	int i,j;
	char temp;

	for(i = 0; i < count - 1; i++)   //第一层循环
	{
		pos = i;
		temp = string[pos];
		//查找最小的字符
		for(j = i + 1; j < count; j++)
		{
			if(string[j] < temp) //是否更小
			{
				pos = j;	//新的最小字符
				temp = string[j];
			}
		}
		string[pos] = string[i];   //交换两字符
		string[i] = temp;
		printf("输出结果：[%s]\n",string);   //输出交换后字符串

	}
	
}

int main()
{
	char string[MAX];  //字符串数组
	int count;			//字符串长度

	printf("输入将排序的字符串 ==>");
	gets(string);  //读取字符串
	count = strlen(string);	//计算字符串长度
	selectsort(string,count);
	printf("\n输出排序结果：[%s]\n",string);
	return 0;
}

