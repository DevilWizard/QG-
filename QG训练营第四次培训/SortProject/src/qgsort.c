#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h> 
#include"C:/Users/13415/Desktop/QG/第四次培训/SortProject/inc/qgsort.h"



void init(stack *s){

	s->head=(stacknode*)malloc(sizeof(stacknode));
	s->head->next=NULL;
	s->count=0;
	
}
void push(stack *s,int begin,int end){
	
	if(begin<end){		//当区间长度大于1时才进行入队操作 
	
		stacknode *node;
		node=(stacknode*)malloc(sizeof(stacknode));
		node->begin=begin;
		node->end=end;
		node->next=s->head;
		s->head=node;

	s->count++;
	}
	else{
		;	
	}
	
}

void pop(stack *s,int *begin,int *end){
	
	if(!empty(s)){
		
		*begin=s->head->begin;
		*end=s->head->end;
		s->head=s->head->next;
		s->count--;
	}
	else{
		printf("空栈无法弹出元素!\n");
	}
	
	
}

bool empty(stack *s){
	
	if(s->count==0){
		return true;
	}
	else{
		return false;
	}
	
}

void destroy(stack *s){
	
	free(s->head);
	
	
}




/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
	
	for(int i=1 ; i<n ; i++){
		
		int q =i;
		int p =i-1;
		int s =a[i];	//储存抽出的元素 
		while(s<a[p]){
			
			a[q--] =a[p--];
			if(p<0){
				break;
			}
		}
		a[q]=s;	
	}

}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	
	int left =begin;	//左子数组指针 
	int right =mid+1; 	//右子数组指针 
	int t =0;			//temp数组指针 
	while(left<=mid && right<=end){
	
		if(a[left]<a[right]){
			temp[t++]= a[left++];
		}
		else{
			temp[t++]= a[right++];
		}
	}
	while(left<=mid){			//将子数组剩余元素输出 
		temp[t++]=a[left++];
	}
	while(right<=end){
		temp[t++]=a[right++];
	}
	int a_p=begin;	//原数组a指针 
	t=0;			//temp数组指针重新初始化 
	while(a_p<=end){
		a[a_p++]=temp[t++];
	}
	
	
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
	
	if(begin<end){
		
		int mid = (begin+end)/2;
		MergeSort(a,begin,mid,temp);	//左子数组递归 
		MergeSort(a,mid+1,end,temp);	//右子数组递归 
		MergeArray(a,begin,mid,end,temp);	//合并
		 
	}
	
	
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end){
	
	if(end-begin<=20){		//递归快排优化 
		insertSort(a,end-begin+1);
	}
	else{
			if(begin<end){
				int split=Partition(a,begin,end);	//确定枢轴下标作为分割线 
				QuickSort_Recursion(a,begin,split-1);
				QuickSort_Recursion(a,split+1,end);
		
			}
	}

	
	
	
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size){
	
	
	void init(stack *s);
	void push(stack *s,int begin,int end);
	void pop(stack *s,int *begin,int *end);
	bool empty(stack *s);
	void destroy(stack *s);
	
	if(size<=20){				//快排优化 
		insertSort(a,size);
	}
	
	else{
		
		int begin,end;
		begin=0,end=size-1;
		
		stack s;
		init(&s);	//创建栈 
		int split=Partition(a,begin,end);		//确定枢轴下标作为分割线
		push(&s,begin,split-1);
		push(&s,split+1,end);
		while(!empty(&s)){
			pop(&s,&begin,&end);
			split=Partition(a,begin,end);
			push(&s,begin,split-1);
			push(&s,split+1,end);
			
		}		
		
		destroy(&s);
	}
	
	
	
	
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end){
	
	int low=begin;	    //区间最左端 
	int high=end;		//区间最右端
	int temp =a[begin];		//以第一个为枢纽 
	while(low!=high){		//挖坑法 
		
		while(low!=high){
			
			if(a[high]<=temp){
				a[low++]=a[high];
				break;
			}
			high--;
		}
		
		while(low!=high){
			
			if(a[low]>=temp){
				a[high--]=a[low];
				break;
			}
			low++;
		}
	
	}
	a[low]=temp;
	
	return low;			//返回该枢纽在数组最终的下标 
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max){
	
	int *count;		//统计数组 
	count=(int*)malloc((max+1)*sizeof(int));
	for(int i=0 ; i<max+1 ; i++){
		count[i]=0;
	} 
	int temp[size];				//临时数组 
	for(int i=0 ; i<size ; i++){	//收集 
		count[a[i]]++;
		
	}
	
	for(int i=1 ; i<max+1 ; i++){	//统计 
		count[i]+=count[i-1];
	}
	
	for(int i=size-1 ; i>=0 ; i--){	//分配 
		temp[--count[a[i]]]=a[i];
	}
	for(int i=0 ; i<size ; i++){
		a[i]=temp[i];
	}
	
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size){
	
 
	int max=0,max_digit=0;	//原数组最大数及其位数 
	int BASE=10,exp=1;      //基数为10 ,exp用于计算10的n次方 
	for(int i=0 ; i<size ; i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	while(max){
		max/=10;
		max_digit++;
	}
	for(int i=0 ; i<max_digit ; i++){
		

		int bucket[10]={0};  //基数桶
		int temp[size]; //临时数组

		for(int m=0 ; m<size ; m++){
			bucket[(a[m]/exp)%BASE]++;
		}
		
		for(int j=1 ; j<BASE ; j++){
			bucket[j]+=bucket[j-1];
		}
		
		for(int k=size-1 ; k>=0 ; k--){
			temp[--bucket[(a[k]/exp)%BASE]]=a[k];
		}

		
		for(int v=0 ; v<size ; v++){
			a[v]=temp[v];
		}
		
		exp*=BASE;
			
	}
	
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
	
	int p0,p2,p;
	p0=0;
	p2=size-1;
	while(a[p0]==0){
		p0++;
	}
	while(a[p2]==2){
		p2--;
	}
	p=p0;
	while(p<=p2){
			if(a[p]==1){
				p++;
			}
			
			else if(a[p] == 0){
			
				int temp=a[p0];
				a[p0]=a[p];
				a[p]=temp;
			
				if(temp == 2){
				
					int temp2=a[p2];
					a[p2]=temp;
					a[p]=temp2;
				
				}
				p0++;
				
			}	

			else if(a[p] == 2){
			
				int temp=a[p2];
				a[p2]=a[p];
				a[p]=temp;
			
				if(temp == 0){
				
					int temp2=a[p0];
					a[p0]=temp;
					a[p]=temp2;
				
				}
				p2--;
				
			}
		
		
			
	} 
	
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
 
void Find_K(int *a,int size,int k){
	int max=0;
	int p=0;	//记录顺序（按从小到大在该数组中是第几位） 
	int k_min=0,k_max=0;  //第K大，第K小 
	for(int i=0 ; i<size ; i++){	//找数组最大值 
		
		if(max<a[i]){
			max=a[i];
		}
	}
	
	int *store;
	store=(int*)malloc((max+1)*sizeof(int));
	for(int i=0 ; i<max+1 ; i++){
		store[i]=-1;		//以-1作为空判断 
	}
	for(int i=0 ; i<max+1 ; i++){
		store[a[i]]=a[i];
	}
	
	for(int i=0 ; i<=max ; i++){
		if(store[i]!=-1){
			p++;
			if(p==k){
				k_min=store[i];
			}	
		} 
	}
	int true_size=p;	//剔除重复元素后的大小 
	p=0;
	for(int i=0 ; i<=max ; i++){
		if(store[i]!=-1){
			p++;
			if(true_size-p+1==k){
				k_max=store[i];
				break;
			}
		}
	}
	
	
	
	//printf("第 %d 小的数为 %d ，第 %d 大的数为 %d\n",k,k_min,k,k_max);
	
	
}

//测试三个档次排序用时函数
void test(int level){
	
	//均为0-10随机数 
	int *L,*temp,*copy;
	L=(int *)malloc(level*sizeof(int));
	temp=(int *)malloc(level*sizeof(int));
	copy=(int *)malloc(level*sizeof(int));
	int size,begin,end,max;
	size=level,begin=0,end=level-1,max=10;
	L[0]=10;	//保证最大值为10 
	for(int i=0 ; i<level ; i++){
		if(i!=0){
			L[i]=rand()%11;
		}
		
	}

	for(int i=0 ; i<level ; i++){				//将L数组复制到copy数组中 
		copy[i]=L[i];		
	}
		
	clock_t start =clock();
	insertSort(copy,size);
	clock_t diff = clock() - start;
	printf("插入排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=L[i];		
	}
	
	start =clock();
	MergeSort(copy,begin,end,temp);
	diff = clock() - start;
	printf("归并排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=L[i];		
	}	
	
	start =clock();
	QuickSort_Recursion(copy,begin,end);
	diff = clock() - start;
	printf("快速排序（递归版）用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=L[i];		
	}
	
	start =clock();
	QuickSort(copy,size);
	diff = clock() - start;
	printf("快速排序（非递归版）用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=L[i];		
	}	
	
	start =clock();
	CountSort(copy,size,max);
	diff = clock() - start;
	printf("计数排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=L[i];		
	}	

	start =clock();
	RadixCountSort(copy,size);
	diff = clock() - start;
	printf("基数排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=L[i];		
	}
	

	

} 

//测试大量小数组在多次排序下的用时
void test2(void){
	
	clock_t start,diff;
	int size,begin,end,max,sort_time;
	size=100,begin=0,end=100,max=10;	//数组长度 
	double sumtime=0;					//计时器 
	sort_time=100000;			//每种排序法的排序次数 
	int *a,*temp,*copy;
	a=(int *)malloc(size*sizeof(int)); 
	temp=(int *)malloc(size*sizeof(int));
	copy=(int *)malloc(size*sizeof(int));
	
	a[0]=10;
	for(int i=0 ; i<size ; i++){
		
		if(i>0){
			a[i]=rand()%11;	
		}
				
	}
	
	for(int i=0 ; i<size ; i++){
		copy[i]=a[i];
	}
	
	
	
	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		insertSort(copy,size);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//每次排序完成后，重新初始化copy数组，该操作不计入排序时间 
			copy[i]=a[i];		
		}
	}
	printf("插入排序用时%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//每种排序结束后，初始化计时器 
	
	
	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		MergeSort(copy,begin,end,temp);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//每次排序完成后，重新初始化copy数组，该操作不计入排序时间 
			copy[i]=a[i];		
		}
	}
	printf("归并排序用时%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//每种排序结束后，初始化计时器 
	
	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		QuickSort_Recursion(copy,begin,end);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//每次排序完成后，重新初始化copy数组，该操作不计入排序时间 
			copy[i]=a[i];		
		}
	}
	printf("快速排序（递归版）用时%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//每种排序结束后，初始化计时器 


	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		QuickSort(copy,size);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//每次排序完成后，重新初始化copy数组，该操作不计入排序时间 
			copy[i]=a[i];		
		}
	}
	printf("快速排序（非递归版）用时%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//每种排序结束后，初始化计时器 

	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		CountSort(copy,size,max);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//每次排序完成后，重新初始化copy数组，该操作不计入排序时间 
			copy[i]=a[i];		
		}
	}
	printf("计数排序用时%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//每种排序结束后，初始化计时器 
	
	
	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		RadixCountSort(copy,size);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size; i++){				//每次排序完成后，重新初始化copy数组，该操作不计入排序时间 
			copy[i]=a[i];		
		}
	}
	printf("基数排序用时%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//每种排序结束后，初始化计时器 

	
	
	
}



