#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @node: linked list
 * @line: line count
 * Return: void
 */
void add(stack_t **node, unsigned int line)
{
	stack_t *new;

	if (*node == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		freedom(node);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*node)->next->n += (*node)->n;
		new = *node;
		*node = (*node)->next;
		(*node)->prev = NULL;
		free(new);
	}
}

/**
 * nop - doesn’t do anything.
 * @node: linked list.
 * @line: line count.
 * Return: void
 */
void nop(stack_t **node, unsigned int line)
{
	(void)node;
	(void)line;
}
