/* 堆排序：
 * 二叉堆的定义：
 * 二叉堆是完全二叉树或者是近似完全二叉树。
 * 二叉堆满足二个特性：
 * 1.父结点的键值总是大于或等于（小于或等于）任何一个子结点的键值。
 * 2.每个结点的左子树和右子树都是一个二叉堆（都是最大堆或最小堆）。
 *
 * 如果将二叉树的数组表示法创建成堆，需要从二叉树数组的中间往回调整，如果数组有n个元素，其中间位置为n/2。
 * 此位置的结点保证是叶结点的上一层，所以在往回调整的过程中，可以处理所有的叶结点。
 *
 *
 * 先找出这个结点的左、右子结点中数据最大的结点和此结点比较，如下所示：
 * （1）如果结点比较大，没有问题，满足堆性质。
 * （2）如果比较小，交换两个结点的数据，然后以交换后的子结点为父结点，重复步骤1的操作。
 */

#include <stdio.h>
#include <stdlib.h>

/* 创建堆 */
void adjust_heap(int *heap,int root,int len)
{
	int done;		//是否可结束的变量
	int j;
	int temp;

	j = 2 * root;   //子结点指针
	temp = heap[root];	//堆的根值
	done = 0;		//创建变量

	while(j <= len && !done)  //主循环
	{
		if(j < len)  //找最大的子结点
		{
			if(heap[j] < heap[j+1])
			{
				j++;  //下一个结点
			}
		}

		if(temp >= heap[j])  //比较树根值
		{
			done = 1;	//结束
		}

		else
		{
			heap[j/2] = heap[j];   //父结点是目前结点
			j = 2 * j;		//其子结点
		}
	}

	heap[j/2] = temp;  //父结点为根值
}

/* 堆排序 */
void heap(int *heap,int len)
{
	int i,j,temp;

	for(i = (len / 2); i >= 1; i--)  //将二叉树转成堆
	{
		adjust_heap(heap,i,len);
	}
	printf("\n堆的内容：");

	for(j = 1; j < 10; j++)  //列出堆的内容
	{
		printf("[%d]",heap[i]);
	}
	printf("\n");

	for(i = len - 1; i >= 1; i--)   //堆排序主循环
	{
		temp = heap[i+1];   	//交换最后元素
		heap[i+1] = heap[1];	
		heap[1] = temp;
		adjust_heap(heap,1,i);   //重建堆
		printf("\n处理内容：");
		for(j = 1; j < 10; j++)
		{
			printf("[%d]",heap[j]);
		}
	}

}

/* 主程序：将数组用堆排序法来排序 */

int main()
{
	//二叉树结点数据
	int data[10] = {0,5,6,4,8,2,3,7,1,9};
	int i;

	printf("二叉树的内容：");
	for(i = 1; i < 10; i++)  //输出二叉树的内容
	{
		printf("[%d]",data[i]);
	}

	heap(data,9);   //堆排序法
	printf("\n\n输出排序结果：");
	
	for(i = 1; i < 10; i++)  //输出最后内容
	{
		printf("[%d]",data[i]);
	}
	printf("\n");
	return 0;
}

