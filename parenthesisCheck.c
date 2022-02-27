#include <stdio.h>
#include <stdlib.h>
#define n 20
struct Node{
	char data;
	struct Node *bottom;
};
struct Node *top = NULL;
int height = 0;
void push(char x){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->bottom = top;
	top = temp;
	height++;
}
int isEmpty(){
	if(height == 0) return 1;
	return 0;
}
void pop(){
	if(isEmpty()){
		printf("Error: List is empty!\n");
		return;
	}
	struct Node *temp = top;
	top = top->bottom;
	free(temp);
	height--;
}
char getTop(){
	if(isEmpty()){
		printf("Error: Listis empty!\n");
		return;
	}
	return top->data;
}
void printList(){
	struct Node *temp = top;
	while(temp){
		printf("%c\n",temp->data);
		temp  = temp->bottom;
	}
}
char opp(char c){
	if(c=='(') return ')';
	if(c==')') return '(';
	if(c=='{') return '}';
	if(c=='}') return '{';
	if(c=='[') return ']';
	if(c==']') return '[';
}
int itemOf(char c){
	int i = 0;
	char a[6] = {"{[()]}"};
	while(i<6){
		if(c == *(a+i)) return 1;
		i++;
	}
	return 0;
}
int isClosing(char c){
	int i = 0;
	char a[3] = {")]}"};
	while(i<3){
		if(c == *(a+i)) return 1;
		i++;
	}
	return 0;
}
int isBalanced(char *a){
	int i;
	for(i=0;i<n;i++){
		if(itemOf(*(a+i))){
			if(isEmpty()){
				if(isClosing(*(a+i))) return 0;
				push(*(a+i));
			}else{
				if((*(a+i)) == opp(getTop())){
					pop();
				}else{
					push(*(a+i));
				}
			}
		}
	}
	if(isEmpty()) return 1;
	return 0;
}
int main(){
	int i;
	char a[n] = {")("};
	
	if(isBalanced(a)){
		printf("Parentheses are balanced");
	}else{
		printf("Parentheses are not balanced");
	}
	
}
