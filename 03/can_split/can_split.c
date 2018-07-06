typedef struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
}Node;

#define MAX(a, b) a > b ? a : b

int count(struct s_node *root)
{
    if (!root)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

int recurs(struct s_node *n, int tot)
{
    if (!n)
        return 0;
    if (count(n) == tot - count(n))
        return 1;
    return MAX(recurs(n->left, tot), recurs(n->right, tot));
}

int can_split(struct s_node *n)
{
    int tot = count(n);
    return recurs(n, tot);
}

#include <stdlib.h>
#include <stdio.h>

Node* b(int n)
{
    Node *node = malloc(sizeof(Node));
    node->value = n;
    node->left = node->right = 0;
    return node;
}

int main()
{
    // Node *new = b(28);
    // new->left = b(51);
    // new->left->left = b(26);
    // new->left->right = b(48);
    // new->left->left->left = b(76);
    // new->left->left->right = b(13);
    // // new->left->left->right->left = b(13);
    // printf("%d\n", can_split(new));
    Node* ex1 = b(28);
    ex1->left = b(51);
    ex1->left->left = b(26);
    ex1->left->left->left = b(76);
    ex1->left->left->right = b(13);
    ex1->left->right = b(48);

    printf("%d\n", can_split(ex1));

    Node* ex2 = b(30);
    ex2->left = b(15);
    ex2->left->left = b(61);
    ex2->right = b(41);
    ex2->right->right = b(80);

    printf("%d\n", can_split(ex2));

    
    Node* ex3 = b(10);
    ex3->left = b(12);

    printf("%d\n", can_split(ex3));

    Node* ex4 = b(5);
    ex4->left = b(1);
    ex4->right = b(6);
    ex4->right->left = b(7);
    ex4->right->left->left = b(3);
    ex4->right->left->left = b(2);
    ex4->right->right = b(4);
    ex4->right->right->right = b(8);

    printf("%d\n", can_split(ex4));
    return 0;
}
