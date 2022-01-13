#include "monty.h"

/**
 * push - Pushes an item to the top of the stack
 * @str: string containing values stack items
 */
void push(stack_t **node, unsigned int line_number)
{
	char *str;
	int idx;
	stack_t *tmp = NULL;

	str = malloc(12 * sizeof(char));
	if (str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freedom();
		exit(EXIT_FAILURE);
	}
	for (idx = 0; str[idx]; idx++)
	{
		if (str[0] == '-' && idx == 0)
			continue;
		if (isdigit(str[idx]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	tmp = malloc(sizeof(node));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(str);
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*node == NULL)
	{
		tmp->next = *node;
		*node = tmp;
	}
	else
	{
		tmp->next = *node;
		(*node)->prev = tmp;
		*node = tmp;
	}
}

/**
 * pall - prints the value of all items on the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: the current line number being processed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

