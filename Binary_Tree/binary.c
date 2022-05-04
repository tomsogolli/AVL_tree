#include "binary.h"

struct Node* add_node(struct Node *tree, int data){
	int balance;
	if(tree==NULL){
		return new_node(data);
	}
	if(data < tree->data){
		tree->left = add_node(tree->left, data);
	}else if(data > tree->data){
		tree->right = add_node(tree->right, data);
	}else{
		return tree;
	}
	tree->height = get_height(tree);
	balance = get_balance(tree);
	
	// LL case
	if(balance > 1 && data < tree->left->data){
		return rr(tree); 
	}
	// RR case
	if(balance < -1 && data > tree->right->data){
		return ll(tree);
	}
		
	// LR case
	if(balance > 1 && data > tree->left->data){
		tree->left = ll(tree->left);
		return rr(tree);
	}
	
	// RL case
	if(balance < -1 && data < tree->right->data){
		tree->right = rr(tree->right);
		return ll(tree);
	}
	
	return tree;
}
struct Node* new_node(int data){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 0;
	return node;
	
}

struct Node* rr(struct Node *root){
	// right rotate
	struct Node *left = root->left;
	struct Node *lright = left->right;
	
	left->right = root;
	root->left = lright;
	
	left->height = get_height(left);
	root->height = get_height(root);
	return left;
}

struct Node* ll(struct Node *root){
	// left rotate
	struct Node *right = root->right;
	struct Node *rleft = right->left;
	
	right->left = root;
	root->right = rleft;
	
	right->height = get_height(right);
	root->height = get_height(root);
	return right;
}

int get_height(struct Node *tree){
	if(tree==NULL){
		return 0;
	}
	return(1 + get_max(get_height(tree->left), get_height(tree->right)));
}

int get_balance(struct Node *tree){
	if(tree==NULL){
		return 0;
	}
	return get_height(tree->left)-get_height(tree->right);
}

int get_max(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

void print_tree(struct Node *tree, int space){
	int i;
	if(tree==NULL){
		return;
	}
	space += SPACE;
	print_tree(tree->right, space);
	
	printf("\n");
	for(i=SPACE; i<space; i++){
		printf(" ");
	}
	printf("%d\n", tree->data);
	
	print_tree(tree->left, space);
}

int search_tree(struct Node *head, int data){
	while(head!=NULL){
		if(data==head->data){
			return 1;
		}else if(data<head->data){
			head = head->left;
		}else if(data>head->data){
			head = head->right;
		}
	}
	return 0;
}

struct Node* create_tree(struct Node *head, int x){
	int i, y;
	for(i=0;i<x;i++){
		y = rand() % 100;
		head = add_node(head, y);
	}
	return head;
}