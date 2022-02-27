#include <stdio.h>
#include <stdlib.h>

int getMax(int a,int b){
	if(a>b) return a;
	return b;
}
struct Node{
	char data;
	struct Node *right;
	struct Node *left;
};
struct Node *root;
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
void preorder(struct Node *temp){
	if(temp){
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(struct Node *temp){
	if(temp){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
void postorder(struct Node *temp){
	if(temp){
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}

int main(){
	
	root = NULL;
	
	root = insert(3,root);
	root = insert(5,root);
	root = insert(1,root);
	root = insert(6,root);
	root = insert(4,root);
	root = insert(2,root);
	
//	preorder(root);
	inorder(root);
//	postorder(root);
}
