typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;


typedef  struct s_StackNode
{
	char data;			 
	struct s_StackNode *next;
}s_StackNode, *s_LinkStackPtr;

typedef  struct i_StackNode
{
	int data;			 
	struct i_StackNode *next;
}i_StackNode, *i_LinkStackPtr;


typedef  struct  LinkStack
{
	s_LinkStackPtr s_top;
	i_LinkStackPtr i_top;
	int	count;
}LinkStack;



//char链栈
Status s_initLStack(LinkStack *s);//初始化栈
Status s_isEmptyLStack(LinkStack *s);//判断栈是否为空
char   s_getTopLStack(LinkStack *s);//得到栈顶元素
Status s_clearLStack(LinkStack *s);//清空栈
Status s_destroyLStack(LinkStack *s);//销毁栈
Status s_pushLStack(LinkStack *s,char *data);//入栈
char   s_popLStack(LinkStack *s);//出栈

//int链栈 
Status i_initLStack(LinkStack *s);//初始化栈
Status i_isEmptyLStack(LinkStack *s);//判断栈是否为空
int    i_getTopLStack(LinkStack *s);//得到栈顶元素
Status i_clearLStack(LinkStack *s);//清空栈
Status i_destroyLStack(LinkStack *s);//销毁栈
Status i_pushLStack(LinkStack *s,int *data);//入栈
int    i_popLStack(LinkStack *s);//出栈

//中缀转后缀
void infix_to_suffix(char *infix,char *suffix); 

//后缀运算结果 
void suffix_to_result(char *suffix,int length);

//检测输入中是否含有非法字符
Status isillegal(char *test,int testl); 
