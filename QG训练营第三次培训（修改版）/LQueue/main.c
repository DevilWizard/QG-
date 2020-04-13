#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
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
