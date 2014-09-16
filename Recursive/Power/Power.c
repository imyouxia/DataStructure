/*
 * 求幂
 */

// 求x的n次幂，递归
double power(double x,int n)
{
    if(n == 1)
        return x;
    if((n % 2) == 0)
        return power(x*x,n/2);
    else
        return x*power(x,n-1);

}

// 循环
double power(double x,int n)
{
    double res;
    res = 1.0;
    while(n > 0)
    {
        if((n % 2) == 0)
        {
            x = x * x;
            n = n / 2;
        }
        else
        {
            n = n - 1;
            res = x * res;
        }
    
    }
    return res;
}

// 循环2
double power(double x,int n)
{
    double ans = 1;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            ans *= x;
        }

        x = x * x;
        n /= 2;

    }
    return ans;
}

