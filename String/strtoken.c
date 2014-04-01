/* 字符串的分割是将字符串按照某特定字符，通常是空格符，将字符串分割成数个子字符串。
 */

#include <stdio.h>

/* 使用空格符来分割字符串 */

int strtoken(char *str1,char *str2,int pos)
{
	int i,j;       
	i = pos;           //从分割位置开始
	while(str1[i] == ' ')  //跳过之前空格符
		i++;
	if(str1[i] != '\0')      //是不是字符串结束
	{
		j = 0;  //找下一个空格符
		while(str1[i] != '\0' && str1[i] != ' ')
		{
			str2[j] = str1[i];   //拷贝非空格符
			i++;
			j++;
		}
		str2[j] = '\0';     //分割字符串结束字符
		
		return i;          //返回目前位置
	}
	else
		return -1;

}

int main()
{
	char string[100];   //字符串数组声明
	char token_string[20];       //分割字符串声明
	int pos;              //分割位置

	printf("请输入字符串 ==>");
	gets(string);     //读取字符串
	pos = 0;          //设置分割位置初值

	printf("分割结果:\n");
	//分割字符串直到字符串结束
	while((pos = strtoken(string,token_string,pos)) != -1)
		printf("%s\n",token_string);   //输出各分割字符串
	return 0;
}

