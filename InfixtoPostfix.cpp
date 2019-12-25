#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define MaxStack 40

char infix1[80] ;
char OpSt[MaxStack];
char SumOp[MaxStack];
int SP = 0 ;

char postfix1[80] ;
float ValPostfix[80];
float ValOperandST[MaxStack];
int SPA = 0;

char cp[80] ;
int k = 0 ;

void push(char oper){
	if(SP == MaxStack){
		printf("ERROR STACK OVER FLOW!!!...\n");
	}
	else{
		SP = SP+1;
		OpSt[SP] = oper;
	}
}
int pop(){
	char oper;
	if(SP != 0){
		oper = OpSt[SP];
		SP--;
		return(oper);
	}
	else
		printf("\nERROR STACK UNDER FLOW!!!...\n");
}
int precedenceIP(char oper){
	switch(oper){
		case'+':return(3);
		case'-':return(3);
		case'*':return(2);
		case'/':return(2);
		case'^':return(0);
		case'(':return(0);
	}
}
int precedenceST(char oper){
	switch(oper){
		case'+':return(3);
		case'-':return(3);
		case'*':return(2);
		case'/':return(2);
		case'^':return(1);
		case'(':return(0);
	}
}
int changeIP(char oper){
	switch(oper){
		case'+':return(1);
		case'-':return(1);
		case'*':return(2);
		case'/':return(2);
		case'^':return(4);
		case'(':return(4);
	}
}
int changeIP10(char oper){
	switch(oper){
		case'+':return(5);
		case'-':return(5);
		case'*':return(5);
		case'/':return(5);
		case'^':return(5);
		case'(':return(0);
		default :return(0);
	}
}
int changeST(char oper){
	switch(oper){
		case'+':return(1);
		case'-':return(1);
		case'*':return(2);
		case'/':return(2);
		case'^':return(3);
		case'(':return(0); 
	}
}
void infixTOpostfix(char infix2[80]){
	int i, j, len;
	char ch, temp;
	printf("INFIX :%s\n",infix2);
	len = strlen(infix2);
	printf("Infix Length =%d\n",len);
	printf("POSTFIX IS : ");
	for( i = 0 ; i <= len ; i++ ){
		ch = infix2[i];
		if(strchr("+-*/^()",ch) == 0 ){
			cp[k++] = ch ;	
		}else{
			if(SP == 0){
				push(ch);
			}
			else
				if(ch != ')'){
					if( precedenceIP(changeIP(ch)) > precedenceST(changeST(OpSt[SP])) ){
							push(ch);
					}else{
						cp[k++] = pop() ;
						while(precedenceIP(changeIP(ch)) <= precedenceST(changeST(OpSt[SP])) && (SP != 0))
							cp[k++] = pop() ;
							push(ch);
					}
				}else{
					temp = pop();
					cp[k++] = temp ;
					while((temp != '(')){
						temp = pop();
					}
				}
			}
		}
		j = SP;
		for( i = 1 ; i <= j ; i++ ){
			printf("%c",pop());
	}
		printf ("%s",cp) ;
		
}
void pushA(float ValOperand){
	if(SPA == MaxStack){
		printf("ERROR STACK OVER FLOW!!!\n");
		
	}
	else{
		SPA = SPA+1;
		ValOperandST[SPA]=ValOperand;
	}
}
float popA(){
	float ValOperand;
	if(SPA != 0){
		ValOperand=ValOperandST[SPA];
		SPA--;
		return(ValOperand);
	}
	else
		printf("\nERROR STACK UNDER FLOW!!!...\n");
}
void CalPostfix(char postfix[80]){
	float pop1,pop2,value;
	int i,len,count,x,y,w=3,e=4;
	char ch,A[80];
	len = strlen(postfix);
	strcpy(A,postfix);
	printf("Postfix = %s\n",A);
	
	for(i=0;i<=len-1;i++){
		ch = postfix[i];
		if(strchr("+-*/^",ch)==0)
		{
		/*	if((ch >= 48) && ( ch <= 57) ){	
				ValPostfix[i] = int(ch)-48;	
			}else{*/
				bool check = 0;
				int j = i-1;
				while (j>=0)
				{
					if((int(postfix[j]) == ch) || ((int(postfix[j])+32) == ch) || ((int(postfix[j])-32) == ch))
					{
						ValPostfix[i] = ValPostfix[j];
						check = 1;
						break;
					}
					j--;
				}
				if( check == 0)
				{	x=0;y=0;
					for (count=len; count>-1; count--){
			               if ((postfix[count]=='('))
			                    x++;
			               if ((postfix[count]==')'))
			                    y++;
         			}
					if(x==y){
						printf("\nAssigh Number to %c :",ch);
						scanf("%f",&ValPostfix[i]);
					}
					else{
						printf("\nError Brackets over \n");
						break ;
						
					}	
				}
			}
		}
//	}
	
	for(i=0;i<=len-1;i++){
		ch=postfix[i];
		if(strchr("+-*/^",ch)==0){
			pushA(ValPostfix[i]);
		}
		else{
			pop1=popA();
			pop2=popA();
			
			switch(ch)
			{
				case'+' :	value=pop2+pop1;
							pushA(value);
							break;
				case'-' :	value=pop2-pop1;
							pushA(value);
							break;	
				case'*' :	value=pop2*pop1;
							pushA(value);
							break;
				case'/' :	value=pop2/pop1;
							pushA(value);
							break;
				case'^' :	value=pow(pop2,pop1);
							pushA(value);
							break;		
			}
		}
	}			
	printf("\nANS = %f",popA());
}


