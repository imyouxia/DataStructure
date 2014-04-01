/* 字符串的连接是指将两个或两个以上的字符串连接成一个字符串
 */

#include <stdio.h>

char *strcat(char *str1,char *str2)
{
	int i,j;
	for(i = 0; str1[i] != '\0'; i++);  //找字符串str1结束
	for(j = 0; str2[j] != '\0'; j++)   //拷贝字符串内容
		str1[i+j] = str2[j];

	str1[i+j] = '\0';    //设置字符串结束
	
	return str1;	
}

int main()
{
	char string1[200]; //字符串数组1声明
	char string2[100]; //字符串数组2声明

	printf("请输入字符串(1) ==>");
	gets(string1);   //读取字符串1
	printf("请输入字符串(2) ==>");
	gets(string2);   //读取字符串2
	strcat(string1,string2); //字符串连接
	printf("结合后的字符串是 %s \n",string1);
	
	return 0;
}
