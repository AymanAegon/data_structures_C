#include <stdio.h>
#include <stdlib.h>

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
void inorder(struct Node *temp){
	if(temp){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
int isBST(struct Node *temp){
	if(!temp) return 1;
	int rightTree = 1;
	int leftTree = 1;
	if(temp->right){
		struct Node *tempR = temp->right;
		if(temp->data <= tempR->data && isBST(tempR)) rightTree = 1;
		else rightTree = 0;
	}
	if(temp->left){
		struct Node *tempL = temp->left;
		if(temp->data >= tempL->data && isBST(tempL)) leftTree = 1;
		else leftTree = 0;
	}
	if(leftTree==1 && rightTree==1) return 1;
	return 0;
}
int isBST2(struct Node *temp,int minValue,int maxValue){
	if(!temp) return 1;
	
	if(temp->data<maxValue &&
		temp->data>minValue &&
		isBST2(temp->right,temp->data,maxValue) &&
		isBST2(temp->left,minValue,temp->data)
		){
		return 1;
	}else return 0;
}

int main(){
	
	root = NULL;
	
	root = insert(10,root);
	root = insert(8,root);
	root = insert(17,root);
	root = insert(6,root);
	root = insert(9,root);
	
	inorder(root);
	printf("\n%d ",isBST(root));
	printf("\n%d ",isBST2(root,-100,100));
	
}
