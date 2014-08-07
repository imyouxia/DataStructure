/*
 * 基数排序：
 * LSD法实现
 * 最低位优先法首先依据最低位关键码Kd对所有对象进行一趟排序，
 * 再依据次低位关键码Kd-1对上一趟排序的结果再排序，
 * 依次重复，直到依据关键码K1最后一趟排序完成，就可以得到一个有序的序列。
 * 使用这种排序方法对每一个关键码进行排序时，不需要再分组，而是整个对象组。
 *
 */

#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 10000

int getdigit(int x,int d)
{
    int a[] = {1,1,10,100};   //最大三位数，所以这里只要百位就满足了
    return (x/a[d]) % 10;
}

void PrintArr(int arr[],int n)
{
    int i;
    for(i = 0; i < n; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

}

void lsdradix_sort(int arr[],int begin,int end,int d)
{
    const int radix = 10;
    int count[radix],i,j;

    int *bucket = (int *)malloc((end-begin+1) * sizeof(int));
    
    //按照分配标准依次进行排序过程
    for(int k = 1; k <= d; ++k)
    {
        for(i = 0; i < radix; i++)
        {
            count[i] = 0;
        }
        
        // 统计各个桶中所盛数据个数
        for(i = begin; i <= end; i++)
        {
            count[getdigit(arr[i],k)]++;
        }

        // count[i]表示第i个桶的右边界索引
        for(i = 1; i < radix; i++)
        {
            count[i] = count[i] + count[i - 1];
        }

        //把数据依次装入桶
        for(i = end; i >= begin; --i)  //这里要从右从左扫描，保证排序稳定性
        {
            j = getdigit(arr[i],k);   //求出关键码的第k位的数字，例如：576的第三位是5
            bucket[count[j] - 1] = arr[i];   //放入对应的桶中，count[j] - 1是第j个桶的右边界索引
            --count[j];   //对应桶的装入数据索引减1
        }

        // 此时count[i]为第i个桶的左边界
        // 从各个桶中收集数据
        for(i = begin,j = 0; i <= end; ++i,++j)
        {
            arr[j] = bucket[j];
        }
    }
    free(bucket);
}

int main()
{
    int br[10] = {20,80,90,589,998,965,852,123,456,789};
    printf("原数据如下： \n");
    PrintArr(br,10);
    lsdradix_sort(br,0,9,3);
    printf("排序后数据如下： \n");
    PrintArr(br,10);
    return 0;
}
