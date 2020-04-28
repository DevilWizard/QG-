#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../head/BinaryTree.h" 



int i=0;
/*
typedef struct BiTNode {
    TElemType      data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode, *BiTree;   // 二叉链表
*/

/*
typedef struct TrTNode{
	TElemType  data;
	struct TrTNode *lchild,*rchild,*father;	  // 左、右孩子,父亲指针
}TrTNode,*TrTree;		//三叉链表 
*/


Status visit(TElemType e){
	
	printf("%c ",e);
	return SUCCESS;
}



//三叉树操作 


//前序遍历创建三叉树 
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
			
			temp=S;				//循环用于回溯到第一个右子树不为空的结点，当S==NULL时，整个循环结束，此时已回溯到根节点，遍历结束 
			S=S->father;		//若则S==NULL明已回溯到整棵树的根节点；若S->lchild!=temp 则为从右子树回溯；若S->rchild==NULL，则不断回溯父亲节点，直至其右节点不为空 
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
						visit(S->data);		//访问双亲结点 
					}
					temp=S;
					S=S->father;
					
				}
				if(S!=NULL){
					visit(S->data);		//访问双亲结点
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
					
					//若双亲结点无右子树 或 已从右子树回溯到双亲结点，则访问双亲结点 
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
		printf("队列初始化失败\n");
	}
	else{
		(*q)->length =0;
		(*q)->front =NULL;
		(*q)->rear =NULL;		
	}

}


//入队 
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



//返回二叉树结点 
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
		printf("队列为空，无法出队\n"); 
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
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
Status InitBiTree(BiTree *T){
	
	*T =(BiTree )malloc(sizeof(BiTNode));
	
	if(*T==NULL){
		printf("空二叉树构造失败\n");
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
 *  @description : 摧毁二叉树T
 *  @param       : 二叉树根结点T
 */
Status DestroyBiTree(BiTree *T){			//后序遍历摧毁二叉树
	
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
 *  @description : 构造二叉树T
 *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
 */
Status CreateBiTree(BiTree *T, char* definition){
	
	char c=definition[i++];
	
	if(c=='#'){				//以#标示该节点为空 
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
 *  @description : 先序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 中序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 后序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 层序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status LevelOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
	
	queue *q;
	initQueue(&q);	//创建队列 
	push(&q,*T);
	BiTNode *t=q->front->Bnode;		//用于遍历队列结点的指针 
	qnode *temp=q->front;			//用于储存队列的下一个节点 
	
	
	//结点入队操作 
	while(t->lchild!=NULL || t->rchild!=NULL){		//当队列中的左右孩子节点的其中一个存在时，将其入队 
		
		if(t->lchild!=NULL){
			push(&q,t->lchild);
		}
		if(t->rchild!=NULL){
			push(&q,t->rchild);
		}
		
		
		temp=temp->next; 
		t=temp->Bnode;				//将指针指向队列的后一个 
		
	}
	
	//节点出队操作(即遍历结果输出)
	
	while(!empty(&q)){
		
		BiTNode *out_node=pop(&q);
		visit(out_node->data);
	
	} 

	//destroy(q);
	
	
	
}




void build_prefix_tree(BiTree *T){
	
	char s;		//储存前缀表达式 
	scanf("%c",&s);
	
	if(s>='0'&&s<='9'){		//若为数字则无左右孩子节点 
		
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
		(*T)->data=s;
		
	}
	else{				//若为运算符则开辟左右孩子节点
		
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=s;
		
		build_prefix_tree(&((*T)->lchild));
		build_prefix_tree(&((*T)->rchild));
		
	}
	
	
}




/**
 *  @name        : int Value(BiTree T);
 *  @description : 对构造出的前缀表达式二叉树求值
 *  @param       : 二叉树根结点T
 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
 *                 可根据需要自行增加操作.
 */
int Value(BiTree *T){
	
	
	char s=(*T)->data;
	
	if(s>='0'&&s<='9'){		//若为数字则直接返回 
		
		int char_2_int=(int)s-48;
		return char_2_int;
		
		
	}
	else{				//若为操作符则计算左右子树的值，最后用该运算符进行左右子树结果的操作 
		
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
