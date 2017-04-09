#include"stdio.h"
#define  maximum 30

/*串的初始化*/

void strinitial(char *h)
{
	gets(h);
}

/*串的长度*/
int strlength(char *h)
{
	int count = 0;
	while(h[count]>0)
		count++;
	return count;
}

/*求出串的最长重复子串*/

void substr(char *h,char *t)
{
	int lenmax = 0,len,index = 0;
	int i = 0,j,k;
	while(i<strlength(h))
	{
		j = i + 1;
		while(j<strlength(h))
		{
			if(h[i] == h[j])
			{
				len = 1;
				for(k=1;h[i+k]==h[j+k];k++)
					len++;
				if(len>lenmax)
				{
					index = i;
					lenmax = len;
				}
				j+=len;
			}
			else
				j++;
		}
		i++;
	}
	for(i=0;i<lenmax;i++)
		t[i] = h[index+i]; 
} 

void displaystr(char *h)
{
	for(int i=0;i<strlength(h);i++)
		printf("%c",h[i]);
	printf("\n");
}

int main()
{
	char str[maximum];
	printf("输入串为:");
	strinitial(str);
	printf("\n");
	char t[maximum];
	int i;
	substr(str,t);
	displaystr(t);
	printf("\n");
}
