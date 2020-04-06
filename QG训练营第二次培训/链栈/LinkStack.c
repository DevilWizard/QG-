#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"


/*typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;*/

Status initLStack(LinkStack *s){	//初始化栈
	
	s->count=0;
	s->top=(LinkStackPtr)malloc(sizeof(LinkStackPtr));
	s->top->next=NULL;
	if(s->top==NULL){
		printf("Initiation failed!\n");
		return ERROR;
	}
	printf("The link stack is successfully initiated!\n");
	return SUCCESS;


}
Status isEmptyLStack(LinkStack *s){		//判断栈是否为空

	if(s->top==NULL){
		printf("The stack doesn't exsist!\n");
		return ERROR;
	}
	if(s->count==0){
		printf("The stack is empty!\n");
		return SUCCESS;
	}
	else{
		printf("The stack is NOT empty!\n");
		return ERROR;
	}
}
Status getTopLStack(LinkStack *s,ElemType *e){		//得到栈顶元素
	
	if(s->top==NULL){
		printf("The stack doesn't exsist!NO TOP element!\n");
		return ERROR;
	}
	if(s->count==0){
		printf("The stack is empty!NO TOP element!\n");
		return ERROR;
	}
	else{
		int val=s->top->data;
		*e=val;
		printf("The top element of the stack is %d\n",val);
		return SUCCESS;
	}
}
Status clearLStack(LinkStack *s){	//清空栈

	if(s->top==NULL){
		printf("The stack has been destroyed!You can't clear it!\n");
		return ERROR;
	}
	else{
		while(s->top->next!=NULL){
			LinkStackPtr p;
			p=s->top;
			s->top=s->top->next;
			free(p);
		}
		printf("The stack is successfully cleared!\n");
		return SUCCESS;
	}
}
Status destroyLStack(LinkStack *s){		//销毁栈

	if(s->top==NULL){
		printf("The stack has been destroyed!You can't destroy it again!\n");
		return ERROR;
	}
	else{
		while(s->top->next!=NULL){
			LinkStackPtr p;
			p=s->top;
			s->top=s->top->next;
			free(p);
		}
		free(s->top);
		s->top=NULL;
		printf("The stack is successfully destroyed!\n");
		return SUCCESS;
	}
}
Status LStackLength(LinkStack *s,int *length){		//检测栈长度

	if(s->top==NULL){
		printf("The stack has been destroyed!NO length!\n");
		return ERROR;
	}
	else{
		int val=s->count;
		*length=val;
		printf("The length of the stack is %d\n",val);
		return SUCCESS;
	}
}
Status pushLStack(LinkStack *s,ElemType data){	//入栈

	if(s->top==NULL){
		printf("The stack has been destroyed!You can't push data into it!\n");
		return ERROR;
	}
	else{
		StackNode *node;
		node=(LinkStackPtr)malloc(sizeof(LinkStackPtr));
		node->data=data;
		node->next=s->top;
		s->top=node;
		s->count++;
		printf("The data %d is successfully pushed into the stack!\n",data);
		return SUCCESS;
	}
}
Status popLStack(LinkStack *s,ElemType *data){	//出栈

	if(s->top==NULL){
		printf("The stack doesn't exsist!NOTHING to be poped out!\n");
		return ERROR;
	}
	if(s->count==0){
		printf("The stack is empty!NOTHING to be poped out!\n");
		return ERROR;
	}
	else{
		int val=s->top->data;
		*data=val;
		s->top=s->top->next;
		s->count--;
		printf("The top element %d of the stack is successfully poped out!\n",val);
		return SUCCESS;
	}
}
