/* 改良的冒泡排序法：
 * 就是检查没有任何元素交换的时候停止运行
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20   //最大字符串长度

/* 冒泡排序法 */
void bubble(char *string,int count)
{
	int i,done;
	char temp;
	
	done = 0;
	while( !done ) //创建变量
	{
		done = 1;
		for(i = 0; i < count - 1; i++)  //第二层循环
		{
			if(string[i+1] < string[i])  //比较相邻的数组元素
			{
				temp = string[i+1];   //交换两元素
				string[i+1] = string[i];
				string[i] = temp;
				done = 0;   //有交换
			}
		}
		if(!done)
		{
			printf("输出结果：[%s]\n",string);
		}
	}
}

int main()
{
	char string[MAX];   //字符串数组
	int count; 			//字符串长度

	printf("输入将排列的字符串 ==>");
	gets(string);		//读取字符串
	count = strlen(string);	//计算字符串长度
	bubble(string,count);   //冒泡排序法

	//输出排序后字符串
	printf("\n输出排序结果：[%s]\n",string);
	return 0;
}

