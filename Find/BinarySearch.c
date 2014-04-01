/* 折半查找法（Binary Search）*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 21   //最大数组容量

struct element   //记录结构声明
{
	int key;   //查找关键码
};

typedef struct element record;   //结构新类型
record data[MAX] = {
		2,5,7,9,17,21,25,
		33,46,89,100,121,127,139,
		237,279,302,356,455,467,500
};

/* 折半查找 */
int binarysearch(int key)
{
	int low;   //数组开始变量
	int high;	//数组结束变量
	int mid;	//数组中间变量
	
	low = 0;  //数组开始
	high = MAX - 1;   //数组结束
	while(low <= high)   //折半查找主循环
	{
		mid = (low + high) / 2;   //计算数组中间值
		if(key < data[mid].key)  //比较小
			high = mid - 1;  //前一半
		else
			if(key > data[mid].key)  //比较大
				low = mid + 1;   //后一半
			else
				return mid;  //找到了

	}
	return -1;
}

/* 主程序：在一个已排序的数组，接着输入值用折半查找来找值 */
int main()
{
	int found;	 //是否找到变量
	int value;   //查找值的内容

	while(1)
	{
		printf("\n请输入查找值（0-500）==>");
		scanf("%d",&value);   //导入查找值
		if(value != -1)
		{
			found = binarysearch(value);   //调用折半查找
			if(found != -1)
			{
				printf("找到查找值：%d[%d]\n",value,found);
			}
			else
			{
				printf("没有找到查找值：%d\n",value);
			}
		}
		else
		{
			exit(1);
		}
	
	}

}

