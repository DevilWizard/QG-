#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h> 
#include"C:/Users/13415/Desktop/QG/���Ĵ���ѵ/SortProject/inc/qgsort.h"



void init(stack *s){

	s->head=(stacknode*)malloc(sizeof(stacknode));
	s->head->next=NULL;
	s->count=0;
	
}
void push(stack *s,int begin,int end){
	
	if(begin<end){		//�����䳤�ȴ���1ʱ�Ž�����Ӳ��� 
	
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
		printf("��ջ�޷�����Ԫ��!\n");
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
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n){
	
	for(int i=1 ; i<n ; i++){
		
		int q =i;
		int p =i-1;
		int s =a[i];	//��������Ԫ�� 
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	
	int left =begin;	//��������ָ�� 
	int right =mid+1; 	//��������ָ�� 
	int t =0;			//temp����ָ�� 
	while(left<=mid && right<=end){
	
		if(a[left]<a[right]){
			temp[t++]= a[left++];
		}
		else{
			temp[t++]= a[right++];
		}
	}
	while(left<=mid){			//��������ʣ��Ԫ����� 
		temp[t++]=a[left++];
	}
	while(right<=end){
		temp[t++]=a[right++];
	}
	int a_p=begin;	//ԭ����aָ�� 
	t=0;			//temp����ָ�����³�ʼ�� 
	while(a_p<=end){
		a[a_p++]=temp[t++];
	}
	
	
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
	
	if(begin<end){
		
		int mid = (begin+end)/2;
		MergeSort(a,begin,mid,temp);	//��������ݹ� 
		MergeSort(a,mid+1,end,temp);	//��������ݹ� 
		MergeArray(a,begin,mid,end,temp);	//�ϲ�
		 
	}
	
	
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end){
	
	if(end-begin<=20){		//�ݹ�����Ż� 
		insertSort(a,end-begin+1);
	}
	else{
			if(begin<end){
				int split=Partition(a,begin,end);	//ȷ�������±���Ϊ�ָ��� 
				QuickSort_Recursion(a,begin,split-1);
				QuickSort_Recursion(a,split+1,end);
		
			}
	}

	
	
	
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size){
	
	
	void init(stack *s);
	void push(stack *s,int begin,int end);
	void pop(stack *s,int *begin,int *end);
	bool empty(stack *s);
	void destroy(stack *s);
	
	if(size<=20){				//�����Ż� 
		insertSort(a,size);
	}
	
	else{
		
		int begin,end;
		begin=0,end=size-1;
		
		stack s;
		init(&s);	//����ջ 
		int split=Partition(a,begin,end);		//ȷ�������±���Ϊ�ָ���
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end){
	
	int low=begin;	    //��������� 
	int high=end;		//�������Ҷ�
	int temp =a[begin];		//�Ե�һ��Ϊ��Ŧ 
	while(low!=high){		//�ڿӷ� 
		
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
	
	return low;			//���ظ���Ŧ���������յ��±� 
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max){
	
	int *count;		//ͳ������ 
	count=(int*)malloc((max+1)*sizeof(int));
	for(int i=0 ; i<max+1 ; i++){
		count[i]=0;
	} 
	int temp[size];				//��ʱ���� 
	for(int i=0 ; i<size ; i++){	//�ռ� 
		count[a[i]]++;
		
	}
	
	for(int i=1 ; i<max+1 ; i++){	//ͳ�� 
		count[i]+=count[i-1];
	}
	
	for(int i=size-1 ; i>=0 ; i--){	//���� 
		temp[--count[a[i]]]=a[i];
	}
	for(int i=0 ; i<size ; i++){
		a[i]=temp[i];
	}
	
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size){
	
 
	int max=0,max_digit=0;	//ԭ�������������λ�� 
	int BASE=10,exp=1;      //����Ϊ10 ,exp���ڼ���10��n�η� 
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
		

		int bucket[10]={0};  //����Ͱ
		int temp[size]; //��ʱ����

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
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
 
void Find_K(int *a,int size,int k){
	int max=0;
	int p=0;	//��¼˳�򣨰���С�����ڸ��������ǵڼ�λ�� 
	int k_min=0,k_max=0;  //��K�󣬵�KС 
	for(int i=0 ; i<size ; i++){	//���������ֵ 
		
		if(max<a[i]){
			max=a[i];
		}
	}
	
	int *store;
	store=(int*)malloc((max+1)*sizeof(int));
	for(int i=0 ; i<max+1 ; i++){
		store[i]=-1;		//��-1��Ϊ���ж� 
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
	int true_size=p;	//�޳��ظ�Ԫ�غ�Ĵ�С 
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
	
	
	
	//printf("�� %d С����Ϊ %d ���� %d �����Ϊ %d\n",k,k_min,k,k_max);
	
	
}

//������������������ʱ����
void test(int level){
	
	//��Ϊ0-10����� 
	int *L,*temp,*copy;
	L=(int *)malloc(level*sizeof(int));
	temp=(int *)malloc(level*sizeof(int));
	copy=(int *)malloc(level*sizeof(int));
	int size,begin,end,max;
	size=level,begin=0,end=level-1,max=10;
	L[0]=10;	//��֤���ֵΪ10 
	for(int i=0 ; i<level ; i++){
		if(i!=0){
			L[i]=rand()%11;
		}
		
	}

	for(int i=0 ; i<level ; i++){				//��L���鸴�Ƶ�copy������ 
		copy[i]=L[i];		
	}
		
	clock_t start =clock();
	insertSort(copy,size);
	clock_t diff = clock() - start;
	printf("����������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=L[i];		
	}
	
	start =clock();
	MergeSort(copy,begin,end,temp);
	diff = clock() - start;
	printf("�鲢������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=L[i];		
	}	
	
	start =clock();
	QuickSort_Recursion(copy,begin,end);
	diff = clock() - start;
	printf("�������򣨵ݹ�棩��ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=L[i];		
	}
	
	start =clock();
	QuickSort(copy,size);
	diff = clock() - start;
	printf("�������򣨷ǵݹ�棩��ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=L[i];		
	}	
	
	start =clock();
	CountSort(copy,size,max);
	diff = clock() - start;
	printf("����������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=L[i];		
	}	

	start =clock();
	RadixCountSort(copy,size);
	diff = clock() - start;
	printf("����������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<level ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=L[i];		
	}
	

	

} 

//���Դ���С�����ڶ�������µ���ʱ
void test2(void){
	
	clock_t start,diff;
	int size,begin,end,max,sort_time;
	size=100,begin=0,end=100,max=10;	//���鳤�� 
	double sumtime=0;					//��ʱ�� 
	sort_time=100000;			//ÿ�����򷨵�������� 
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
		for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���飬�ò�������������ʱ�� 
			copy[i]=a[i];		
		}
	}
	printf("����������ʱ%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//ÿ����������󣬳�ʼ����ʱ�� 
	
	
	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		MergeSort(copy,begin,end,temp);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���飬�ò�������������ʱ�� 
			copy[i]=a[i];		
		}
	}
	printf("�鲢������ʱ%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//ÿ����������󣬳�ʼ����ʱ�� 
	
	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		QuickSort_Recursion(copy,begin,end);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���飬�ò�������������ʱ�� 
			copy[i]=a[i];		
		}
	}
	printf("�������򣨵ݹ�棩��ʱ%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//ÿ����������󣬳�ʼ����ʱ�� 


	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		QuickSort(copy,size);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���飬�ò�������������ʱ�� 
			copy[i]=a[i];		
		}
	}
	printf("�������򣨷ǵݹ�棩��ʱ%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//ÿ����������󣬳�ʼ����ʱ�� 

	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		CountSort(copy,size,max);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���飬�ò�������������ʱ�� 
			copy[i]=a[i];		
		}
	}
	printf("����������ʱ%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//ÿ����������󣬳�ʼ����ʱ�� 
	
	
	for(int i=0 ; i<sort_time ; i++){
		start =clock();
		RadixCountSort(copy,size);
		diff = clock() - start;
		sumtime+=diff;
		for(int i=0 ; i<size; i++){				//ÿ��������ɺ����³�ʼ��copy���飬�ò�������������ʱ�� 
			copy[i]=a[i];		
		}
	}
	printf("����������ʱ%.2f ms \n",(float)sumtime/CLOCKS_PER_SEC*1000);
	sumtime=0;		//ÿ����������󣬳�ʼ����ʱ�� 

	
	
	
}



//����ָ������ ��int���ͣ� 
void create(void){
	
	int size,max,min;
	
	printf("��ʼ���������ļ�(Ĭ��·��Ϊ����),���������ݳ��ȼ����ݷ�Χ(ע�⣡��������Ϊint ����)��\n");
	printf("���ݳ���(���������0����)��");
	scanf("%d",&size);
	while(size<=0){
		printf("�������ֵ<=0,����������>0������"); 
		scanf("%d",&size);
	}
	

	
	printf("������Сֵ��");
	scanf("%d",&min);
	
	printf("�������ֵ��"); 
	scanf("%d",&max);
	
	int *array;
	array=(int*)malloc(size*sizeof(int));
	//  ���������Ϊ��Сֵ�����Ҷ�Ϊ���ֵ
	//	������������Ԫ�ؾ���[min,max]��Χ�� 
	array[0]=min;		
	array[size-1]=max;
	for(int i=1 ; i<size-1 ; i++){
		array[i]=rand()%(max-min+1)+min;		//����[min,max]��Χ�ڵ���  
	}
	
	

	FILE *fp=NULL;													//�����������·�������޸� 
	fp=fopen("C:\\Users\\13415\\Desktop\\create_data.txt","w");		//Ĭ�������洴����Ϊcreate_data��txt�����ļ�����ͷд������ 
	for(int i=0 ; i<size ; i++){
		fprintf(fp,"%d",array[i]);
		fprintf(fp,",");			//�Զ��ŷָ���� 
	}
	
	fclose(fp);
	printf("�ѳɹ�������Ŀ¼�´�����Ϊ\'create_data\'��txt�����ļ�,��ע��鿴\n");
	return 0;



} 

//������������� 
void sort(int *a,int size,int max){
	
	clock_t start,diff;
	int *temp,*copy;
	temp=(int *)malloc(size*sizeof(int));
	copy=(int *)malloc(size*sizeof(int));
	int begin,end;
	begin=0,end=size-1;


	for(int i=0 ; i<size ; i++){				//��L���鸴�Ƶ�copy������ 
		copy[i]=a[i];		
	}
		
	start =clock();
	insertSort(copy,size);
	diff = clock() - start;
	printf("����������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=a[i];		
	}
	
	start =clock();
	MergeSort(copy,begin,end,temp);
	diff = clock() - start;
	printf("�鲢������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=a[i];		
	}	
	
	start =clock();
	QuickSort_Recursion(copy,begin,end);
	diff = clock() - start;
	printf("�������򣨵ݹ�棩��ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=a[i];		
	}
	
	start =clock();
	QuickSort(copy,size);
	diff = clock() - start;
	printf("�������򣨷ǵݹ�棩��ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=a[i];		
	}	
	
	start =clock();
	CountSort(copy,size,max);
	diff = clock() - start;
	printf("����������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=a[i];		
	}	

	start =clock();
	RadixCountSort(copy,size);
	diff = clock() - start;
	printf("����������ʱ%.2f ms \n",(float)diff/CLOCKS_PER_SEC*1000);
	for(int i=0 ; i<size ; i++){				//ÿ��������ɺ����³�ʼ��copy���� 
		copy[i]=a[i];		
	}
	
}

//��ȡ���ɵ�ָ�����ݲ������������ 
void read_sort(void){
	 
		printf("��ʼ��ȡ�������ɵ�����(ע�⣡��ȡǰ��ȷ������create���������������ϴ�����create_data.txt�ļ�)...\n");
		
		FILE *f=NULL;
		f=fopen("C:\\Users\\13415\\Desktop\\create_data.txt","r");		//�����������·�������޸� 
		
		if(f==NULL){
			
			
			int min,max;
			int len=0;	//���鳤�� 
			int x;
			printf("�������治�����ļ�create_data.txt,���濪ʼ����:\n");
			printf("-------------------------------------------------------\n");
			create();
			printf("�����ɹ�!\n");
			f=fopen("C:\\Users\\13415\\Desktop\\create_data.txt","r");
			while(fscanf(f,"%d,",&x)!=-1){		//ȷ�������С 
				len++;
			}
			rewind(f);							//���ļ�ָ�������Ƶ���ͷ 
			int a[len];							//��������Ϊlen������a
			
			for(int i=0 ; i<len ; i++){			//������д������a 
				fscanf(f,"%d,",&a[i]);
			}
			fclose(f);
			min=a[0],max=a[len-1]; 
			printf("���ݶ�ȡ��ϣ���������������:\n");
			printf("\n�������,��ʱ������£�\n\n");
			sort(a,len,max);
			
			 
		} 
		else{
			
			int min,max,len,x;
			len=0;
			printf("���ݶ�ȡ�ɹ���\n");
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
			
			printf("���ݶ�ȡ��ϣ���������������:\n");
			printf("\n�������,��ʱ������£�\n\n");			
			sort(a,len,max);
			
		}
		
	
}



//��ӡ��������� 
void print(int *a,int size){
 	
	printf("��������������:\n");
	for(int i=0 ; i<size ;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
 
 } 
