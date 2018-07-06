#include <stdlib.h>
#include <stdio.h>

    struct s_node {
        void          *content;
        struct s_node *next;
    };
    struct s_stack {
        struct s_node *top;
    };

struct s_stack *init(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	if (stack->top)
	{
		struct s_node *tmp = stack->top;
		void *content = tmp->content;
		stack->top = tmp->next;//stack->top->next;
		free(tmp);
		return content;
	}
	return NULL;
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (stack->top)
		return (stack->top->content);
	return NULL;
}

int isEmpty(struct s_stack *stack)
{
	if (stack->top == NULL)
		return 1;
	return 0;
}

//Test main
#include <stdio.h>
int main() {

	struct s_stack* s = init();

	printf("Empty? %d\n", isEmpty(s));
	puts("Pushing 'Hello'");
	push(s, "Hello");
	printf("Empty? %d\n", isEmpty(s));
	printf("Peeking: %s\n", peek(s));
	puts("Pushing 'World'");
	push(s, "World");
	printf("Empty? %d\n", isEmpty(s));
	printf("Peeking: %s\n", peek(s));
	puts("Pushing ':)'");
	push(s, ":)");
	printf("Empty? %d\n", isEmpty(s));
	printf("Peeking: %s\n", peek(s));

	printf("Popped: %s\n", pop(s));
	printf("Popped: %s\n", pop(s));
	printf("Popped: %s\n", pop(s));
	printf("Popped: %s\n", pop(s));
	printf("Empty? %d\n", isEmpty(s));

	return 0;
}
