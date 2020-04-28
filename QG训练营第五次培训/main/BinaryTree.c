#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../head/BinaryTree.h" 



int i=0;
/*
typedef struct BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode, *BiTree;   // ��������
*/

/*
typedef struct TrTNode{
	TElemType  data;
	struct TrTNode *lchild,*rchild,*father;	  // ���Һ���,����ָ��
}TrTNode,*TrTree;		//�������� 
*/


Status visit(TElemType e){
	
	printf("%c ",e);
	return SUCCESS;
}



//���������� 


//ǰ��������������� 
Status CreateTrTree(TrTree *child,TrTree *father,char *string){
	
	
	char c=string[i++];
	
	if(c=='#'){
		
		*child=NULL;
		return ERROR;
	}
	
	else{
		
		*child=(TrTree)malloc(sizeof(TrTNode));
		
		(*child)->data=c;
		if(father==NULL){
			(*child)->father=NULL;
		}
		else{
			(*child)->father=*father;
		}
		
		CreateTrTree(&((*child)->lchild),&(*child),string);
		CreateTrTree(&((*child)->rchild),&(*child),string);
		
		return SUCCESS;
	}
	
}
Status PreOrderTrible(TrTree *T,Status (*visit)(TElemType e)){
	
	if(*T==NULL){
		return ERROR;
	}
	
	TrTree S,temp;
	S=*T;
	
	while(S!=NULL){
		
		visit(S->data);
		
		if(S->lchild!=NULL){
			S=S->lchild;
		}
		else if(S->rchild!=NULL){
			
			S=S->rchild;
		}
		else{
			
			temp=S;				//ѭ�����ڻ��ݵ���һ����������Ϊ�յĽ�㣬��S==NULLʱ������ѭ����������ʱ�ѻ��ݵ����ڵ㣬�������� 
			S=S->father;		//����S==NULL���ѻ��ݵ��������ĸ��ڵ㣻��S->lchild!=temp ��Ϊ�����������ݣ���S->rchild==NULL���򲻶ϻ��ݸ��׽ڵ㣬ֱ�����ҽڵ㲻Ϊ�� 
			while(S!=NULL && ( S->lchild!=temp ||  S->rchild==NULL ) ){
				temp=S;
				S=S->father;
			}
			if(S!=NULL){
				S=S->rchild;
			}
			
	
				
		}		
	}

	return SUCCESS;
	
}


Status InOrderTrible(TrTree *T,Status (*visit)(TElemType e)){
	
	
	if(*T==NULL){
		return ERROR;
	}
	
	TrTree S,temp;
	S=*T;
	
	while(S!=NULL){
		
		
		if(S->lchild!=NULL){
			S=S->lchild;
		}
		
		else{
			
			visit(S->data);
			if(S->rchild!=NULL){
				S=S->rchild;
				
			}
			else{
				
				
				temp=S;
				S=S->father;
				while(S!=NULL && ( S->lchild!=temp || S->rchild==NULL )){
					
					if(S->lchild==temp){
						visit(S->data);		//����˫�׽�� 
					}
					temp=S;
					S=S->father;
					
				}
				if(S!=NULL){
					visit(S->data);		//����˫�׽��
					S=S->rchild;
				}
				
			}
			
		}
		
		
	}
	
	return SUCCESS;
	
}



Status PostOrderTrible(TrTree *T,Status (*visit)(TElemType e)){
	
	
	if(*T==NULL){
		return ERROR;
	}
	
	
	
	TrTree S,temp;
	S=*T;
	
	while(S!=NULL){
		
		
		if(S->lchild!=NULL){
			S=S->lchild;
		}
		else{
			
			if(S->rchild!=NULL){
				S=S->rchild;
			}
			else{
				
				visit(S->data);
				
				temp=S;
				S=S->father;
				while(S!=NULL && (S->lchild!=temp || S->rchild==NULL)){
					
					//��˫�׽���������� �� �Ѵ����������ݵ�˫�׽�㣬�����˫�׽�� 
					if(S->lchild!=temp || S->rchild==NULL){
						visit(S->data);
					}
					temp=S;
					S=S->father; 
					
				}
				if(S!=NULL){
					S=S->rchild;
				}
			}				
		}	
			
			
	}
	
	return SUCCESS;
	
}


Status DestroyTrible(TrTree *T){
	
	if((*T)!=NULL){
		
		DestroyTrible(&((*T)->lchild));
		DestroyTrible(&((*T)->rchild));
		free(*T);
		return SUCCESS;
		
	}
	else{
		return ERROR;
	}
	
	
	
	
}



























void initQueue(queue **q){
	
	*q=(queue *)malloc(sizeof(queue));
	
	if(*q==NULL){
		printf("���г�ʼ��ʧ��\n");
	}
	else{
		(*q)->length =0;
		(*q)->front =NULL;
		(*q)->rear =NULL;		
	}

}


//��� 
void push(queue **q,BiTree Bnode){
	
	
	if((*q)->length==0){
		
		qnode *node=(qnode*)malloc(sizeof(qnode));
		node->Bnode=Bnode;
		node->next=NULL;
		(*q)->front=(*q)->rear=node;
		(*q)->length++;	
		
	}
	else{
		
		qnode *node=(qnode*)malloc(sizeof(qnode));
		node->Bnode=Bnode;
		node->next=NULL;
		(*q)->rear->next=node;
		(*q)->rear=node; 
		(*q)->length++;	
		
	}

	
	
}



