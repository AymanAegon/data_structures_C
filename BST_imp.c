#include <stdio.h>
#include <stdlib.h>

int getMax(int a,int b){
	if(a>b) return a;
	return b;
}
struct Node{
	int data;
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
int search(int x,struct Node* temp){
	if(temp == NULL) return 0;
	if(temp->data == x) return 1;
	if(temp->data < x) return search(x,temp->right);
	else return search(x,temp->left);
}
struct Node* getNode(struct Node* temp,int x){
	if(temp == NULL) return NULL;
	if(temp->data == x) return temp;
	else if(temp->data < x) return getNode(temp->right,x);
	else return getNode(temp->left,x);
}
struct Node* getParent(struct Node* temp,struct Node* parent){
	if(parent == NULL || parent == temp) return NULL;
	if(parent->left==temp || parent->right==temp) return parent;
	else if(parent->data < temp->data) return getParent(temp,parent->right);
	else return getParent(temp,parent->left);
	
}	
int max(struct Node* temp){
	if(temp == NULL) return 0;
	else if(temp->right == NULL) return temp->data;
	return max(temp->right);
}	
int min(struct Node* temp){
	if(temp == NULL) return 0;
	else if(temp->left == NULL) return temp->data;
	return min(temp->left);
}
int findHeight(struct Node* temp){
	if(temp==NULL) return -1;
	if(temp->right){
		return getMax(findHeight(temp->right),findHeight(temp->left))+1;
	}
	return 0;
}
struct Node *removeNode(struct Node *temp, int x){
	if(temp==NULL) return NULL;
	else if(temp->data<x) temp->right = removeNode(temp->right,x);
	else if(temp->data>x) temp->left = removeNode(temp->left,x);
	else {
		if(temp->left==NULL && temp->right==NULL){
			free(temp);
			temp = NULL;
		}else if(!temp->right){
			struct Node *parent = temp;
			temp = temp->left;
			free(parent);
		}else if(!temp->left){
			struct Node *parent = temp;
			temp = temp->right;
			free(parent);
		}else{
			temp->data = min(temp->right);
			temp->right = removeNode(temp->right,temp->data);
		}
		return temp;
	}
}
void inorder(struct Node *temp){
	if(temp){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
int inorderSucc(struct Node *temp,int x){
	struct Node *parent = NULL;
	while(temp->data != x){
		if(temp->data > x){
			parent = temp;
			temp = temp->left;
		}
		if(temp->data < x) temp = temp->right;
	}
	if(temp->right) return min(temp->right);
	else{
		if(parent) return parent->data;
		return x;
	}
}

int main(){
	
	root = NULL;
	
	root = insert(15,root);
	root = insert(10,root);
	root = insert(20,root);
	root = insert(25,root);
	root = insert(27,root);
	root = insert(17,root);
	root = insert(16,root);
	root = insert(8,root);
	root = insert(6,root);
	root = insert(11,root);
	root = insert(12,root);
//	removeNode(root,8);
	inorder(root);
	
	int x = 12;
	printf("\n%d -> %d",x,inorderSucc(root,x));
	
	
}
