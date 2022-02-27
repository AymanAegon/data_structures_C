#include <stdio.h>
#include <stdlib.h>
#define n 12

int strToInt(char *s){
	int result=0, sign=0;
	if(*s == '-'){
		sign=1;
		s++;
	}
	while(*s){
		result = result*10 + *s - 48;
		s++;
	}
	if(sign) return -result;
	return result;
}
int toInt(char c){
	return c - 48;
}
int isOpp(char c){
	char opp[4] = {"+-*/"};
	int i=0;
	while(i<4){
		if(c == opp[i]) return 1;
		i++;
	}
	return 0;
}
int isNum(char c){
	char x[10] = {"0123456789"};
	int i=0;
	while(i<11){
		if(c == x[i]) return 1;
		i++;
	}return 0;
}
int calc(int n1,char opp,int n2){
	if(opp == '+') return n1+n2;
	if(opp == '-') return n1-n2;
	if(opp == '*') return n1*n2;
	if(opp == '/') return n1/n2;
}
struct Node{
	int data;
	struct Node *link;
};
struct Node *top = NULL;
void push(int x){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->link = top;
	top = temp;
}
int pop(){
	if(top){
		int a = top->data;
		top = top->link;
		return a;
	}
	return ;
}
int isEmpty(){
	if(top) return 0;
	return 1;
}
void printList(){					//	printing the list
	struct Node* temp = top;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
int postfix(char *s){
	int i=0;
	while(!isNum( *(s+i) )){
		i++;
	}
	push(toInt(*(s+i)));
	for(i=i+1;i<n;i++){
		if(isNum( *(s+i) )){		//pushing numders
			if(isNum( *(s+i-1) )){
				top->data = top->data*10 + toInt(*(s+i));
			}else{
				push(toInt(*(s+i)));
			}
		}else if(isOpp( *(s+i) )){	//calculating the two numbers
			int n2 = pop();
			int n1 = pop();
			push(calc(n1,*(s+i),n2));
		}
	}
	return top->data;
}
int prefix(char *s){
	int i=n-1;
	while(!isNum( *(s+i) )){
		i--;
	}
	push(toInt(*(s+i)));
	for(i=i-1;i>=0;i--){
		if(isNum( *(s+i) )){		//pushing numders
			if(isNum( *(s+i+1) )){
				top->data = top->data*10 + toInt(*(s+i));
			}else{
				push(toInt(*(s+i)));
			}
		}else if(isOpp( *(s+i) )){	//calculating the two numbers
			int n1 = pop();
			int n2 = pop();
			push(calc(n1,*(s+i),n2));
		}
	}
	return top->data;
}

int main(){
	char a[n] = {"2 3*5 4*+9- "};
	char b[n] = {"-+*2 3*5 4 9"};
	printf(" %s\n",a);
	printf("postfix = %d\n",postfix(a));
	printf("prefix = %d\n",prefix(b));
	
	
}
