#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include"Calculator2.h"

int main(){
	int length,testl;
	char * infix_exp,* suffix_exp,* test; 
	test=(char *)malloc(100*sizeof(char *));
	infix_exp=(char *)malloc(100*sizeof(char *));	//set the default maxsize of the infix_expression(��׺���ʽ) as 100
	suffix_exp=(char *)malloc(100*sizeof(char *));	//set the default maxsize of the suffix_expression(��׺���ʽ) as 100
	printf("��淶������׺���ʽ(��'='��Ϊ��β,�����в��ɺ��пո񼰷Ƿ��ַ�):\n");
	scanf("%s",test);			//read the user's input of the infix_expression(��׺���ʽ)
	testl=strlen(test);
	while(isillegal(test,testl)){
		printf("���������к��зǷ��ַ������������룺\n");
		scanf("%s",test);
		testl=strlen(test);
	}
	infix_exp=test;
	infix_to_suffix(infix_exp,suffix_exp);
	printf("ת����ĺ�׺���ʽΪ: ");
	length=printf("%s",suffix_exp);
	printf("\n");
	suffix_to_result(suffix_exp,length);
	return 0;
	
}
