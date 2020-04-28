#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED



typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�


typedef struct BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode, *BiTree;   // ��������


typedef struct TrTNode{
	TElemType  data;
	struct TrTNode *lchild,*rchild,*father;	  // ���Һ���,����ָ��
}TrTNode,*TrTree;		//�������� 


typedef enum Status{
	SUCCESS = 1,
	ERROR = 0,
}Status;

//ʵ�ֲ�α����Ķ��� 
typedef struct QueueNode{
	BiTree Bnode; 
	struct QueueNode *next;
	
}qnode;

typedef struct Queue{
	qnode *front;
	qnode *rear;
	int length;		//���г��� 
	
}queue;

//���еĲ���

void initQueue(queue **q);
void push(queue **q,BiTree Bnode);
BiTNode *pop(queue **q);
bool empty(queue **q);
void destroy(queue **q);

extern int i;		//���ڼ�¼�ַ�������λ�� 


//���ʴ�ӡ�ڵ㺯�� 
Status visit(TElemType e);


//���������� 
Status CreateTrTree(TrTree *T,TrTree *father,char *string);
Status PreOrderTrible(TrTree *T,Status (*visit)(TElemType e));
Status InOrderTrible(TrTree *T,Status (*visit)(TElemType e));
Status PostOrderTrible(TrTree *T,Status (*visit)(TElemType e));
Status DestroyTrible(TrTree *T);
  







/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree *T);


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree *T);


/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
Status CreateBiTree(BiTree *T, char* definition);


/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree *T);

void build_prefix_tree(BiTree *T);

#endif // BINARYTREE_H_INCLUDED

