/*
 * 计数排序：
 * 1.初始化一个计数数组，大小是输入数组中的最大数
 * 2.遍历输入数组，遇到一个数就在计数数组对应的位置上加1，例如：遇到5，就将计数数组第五个位置的数加1
 * 3.把计数数组直接覆盖到输出数组
 *
 * 示例：
 * 输入{3,4,3,2,1}，最大是4，数组长度是5。
 * 建立计数数组{0,0,0,0}
 * 遍历输入数组：
 * {3,4,3,2,1} -> {0,0,1,0}
 * {3,4,3,2,1} -> {0,0,1,1}
 * {3,4,3,2,1} -> {0,0,2,1}
 * {3,4,3,2,1} -> {0,1,2,1}
 * {3,4,3,2,1} -> {1,1,2,1}
 *
 * 计数数组现在是{1,1,2,1}，我们现在把它写回到输入数组里：
 * {0,1,2,1} -> {1,4,3,2,1}
 * {0,0,2,1} -> {1,2,3,2,1}
 * {0,0,1,1} -> {1,2,3,2,1}
 * {0,0,0,1} -> {1,2,3,3,1}
 * {0,0,0,0} -> {1,2,3,3,4}
 *
 * 时间：O(n+k)，n是输入数组长度，k是最大的数的大小。
 * 空间：O(n+k)，n是输入数组长度，k是最大的数的大小。
 */


#include <stdio.h>
#include <stdlib.h>

void printArray(int *array,int size)
{
    int curr;
    for(curr = 0; curr < size; curr++)
    {
        printf("%d, ",array[curr]);
    }
    printf("\n");
}

int maximum(int *array,int size)
{
    int curr = 0;
    int max = 0;
    for(curr = 0; curr < size; curr++)
    {
        if(array[curr] > max)
        {
            max = array[curr];
        }
    }
    return max;
}

void countingSort(int *array,int size)
{
    int curr = 0;
    int max = maximum(array,size);
    int *counting_array = calloc(max,sizeof(int));
    for(curr = 0; curr < size; curr++)
    {
        counting_array[array[curr]]++;
    }
    
    int num = 0;
    curr = 0;

    while(curr <= size)
    {
        while(counting_array[num] > 0)
        {
            array[curr] = num;
            counting_array[num]--;
            curr++;
            if(curr > size)
            {
                break;
            }
        }
        num++;
    }
    printArray(array,size);
}

int main()
{
    int test1[] = {2,6,4,3,2,3,4,6,3,4,3,5,2,6};
    int size1 = 14;
    countingSort(test1,size1);

    int test2[] = {5,6,7,8,5};
    int size2 = 5;
    countingSort(test2,size2);
    
    return 0;
}

