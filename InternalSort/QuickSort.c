/* 快速排序：
 * 快速排序法和冒泡法一样都是使用交换方式进行排序。
 * 快速排序法和希尔排序法一样是将数据分割，其分割的方法是选择一个元素为分割标准，
 * 将数据分成两半，其中一半是比标准值大的元素，另一半是比较小或相等的元素。
 * 接着每一半元素使用相同的方法分割直到分割的部分无法再分割为止。
 * 这时所有的元素就已经完成排序
 *
 * 接着我们需要决定如何选择分割的标准元素。最佳的方法是找出中间值将数组分割成两个大小相近的
 * 集合，但是对于排序的数据而言，选出中间值并不容易，取而代之的是使用两种常用的方法：如下：
 * 1.选取分割数组组元素的第一个
 * 2.选取分割数组数组最中间的元素
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20   //最大字符串长度

/* 快速排序法的递归处理 */
void q_sort(char *string,int left,int right)
{
	char partition;		//分割元素
	char temp;
	int i,j,k;

	if(left < right)   //是否继续分割
	{
		i = left;		//分割的最左
		j = right + 1;	//分割的最右
		partition = string[left];   //取第一个元素
		do
		{
			do    //从左往右找
			{
				i++;
			}while(string[i] < partition);
			
			do	  //从右往左走
			{
				j--;
			}while(string[j] > partition);

			if(i < j)
			{
				temp = string[i];	//交换数据
				string[i] = string[j];
				string[j] = temp;
			}
		}while(i < j);
		
		temp = string[left];	//交换数据
		string[left] = string[j];
		string[j] = temp;
		printf("输出结果：");

		for(k = left; k <= right; k++)  //输出处理字符串
		{
			printf("%c",string[k]);
		}
		printf("\n");   //换行
		q_sort(string,left,j-1);     //快速排序递归调用
		q_sort(string,j+1,right);	 //快速排序递归调用
			
	}

}

/* 快速排序法 */
void quick(char *string,int n)
{
	q_sort(string,0,n-1);
}

/* 主程序：输入字符串后将字符串排序 */
int main()
{
	char string[MAX];	//字符串数组
	int count;    //字符串长度

	printf("输入将排序的字符串 ==>");
	gets(string);   //读取字符串
	count = strlen(string);	//计算字符串长度
	quick(string,count);
	
	//输出排序后字符串
	printf("\n输出排序结果：[%s]\n",string);
	return 0;
}

