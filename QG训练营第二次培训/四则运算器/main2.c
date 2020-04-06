#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include"Calculator2.h"

int main(){
	int length,testl;
	char * infix_exp,* suffix_exp,* test; 
	test=(char *)malloc(100*sizeof(char *));
	infix_exp=(char *)malloc(100*sizeof(char *));	//set the default maxsize of the infix_expression(中缀表达式) as 100
	suffix_exp=(char *)malloc(100*sizeof(char *));	//set the default maxsize of the suffix_expression(后缀表达式) as 100
	printf("请规范输入中缀表达式(以'='作为结尾,输入中不可含有空格及非法字符):\n");
	scanf("%s",test);			//read the user's input of the infix_expression(中缀表达式)
	testl=strlen(test);
	while(isillegal(test,testl)){
		printf("您的输入中含有非法字符，请重新输入：\n");
		scanf("%s",test);
		testl=strlen(test);
	}
	infix_exp=test;
	infix_to_suffix(infix_exp,suffix_exp);
	printf("转化后的后缀表达式为: ");
	length=printf("%s",suffix_exp);
	printf("\n");
	suffix_to_result(suffix_exp,length);
	return 0;
	
}
