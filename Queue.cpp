#include"stdio.h"
#include"malloc.h"

/*
�ö���ʵ�ֻ��߿����Ĺ��� 
*/

typedef struct queue	//��ʽ���д洢�ṹ 
{
	int data;	//������ 
	struct queue *next;	//ָ���� 
}QUEUE;	//��ʽ����������

QUEUE *front = NULL;//��ͷָ�� 
QUEUE *rear = NULL;//��βָ�� 

/*�������*/
void addQueue(int x)
{
	QUEUE *s;
	s = (QUEUE*)malloc(sizeof(QUEUE));//������� 
	s->data = x;
	s->next = NULL;
	if(rear == NULL)
		front = s;
	else
		rear->next = s;
	rear = s; 
} 

//���˾����������

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

//��ʾ����
void displayQueue()
{
	if(rear == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	QUEUE *temp = front;
	printf("Ŀǰ���еĲ�����:");
	while(temp!=NULL)
	{
		printf("%d \t",temp->data);
		temp = temp->next;
	}
	printf("\n");
} 

void seeDoctor()
{
	int selection,number;//numberΪ������ 
	int exinum;/*exitnum����ȷ�Ϻ����Ƿ����У�true��ʾ��֮ǰ�ĺ����ظ���������Ч*/
	
	int stop = 0;/*�жϲ������Ƿ�ȫ�����ӣ�stop=1,ȫ�����ӣ�stop=0,����ʣ���û�н���*/
	
	int e;
	int flag = 1;//flag = 0��ֹͣ�Ŷ� 
	QUEUE *temp;
	while(flag==1)
	{
		printf("1:�Ŷ� 2:���� 3:�鿴�Ŷ� 4:ֹͣ�Ŷ�\n");
		printf("��ѡ��:");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				{
					while(stop==0)//�Ŷ� 
					{
						printf("�����벡����:");
						do
						{
							scanf("%d",&number);
							//����Ϊ0ʱ����ѭ�� 
							if(number==0)
								break;
							exinum = 0;
							temp = front;
							while(temp!=NULL && exinum == 0)
							//�ж��Ƿ����ظ��ĺ� 
							{
								if(temp->data==number)
									exinum = 1;
								else
									temp = temp->next;
								if(exinum==1)
									printf("���벡���ظ�������������\n");
							}
						} 
						while(exinum == 1);
						if(number==0)
							break;
						else
							addQueue(number);//������� 
					}
				}
				break;
			case 2:	//���� 
				{
					if(rear == NULL)	//�ն��� 
						printf("Ŀǰ�����Ŷ�");
					else
					{
						temp = front;
						delQueue(&e);
						printf("��%d�Ų��˾���\n",e);
					}
				}
				break;
			case 3:
				displayQueue(); 	//��ʾ���������еĺ���
				break;
			case 4:
				{
					if(front != NULL)	//���в�Ϊ�� 
						printf("���ŶӵĲ��������ҽ!\n");	 
					flag = 0;//��ֹѭ�� 
				}
				break; 
		}
	} 
}

/*������*/
int main()
{
	seeDoctor();
} 
