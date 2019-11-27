#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MaxStack 20

int stack[MaxStack];
int x;
int SP=0;
char status = 'N';
char ch;
int size;

void push(int x)
	{
		if(SP == size-1)
			{
			printf("!!!OVER FLOW!!!...\n");
			status='O';
			}
		else
			{
			SP=SP+1;
			stack[SP]=x;
			}
	}
int pop()
	{
	int x;
	if(SP !=0)
		{
		x=stack[SP];
		stack[SP]=0;
		SP--;
		return(x);
		}
	else
		{
		printf("\n!!!UNDER FLOW!!!...\n");
		status='U';
		}
	}
void showAllStack()
	{
	int i;
	printf(" %-10s:%d\n","N",size-1);
	printf(" %-10s:%c\n","Status",status);
	printf(" %-10s:%d\n","SP",SP);
	for(i=1;i<size;i++)
		{
		printf("%d:%d  ",i,stack[i]);
		}
	printf("\n---------------------------------\n");
	}
	
int Inputsize()
	{
	int x;
	printf("Enter Number size : ");
	scanf("%d",&x);
	printf("\n====================================\n");
	return(x+1);
	}
	
int main()
	{
	printf("STACK PROGRAM...\n");
	printf("====================================\n");
	size=Inputsize();
	while(status=='N')
		{
		printf("[1=PUSH    :2=POP]:");
		ch = getch();
		switch(ch)
			{
			case '1':	printf("\nEnter Number : ");
						scanf("%d",&x);
						push(x);
						showAllStack();
						break;
			case '2':	x=pop();
						printf("\nData :%d\n",x);
						showAllStack();
						break;
			}
		getch();
		system("cls");
		printf("STACK PROGRAM...\n");
		printf("====================================\n");
		printf("Enter Number size : %d",size-1);
		printf("\n====================================\n");
		}
	printf("\n");
	return(0);
	}
