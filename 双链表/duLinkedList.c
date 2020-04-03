#include<stdio.h>
#include<stdlib.h> 
#include "duLinkedList.h"
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {

	*L=(DuLinkedList )malloc(sizeof(DuLinkedList));
	if(*L==NULL){
		printf("Initiation Fail!\n");
		exit(1);
	}
	(*L)->prior=(*L)->next=NULL;
	printf("Initiation SUCCEDD!\n"); 
	return SUCCESS;


}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	
	DuLinkedList p;
	p=*L;
	while(p){
		p=(*L)->next;
		free(*L);
		L=&p;
	}
	printf("Destroyed successfully!\n");
	

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {

	DuLNode *store;
	store=p->prior;
	p->prior=q;
	store->next=q;
	q->prior=store;
	q->next=p;
	printf("insert successfully!\n");
	return SUCCESS;
	
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	
	DuLNode *store;
	store=p->next;
	p->next=q;
	store->prior=q;
	q->prior=p;
	q->next=store;
	printf("insert successfully!\n");
	return SUCCESS;
	
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {

	DuLNode *store;
	store=p->next->next;
	e=&(p->next->data);
	free(p->next);
	p->next=store;
	store->prior=p;
	printf("delete successfully!\n");
	return SUCCESS;
	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
	DuLinkedList head;
	head=L;
	while(head){		//travel in sequence
		visit(head->data);
		if(head->next!=NULL){
			head=head->next;
		}
		
	}
	while(head){		//travel reversely
		visit(head->data);
		if(head->prior!=NULL){
			head=head->prior;
		}
	}
	printf("SUCCESS!\n");

}
