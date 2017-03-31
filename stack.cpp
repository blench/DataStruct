#include"stdio.h"
#define H 6
#define W 6
#define maximum 20
int map [H][W]= 
{
	{1,1,1,1,1,1},
	{1,0,0,0,0,1},
	{1,0,1,0,0,1},
	{1,0,1,0,1,1},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1},
} ;

int top = -1; //ջ��ָ��
int mindirections = maximum;//���·��
struct 
{
	int i;//������
	int j;//������
	int direction;//���� 
}Stack[maximum],Path[maximum];

void maze()
{
	int k;
	int count = -1;//·�����ȼ���
	int i,j,direction,find;
	top++;
	Stack[top].i = 1; 
	Stack[top].j = 1;//(1,1)Ϊ��ʼ��
	Stack[top].direction = -1;
	map[1][1] = -1;
	
	while(top >-1)//ջ����
	{
		i = Stack[top].i;
		j = Stack[top].j;
		direction = Stack[top].direction;
		if(i==H-2 && j==W-2)//�ж��Ƿ񵽴���� 
		{
			for(k=0;k<=top;k++)
			{
				printf("[%d,%d]",Stack[k].i,Stack[k].j);
				if((k+1)%5==0)
					printf("\n");
			}
			printf("\n");
			//Ѱ�����·�� 
			if(top+1<mindirections)
			{
				for(k=0;k<=top;k++)
				Path[k] = Stack[k];
				mindirections = top+1; 
			}
			map[Stack[top].i][Stack[top].j] = 0;
			top--;
			i = Stack[top].i;
			j = Stack[top].j;
			direction = Stack[top].direction;
		}
		
		find = 0;
		while(direction<4 && find==0)
		{
			direction++;
			switch(direction)
			{
				case 0:i = Stack[top].i-1;j = Stack[top].j;break;
				case 1:i = Stack[top].i;j = Stack[top].j+1;break;
				case 2:i = Stack[top].i+1;j = Stack[top].j;break;
				case 3:i = Stack[top].i;j = Stack[top].j-1;break;
			}
			if(map[i][j]== 0)
				find =1;
		}
			if(find ==1)
			{
				Stack[top].direction = direction;
				top++;
				Stack[top].i = i;//���߽���������ջ 
				Stack[top].j = j;
				Stack[top].direction = -1;//׼��Ѱ����һ�����߽��
				map[i][j] = -1;//�����ظ��ߵ��õ� 
			}
			//δ�ҵ���һ�����н�� ���˻ص���һ��λ��
			else
			{
				map[Stack[top].i][Stack[top].j] = 0;
				top--;
//				maze();
			} 
		}
		printf("���·������Ϊ��%d\n",mindirections);
		printf("���·����\n");
		for(k=0;k<mindirections;k++)
		{
			printf("[%d,%d]",Path[k].i,Path[k].j);
			if((k+1)%4==0)
				printf("\n");
		}
		printf("\n");
	}

int main()
{
	printf("�Թ�����·����\n");
	maze();
	return 12;
}

