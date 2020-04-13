#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"


char type;					
char datatype[10]="abcdefghij";				//全局变量定义 
int type_size=sizeof(type); 

/*
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;
*/

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data				
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	
	Q->length=0;
	Q->front=Q->rear=NULL;
	printf("The queue is cleared!\n");
	
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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
