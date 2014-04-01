/* 希尔排序法：
 * 排序的策略是将排序的元素根据指定间隔分成数个集合，然后逐渐减少这个量直到元素排序完成
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20   //最大字符串长度

/* 希尔排序法 */
void shell(char *string,int count)
{
	int pos;   	//处理位置
	int offset;	//位移量
	int j;
	char temp;

	offset = count / 2;	//创建位移量
	while(offset != 0)  //处理排序循环
	{
		for(j = offset; j < count; j++)  //交换循环
		{
			temp = string[j];   //保留其值
			pos = j - offset;	//计算处理位置
			while(temp < string[pos] &&
					pos >= 0 && j <= count)
			{
				//交换其值
				string[pos + offset] = string[pos];
				pos = pos - offset;	//下一个处理位置
			}
			string[pos + offset] = temp;		//与最后元素交换
		}
		
		printf("输出结果：[%s]\n",string);   //输出处理字符串
		offset = offset / 2;    //创建下次位移量
	}

}

/* 主程序：输入字符串后将字符串排序 */
int main()
{
	char string[MAX];    //字符串数组
	int count;			//字符串长度

	printf("输入将排序的字符串 ==>");
	gets(string);		//读取字符串
	count = strlen(string);		//计算字符串长度
	shell(string,count);		//希尔排序法
	printf("\n输出排序结果：[%s]\n",string);
	return 0;
}

