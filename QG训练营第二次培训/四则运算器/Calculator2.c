#include<stdio.h>
#include<stdlib.h>
#include"Calculator2.h"


/*typedef  struct StackNode
{
	void* data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;*/

Status s_initLStack(LinkStack *s){	//初始化栈
	
	s->count=0;
	s->s_top=(s_LinkStackPtr)malloc(sizeof(s_LinkStackPtr));
	s->s_top->next=NULL;
	if(s->s_top==NULL){
		printf("Initiation failed!\n");
		return ERROR;
	}
	//printf("The link stack is successfully initiated!\n");
	return SUCCESS;

}

Status i_initLStack(LinkStack *s){	//初始化栈
	
	s->count=0;
	s->i_top=(i_LinkStackPtr)malloc(sizeof(i_LinkStackPtr));
	s->i_top->next=NULL;
	if(s->i_top==NULL){
		printf("Initiation failed!\n");
		return ERROR;
	}
	//printf("The link stack is successfully initiated!\n");
	return SUCCESS;

}

Status s_isEmptyLStack(LinkStack *s){		//判断栈是否为空

	if(s->s_top==NULL){
		//printf("The stack doesn't exsist!\n");
		return ERROR;
	}
	if(s->count==0){
		//printf("The stack is empty!\n");
		return SUCCESS;
	}
	else{
		//printf("The stack is NOT empty!\n");
		return ERROR;
	}
}

Status i_isEmptyLStack(LinkStack *s){		//判断栈是否为空

	if(s->i_top==NULL){
		//printf("The stack doesn't exsist!\n");
		return ERROR;
	}
	if(s->count==0){
		//printf("The stack is empty!\n");
		return SUCCESS;
	}
	else{
		//printf("The stack is NOT empty!\n");
		return ERROR;
	}
}

char s_getTopLStack(LinkStack *s){		//得到栈顶元素
	
	if(s->s_top==NULL){
		//printf("The stack doesn't exsist!NO TOP element!\n");
		//return ERROR;
	}
	if(s->count==0){
		//printf("The stack is empty!NO TOP element!\n");
		//return ERROR;
	}
	else{
		//memcpy(top,s->top->data,sizeof(s->top->data));
		//printf("The top element of the stack is '%c'\n",val);
		char val=s->s_top->data;
		return val;
	}
}
int i_getTopLStack(LinkStack *s){		//得到栈顶元素
	
	if(s->i_top==NULL){
		//printf("The stack doesn't exsist!NO TOP element!\n");
		//return ERROR;
	}
	if(s->count==0){
		//printf("The stack is empty!NO TOP element!\n");
		//return ERROR;
	}
	else{
		//memcpy(top,s->top->data,sizeof(s->top->data));
		//printf("The top element of the stack is '%c'\n",val);
		int val=s->i_top->data;
		return val;
	}
}
Status s_clearLStack(LinkStack *s){	//清空栈

	if(s->s_top==NULL){
		printf("The stack has been destroyed!You can't clear it!\n");
		return ERROR;
	}
	else{
		while(s->s_top->next!=NULL){
			s_LinkStackPtr p;
			p=s->s_top;
			s->s_top=s->s_top->next;
			free(p);
		}
		//printf("The stack is successfully cleared!\n");
		return SUCCESS;
	}
}
Status i_clearLStack(LinkStack *s){	//清空栈

	if(s->i_top==NULL){
		printf("The stack has been destroyed!You can't clear it!\n");
		return ERROR;
	}
	else{
		while(s->i_top->next!=NULL){
			i_LinkStackPtr p;
			p=s->i_top;
			s->i_top=s->i_top->next;
			free(p);
		}
		//printf("The stack is successfully cleared!\n");
		return SUCCESS;
	}
}
Status s_destroyLStack(LinkStack *s){		//销毁栈

	if(s->s_top==NULL){
		printf("The stack has been destroyed!You can't destroy it again!\n");
		return ERROR;
	}
	else{
		while(s->s_top->next!=NULL){
			s_LinkStackPtr p;
			p=s->s_top;
			s->s_top=s->s_top->next;
			free(p);
		}
		free(s->s_top);
		s->s_top=NULL;
		//printf("The stack is successfully destroyed!\n");
		return SUCCESS;
	}
}
Status i_destroyLStack(LinkStack *s){		//销毁栈

	if(s->i_top==NULL){
		printf("The stack has been destroyed!You can't destroy it again!\n");
		return ERROR;
	}
	else{
		while(s->i_top->next!=NULL){
			i_LinkStackPtr p;
			p=s->i_top;
			s->i_top=s->i_top->next;
			free(p);
		}
		free(s->i_top);
		s->i_top=NULL;
		//printf("The stack is successfully destroyed!\n");
		return SUCCESS;
	}
}

