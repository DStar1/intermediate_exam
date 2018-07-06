#include <stdio.h>

    struct s_node {
        int           value;
        struct s_node **nodes;
    };

// typedef struct s_node {
//   int value;
//   struct s_node **nodes;
// } Node;

int height_tree(struct s_node *root)
{
	if (!root)
		return 0;
	int i = 0;
	int max = 0;
	while (root->nodes[i])
	{
		int tmp = 1 + height_tree(root->nodes[i]);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return max;
}

//  Test Main

#include <stdlib.h>

struct s_node* b(int v) {
    struct s_node *new = malloc(sizeof(struct s_node));
    new->value = v;
    new->nodes = malloc(100000);
    return new;
}
int main() {

    struct s_node* r = b(94);
    r->nodes[0] = b(34);
    r->nodes[1] = b(52);

    r->nodes[0]->nodes[0] = b(1);
    r->nodes[0]->nodes[1] = b(99);
    r->nodes[0]->nodes[2] = b(11);

    r->nodes[0]->nodes[1]->nodes[0] = b(13);

    printf("%d\n", height_tree(r));

    return 0;
}
