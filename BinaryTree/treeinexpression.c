/* 树：处理表达式 */

#include <stdio.h>
#include <stdlib.h>

struct tree   //树的结构声明
{
	char data;   //结点数据
	struct tree *left;   //指向左子树的指针
	struct tree *right;  //指向右子树的指针
};
typedef struct tree treenode;    //树的结构新类型
typedef treenode *btree;     //声明树结点指针类型

int getvalue(int op,int operand1,int operand2);

/* 创建表达式二叉树 */
btree createbtree(int *data,int pos)
{
	btree newnode;    //新结点指针
	if(data[pos] == 0 || pos > 7)  //终止条件
	{
		return NULL;
	}
	else
	{
		//创建新结点内存
		newnode = (btree)malloc(sizeof(treenode));
		newnode->data = data[pos];  //创建结点内容
		newnode->left = createbtree(data,2*pos);
		newnode->right = createbtree(data,2*pos + 1);
		return newnode;
	}
}

/* 表达式二叉树中序输出 */
void inorder(btree ptr)
{
	if(ptr != NULL)  //终止条件
	{
		inorder(ptr->left);  //左子树
		printf("%c",ptr->data);   //输出结点内容
		inorder(ptr->right);  //右子树
	}
}

/* 表达式二叉树前序输出 */
void preorder(btree ptr)
{
	if(ptr != NULL)   //终止条件
	{
		printf("%c",ptr->data);   //输出结点内容
		preorder(ptr->left);      //左子树
		preorder(ptr->right);     //右子树
	}
}

/* 表达式二叉树后序输出 */
void postorder(btree ptr)
{
	if(ptr != NULL)  //终止条件
	{
		postorder(ptr->left);   //左子树
		postorder(ptr->right);  //右子树
		printf("%c",ptr->data);  //输出结点内容
	}

}

/* 表达式二叉树后序计值 */
int cal(btree ptr)
{
	int operand1 = 0;   //前操作数变量
	int operand2 = 0;   //后操作数变量
	if(ptr->left == NULL && ptr->right == NULL)
		return ptr->data-48;
	else
	{
		operand1 = cal(ptr->left);    //左子树
		operand2 = cal(ptr->right);   //右子树
		return getvalue(ptr->data,operand1,operand2);
	}
}

/* 计算二叉表达式的值 */
int getvalue(int op,int operand1,int operand2)
{
	switch((char) op)
	{
		case '*':
			return (operand1 * operand2);
		case '/':
			return (operand1 / operand2);
		case '+':
			return (operand1 + operand2);
		case '-':
			return (operand1 - operand2);
	}
}

/* 主程序：创建表达式二叉树后计算结果 */
int main()
{
	btree root = NULL;   //表达式二叉树指针
	int result;   //结果变量

	/* 表达式二叉树结点数据 */
	int data[8] = {' ','+','*','*','5','6','4','3'};
	root = createbtree(data,1);   //创建表达式二叉树
	printf("中序表达式：");
	inorder(root);    //中序输出二叉树
	printf("\n前序表达式：");
	preorder(root);   //前序输出二叉树
	printf("\n后序表达式：");
	postorder(root);  //后序输出二叉树
	result = cal(root);   //计算结果
	printf("\n表达式结果是：%d\n",result);   //输出结果
	return 0;
}

