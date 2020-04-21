
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define level1 10000
#define level2 50000
#define level3 200000


//快排非递归栈
typedef struct stack_node{
	
	int begin;	//区间左边界 
	int end;	//区间右边界 
	struct stack_node *next;
	
}stacknode;

typedef struct stack_starter{
	
	stacknode *head;
	int count;
	
}stack;

//栈操作 
void init(stack *s);
void push(stack *s,int begin,int end);
void pop(stack *s,int *begin,int *end);
bool empty(stack *s);
void destroy(stack *s);






/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
void Find_K(int *a,int size,int k);


//测试三个档次排序用时函数 
void test(int level); 

//测试大量小数组在多次排序下的用时 
void test2(void);


//打印排序后数组 
void print(int *a,int size);

//生成指定数据 （int类型）
void create(void);

//输出单次排序结果 
void sort(int *a,int size,int max);

//读取生成的指定数据并对其进行排序 
void read_sort(void);


#endif // QUEUE_H_INCLUDED
