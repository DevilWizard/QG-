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



//char��ջ
Status s_initLStack(LinkStack *s);//��ʼ��ջ
Status s_isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
char   s_getTopLStack(LinkStack *s);//�õ�ջ��Ԫ��
Status s_clearLStack(LinkStack *s);//���ջ
Status s_destroyLStack(LinkStack *s);//����ջ
Status s_pushLStack(LinkStack *s,char *data);//��ջ
char   s_popLStack(LinkStack *s);//��ջ

//int��ջ 
Status i_initLStack(LinkStack *s);//��ʼ��ջ
Status i_isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
int    i_getTopLStack(LinkStack *s);//�õ�ջ��Ԫ��
Status i_clearLStack(LinkStack *s);//���ջ
Status i_destroyLStack(LinkStack *s);//����ջ
Status i_pushLStack(LinkStack *s,int *data);//��ջ
int    i_popLStack(LinkStack *s);//��ջ

//��׺ת��׺
void infix_to_suffix(char *infix,char *suffix); 

//��׺������ 
void suffix_to_result(char *suffix,int length);

//����������Ƿ��зǷ��ַ�
Status isillegal(char *test,int testl); 
