/* 字符串删除的处理和字符串插入正好相反，其目的是从特定位置开始删除某长度的字符串
 */

#include <stdio.h>

char *strdel(char *str,int pos,int len)
{
	int i;
	pos--;      //计算字符串的开始

	//从pos开始删除长度len的字符串
	for(i = pos + len; str[i] != '\0'; i++)
		str[i-len] = str[i];
	str[i-len] = '\0';  //新的字符串结束
	return str;
}

int main()
{
	char string[200];     //字符串数组声明
	int pos;              //删除位置
	int len;              //删除长度

	printf("请输入初始字符串 ==>");
	gets(string);
	printf("请输入删除位置 ==>");
	scanf("%d",&pos);     //读取位置
	printf("请输入删除长度 ==>");
	scanf("%d",&len);     //读取长度
	strdel(string,pos,len);   //删除字符串
	printf("删除后的字符串是 %s \n",string);

	return 0;
}
