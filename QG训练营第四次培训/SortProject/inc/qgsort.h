
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define level1 10000
#define level2 50000
#define level3 200000


//���ŷǵݹ�ջ
typedef struct stack_node{
	
	int begin;	//������߽� 
	int end;	//�����ұ߽� 
	struct stack_node *next;
	
}stacknode;

typedef struct stack_starter{
	
	stacknode *head;
	int count;
	
}stack;

//ջ���� 
void init(stack *s);
void push(stack *s,int begin,int end);
void pop(stack *s,int *begin,int *end);
bool empty(stack *s);
void destroy(stack *s);






/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
void Find_K(int *a,int size,int k);


//������������������ʱ���� 
void test(int level); 

//���Դ���С�����ڶ�������µ���ʱ 
void test2(void);


//��ӡ��������� 
void print(int *a,int size);

//����ָ������ ��int���ͣ�
void create(void);

//������������� 
void sort(int *a,int size,int max);

//��ȡ���ɵ�ָ�����ݲ������������ 
void read_sort(void);


#endif // QUEUE_H_INCLUDED
