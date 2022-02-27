#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30

struct Node{
	int data;
	struct Node *right;
	struct Node *left;
};
struct Node *root;

struct Node *queue[MAX_SIZE];
int front=-1, rear=-1;
int isEmpty(){
	if(rear==-1 && front==-1) return 1;
	return 0;
}
int isFull(){
	if(isEmpty()) return 0;
	int i = front%MAX_SIZE;
	int j = (rear+1)%MAX_SIZE;
	if(i-j == 0) return 1;
	return 0;
}
void enqueue(struct Node* temp){
	if(isFull()){
		printf("Queue is full !!");
		return;
	}
	if(isEmpty()){
		front = 0;
		rear = 0;
	}else if(rear==MAX_SIZE-1 && front>0){
		rear = 0;
	}else{
		rear++;
	}
	queue[rear] = temp;
}
struct Node* dequeue(){
	if(isEmpty()) return NULL;
	struct Node* temp = queue[front];
	queue[front] = 0;
	if(front == rear){
		front = -1;
		rear = -1;
		return temp;
	}
	front = (front+1)%MAX_SIZE;
	return temp;
}

struct Node* insert(int x,struct Node* temp){
	
	if(temp == NULL){
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->right = NULL;
		newNode->left = NULL;
		temp = newNode;
	}else if(temp->data < x){
		temp->right = insert(x,temp->right);
	}else{
		temp->left = insert(x,temp->left);
	}
	return temp;
}
void travers2(){	//	printing the list recurcivly
	if(isEmpty()) return;
	struct Node* temp = dequeue();
	printf("%d ",temp->data);
	if(temp->left) enqueue(temp->left);
	if(temp->right) enqueue(temp->right);
	travers2();
}
void travers(){	//	printing the list recurcivly
	enqueue(root);
	while(!isEmpty()){
		struct Node* temp = dequeue();
		printf("%d ",temp->data);
		if(temp->left) enqueue(temp->left);
		if(temp->right) enqueue(temp->right);
	}
}

int main(){
	
	root = NULL;
	
	root = insert(10,root);
	root = insert(8,root);
	root = insert(9,root);
	root = insert(17,root);
	
	travers();
	
}
