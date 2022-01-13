 #include "monty.h"

/**
 * push - pushes an item to the top of the stack.
 * @node: linked list
 * @line: line count
 * @str: string containing values stack items
 * Return: void or failure
 */
void push(stack_t **node, unsigned int line, char *str)
{
	stack_t *tmp = NULL;
	int idx;

	if (str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	for (idx = 0; str[idx]; idx++)
	{
		if (str[0] == '-' && idx == 0)
			continue;
		if (isdigit(str[idx]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
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
	if (*node)
	{
		tmp->next = *node;
		(*node)->prev = tmp;
	}
	*node = tmp;
}

/**
 * pall - prints the value of all items on the stack
 * @node: linked list
 * @line: line count
 * Return: void
 */
void pall(stack_t **node, unsigned int line)
{
	stack_t *tmp = *node;
	(void)line;

	if (node == NULL || *node == NULL)
	{
		return;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @node: linked list.
 * @line: line count.
 * Return: void
 */

void pint (stack_t **node, unsigned int line)
{
	if (*node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node)->n);
}
