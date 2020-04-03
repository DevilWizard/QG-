#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L=(LinkedList )malloc(sizeof(LNode));
	if(*L==NULL){
		printf("Fail in initiating Linked list!\n");
		exit(1);
	}
	(*L)->next=NULL;
	printf("Linked list initiated successfully!\n");
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {

	LinkedList b;  
	b=*L;
	while(b){
		b=(*L)->next;
		free(*L);
		L=&b;		
	}
	printf("Linked list successfully destroyed!\n");

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {

	LNode *store;
	store=p->next;
	p->next=q;
	q->next=store;
	printf("Node successfully inserted!\n");
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	
	LNode *store;
	store=p->next->next;
	e=&(p->next->data);
	free(p->next);
	p->next=store;
	printf("Node deleted!\n");
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	
	LinkedList p;
	p=L->next;
	while(p){
		visit(p->data);
		p=p->next;
	}

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {

	LinkedList head=L;
	while(1){
		if(head->data==e){
			printf("Node found!\n");
			return SUCCESS;
		}
		head=head->next;
	}
	return ERROR;
	
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {

	LinkedList s,f,temp;    //s is slow pointer,f is fast pointer
	s=f=*L;
	while(f){
		if(s==*L){
			f=f->next;
			s->next=NULL;
		}
		temp=f->next;
		f->next=s;
		s=f;
		f=temp;
	}
	printf("Linked list successfully reversed!\n");
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

	LinkedList s,f;
	s=f=L;
	while(f){
		f=f->next->next;
		if(f==s){	//is loop list 
			printf("The linked list is looped!\n");
			return SUCCESS;
		}
		s=s->next;
	}
	printf("The linked list is not looped!\n");//not the loop list
	return SUCCESS;	
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

	
	
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

	LinkedList s,f;    //s pointer is two steps slower than f pointer
	s=f=*L;
	if((*L)->next==NULL ){	  //specially,when the linked list has only one node
		return *L;
	}
	if((*L)->next->next==NULL){	//specially,when the linked list has only two nodes
		return (*L)->next;
	}
	while(f){
		f=f->next->next;
		s=s->next;
		if(f->next==NULL){
			printf("The midNode found!\n");
			return s;
		}	
	}
}

