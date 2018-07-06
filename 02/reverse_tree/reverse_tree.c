typedef struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
}Node;

void reverse_tree(struct s_node *root)
{
	if (!root)
		return;
	Node* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}

// Test main
#include <stdio.h>
#include <stdlib.h>

void pr_tree(struct s_node *root)
{
	if (!root)
		return;
	printf("%d", root->value);
	pr_tree(root->left);
	pr_tree(root->right);
}
void pr_tree_mirror(struct s_node *root)
{
	if (!root)
		return;
	printf("%d", root->value);
	pr_tree_mirror(root->right);
	pr_tree_mirror(root->left);
}

Node* b(int i)
{
	Node* new = malloc(sizeof(Node));
	new->value = i;
	new->right = 0;
	new->left = 0;
	return (new);
}

int main()
{
	Node* tree = b(1);
	tree->right = b(2);
	tree->left = b(2);
	tree->right->right = b(5);
	tree->left->left = b(2);
	tree->left->right = b(3);
	tree->left->right->left = b(2);
	// reverse_tree(tree);



	//test
	pr_tree(tree);//orig should be like mirror after reverse tree
	printf(" | orig\n");
	pr_tree_mirror(tree);
	printf(" | opposite\n");
	reverse_tree(tree);
	pr_tree(tree);
	printf(" | orig reversed (should be same as opposite)\n");
	return (0);
}