//生成指定数据 （int类型） 
void create(void){
	
	int size,max,min;
	
	printf("开始创建数据文件(默认路径为桌面),请输入数据长度及数据范围(注意！创建数据为int 类型)：\n");
	printf("数据长度(需输入大于0的数)：");
	scanf("%d",&size);
	while(size<=0){
		printf("您输入的值<=0,请重新输入>0的数："); 
		scanf("%d",&size);
	}
	

	
	printf("数据最小值：");
	scanf("%d",&min);
	
	printf("数据最大值："); 
	scanf("%d",&max);
	
	int *array;
	array=(int*)malloc(size*sizeof(int));
	//  数组最左端为最小值，最右端为最大值
	//	整个数组所含元素均在[min,max]范围内 
	array[0]=min;		
	array[size-1]=max;
	for(int i=1 ; i<size-1 ; i++){
		array[i]=rand()%(max-min+1)+min;		//生成[min,max]范围内的数  
	}
	
	

	FILE *fp=NULL;								//根据桌面具体路径进行修改 
	fp=fopen("C:\\Users\\13415\\Desktop\\create_data.txt","w");		//默认在桌面创建名为create_data的txt类型文件，从头写入数据 
	for(int i=0 ; i<size ; i++){
		fprintf(fp,"%d",array[i]);
		fprintf(fp,",");			//以逗号分割各数 
	}
	
	fclose(fp);
	printf("已成功在桌面目录下创建名为\'create_data\'的txt类型文件,请注意查看\n");
	return 0;



} 

