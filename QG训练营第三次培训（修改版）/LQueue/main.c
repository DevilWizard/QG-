#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
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

int main(){
	
	char e;
	LQueue q;
	InitLQueue(&q);
	for(int i=0;i<10;i++){
		EnLQueue(&q, &datatype[i]);
	}
	GetHeadLQueue(&q, &e);
	LengthLQueue(&q);
	
	printf("The queue is as follows:\n");
	TraverseLQueue(&q,LPrint);
	printf("\n");
	
	IsEmptyLQueue(&q);
	
	for(int i=0;i<10;i++){
		DeLQueue(&q);
	}
	
	LengthLQueue(&q);
	ClearLQueue(&q);
	DestoryLQueue(&q);
	printf("Please press any key to exit:\n");
	getch();
	return 0;
}
