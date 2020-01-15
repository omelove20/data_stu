#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MaxNode 100

int N, data[MaxNode];
char namescan[MaxNode];
char name[MaxNode] = "   i  ww   in-ao     tjteptilnhc";
char ch;
void CreateTreeNS(int n)
	{
		int i, temp;
		for( i = 1 ; i <= n ; i++ )
			{
				data[i] = name[i] ;	
		//		printf("\t%d",data[i]);
			}
	}
void ShowArray()
	{
		int i = 1;
		printf ("String : %s\n",name) ;
		while( data[i] != NULL)
			{
				printf("[%i]%c ",i,data[i]);
				i++;
			}
			printf("\n==========================\n");
	}
void ShowTree()
	{
		int j,level,start,ends;
		j = 1;
		level = 1;
		printf("\n");
		while( data[j] != NULL)
			{
				start = pow(2,level)/2;
				ends = pow(2,level)-1;
				for( j = start ; j <= ends ; j++ )
					if( data[j] != NULL )
						{
							switch(level)
								{
									case 1 :	printf("%40c",data[j]);
												break;
									case 2 :	if( j == 2 )
													printf("%20c",data[j]);
												else
													printf("%40c",data[j]);
												break;
									case 3 :	if( j == 4 )
													printf("%10c",data[j]);
												else
													printf("%20c",data[j]);
												break;
									case 4 :	if( j == 8 )
													printf("%5c",data[j]);
												else
													printf("%10c",data[j]);
												break;
									case 5 :	if( j == 16 )
													printf("%c",data[j]);
												else
													printf("%5c",data[j]);
												break;
									
								}
						}
			printf("\n\n");
			level++;
			}
	}
void PreOrder(int i)
	{
		int info,lson,rson;
		info = data[i];
		if( info != NULL )
			{
				printf("%c ",data[i]);
				lson = 2*i;
				rson = 2*i+1;
				PreOrder(lson);
				PreOrder(rson);
			}
	}
void ReversePreOrder(int i)
	{
		int info,lson,rson;
		info = data[i];
		//printf("%d",info);
		if( info != NULL )
			{
				printf("%c ",data[i]);
				lson = 2*i;
				rson = 2*i+1;
				ReversePreOrder(rson);
				ReversePreOrder(lson);
			}
	}
void InOrder(int i)
	{
		int info,lson,rson;
		info = data[i];
		if( info != NULL )
			{
				lson = 2*i;
				rson = 2*i+1;
				InOrder(lson);
				printf("%c ",data[i]);
				InOrder(rson);
			}
	}
void ReverseInOrder(int i)
	{
		int info,lson,rson;
		info = data[i];
		if( info != NULL )
			{
				lson = 2*i;
				rson = 2*i+1;
				ReverseInOrder(rson);
				printf("%c ",data[i]);
				ReverseInOrder(lson);
			}
	}
void PostOrder(int i)
	{
		int info,lson,rson;
		info = data[i];
		if( info != NULL)
			{
				lson = 2*i;
				rson = 2*i+1;
				PostOrder(lson);
				PostOrder(rson);
				printf("%c ",data[i]);
			}
	}
void ReversePostOrder(int i)
	{
		int info,lson,rson;
		info = data[i];
		if( info != NULL)
			{
				lson = 2*i;
				rson = 2*i+1;
				ReversePostOrder(rson);
				ReversePostOrder(lson);
				printf("%c ",data[i]);
			}
	}
	
/*int scanname(){
	int lene,k;
	printf("%s","Enter Your Name : ");
	scanf("%s",namescan);
	lene = strlen(namescan);
	name[1]=namescan[0];
	name[3]=namescan[1];
	name[7]=namescan[2];
	name[15]=namescan[3];
	name[14]=namescan[4];
	name[6]=namescan[5];
	name[13]=namescan[6];
	name[12]=namescan[7];
	name[2]=namescan[8];
	name[5]=namescan[9];
	name[11]=namescan[10];
	name[10]=namescan[11];
	name[4]=namescan[12];
	name[9]=namescan[13];
	name[8]=namescan[14];
	return lene;	
}*/
int main()
	{
		N = strlen(name);
		printf("%d",N);
		
		for(int k=1 ;k<=N;k++){
		printf("%c",name[k]);
		
	}printf("\n");
		CreateTreeNS(N);
		while(ch = 'E')
			{
				printf("\nTREE (NODE SEQUENCE)\n");
				printf("\n======================\n");
				ShowArray();
				ShowTree();
				printf("\n MENU >> P : PreOrder | I : InOrder | O : PostOrder |\n\t 1 : Reverse(PreOrder) | 2 : Reverse(INORDER) | 3 : Reverse(PostOrder) | E : Exit");
				ch = getch();
				printf("\n======================\n");
				switch(ch)
					{
						case 'P':	ShowTree();
									printf("PRE ORDER TRAVERSAL : ");
									PreOrder(1);
									printf("\n");
									break;
						case 'I':	ShowTree();
									printf("In ORDER TRAVERSAL : ");
									InOrder(1);
									printf("\n");
									break;
						case 'O':	ShowTree();
									printf("POST ORDER TRAVERSAL : ");
									PostOrder(1);
									printf("\n");
									break;
						case '1':	ShowTree();
									printf("REVERSE PRE ORDER TRAVERSAL : ");
									ReversePreOrder(1) ;
									printf("\n");
									break;
						case '2':	ShowTree();
									printf("REVERSE In ORDER TRAVERSAL : ");
									ReverseInOrder(1) ;
									printf("\n");
									break;
						case '3':	ShowTree();
									printf("REVERSE Post ORDER TRAVERSAL : ");
									ReversePostOrder(1) ;
									printf("\n");
									break;
					}
			}
	}