int chackoperan(char infix2[80]){
	char ch1[80],ch2[80];
	int len,i,x,y;
	len = strlen(infix1);
	strcpy(ch1,infix2);
	strcpy(ch2,infix2);
	for( i=0 ; i<=len ; i++){
		x=changeIP10(ch1[i]);
		y=changeIP10(ch2[i+1]);
		if(x>0 && y>0){
			printf("Error Operator\n");
			return 0;
		}		
	}
	return 1;
}

int chackoperator(char infix3[80]){
	char ch1[80],ch2[80];
	int len,i,x,y;
	len = strlen(infix1);
	for( i=0 ; i<=len ; i++){
		strcpy(ch1,infix3);
		strcpy(ch2,infix3);
		
		if(ch1[i]=='A' || ch1[i]=='B' || ch1[i]=='C' || ch1[i]=='D' || ch1[i]=='E' || ch1[i]=='F' || ch1[i]=='G' || ch1[i]=='H' || ch1[i]=='I' || ch1[i]=='J' || ch1[i]=='K' || ch1[i]=='L' || ch1[i]=='M' || ch1[i]=='N' || ch1[i]=='O' || ch1[i]=='P' || ch1[i]=='Q' || ch1[i]=='R' || ch1[i]=='S' || ch1[i]=='T' || ch1[i]=='U' || ch1[i]=='V' || ch1[i]=='W' || ch1[i]=='X' || ch1[i]=='Y' || ch1[i]=='Z'){
			if(ch2[i+1]=='A' || ch2[i+1]=='B' || ch2[i+1]=='C' || ch2[i+1]=='D' || ch2[i+1]=='E' || ch2[i+1]=='F' || ch2[i+1]=='G' || ch2[i+1]=='H' || ch2[i+1]=='I' || ch2[i+1]=='J' || ch2[i+1]=='K' || ch2[i+1]=='L' || ch2[i+1]=='M' || ch2[i+1]=='N' || ch2[i+1]=='O' || ch2[i+1]=='P' || ch2[i+1]=='Q' || ch2[i+1]=='R' || ch2[i+1]=='S' || ch2[i+1]=='T' || ch2[i+1]=='U' || ch2[i+1]=='V' || ch2[i+1]=='W' || ch2[i+1]=='X' || ch2[i+1]=='Y' || ch2[i+1]=='Z'){
				printf("\nError not Operator\n");
				return 0;
			}
		}
		return 1;
	}
}

int vonloop(){
	int b,c;
		printf ("== INFIX TO POSTFIX PROGRAME ==\n\n") ;
		printf ("Input INFIX : ") ;
		scanf ("%s",infix1) ;
		infixTOpostfix(infix1);
		printf("\n\nPOSTFIX CALCULATION PROGRAM\n");
		printf("===========================\n");
		b=chackoperan(infix1);
		c=chackoperator(infix1);
		if(c==1){
			if(b==1){
			CalPostfix(cp);
			}	
		}
		
}


int main(){
//	for(int i=0;i<10;i++){
		vonloop();
		getch();
		system("cls");
//	}
	
	return 0 ;
}
