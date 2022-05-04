#include "binary.h"

int main(int argc, char **argv)
{
	struct Node *head = NULL;
	int n = 1, x, t;
	printf("Program for binary tree\n");

	
	while(n!=0){
		printf("\n");
		printf("1) add node to tree\n");
		printf("2) print tree\n");
		printf("3) search from tree\n");
		printf("4) add random numbers\n");
		printf("0) end\n\n");
		printf("Choice: ");
		scanf("%d", &n);
		if(n==0){
			break;
		}else if(n==1){
			printf("Give number: ");
			scanf("%d", &x);
			head = add_node(head, x);
			print_tree(head, 0);
		}else if(n==2){
			print_tree(head, 0);
		}else if(n==3){
			printf("Give number to search: ");
			scanf("%d", &x);
			t = search_tree(head, x);
			if(t==1){
				printf("Number %d is in the tree\n", x);
			}else{
				printf("Number %d is not in the tree\n", x);
			}
		}else if(n==4){
			printf("How many numbers: ");
			scanf("%d", &x);
			head = create_tree(head, x);
			print_tree(head, 0);
		}
	}
	printf("End of program.\n");
	return 0;
}
