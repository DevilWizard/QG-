#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"


/*typedef struct SqStack 
{
	ElemType *elem;
	int top;
	int size;
} SqStack;               */

//基于数组的顺序栈
Status initStack(SqStack *s,int sizes){				//初始化栈

	if(s==NULL){
		printf("Fail in initiating stack!\n");
		return ERROR;
	}
	s->size=sizes;
	s->top=-1;
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));
	printf("Initiation SUCCEDD!\n");
	return SUCCESS;

}			
Status isEmptyStack(SqStack *s){		//判断栈是否为空

	if(s->size==0){
		printf("The stack has been destroyed!\n");
		return ERROR;
	}
	if(s->top==-1){
		printf("The stack is empty!\n");
		return SUCCESS;
	}
	else{
		printf("The stack is NOT empty!\n");
		return ERROR;
	}

}
Status getTopStack(SqStack *s,ElemType *e){		//得到栈顶元素

	if(s->top==-1){		//if the stack is empty
		printf("The stack is empty!\n");
		return ERROR;
	}
	if((s->elem)==NULL){
		printf("The stack has been destroyed!NO TOP data!\n");
		return ERROR;
	}
	else{
		int val=s->elem[s->top];
		*e=val;
		printf("The top element of the stack is %d\n",val);
		return SUCCESS;
	}
} 
Status clearStack(SqStack *s){				//清空栈

	if((s->elem)==NULL){
		printf("The stack has been destroyed!You can't clear it!\n");
		return ERROR;
	}
	else{
		s->top=-1;
		printf("The stack is cleared!\n");
		return SUCCESS;
	}
	

}
Status destroyStack(SqStack *s){	//销毁栈

	free(s->elem);
	s->size=0;
	s->elem=NULL;
	printf("The stack is destroyed!\n");
	return SUCCESS;

};
Status stackLength(SqStack *s,int *length){		//检测栈长度

	if((s->elem)==NULL){	//judge whether the stack exsists or destroyed
		printf("The stack doesn't exsist!NO length!\n");
		return ERROR;
	}
	else{
		int val=(s->top)+1;
		*length=val;
		printf("The length of the stack is %d\n",(s->top)+1);
		return SUCCESS;
	}
}
Status pushStack(SqStack *s,ElemType data){		//入栈

	if((s->top)+1==s->size){
		printf("The stack is FULL,no more room for you to push data in!\n");
		return ERROR;
	}
	if((s->size)==0){
		printf("The stack has been destroyed,you can't push data into it!\n");
		return ERROR;
	}
	else{
		s->elem[(s->top)+1]=data;
		s->top++;
		printf("The data %d successfully pushed into the stack!\n",data);
		return SUCCESS;	
	}
}
Status popStack(SqStack *s,ElemType *data){		//出栈

	if((s->elem)==NULL){
		printf("The stack has been destroyed,nothing to be poped up!\n");
		return ERROR;
	}
	if(s->top==-1){
		printf("The stack is empty,nothing to be poped up!\n");
		return ERROR;
	}
	else{
		int val=(s->elem)[(s->top)];
		s->top--;
		*data=val;
		printf("The top data %d of the stack is successfully poped up!\n",val);
		return SUCCESS;
	}
}