//输出单次排序结果 
void sort(int *a,int size,int max){
	
	clock_t start,diff;
	int *temp,*copy;
	temp=(int *)malloc(size*sizeof(int));
	copy=(int *)malloc(size*sizeof(int));
	int begin,end;
	begin=0,end=size-1;


	for(int i=0 ; i<size ; i++){				//将a数组复制到copy数组中 
		copy[i]=a[i];		
	}
		
	start =clock();
	insertSort(copy,size);
	diff = clock() - start;
	printf("插入排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=a[i];		
	}
	
	start =clock();
	MergeSort(copy,begin,end,temp);
	diff = clock() - start;
	printf("归并排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=a[i];		
	}	
	
	start =clock();
	QuickSort_Recursion(copy,begin,end);
	diff = clock() - start;
	printf("快速排序（递归版）用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=a[i];		
	}
	
	start =clock();
	QuickSort(copy,size);
	diff = clock() - start;
	printf("快速排序（非递归版）用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=a[i];		
	}	
	
	start =clock();
	CountSort(copy,size,max);
	diff = clock() - start;
	printf("计数排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=a[i];		
	}	

	start =clock();
	RadixCountSort(copy,size);
	diff = clock() - start;
	printf("基数排序用时%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//每种排序完成后，重新初始化copy数组 
		copy[i]=a[i];		
	}
	
}

