#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define l 1
#define u 5
#define l1 1
#define u1 3
#define l2 1
#define u2 4
#define l3 1
#define u3 5

int *BA, *p ;
int i,j,k;

void Create3Darray()
	{
	int element,c,total_mem;
	element=(u1-l1+1)*(u2-l2+1)*(u3-l3+1);
	c=sizeof(*BA);
	total_mem=element*c;
	BA=(int*)malloc(total_mem);
	}
void A(int i,int j,int k,int x,int z)
	{
		printf("========================\n");
		switch (z) {
					case 1 :	p=BA+((i-l1)*(u2-l2+1)*(u3-l3+1)+(j-l2)*(u3-l3+1)+(k-l3));
								*p=x;
								break;
					case 2 :	p=BA+((i-l1)*(u2-l2+1)*(u3-l3+1)+(k-l3)*(u2-l2+1)+(j-l2));
								*p=x;
								break;
					case 3 :	p=BA+((j-l2)*(u1-l1+1)*(u3-l3+1)+(i-l1)*(u3-l3+1)+(k-l3));
								*p=x;
								break;
					case 4 :	p=BA+((j-l2)*(u1-l1+1)*(u3-l3+1)+(k-l3)*(u1-l1+1)+(i-l1));
								*p=x;
								break;
					case 5 :	p=BA+((k-l3)*(u1-l1+1)*(u2-l2+1)+(i-l1)*(u2-l2+1)+(j-l2));
								*p=x;
								break;
					case 6 :	p=BA+((k-l3)*(u1-l1+1)*(u2-l2+1)+(j-l2)*(u1-l1+1)+(i-l1));
								*p=x;
								break;
		}
	}
	
	
int ReadA(int i,int j,int k,int z)
	{switch (z) {
					case 1 :	p=BA+((i-l1)*(u2-l2+1)*(u3-l3+1)+(j-l2)*(u3-l3+1)+(k-l3));
								break;
					case 2 :	p=BA+((i-l1)*(u2-l2+1)*(u3-l3+1)+(k-l3)*(u2-l2+1)+(j-l2));
								break;
					case 3 :	p=BA+((j-l2)*(u1-l1+1)*(u3-l3+1)+(i-l1)*(u3-l3+1)+(k-l3));
								break;
					case 4 :	p=BA+((j-l2)*(u1-l1+1)*(u3-l3+1)+(k-l3)*(u1-l1+1)+(i-l1));
								break;
					case 5 :	p=BA+((k-l3)*(u1-l1+1)*(u2-l2+1)+(i-l1)*(u2-l2+1)+(j-l2));
								break;
					case 6 :	p=BA+((k-l3)*(u1-l1+1)*(u2-l2+1)+(j-l2)*(u1-l1+1)+(i-l1));
								break;
				}return(*p);
	}
	
int input_i(char z)
	{int x;
	printf("Enter number to %c less than %d and more than %d  = ",z,u1,l1);
	scanf("%d",&x);
	if (x>l1-1 && x<u1+1){
		return x;
	}else{
		printf("Error over size\n");
		exit(0);
	}
	}
	
int input_j(char z)
	{int x;
	printf("Enter number to %c less than %d and more than %d  = ",z,u2,l2);
	scanf("%d",&x);
	if (x>l2-1 && x<u2+1){
		return x;
	}else{
		printf("Error over size\n");
		exit(0);
	}
	}
	
int input_k(char z)
	{int x;
	printf("Enter number to %c less than %d and more than %d  = ",z,u3,l3);
	scanf("%d",&x);
	if (x>l3-1 && x<u3+1){
		return x;
	}else{
		printf("Error over size\n");
		exit(0);
	}
	}
	
int input_Number()
	{int number;
	printf("================================\n");
	printf("Enter number to = ");
	scanf("%d",&number);
	return number;
	}
	
void showcase(){
	printf("%+7s - %+7s - %+7s  ==  {1} \n","Plane","Row","Column");
	printf("%+7s - %+7s - %+7s  ==  {2} \n","Plane","Column","Row");
	printf("%+7s - %+7s - %+7s  ==  {3} \n","Row","Plane","Column");
	printf("%+7s - %+7s - %+7s  ==  {4} \n","Row","Column","Plane");
	printf("%+7s - %+7s - %+7s  ==  {5} \n","Column","Plane","Row");
	printf("%+7s - %+7s - %+7s  ==  {6} \n","Column","Row","Plane");
	printf("================================\n");
}
	
int main()
	{int z;
	printf("3 DIMENSION ARRAY FUNCTION...\n");
	printf("================================\n");
	Create3Darray();
	
	showcase();
	printf("Enter case = ");
	scanf("%d",&z);
	
	i=input_i('i'); j=input_j('j'); k=input_k('k');
	
	A(i,j,k,input_Number(),z);
	printf("\nArray <%d,%d,%d>=%d \n",i,j,k,ReadA(i,j,k,z));
	printf("================================\n");
	printf("\n%-20s=%x","Base Address",BA);
	printf("\n%-20s=%x ","Address",p);

	return(0);
	}
