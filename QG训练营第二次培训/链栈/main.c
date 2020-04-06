#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

int main(){
	LinkStack s;
	int length,e;
	int data[4];
	initLStack(&s);
	for(int i=1;i<5;i++){	//set the stack as[1,2,3,4]
		pushLStack(&s,i);	
	}
	LStackLength(&s,&length);
	isEmptyLStack(&s);
	for(int i=0;i<4;i++){
		getTopLStack(&s,&e);
		popLStack(&s,&data[i]);
		printf("\n");
	}
	popLStack(&s,&data[0]);
	printf("The data poped out from the stack are as follows:\n");
	for(int i=0;i<4;i++){
		printf("%d ",data[i]);
	}
	printf("\n");
	clearLStack(&s);
	destroyLStack(&s);
}
