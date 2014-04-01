/* 字符串的插入处理是将要插入的字符串插入初始字符串内的某位置，所以字符串的长度将会成为两个字符串的总和
 */

#include <stdio.h>

int strlen(char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++); //用循环计算长度
	
	return i;
}

/* 
 * 插入字符串
 */

char *strins(char *str1,char *str2,int pos)
{
	int s_len;   //字符串str1的长度
	int d_len;   //字符串str1的长度
	int i,j;

	pos--;       //计算字符串的开始
	s_len = strlen(str1);  //计算字符串长度
	d_len = strlen(str2);

	for(i = s_len + 1; i >= pos ; i--)  //空出str1的空间
		str1[i+d_len] = str1[i];
	
	//用循环填入str2到字符串str1
	for( j = pos; str2[j-pos] != '\0'; j++)
		str1[j] = str2[j-pos];
	return str1;
}

int main()
{
	char string1[200];  //字符串数组1声明
	char string2[100];  //字符串数组2声明
	int pos;            //插入位置

	printf("请输入初始字符串 ==>");
	gets(string1);      //读取字符串1
	printf("请输入插入字符串 ==>");
	gets(string2);      //读取字符串2
	printf("请输入插入位置 ==>");
	scanf("%d",&pos);   //读取位置
	strins(string1,string2,pos);    //插入字符串
	printf("插入后的字符串是 %s \n",string1);

	return 0;
}
