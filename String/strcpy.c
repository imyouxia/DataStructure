/* 字符串的拷贝是将字符串的内容备份下来。其目的是保留初始字符串，以免在运行其他字符串处理时，更改到初始字符串的内容
 */

#include <stdio.h>

char *strcpy(char *str1,char *str2)
{
	int i;
	for(i = 0; str2[i] != '\0'; i++)
		str1[i] = str2[i];   //拷贝字符串内容

	str1[i] = '\0';  //设置字符串结束

	return str1;
}

int main()
{
	char string[100];  //初始字符串声明
	char backup[100];  //备份字符串声明

	printf("请输入字符串 ==> ");
	gets(string);   //读取字符串
	strcpy(backup,string);  //拷贝字符串

	printf("初始字符串 %s \n",string);
	printf("备份字符串 %s \n",backup);
	
	return 0;
}
