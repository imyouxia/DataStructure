/*
 * 归并排序，也叫归并算法，指的是将两个已经排序的串行合并成一个串行的操作。归并排序算法依赖归并操作。
 *
 * 归并操作的过程如下：
 * 1.申请空间，使其大小为两个已经排序串行之和，该空间用来存放合并后的串行。
 * 2.设定两个指针，最初位置分别为两个已经排序串行的起始位置
 * 3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
 * 4.重复步骤3直到某一指针到达串行尾
 * 5.将另一串行剩下的所有元素直接复制到合并串行尾
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define SORT_NUM 10

void print_array(int *list,int len);
void merge_array(int *list1,int list1_size,int *list2,int list2_size);

/*
 * 归并排序
 * *list 要排序的数组
 * n 数组中的元素数量
 */

void merge_sort(int *list,int list_size)
{
    if(list_size > 1)
    {
        //把数组平均分成两个部分
        int *list1 = list;
        int list1_size = list_size / 2;
        int *list2 = list + list_size / 2;
        int list2_size = list_size - list1_size;

        // 分别归并排序
        merge_sort(list1,list1_size);
        merge_sort(list2,list2_size);
        
        //归并
        merge_array(list1,list1_size,list2,list2_size);
    }

}

/*
 * 归并两个有序数组
 *
 */

void merge_array(int *list1,int list1_size,int *list2,int list2_size)
{
    int i,j,k;
    i = j = k = 0;
    
    // 声明临时数组用于存储归并结果
    int *list = malloc((list1_size + list2_size) * sizeof(int));

    // 只要有一个数组到达了尾部就要跳出
    // 也就是说只有两个都没有到达尾部的时候才执行这个循环
    while(i < list1_size && j < list2_size)
    {
        //把较小的那个数据放到结果数组里，同时移动指针
        list[k++] = list1[i] < list2[j] ? list1[i++] : list2[j++];
    } 

    // 如果list1还有元素，把剩下的数据直接放到结果数组
    while(i < list1_size)
    {
        list[k++] = list1[i++];
    }

    // 如果list2还有元素，把剩下的数据直接放到结果数组
    while(j < list2_size)
    {
        list[k++] = list2[j++];
    }

    // 把结果数组copy到list1里
    for(int ii = 0; ii < (list1_size + list2_size); ++ii)
    {
        list1[ii] = list[ii];
    }
    free(list);

}

void print_array(int *list,int len)
{
    int i;
    for(i = 0; i < len; ++i)
    {
        printf("%3d",list[i]);
        if(i < len - 1)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int len = SORT_NUM;
    int list[len];
    srand(time(NULL));
    for(int i = 0; i < len; ++i)
    {
        list[i] = rand() % (SORT_NUM * SORT_NUM);
    }

    print_array(list,len);
    merge_sort(list,len);
    print_array(list,len);

    return 0;
}

