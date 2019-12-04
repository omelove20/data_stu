#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MaxStack 20

int stack[MaxStack];
int x;
int SP;
char status = 'N';
char ch;
int size;
int cyloop;
int push(int x)
	{
		if(cyloop == 0)
			{
			printf("!!!OVER FLOW!!!...\n");
			status='O';
			getch();
			}
		else
			{
			stack[SP-1] = x;
			SP = SP-1;
			status='N';
			return(SP-1);
			}
	}

int pop()
	{
	int x;
	if(SP != size)
		{
		x=stack[SP];
		stack[SP]=0;
		SP++;
		status='N';
		return(x);
		}
	else
		{
		printf("\n!!!UNDER FLOW!!!...\n");
		status='U';
		getch();
		}
	}
void showAllStack()
	{	
		for(int j=1;j<size;j++)
			{	
			system("cls");	
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
	}
	
int Inputsize()
	{
	int x;
	printf("Enter Number size : ");
	scanf("%d",&x);
	printf("\n====================================\n");
	return(x+1);
	}
	
void SW(){
	switch(ch)
				{
				case '1':	printf("\nEnter Number : ");
							scanf("%d",&x);
							cyloop = push(x);showAllStack();
							break;
				case '2':	x=pop();
							printf("\nData :%d\n",x);showAllStack();
							break;
				}
	
}
void SWO(){
	switch(ch)
				{
				case '1':	showAllStack();
							break;
				case '2':	x=pop();
							printf("\nData :%d\n",x);showAllStack();
							break;
				}
	
}
void SWU(){
	switch(ch)
				{
				case '1':	printf("\nEnter Number : ");
							scanf("%d",&x);
							cyloop = push(x);showAllStack();
							break;
				case '2':	showAllStack();
							break;
				}
	
}
int main()
	{
	size=Inputsize();
	SP=size;
	cyloop=SP;

		while(status=='N')
			{
			printf("[1=PUSH    :2=POP]:");
			ch = getch();
			SW();
			while(status=='O')
			{
			printf("[1=PUSH    :2=POP]:");
			ch = getch();
			SWO();
	//		break;
			}
		while(status=='U')
			{
			printf("[1=PUSH    :2=POP]:");
			ch = getch();
			SWU();
	//		break;
			}
			}
		
		
	printf("\n");
	return(0);
	}