//���ض�������� 
BiTNode *pop(queue **q){
	
	if((*q)->length!=0){
		
		BiTNode *re_val=(*q)->front->Bnode;
		qnode *n=(*q)->front;
		(*q)->front=(*q)->front->next; 
		free(n);
		(*q)->length--;
		return re_val;
		
	}
	else{
		printf("����Ϊ�գ��޷�����\n"); 
	}
	

}




bool empty(queue **q){
	
	if((*q)->length>0){
		
		return false;
	}
	else{
		return true;
	}
	
}





void destroy(queue **q){
	
	while((*q)->front){
		
		qnode *temp=(*q)->front->next;
		free((*q)->front);
		(*q)->front=temp; 
		
	}
	
	
}






/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree *T){
	
	*T =(BiTree )malloc(sizeof(BiTNode));
	
	if(*T==NULL){
		printf("�ն���������ʧ��\n");
		return ERROR;
	}
	
	else{
		(*T)->lchild =NULL;
		(*T)->rchild =NULL;
		(*T)->data ='\0';
		return SUCCESS;
	}
	
}



/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree *T){			//��������ݻٶ�����
	
	if((*T)!=NULL){
		 
		DestroyBiTree(&((*T)->lchild));
		DestroyBiTree(&((*T)->rchild));
		free(*T);
		
		return SUCCESS;
	}	 
	else{
		return ERROR;
	}
	
	
}


/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
Status CreateBiTree(BiTree *T, char* definition){
	
	char c=definition[i++];
	
	if(c=='#'){				//��#��ʾ�ýڵ�Ϊ�� 
		*T=NULL;
		return ERROR;
	}
	
	else{

		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=c;
		CreateBiTree(&((*T)->lchild),definition);
		
		CreateBiTree(&((*T)->rchild),definition);
		
		return SUCCESS;			
		
	}

	

}


/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
	
	if(*T!=NULL){
		
		visit((*T)->data);
		PreOrderTraverse(&((*T)->lchild),visit);
		PreOrderTraverse(&((*T)->rchild),visit);
		
		return SUCCESS;
	}
	
	else{
		return ERROR;
	}
	
}


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
	
	if((*T)!=NULL){
		
		InOrderTraverse(&((*T)->lchild),visit);
		visit((*T)->data);
		InOrderTraverse(&((*T)->rchild),visit);
		
		return SUCCESS;
	}
	
	else{
		return ERROR;
	}
	
	
}


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
	
	if((*T)!=NULL){
		
		PostOrderTraverse(&((*T)->lchild),visit);
		PostOrderTraverse(&((*T)->rchild),visit);
		visit((*T)->data);
		
		return SUCCESS;
	}
	
	else{
		
		return ERROR;
	}
	
}


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
	
	queue *q;
	initQueue(&q);	//�������� 
	push(&q,*T);
	BiTNode *t=q->front->Bnode;		//���ڱ������н���ָ�� 
	qnode *temp=q->front;			//���ڴ�����е���һ���ڵ� 
	
	
	//�����Ӳ��� 
	while(t->lchild!=NULL || t->rchild!=NULL){		//�������е����Һ��ӽڵ������һ������ʱ��������� 
		
		if(t->lchild!=NULL){
			push(&q,t->lchild);
		}
		if(t->rchild!=NULL){
			push(&q,t->rchild);
		}
		
		
		temp=temp->next; 
		t=temp->Bnode;				//��ָ��ָ����еĺ�һ�� 
		
	}
	
	//�ڵ���Ӳ���(������������)
	
	while(!empty(&q)){
		
		BiTNode *out_node=pop(&q);
		visit(out_node->data);
	
	} 

	//destroy(q);
	
	
	
}




void build_prefix_tree(BiTree *T){
	
	char s;		//����ǰ׺���ʽ 
	scanf("%c",&s);
	
	if(s>='0'&&s<='9'){		//��Ϊ�����������Һ��ӽڵ� 
		
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
		(*T)->data=s;
		
	}
	else{				//��Ϊ������򿪱����Һ��ӽڵ�
		
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=s;
		
		build_prefix_tree(&((*T)->lchild));
		build_prefix_tree(&((*T)->rchild));
		
	}
	
	
}




/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree *T){
	
	
	char s=(*T)->data;
	
	if(s>='0'&&s<='9'){		//��Ϊ������ֱ�ӷ��� 
		
		int char_2_int=(int)s-48;
		return char_2_int;
		
		
	}
	else{				//��Ϊ���������������������ֵ������ø����������������������Ĳ��� 
		
		int l_result=Value(&((*T)->lchild));
		int r_result=Value(&((*T)->rchild));
		
		if(s=='+'){
			return l_result+r_result;
		}
		else if(s=='-'){
			return l_result-r_result;
		}
		else if(s=='*'){
			return l_result*r_result;
		}
		else if(s=='/'){
			return l_result/r_result;
		}
		
	
	}

}
