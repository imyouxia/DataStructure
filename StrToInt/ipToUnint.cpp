#include <iostream>
#include <string>
using namespace std;

#define IPLEN 16  // 设输入ip地址长度不超过16

enum ERR_STATE
{
    SUCCESS = 0,
    NULL_POINTER,
    OVER_BOUNDARY,
    INVALID_CHAR,
    INVALID_FORM
};

char *ERR_Strings[5] = {
    "Success!",   // SUCCESS
    "Null Pointer!",  // NULL_POINTER
    "Over boundary digits!",  // OVER_BOUNDARY
    "Invalid char!",  // INVALID_CHAR
    "Invalid form!"   // INVALID_FORM
};

/*
 * ip to unint
 * 一般返回一个int作为Error Code,真正的返回值放在参数里
 * para:ip,ip字符串; result,计算结构
 * return：ERROR & SUCCESS
 */

int ipToUnint(char *ip,unsigned int &result)
{
    if(NULL == ip)
    {
        return NULL_POINTER;
    }

    unsigned int digit = 0; // 记录ip地址4个整数
    int dotNum = 0;   // num of dot
    int digitNum = 0;  // num of digit
    char input = 0;

    for(int ipIdx = 0; ; ++ ipIdx)
    {
    
    }
    

}

