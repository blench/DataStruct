#include"stdio.h"
#include"malloc.h"

/*
用队列实现患者看病的过程 
*/

typedef struct queue	//链式队列存储结构 
{
	int data;	//数据域 
	struct queue *next;	//指针域 
}QUEUE;	//链式队列类型名

QUEUE *front = NULL;//队头指针 
QUEUE *rear = NULL;//队尾指针 

/*病例入队*/
void addQueue(int x)
{
	QUEUE *s;
	s = (QUEUE*)malloc(sizeof(QUEUE));//创建结点 
	s->data = x;
	s->next = NULL;
	if(rear == NULL)
		front = s;
	else
		rear->next = s;
	rear = s; 
} 

//病人就诊，病历出队

void delQueue(int *e)
{
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{
		QUEUE *temp;
		temp = front->next;
		*e = front->data;
		free(front);
		front = temp;
	}
	return;
} 

//显示病历
void displayQueue()
{
	if(rear == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	QUEUE *temp = front;
	printf("目前所有的病历号:");
	while(temp!=NULL)
	{
		printf("%d \t",temp->data);
		temp = temp->next;
	}
	printf("\n");
} 

void seeDoctor()
{
	int selection,number;//number为病历号 
	int exinum;/*exitnum用于确认号码是否已有，true表示与之前的号码重复，输入无效*/
	
	int stop = 0;/*判断病历号是否全部进队，stop=1,全部进队，stop=0,还有剩余的没有进队*/
	
	int e;
	int flag = 1;//flag = 0，停止排队 
	QUEUE *temp;
	while(flag==1)
	{
		printf("1:排队 2:就诊 3:查看排队 4:停止排队\n");
		printf("请选择:");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				{
					while(stop==0)//排队 
					{
						printf("请输入病历号:");
						do
						{
							scanf("%d",&number);
							//输入为0时跳出循环 
							if(number==0)
								break;
							exinum = 0;
							temp = front;
							while(temp!=NULL && exinum == 0)
							//判断是否有重复的号 
							{
								if(temp->data==number)
									exinum = 1;
								else
									temp = temp->next;
								if(exinum==1)
									printf("输入病号重复，请重新输入\n");
							}
						} 
						while(exinum == 1);
						if(number==0)
							break;
						else
							addQueue(number);//号码入队 
					}
				}
				break;
			case 2:	//看病 
				{
					if(rear == NULL)	//空队列 
						printf("目前无人排队");
					else
					{
						temp = front;
						delQueue(&e);
						printf("第%d号病人就诊\n",e);
					}
				}
				break;
			case 3:
				displayQueue(); 	//显示队列中所有的号码
				break;
			case 4:
				{
					if(front != NULL)	//队列不为空 
						printf("请排队的病人明天就医!\n");	 
					flag = 0;//终止循环 
				}
				break; 
		}
	} 
}

/*主函数*/
int main()
{
	seeDoctor();
} 
