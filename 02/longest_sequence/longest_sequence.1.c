#include <stdio.h>
typedef struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
}Node;

#define MAX(a, b) (a > b ? a : b)

int	recurse(struct s_node *node, int value, int deep)
{
    if (!node)
        return 0;
    int c = 1;
    if (node->value == value + 1)
        c = deep + 1;
    return (MAX(MAX(recurse(node->left, node->value, c), recurse(node->right, node->value, c)), c));
}

int	longest_sequence(struct s_node *node)
{
	if (!node)
		return 0;
	return recurse(node, ~0u >> 1, 0);
	// return (node->value);
}

//  Test Main

#include <stdio.h>
#include <stdlib.h>
Node* b(int v) {
    Node* new = malloc(sizeof(Node));
    new->value = v;
    new->left = 0;
    new->right = 0;
    return new;
}
int main() {
    Node* n = b(10);
    n->left = b(5);
    n->left->left = b(6);
    n->left->left->left = b(7);
    n->left->left->right = b(13);
    n->left->right = b(9);
    printf("%d, target is 3\n", longest_sequence(n));

    Node* m = b(5);
    m->left = b(6);
    m->right = b(4);
    m->right->left = b(9);
    m->right->left->left = b(3);
    m->right->left->right = b(2);
    m->right->right = b(3);
    m->right->right->right = b(2);
    printf("%d, target is 2\n", longest_sequence(m));

    Node* o = b(30);
    o->left = b(15);
    o->left->left = b(61);
    o->right = b(41);
    o->right->right = b(80);
    printf("%d, target is 1\n", longest_sequence(o));

    printf("%d, target is NULL\n", longest_sequence(0));

    return 0; 
}
