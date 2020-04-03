#include<stdio.h>
#include<stdlib.h> 
#include "duLinkedList.h"

int main(){
	DuLinkedList L,head;
	ElemType m;
	InitList_DuL(&L);
	head=L;
	while(1){		//set the double linked list as 1->2->3->4 manually
		printf("Please input data:\n");
		scanf("%d",&m);
		if(m!=-1){		
			DuLinkedList node=(DuLinkedList)malloc(sizeof(DuLinkedList));
			head->next=node;
			node->prior=head;
			node->next=NULL;
			node->data=m;
			head=node;
		}
		else{		//when inputting -1,stop creating list
			break;
		}
	}
	printf("double linked list successfully built as follows:\n");
	head=L->next;
	while(head){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
	DuLNode *q;
	q=(DuLNode *)malloc(sizeof(DuLNode));	//create the node q with value 100
	q->data=100;
	q->next=q->prior=NULL;
	InsertBeforeList_DuL(L->next,q);	//insert the node q before the node whose valude is 1 
	printf("after inserting,the link is as follows :");
	head=L->next;
	while(head){
		printf("%d ",head->data);
		head=head->next;
	}
	return 0;
}
