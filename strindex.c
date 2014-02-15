/* 字符串的对比是指在初始字符串中对比某特定字符串是否存在，如果存在则此特定字符串为初始字符串的子字符串
 */

#include <stdio.h>

int strlen(char *str)
{
	int i;
	for(i = 0;str[i] != '\0';i++);  // 用循环计算长度
	
	return i;
}

/* 在字符串中查找子字符串 */

int strindex(char *str1,char *str2)
{
	int end,i,j;
	end = strlen(str1) - strlen(str2);   //计算结束位置
	if(end > 0)     //子字符串小于字符串
	{
		for(i = 0; i <= end; i++)
		{
			for(j = i;str1[j] == str2[j-i];j++)
				if(str2[j-i+1] == '\0')      //子字符串字结束
					return i+1;              //找到了子字符串
		}

	}

	return -1;
}

int main()
{
	char string[100];          //字符串数组声明
	char substring[100];       //子字符串数组声明
	int result;        //查找结果
	printf("请输入字符串 ==>");
	gets(string);
	printf("请输入要找寻的子字符串 ==>");
	gets(substring);     //读取子字符串
	result = strindex(string,substring);   //查找子字符串
	
	if(result > 0)
		printf("子字符串 %s 位置在 %d \n",substring,result);
	else
		printf("没有找到子字符串 %s\n",substring);
	return 0;
}

