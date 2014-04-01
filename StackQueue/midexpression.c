/* 利用栈，计算中序四则表达式的值。
 * 输入的表达式内的每一个字符代表一个操作数或运算符。
 * 而且中间不可用空格。换句话说，操作数的范围只有数字0到9。
 */

#include <stdio.h>
#include <stdlib.h>

struct stack_node   //栈的结构声明
{
	int data;   //栈数据
	struct stack_node *next;   //指向下一结点
};

typedef struct stack_node stack_list;   //链表新类型
typedef stack_list *link;   //链表指针新类型

link operator = NULL;   //运算符栈指针
link operand = NULL;   //操作数栈指针

/* 栈数据的存入 */
link push(link stack,int value)
{
	link new_node;   //新结点指针
	/* 分配结点内存 */
	new_node = (link)malloc(sizeof(stack_list));
	if(!new_node)
	{
		printf("内存分配失败！\n");
		return NULL;
	}
	new_node->data = value;   //创建结点内容
	new_node->next = stack;   //新结点指向原开始
	stack = new_node;   //新结点成为栈开始
	return stack;
}

/* 栈数据的取出 */
link pop(link stack,int *value)
{
	link top;   //指向栈顶端
	if(stack != NULL)
	{
		top = stack;    //指向栈顶端
		stack = stack->next;   //栈指针指向下结点
		*value = top->data;   //取出数据
		free(top);   //释放结点内存
		return stack;   //返回栈指针
	}
	else
		*value = -1;
}

/* 检查栈是否是空的 */
int empty(link stack)
{
	if(stack == NULL)
		return 1;
	else
		return 0;
}

/* 是否是运算符 */
int isoperator(char op)
{
	switch(op)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;  //是运算符
		default:
			return 0;  //不是运算符
	}
}

/* 运算符的优先级 */
int priority(char op)
{
	switch(op)
	{
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

/* 计算二元表达式的值 */
int get_value(int op,int operand1,int operand2)
{
	switch((char)op)
	{
		case '*':
			return (operand2 * operand1);
		case '/':
			return (operand2 / operand1);
		case '+':
			return (operand2 + operand1);
		case '-':
			return (operand2 - operand1);
	}
	return 0;
}

/* 输入中序表达式后，计算其值 */
int main()
{
	char exp[100];   //表达式字符串变量
	int op = 0;      //运算符变量
	int operand1 = 0;  //前操作数变量
	int operand2 = 0;   //后操作数变量
	int result = 0;     //计算结果变量
	int pos = 0;  //目前表达式位置

	printf("请输入中序表达式 ==>");
	gets(exp);   //读取表达式

	/* 分析表达式字符串循环 */
	while(exp[pos] != '\0' && exp[pos] != '\n')
	{
		if(isoperator(exp[pos]))   //是不是运算符
		{
			if(!empty(operator))   //检查运算符栈
			{
				while(priority(exp[pos]) <= 
						priority(operator->data) && 
						!empty(operator))
				{
					//从栈取出一运算符和两操作数
					operator = pop(operator,&op);
					operand = pop(operand,&operand1);
					operand = pop(operand,&operand2);
					//计算取出运算符和元的值后，存入栈
					operand = push(operand,get_value(op,operand1,operand2));
				}
			
			}
			//是运算符，存入运算符栈
			operator = push(operator,exp[pos]);

		}
		else
			//是操作数，存入操作数栈
			operand = push(operand,exp[pos]-48);
		pos++;  //下一字符串位置
	}
	//取出运算符栈的全部内容
	while(!empty(operator))
	{
		//从栈取出一运算符和两操作符
		operator = pop(operator,&op);
		operand = pop(operand,&operand1);
		operand = pop(operand,&operand2);

		//计算取出运算符和操作数的值后，存入栈
		operand = push(operand,get_value(op,operand1,operand2));
	}
	operand = pop(operand,&result);  //取出结果
	printf("表达式[%s]的结果是%d \n",exp,result);
	return 0;

}






