#include<stdlib.h>
#include<stdio.h>
#include"AQueue.h"

int main(){
	
	AQueue q;
	InitAQueue(&q);
	for(int i=0;i<MAXQUEUE;i++){	//��datatype����Ԫ����� 
		EnAQueue(&q, &datatype[i]);
	}
	LengthAQueue(&q);
	printf("The queue is as follows:\n");
	TraverseAQueue(&q,APrint);
	printf("\n");
	for(int i=0;i<MAXQUEUE;i++){
		DeAQueue(&q);
	}
	
	LengthAQueue(&q);
	IsFullAQueue(&q);
	IsEmptyAQueue(&q);
	ClearAQueue(&q);	
	DestoryAQueue(&q);
	printf("Please press any key to exit:\n");
	getch();
	return 0;
}
