#include<stdlib.h>
#include<stdio.h>
#include"AQueue.h"

/*循环队列结构
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;        //队列长度
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
*/
int type;
int datatype[MAXQUEUE]={1,2,3,4,5,6,7,8,9,10};
/*char type;
  char datatype[MAXQUEUE]="abcdefghij";*/
int type_size=sizeof(type);


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	
	if(Q==NULL){
		printf("Initiation failed!\n");
	}
	else{
		Q->front=-1;
		Q->rear=-1;
		Q->length=0;
		printf("Initiation SUCCEDD!\n");
	}
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	Q->length=-1;
	Q->front=-1;
	Q->rear=-1;
	printf("Queue Successfully destroyed!\n");
	
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	
	if(Q->length==MAXQUEUE){
		//printf("The queue is full!\n");
		return TRUE;
	}
	else{
		//printf("The queue is NOT full!\n");
		return FALSE;
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	
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
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	
	if(!IsEmptyAQueue(Q)){	//非空时才能查看 
		if(sizeof(Q->data[Q->front])==sizeof(char)){
			*(char*)e=Q->data[Q->front];
			printf("The head of the queue is :%c\n",Q->data[Q->front]);
		}
		else if(sizeof(Q->data[Q->front])==sizeof(int)){
			*(int*)e=Q->data[Q->front];
			printf("The head of the queue is :%d\n",Q->data[Q->front]);
		}
		
		return TRUE;
	}
	else{
		printf("The queue is empty!\n");
		return FALSE;
	}
	
	
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	
	printf("The length of the queue is %d\n",Q->length);
	return Q->length;

}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
	
	if(IsEmptyAQueue(Q)){	//若队空 
		Q->front++;
		Q->rear++;
		Q->length++;
		if(type_size==sizeof(char)){	//泛型实现 
			Q->data[Q->rear]=*((char*)data);
		}
		else if(type_size==sizeof(int)){
			Q->data[Q->rear]=*((int*)data);
		}
		//printf("insert successfully!\n");
		return TRUE;
	}
	
	if(IsFullAQueue(Q)){	//若队满 
		printf("The queue is full,can't insert!\n");
		return FALSE;
	}
	else if(!IsFullAQueue(Q)){
		if(Q->rear==MAXQUEUE-1){
			Q->rear=-1;		//若rear指队尾则初始化，实现循环队列 
		}
		if(type_size==sizeof(char)){
			Q->data[++(Q->rear)]=*((char*)data);
		}
		if(type_size==sizeof(int)){
			Q->data[++(Q->rear)]=*((int*)data);
		}
		Q->length++;
		//printf("insert successfully!\n");
		return TRUE;
	}
	
}	



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	
	if(!IsEmptyAQueue(Q)){
		Q->front++;
		Q->length--;
		if(Q->front==MAXQUEUE){
			Q->front=-1;
		}
		return TRUE;
		
	}
	else{
		printf("The queue is empty!\n");
		return FALSE;
	}
	
}		



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q==NULL){
		printf("Can't clear a queue doesn't exsist!\n");
	}
	else{
		Q->front=0;
		Q->rear=0;
		Q->length=0;
		printf("Queue cleared!\n");
	}
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(!IsEmptyAQueue(Q)){
		for(int i=0;i<=Q->rear;i++){
			foo(&Q->data[i]);
		}
		return TRUE;
	}
	else{
		printf("The queue is empty!\n");
		return FALSE;
	}

}	



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
	if(type_size==sizeof(int)){
		printf("%d ",*(int*)q);
	}
	else if(type_size==sizeof(char)){
		printf("%c ",*(char*)q);
	}
	
}
