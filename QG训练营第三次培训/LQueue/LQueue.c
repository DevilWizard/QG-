#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"


char type;					
char datatype[10]="abcdefghij";				//ȫ�ֱ������� 
int type_size=sizeof(type); 

/*
typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
} LQueue;
*/

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	
	Q->front=NULL;
	Q->rear=NULL;
	Q->length=0;
	printf("Initiation succedd!\n");
	
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	
	Q->front=NULL;
	Q->rear=NULL;
	Q->length=-1;
	printf("Queue Destroyed successfully!\n");
	
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	
	if(Q->length==0){
		//printf("The queue is empty!\n");
		return TRUE;
	}
	else{
		//printf("The queue is NOT empty!\n");
		return FALSE;
	}
	
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	
	if(IsEmptyLQueue(Q)){
		printf("The queue is empty!\n");
		return FALSE;
	}
	else{
		if(type_size==sizeof(int)){
			*(int*)e=*((int*)Q->front->data);
			printf("The head of the queue is :%d\n",*((int*)Q->front->data));
		}
		else if(type_size==sizeof(char)){
			*(char*)e=*((char*)Q->front->data);
			printf("The head of the queue is :%c\n",*((char*)Q->front->data));
		}
		return TRUE;
	}
	
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->length==-1){
		printf("The queue doesn't exsist !\n");
		return -1;
	}
	else{
		printf("The length of the queue is %d\n",Q->length);
		return Q->length;
	}
	
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)		
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data				
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q->length==-1){
		printf("The queue doesn't exsist!\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)){
		
		Node *node=(Node*)malloc(sizeof(Node));
		node->data=data;
		node->next=NULL;
		Q->front=Q->rear=node;
		Q->length++;
		return TRUE;
	}
	else{
		
		Node *node=(Node*)malloc(sizeof(Node));
		node->data=data;
		Q->rear->next=node;
		Q->rear=node;
		node->next=NULL;
		Q->length++;
		return TRUE;
	}
	
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	
	if(Q->length==-1){
		printf("The queue doesn't exsist!\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)){
		printf("The queue is empty!\n");
		return FALSE;
	}
	else{
		Q->front=Q->front->next;
		Q->length--;
		return TRUE;
	}
	
	
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	
	Q->length=0;
	Q->front=Q->rear=NULL;
	printf("The queue is cleared!\n");
	
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
void TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	
	Node *head=Q->front;
	while(head){
		foo(head->data);
		head=head->next;
	}
	
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	
	if(type_size==sizeof(int)){
		printf("%d ",*(int*)q );
	}
	else if(type_size==sizeof(char)){
		printf("%c ",*(char*)q);
	}
	
}
