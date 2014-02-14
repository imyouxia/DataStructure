/* 子字符串是指在初始字符串内截取一个或一个以上连续的字符来组合成新的字符串，而这个新的字符串就称为初始字符串的子字符串
 */

#include <stdio.h>

char *substr(char *str,int pos,int len)
{
	static char str1[100];   //子字符串声明
	int i,j,end;
	
	pos--;     //计算字符串的开始
	end = pos + len - 1;     //计算结束位置
	for(i = pos,j = 0; i <= end; i++,j++ )
		str1[j] = str[i];    //拷贝字符串内容

	str1[len] =  '\0';     //设置字符串结束

	return str1;
}

int main()
{
	char string[100];      //字符串数组声明
	char *substring;       //结束字符串指针声明

	int pos;              //起始位置
	int len;              //子字符串长度

	printf("请输入字符串 ==>");
	gets(string);   //读取字符串
	printf("请输入起始位置 ==>");
	scanf("%d",&pos);   //读取位置
	printf("请输入子字符串长度 ==>");
	scanf("%d",&len);    //读取长度
	substring = substr(string,pos,len);   //提取子字符串
	printf("子字符串 %s \n",substring);

	return 0;
		

}