Status s_pushLStack(LinkStack *s,char* data){	//入栈

	if(s->s_top==NULL){
		printf("The stack has been destroyed!You can't push data into it!\n");
		return ERROR;
	}
	else{
		s_StackNode *node;
		node=(s_LinkStackPtr)malloc(sizeof(s_LinkStackPtr));
		//memcpy(node->data,data,sizeof(data));
		node->data=*data;
		node->next=s->s_top;
		s->s_top=node;
		s->count++;
		//printf("The data '%c' is successfully pushed into the stack!\n",data);
		return SUCCESS;
	}
}
Status i_pushLStack(LinkStack *s,int* data){	//入栈

	if(s->i_top==NULL){
		printf("The stack has been destroyed!You can't push data into it!\n");
		return ERROR;
	}
	else{
		i_StackNode *node;
		node=(i_LinkStackPtr)malloc(sizeof(i_LinkStackPtr));
		//memcpy(node->data,data,sizeof(data));
		node->data=*data;
		node->next=s->i_top;
		s->i_top=node;
		s->count++;
		//printf("The data '%c' is successfully pushed into the stack!\n",data);
		return SUCCESS;
	}
}
char s_popLStack(LinkStack *s){	//出栈

	if(s->s_top==NULL){
		printf("The stack doesn't exsist!NOTHING to be poped out!\n");
		//return ERROR;
	}
	if(s->count==0){
		printf("The stack is empty!NOTHING to be poped out!\n");
		//return ERROR;
	}
	else{
		char val=s->s_top->data;
		s->s_top=s->s_top->next;
		s->count--;
		//printf("The top element '%c' of the stack is successfully poped out!\n",val);
		return val;
	}
}
int i_popLStack(LinkStack *s){	//出栈

	if(s->i_top==NULL){
		printf("The stack doesn't exsist!NOTHING to be poped out!\n");
		//return ERROR;
	}
	if(s->count==0){
		printf("The stack is empty!NOTHING to be poped out!\n");
		//return ERROR;
	}
	else{
		int val=s->i_top->data;
		s->i_top=s->i_top->next;
		s->count--;
		//printf("The top element '%c' of the stack is successfully poped out!\n",val);
		return val;
	}
}


//中缀转后缀
void infix_to_suffix(char *infix,char *suffix){
	
	LinkStack s;
	s_initLStack(&s);
	int p1=0,p2=0;
	while(infix[p1]!='='){		//以等号作为中缀表达式的尾 
		char c=*(infix+p1);
		if(c>='0' && c<='9'){		//若为0~9的运算数 
			suffix[p2++]=c;
		}
		else if(c=='('){					//若为左括号 
			s_pushLStack(&s,&c);
		}
		else if(c==')'){					//若为右括号 
			while(!s_isEmptyLStack(&s) && s_getTopLStack(&s)!='('){
				suffix[p2++]=s_popLStack(&s);                       			 
			}
			if(!s_isEmptyLStack(&s) && s_getTopLStack(&s)=='('){
				s_popLStack(&s);
			}
		}	
		else if(c=='+' || c=='-' ||c=='*' ||c=='/'){	//若为运算符 
			if(c=='+' ||c=='-'){
				if(s_getTopLStack(&s)=='('){
					s_pushLStack(&s,&c);
				}
				else{
					while(!s_isEmptyLStack(&s)){
						suffix[p2++]=s_popLStack(&s);
					}
					s_pushLStack(&s,&c);
				}
			}
			else if(c=='*' ||c=='/'){
				if(!s_isEmptyLStack(&s) && ((s_getTopLStack(&s)=='+' || s_getTopLStack(&s)=='-')||s_getTopLStack(&s)=='(')){
					s_pushLStack(&s,&c);
				}
				else{
					while(!s_isEmptyLStack(&s) ){
						if(s_getTopLStack(&s)=='+' || s_getTopLStack(&s)=='-'||s_getTopLStack(&s)=='('){
							s_pushLStack(&s,&c);
							break;
						}
						else if(s_getTopLStack(&s)!='('){
							suffix[p2++]=s_popLStack(&s);
						}
					}	
					
				}
			}
		}
		p1++;
	}
	while(!s_isEmptyLStack(&s)){
		suffix[p2++]=s_popLStack(&s);	
	}
	suffix[p2]='\0';
	s_clearLStack(&s);
	s_destroyLStack(&s);
}



void suffix_to_result(char *suffix,int length){
	int p=0;
	LinkStack s;
	i_initLStack(&s);
	while(p<length){
		char c=suffix[p];
		if(c>='0' && c<='9'){
			int d=(int)c-48;
			i_pushLStack(&s,&d);
		}
		else{
			int L,R,result;
			R=i_popLStack(&s);
			L=i_popLStack(&s);
			if(c=='+'){
				result=L+R;
				i_pushLStack(&s,&result);
			}
			else if(c=='-'){
				result=L-R;
				i_pushLStack(&s,&result);
			}
			else if(c=='*'){
				result=L*R;
				i_pushLStack(&s,&result);
			}
			else if(c=='/'){
				result=L/R;
				i_pushLStack(&s,&result);
			}
		}
		
		p++;
	}
	int final; 
	final=i_popLStack(&s);
	printf("表达式的运算结果为: %d\n",final);

	i_clearLStack(&s);
	i_destroyLStack(&s);
} 

Status isillegal(char *test,int testl){
	for(int i=0;i<testl;i++){
		char c=*(test+i);
		if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='='||(c>='0' && c<='9')){
			;
		}
		else{
			return SUCCESS;
		}
	}
	return ERROR;
	
}
