#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *head;
int length;
struct Node* getNewNode(int x){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void insertAtHead(int x){
	struct Node *newNode = getNewNode(x);
	if(head){
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}else{
		head = newNode;
	}
	length++;
}
void add(int x){
	struct Node *newNode = getNewNode(x);
	if(head){
		struct Node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}else{
		head = newNode;
	}
	length++;
}
void insertAt(int x,int n){
	if(n>=length){
		add(x);
	}else if(n<=0){
		insertAtHead(x);
	}else{
		struct Node *newNode = getNewNode(x);
		struct Node *prevTemp, *temp = head;
		int i=0;
		while(i<n){
			temp = temp->next;
			i++;
		}
		prevTemp = temp->prev;
		temp->prev = newNode;
		prevTemp->next = newNode;
		newNode->next = temp;
	}
}
void reverseList(struct Node *temp){
	struct Node *x;
	if(temp){
		x = temp->next;
		temp->next = temp->prev;
		temp->prev = x;
		head = temp;
		reverseList(temp->prev);
	}
}
void pop(){
	struct Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	struct Node* temp0 = temp->prev;
	temp0->next = NULL;
	free(temp);
	length--;
}
void removeItem(int n){
	if(n>=length){
		pop(); return;
	}else if(n<=0){
		head = head->next;
		head->prev = NULL;
	}else{
		struct Node* temp = head;
		int i=0;
		while(i<n){
			temp = temp->next;
			i++;
		}
		struct Node* next = temp->next;
		struct Node* prev = temp->prev;
		next->prev = prev;
		prev->next = next;
		free(temp);
	}
	length--;
}
void printList(){	//	printing the list
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
//	printf("\n/*length = %d"length*/);
	printf("\n");
}
void printListRec(struct Node *temp){	//	printing the list
	if(temp){
		printf("%d ",temp->data);
		printListRec(temp->next);
	}else{
		printf("\nlength = %d",length);
		printf("\n");
	}
}

int main(){
	head = NULL;
	length = 0;		
	int i;
	for(i=10;i>0;i=i-1){
		add(i);
	}
	printListRec(head);
	removeItem(10);
	printListRec(head);
}






