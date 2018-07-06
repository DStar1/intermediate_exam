typedef struct s_node {
    int value;
    struct s_node *next;
}Node;

int is_looping(struct s_node *node)
{
	Node* o = node;
	Node* s = node;
	while (o && s)
	{
		o = o->next;
		s = s->next;
		//always iterating one more in one of the lists, and eventually they will converge
		if (o)
			o = o->next;
		// If neither ends, and they equal eachother, it is looping
		if (o && s && s == o)
			return 1;
	}
	return 0;
}

//  Test Main

#include <stdlib.h>
#include <stdio.h>
Node* b(int v) {
	Node* new = malloc(sizeof(Node));
	new->value = v;
	new->next = 0;
	return new;
}
int main() {

	Node* a = b(1);

	a->next = b(2);
	a->next->next = b(3);
	a->next->next->next = b(4);
	a->next->next->next->next = a;

	printf("%d\n", is_looping(a));
	//        while(a){
	//          printf("%p = %d | ", a, a->value);
	//          a = a->next;
	//        }


	Node* c = b(1);
	c->next = b(2);
	c->next->next = b(3);
	c->next->next->next = b(4);

	printf("%d\n", is_looping(c));
	//	while(c){
	//	  printf("%p = %d | ", c, c->value);
	//	  c = c->next;
	//	}
	return 0;
}
