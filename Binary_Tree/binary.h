#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SPACE 10

struct Node{
	int data;
	int height;
	struct Node *left;
	struct Node *right;
};

struct Node* add_node(struct Node *tree, int data);
struct Node* new_node(int data);
void print_tree(struct Node *tree, int space);
int search_tree(struct Node *head, int data);
int get_height(struct Node *tree);
int get_balance(struct Node *tree);
int get_max(int a, int b);
struct Node* rr(struct Node *root);
struct Node* ll(struct Node *root);
struct Node* create_tree(struct Node *head, int x);