#include <stdio.h>
#include <stdlib.h>
#define n 5

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
int hhp(char c1, char c2){
	if(c1=='*' || c1=='/') return 1;
	if(c2=='+' || c2=='-') return 0;
}

struct Node{
	char data;
	struct Node *link;
};
struct Node *top = NULL;
void push(char x){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->link = top;
	top = temp;
}
char pop(){
	if(top){
		char a = top->data;
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
		printf("%c ",temp->data);
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
char *infixToPostfix(char *s){
	int index=0,e=0,i;
	char arr[2*n];
	for(i=0; i<n; i++){
		if(isNum(s[i])){
			if(isNum(arr[index-1])){
				arr[index] = ' '; index++; e++;
			}
			arr[index] = s[i];
			index++;
		}else if(isOpp(s[i])){
			while(!isEmpty() && hhp(top->data,s[i])){
				arr[index] = pop();
				index++;
			}
			push(s[i]);
		}
	}
	while(!isEmpty()){
		arr[index] = pop();
		index++;
	}
	static char res[100];
	for(i=0; i<n+e; i++){
		res[i] = arr[i];
	}
	return res;
}
int main(){
//	char a[n] = {"2 3*5 4*+9- "};
	char a[n] = {"7*2+1"};
	int i;
	char *exp = infixToPostfix(a);
	
	for(i=0; i<2*n; i++){
		printf("%c",*(exp+i));
	}
//	printf(" = %d",postfix(exp));
}
