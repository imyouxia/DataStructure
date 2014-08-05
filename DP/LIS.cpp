/*
 * 第i个元素之前的最长递增子序列的长度要么是1（单独成一个序列），
 * 要么就是第 i-1 个元素之前的最长递增子序列加1
 * LIS[i] = max{1,LIS[k]+1} ,其中对于任意的k <= i-1,arr[i] > arr[k]，
 * 这样arr[i]才能在arr[k]的基础上构成一个新的递增子序列。
 *
 * 1 -1 2 -3 4 -5 6 -7 
 * 1  1 2  1 3  1 4  1
 */ 

#include <cstdio>
using namespace std;

/*
 * 最长递增子序列LIS
 * 设数组长度不超过 30
 * DP
 */

int dp[31];  //dp[i] 记录到[0,i]数组的LIS
int lis = 0;     //LIS长度

int LIS(int *arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if(dp[i] > lis)
                {
                    lis = dp[i];
                }
            }
        }
        printf("LCS :%d\n",dp[i]);
    
    }
    return lis;
}

int main()
{
    int arr[] = {1,-1,2,-3,4,-5,6,-7};
    printf("%d\n",LIS(arr,sizeof(arr)/sizeof(int)));
    return 0;
}






