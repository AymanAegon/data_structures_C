#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *head;	//	the head of the linked-list
int length; 		//	the length of the linked-list
void insertAt(int x,int n){	//	inserting item in a specific position
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	if(n<=0){
		head = temp;
		length++;
	}else{
		struct Node *temp1 = head;
		int i;
		for(i=0;i<n-1;i++){
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
		length++;
	}
}
void add(int x){	//	adding item into the list
	insertAt(x,length);
}
void Remove(int n){	//	removing the nth item of the list
	int i;
	struct Node *temp = head;
	if(n==0){
		head = temp->next;
		free(temp);
	}else if(n>0&&n<length){
		for(i=0;i<n-1;i++){
			temp = temp->next;
		}
		struct Node *temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}else{
		printf("index is invalid !!\n");
		return;
	}
	length--;
}
void pop(){			//	removing the last item of the list
	if(length==0){
		printf("List is empty !!\n");
		return;
	}
	Remove(length-1);
}
void reverse(){
	struct Node *prev, *temp, *next;
	temp = head;
	prev = NULL;
	while(temp != NULL){
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = temp;
}
void reverseRec(struct Node *temp){
	if(temp->next == NULL){
		head = temp;
		return;
	}
	reverseRec(temp->next);
	struct Node *temp1 = temp->next;
	temp1->next = temp;
	temp->next = NULL;
}
void printList(){	//	printing the list
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void printListRec(struct Node *temp){	//	printing the list recurcivly
	if(temp != NULL){
		printf("%d ",temp->data);
		printListRec(temp->next);
	}else{
		printf("\n");
	}
}
int main(){
	head = NULL;
	length = 0;
	
	add(2);
	add(4);
	add(6);
	add(8);
	printf("head = %d\n",head->data);
	printListRec(head);
	reverseRec(head);
	printListRec(head);
	printf("length = %d\n",length);
	
}
