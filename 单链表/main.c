#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

int main(){
	LinkedList L;
	ElemType m;
	InitList(&L);
	LinkedList head,node;
	head=L;
	while(1){		//set the link as 1->2->3->4 manually
		printf("Please input data:\n");
		scanf("%d",&m);
		if(m!=-1){			
			node=(LinkedList )malloc(sizeof(LNode));
			node->data=m;
			node->next=NULL;
			head->next=node;
			head=node;
		}
		else{		//stop building list when inputting -1
			break;
		}
	}
	LinkedList rear;
	rear=head;
	printf("Linked list successfully built as follows:\n");
	head=L->next;
	while(head){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
	ReverseList(&L);	//reverse the whole list
	printf("the list after reversing: \n");
	while(rear){
		printf("%d ",rear->data);
		rear=rear->next;
		if(rear==L){
			break;
		}
	}
	return 0;
}
