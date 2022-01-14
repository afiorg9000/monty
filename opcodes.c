#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @node: linked list
 * @line: line count
 * Return: void
 */
void add(stack_t **node, unsigned int line)
{
	if (*node == NULL || (*node)->next == NULL) /*if the stack contains less than two elements*/
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		freedom(node);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*node)->next->n += (*node)->n;
		(*node) = (*node)->next;
		free((*node)->prev);
		(*node)->prev = NULL;
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
	*node = *node;
	line = line;
}
