#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *front;
struct Node *rear;
int isEmpty(){
	if(front==NULL && rear==NULL) return 1;
	return 0;
}
void enqueue(int x){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(isEmpty()){
		front = temp;
		rear = temp;
	}else{
		rear->next = temp;
		rear = temp;
	}
}
int dequeue(){
	if(isEmpty()) return ;
	int x = front->data;
	front = front->next;
	return x;
}
int getFront(){
	if(isEmpty()) return ;
	return front->data;
}
void printQueue(){
	struct Node *temp = front;
	while(temp){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main(){
	front = NULL;
	rear = NULL;
	int i;
	for(i=1;i<=10;i++){
		enqueue(i);
	}
	printf("%d\n", front->data);
	printf("%d\n", rear->data);
//	printQueue();
}
