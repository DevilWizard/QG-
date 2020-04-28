#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../head/BinaryTree.h" 


int main(){
	
	
	
/*
	BiTree T;
	char *s="abd##e##cf##g##";
	printf("二叉树结构如下：\n");
	printf("       a \n");
	printf("      / \\ \n");
	printf("     b   c \n");
	printf("    / \\ / \\ \n");
	printf("   d  e f  g \n");
	InitBiTree(&T);
	CreateBiTree(&T,s);
	
	printf("先序遍历结果如下:\n");			//该部分为二叉树递归遍历部分 
	PreOrderTraverse(&T, visit);
	
	printf("\n中序遍历结果如下:\n");
	InOrderTraverse(&T, visit);
	
	printf("\n后序遍历结果如下:\n");
	PostOrderTraverse(&T, visit);
	
	
	printf("\n层次遍历结果如下:\n");
	LevelOrderTraverse(&T, visit);
	
	DestroyBiTree(&T);
	
*/



//下面为计算器部分 

/* 
	printf("请规范输入前缀表达式(0~9的整数,不允许输入除 +-/* 外的非法字符[如空格]):\n");
	build_prefix_tree(&T);
	printf("转换为中缀表达式如下:\n");
	InOrderTraverse(&T, visit);		//中序遍历得中缀表达式 
	printf("\n计算结果为: %d",Value(&T));
	
*/	
	


//下面为三叉树实现非递归遍历部分

/*
	TrTree T;
	char *s="abd##e##cf##g##";
	printf("三叉树结构如下：\n");
	printf("       a \n");
	printf("      / \\ \n");
	printf("     b   c \n");
	printf("    / \\ / \\ \n");
	printf("   d  e f  g \n");
	
	
	CreateTrTree(&T,NULL,s);
	printf("三叉树的非递归遍历如下:\n");
	
	printf("\n前序遍历:\n");
	PreOrderTrible(&T,visit);
	
	printf("\n中序遍历:\n");
	InOrderTrible(&T,visit);
	
	printf("\n后序遍历:\n");
	PostOrderTrible(&T,visit);
	
	DestroyTrible(&T);
*/ 
	
	
	printf("\n\n按下任意键结束：\n");
	getch();
	
	return 0;
	
}
