/* 字符串的替换是将字符串中的末一子字符串代换成另一个字符串的内容。
 * 而这种字符串处理方法并不会改变字符串的长度
 */

#include <stdio.h>

char *strrep(char *str1,char *str2,int pos)
{
	int i,j;
	pos--;   //计算字符串的开始
    i = 0;
	
	for(j = pos; str1[j] != '\0'; j++)  //遍历字符串str1
		if(str2[i] != '\0')
		{
			str1[j] = str2[i];      //替换str2至str1
			i++;
		}
		else
			break;	
	return str1;
}

int main()
{
	char string1[200];   //字符串数组1声明 
    char string2[100];   //字符串数组2声明

	int pos;
	printf("请输入初始字符串 ==>");
	gets(string1);  //读取字符串1
	printf("请输入替换字符串 ==>");
	gets(string2);  //读取字符串2
	printf("请输入替换位置 ==>");
	scanf("%d",&pos);   //读取位置
	strrep(string1,string2,pos); //替换字符串
	printf("替换后的字符串是 %s \n",string1);

	return 0;
}
