#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 获取部分匹配字符数组
void get_next(int next[],char source[],int n); 

/*
   返回源字符串s_string中pos开始与t_string匹配的第一个字符串首字母下标
   无匹配返回0
*/
int Index_KMP(char *s_string,char *t_string,int pos);

int main()
{
    char *source_str = "BBC ABCDAB ABCDABCDABDE";
    char *t_str = "ABCDAB"; //模式串
    printf("%d\n",Index_KMP(source_str,t_str,8));

    return 0;
}

void get_next(int next[],char source[],int n)
{
    int i = 0;
    next[0] = 0;
    for(i = 1; i < n; i++)
    {
        if(source[i] == source[next[i-1]])
            next[i] = next[i-1] + 1;
        else
            next[i] = 0;    
    }
}

int Index_KMP(char *s_string,char *t_string,int pos)
{
    int i = pos; //指向s_string的起始下标
    int j = 0;   //指向t_string的起始下标
    int t_len = strlen(t_string);
    int s_len = strlen(s_string);
    int *t_next = (int*)malloc(sizeof(int) * t_len);
    int m;
    
    get_next(t_next,t_string,t_len); //获取t_string的部分匹配字符数组
    for(m = 0; m < t_len; m++)
        printf("%d ",t_next[m]);
    printf("\n");

    while((i < s_len) && (j < t_len))
    {
        if(s_string[i] == t_string[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j == 0)
            {
                i++; //源字符串下标前移动
            }
            else
            {
                m = j - t_next[j - 1]; //需回溯的位数
                j = j - m; //设置下一次的起始坐标
            }
        }
    }
    free(t_next);
    if(j == t_len)
        return i - t_len;
    else
        return 0;
}

