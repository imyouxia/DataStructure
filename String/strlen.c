/* 计算字符串的长度 */

#include <stdio.h>


int strlen(char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++); //用循环计算长度
	
	return i;		
}

int main()
{
	char c_string[100];  //字符串数组声明
	int len;             //字符串长度
	printf("请输入字符串 ==>");
	gets(c_string);        //读取字符串
	len = strlen(c_string);	//计算字符串长度
	printf("输入字符串长度是 %d \n",len);
	return 0;
}


