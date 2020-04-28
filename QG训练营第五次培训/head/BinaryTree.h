#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED



typedef char TElemType;     // 假设二叉树结点的元素类型为字符


typedef struct BiTNode {
    TElemType      data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode, *BiTree;   // 二叉链表


typedef struct TrTNode{
	TElemType  data;
	struct TrTNode *lchild,*rchild,*father;	  // 左、右孩子,父亲指针
}TrTNode,*TrTree;		//三叉链表 


typedef enum Status{
	SUCCESS = 1,
	ERROR = 0,
}Status;

//实现层次遍历的队列 
typedef struct QueueNode{
	BiTree Bnode; 
	struct QueueNode *next;
	
}qnode;

typedef struct Queue{
	qnode *front;
	qnode *rear;
	int length;		//队列长度 
	
}queue;

//队列的操作

void initQueue(queue **q);
void push(queue **q,BiTree Bnode);
BiTNode *pop(queue **q);
bool empty(queue **q);
void destroy(queue **q);

extern int i;		//用于记录字符串数组位置 


//访问打印节点函数 
Status visit(TElemType e);


//三叉树操作 
Status CreateTrTree(TrTree *T,TrTree *father,char *string);
Status PreOrderTrible(TrTree *T,Status (*visit)(TElemType e));
Status InOrderTrible(TrTree *T,Status (*visit)(TElemType e));
Status PostOrderTrible(TrTree *T,Status (*visit)(TElemType e));
Status DestroyTrible(TrTree *T);
  







/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
Status InitBiTree(BiTree *T);


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : 摧毁二叉树T
 *  @param       : 二叉树根结点T
 */
Status DestroyBiTree(BiTree *T);


/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : 构造二叉树T
 *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
 */
Status CreateBiTree(BiTree *T, char* definition);


/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 先序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PreOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 中序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status InOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : 后序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PostOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 层序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status LevelOrderTraverse(BiTree *T, Status (*visit)(TElemType e));


/**
 *  @name        : int Value(BiTree T);
 *  @description : 对构造出的前缀表达式二叉树求值
 *  @param       : 二叉树根结点T
 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
 *                 可根据需要自行增加操作.
 */
int Value(BiTree *T);

void build_prefix_tree(BiTree *T);

#endif // BINARYTREE_H_INCLUDED

