#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"

int main(){
	SqStack s;
	int sizes,length,e[4],data;
	printf("Please set the size of the stack:\n");
	scanf("%d",&sizes);
	initStack(&s,sizes);
	for(int i=0;i<sizes;i++){	//set the stack as [1,2,3,4] 
		pushStack(&s,i+1);
	}
	stackLength(&s,&length);
	isEmptyStack(&s);
	pushStack(&s,5);
	for(int i=0;i<4;i++){
		getTopStack(&s,&data);
		popStack(&s,&e[i]);
		printf("\n"); 
	} 
	printf("The data poped out from stack are as follows:\n");
	for(int i=0;i<4;i++){
		printf("%d ",e[i]);
	}
	printf("\n");  
	clearStack(&s);
	destroyStack(&s);	
	return 0;
}
