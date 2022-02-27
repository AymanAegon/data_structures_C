#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int queue[MAX_SIZE], front=-1, rear=-1;
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
void enqueue(int x){
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
	queue[rear] = x;
}
int dequeue(){
	if(isEmpty()) return -1;
	int temp = queue[front];
	queue[front] = 0;
	if(front == rear){
		front = -1;
		rear = -1;
		return temp;
	}
	front = (front+1)%MAX_SIZE;
	return temp;
}
int getFront(){
	if(!isEmpty()) return queue[front];
	return -1;
}
void show(){
	int i;
	for(i=0;i<=10;i++){
		printf("%d ", queue[i]);
	}
	printf("\n");
	for(i=1;i<=10;i++){
		printf("%d ", i);
	}
}
int main(){
	
	printf("\n%d\n", isFull());
}
