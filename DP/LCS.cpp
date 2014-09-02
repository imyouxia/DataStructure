/*
 * 最长公共子序列就是寻找两个给定序列的子序列，
 * 该子序列在两个序列中以相同的顺序出现，但是不一定是连续的。
 */

/* 
 *
 * dp[i][j] = 0，如果 i = 0 或 j = 0;
 * dp[i][j] = dp[i-1][j-1] + 1 ，如果X[i-1] = Y[j-1]
 * dp[i][j] = max{dp[i-1][j],dp[i][j-1]} 如果X[i-1] != Y[j-1]
 *
 */

#include <iostream>

int dp[21][21];  // 存储LCS长度
char X[21];
char Y[21];
int i,j,k;

int main()
{
    cin.getline(X,20);
    cin.getline(Y,20);

    int xlen = strlen(X);
    int ylen = strlen(Y);

    /* 都已初始化为0 */
    for(i = 1; i <= xlen; ++i)
    {
        for(j = 1; j <= ylen; ++j)
        {
            if(X[i-1] == Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else if(dp[i][j-1] > dp[i-1][j])
            {
                dp[i][j] = dp[i][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            } 
        }
    }
    printf("len of LCS is:%d\n",dp[xlen][ylen]);

}
