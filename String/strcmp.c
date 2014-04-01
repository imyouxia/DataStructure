/* 字符串的比较是比较两个字符串的内容，如果两个字符串完全相同的话，就返回0
 */


#include <stdio.h>
int strcmp(char *str1,char *str2)
{
	int i;
	for(i = 0; str1[i] == str2[i]; i++)
		//字符串1等于字符串2
		if(str1[i] == '\0' && str2[i] == '\0')
			return 0;

	if(str1[i] < str2[i])   //字符串1小于字符串2
		return -1;
	return 1;               //字符串1大于字符串2
}

int main()
{
	char string1[100];      //字符串数组1声明
	char string2[100];      //字符串数组2声明

	int result;             //比较结果

	printf("请输入字符串(1) ==>");
	gets(string1);          //读取字符串1
	printf("请输入字符串(2) ==>");
	gets(string2);          //读取字符串2

	result = strcmp(string1,string2);  //字符串比较
	switch(result)
	{
		case 0:
			printf("字符串(1)等于字符串(2)\n");
			break;
		case 1:
			printf("字符串(1)大于字符串(2)\n");
			break;
		case -1:
			printf("字符串(1)小于字符串(2)\n");
			break;
	}
	
	return 0;

}
