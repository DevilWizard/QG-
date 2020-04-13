#include<stdlib.h>
#include<stdio.h>
#include"AQueue.h"

/*ѭ�����нṹ
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	
	if(!IsEmptyAQueue(Q)){	//�ǿ�ʱ���ܲ鿴 
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	
	printf("The length of the queue is %d\n",Q->length);
	return Q->length;

}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
	
	if(IsEmptyAQueue(Q)){	//���ӿ� 
		Q->front++;
		Q->rear++;
		Q->length++;
		if(type_size==sizeof(char)){	//����ʵ�� 
			Q->data[Q->rear]=*((char*)data);
		}
		else if(type_size==sizeof(int)){
			Q->data[Q->rear]=*((int*)data);
		}
		//printf("insert successfully!\n");
		return TRUE;
	}
	
	if(IsFullAQueue(Q)){	//������ 
		printf("The queue is full,can't insert!\n");
		return FALSE;
	}
	else if(!IsFullAQueue(Q)){
		if(Q->rear==MAXQUEUE-1){
			Q->rear=-1;		//��rearָ��β���ʼ����ʵ��ѭ������ 
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
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
