/* 使用递归折半查找 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 21   //最大数组容量

struct element    //记录结构声明
{
	int key;    //查找关键码
};

typedef struct element record;   //结构新类型
record data[MAX] = {
		2,5,7,8,17,21,25,
		33,46,89,100,121,127,139,
		237,279,302,356,455,467,500
};

/* 折半查找 */
int binarysearch(int key)
{
	return binaryfind(key,0,MAX - 1);    //折半查找递归调用
}

/* 折半查找递归处理 */
int binaryfind(int key,int left,int right)
{
	int mid;    //数组中间变量
	if(left == right)   //是否相等
	{
		if(data[left].key == key)
			return left;
		else
			return -1;
	}
	else
	{
		mid = (left + right) / 2;  //计算数组中间值
		if(mid == left)  //是否相等
		{
			mid++;
		}

		if(key < data[mid].key)   //比较小
		{
			//左半部递归调用折半查找
			return binaryfind(key,left,mid-1);
		}
		else
		{
			return binaryfind(key,mid,right);
		}

	}

}

int main()
{
	int found;   //是否找到变量
	int value;	//查找值的内容

	while(1)
	{
		printf("\n请输入查找值（0-500）==>");
		scanf("%d",&value);   //导入查找值
		if(value != -1)
		{
			found = binarysearch(value);   //调用折半查找
			if(found != -1)
				printf("找到查找值：%d[%d]\n",value,found);
			else
				printf("没有找到查找值：%d\n",value);
		}
		else
			exit(1);

	}
	return 0;
}

