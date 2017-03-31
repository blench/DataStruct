#include<stdio.h>
#include<malloc.h>
typedef int Datatype;
typedef struct node
{
	Datatype *data;
	struct node *next;
}NODE;

NODE *CreateLink(int len)
{
	NODE *h,*p,*s;
	int i;
	p = h =(NODE*)malloc(sizeof(NODE));//建立头结点
	h->next = NULL;
	for(i=1;i<=len;i++)
	{
		s = (NODE*)malloc(sizeof(NODE));//生成新节点
		scanf("%d",&s->data);
		s->next = NULL;
		p->next = s;
		p = s;
	} 
	return h;
}

int GetLength(NODE *h)
{
	NODE *p;
	p = h->next;
	int num = 0;
	while(p!=NULL)
	{
		num++;
		p = p->next; 
	}
	return num;
}

int FindElement(NODE *h,int i,int len)
{
	NODE *p;
	p = h->next;
	int count = 1;
	if(i>1 && i<1)
		return -1;
	while(p != NULL && count<i)
	{
		p = p->next;
		count++;
	}
	return p->data;
}

void Display(NODE *h)
{
	NODE *p;
	p = h->next;
	while(p!=NULL)
	{
		printf("%d",p->data);
		p = p->next;
	} 
}

void InsertElement(NODE *h,int i,int t,int *len)
{
	NODE *p = h,*s;
	int j = 0;
	if(i>*len+1 || i<1)//确认插入位置在链表的合法范围之内
	{
		printf("The location is illegal\n");
		return;
	} 
	while(p->next !=NULL && j<i-1)
	{
		p = p->next;
		j++;
	}
	s = (NODE*)malloc(sizeof(NODE));
	s->data = t;
	s->next = p->next;
	p->next = s;
	*len = *len+1;
	return;
}

void DeleteElement(NODE *h,int i,int *len,int *e)
{
	NODE *p = h->next,*q;
	int j = 1;
	if(i>*len || i<1)
	{
		printf("The location is illegal\n");
		return;
	}
	while(p!=NULL && j<i-1)
	{
		p = p->next;
		j++;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	*len = *len-1;
	free(q);
	return;
}

void DEstroy(NODE *h)
{
	NODE *p;
	while(h->data != NULL)
	{
		p = h;
		h = h->next;
		free(p);
	}
}

void InvertLink(NODE *h)
{
	NODE *p = h->next,*q,*r;
	h->next = NULL;
	while(p != NULL)
	{
		q = p->next;
		p->next = h->next;
		h->next = p;
		p = q;
	} 
}

int main()
{
	NODE *p = CreateLInk(4);
	Display(p);
}