//读取生成的指定数据并对其进行排序 
void read_sort(void){
	 
		printf("开始读取程序生成的数据(注意！读取前请确保已用create程序在您的桌面上创建了create_data.txt文件)...\n");
		
		FILE *f=NULL;
		f=fopen("C:\\Users\\13415\\Desktop\\create_data.txt","r");		//根据桌面具体路径进行修改 
		
		if(f==NULL){
			
			
			int min,max;
			int len=0;	//数组长度 
			int x;
			printf("您的桌面不存在文件create_data.txt,下面开始创建:\n");
			printf("-------------------------------------------------------\n");
			create();
			printf("创建成功!\n");
			f=fopen("C:\\Users\\13415\\Desktop\\create_data.txt","r");
			while(fscanf(f,"%d,",&x)!=-1){		//确定数组大小 
				len++;
			}
			rewind(f);							//将文件指针重新移到开头 
			int a[len];							//创建长度为len的数组a
			
			for(int i=0 ; i<len ; i++){			//将数据写入数组a 
				fscanf(f,"%d,",&a[i]);
			}
			fclose(f);
			min=a[0],max=a[len-1]; 
			printf("数据读取完毕，下面对其进行排序:\n");
			printf("\n排序完毕,用时结果如下：\n\n");
			sort(a,len,max);
			
			 
		} 
		else{
			
			int min,max,len,x;
			len=0;
			printf("数据读取成功！\n");
			while(fscanf(f,"%d,",&x)!=-1){
				len++;
			}
			rewind(f);
			int a[len];
			for(int i=0 ; i<len ;i++){
				fscanf(f,"%d,",&a[i]);
			}
			fclose(f);
			min=a[0],max=a[len-1];
			
			printf("数据读取完毕，下面对其进行排序:\n");
			printf("\n排序完毕,用时结果如下：\n\n");			
			sort(a,len,max);
			
		}
		
	
}



//打印排序后数组 
void print(int *a,int size){
 	
	printf("排序后的数组如下:\n");
	for(int i=0 ; i<size ;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
 
 } 
