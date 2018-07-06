#include <stdlib.h>
#include <stdio.h>

    struct s_node {
        void *content;
        struct s_node *next;
    };

    struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };

struct s_queue *init(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, void *content)//practice
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	if (!queue->first)
		queue->first = new;
	if (queue->last)
		queue->last->next = new;
	queue->last = new;
}

void *dequeue(struct s_queue *queue)//practice
{
	if (queue->first)
	{
		struct s_node *tmp = queue->first;
		void *content = tmp->content;
		queue->first = queue->first->next;
		if (!queue->first)
			queue->last  = NULL;
		free(tmp);
		return content;
	}
	return NULL;
}

void *peek(struct s_queue *queue)
{
	if (queue->first)
		return (queue->first->content);
	return NULL;
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return 1;
	return 0;
}

//Test main
#include <stdio.h>
int main() {

	struct s_queue* q = init();

	printf("Empty? %d\n", isEmpty(q));
	printf("Enqueueing 'Hello'\n");
	enqueue(q, "Hello");
	printf("Empty? %d\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Enqueueing 'World'\n");
	enqueue(q, "World");
	printf("Empty? %d\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Enqueueing ':)'\n");
	enqueue(q, ":)");
	printf("Empty? %d\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Empty? %d\n", isEmpty(q));

	return 0;	
}
