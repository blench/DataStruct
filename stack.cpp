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

int top = -1; //栈顶指针
int mindirections = maximum;//最短路径
struct 
{
	int i;//纵坐标
	int j;//横坐标
	int direction;//方向 
}Stack[maximum],Path[maximum];

void maze()
{
	int k;
	int count = -1;//路径长度计数
	int i,j,direction,find;
	top++;
	Stack[top].i = 1; 
	Stack[top].j = 1;//(1,1)为起始点
	Stack[top].direction = -1;
	map[1][1] = -1;
	
	while(top >-1)//栈不空
	{
		i = Stack[top].i;
		j = Stack[top].j;
		direction = Stack[top].direction;
		if(i==H-2 && j==W-2)//判断是否到达出口 
		{
			for(k=0;k<=top;k++)
			{
				printf("[%d,%d]",Stack[k].i,Stack[k].j);
				if((k+1)%5==0)
					printf("\n");
			}
			printf("\n");
			//寻找最短路径 
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
				Stack[top].i = i;//可走结点的坐标入栈 
				Stack[top].j = j;
				Stack[top].direction = -1;//准备寻找下一个可走结点
				map[i][j] = -1;//避免重复走到该点 
			}
			//未找到下一个可行结点 ，退回到上一个位置
			else
			{
				map[Stack[top].i][Stack[top].j] = 0;
				top--;
//				maze();
			} 
		}
		printf("最短路径长度为：%d\n",mindirections);
		printf("最短路径：\n");
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
	printf("迷宫所有路径：\n");
	maze();
	return 12;
}

