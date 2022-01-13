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
	stack_t *new = NULL;
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
	new = malloc(sizeof(node));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(str);
	new->next = NULL;
	new->prev = NULL;
	if (*node)
	{
		new->next = *node;
		(*node)->prev = new;
	}
	*node = new;
}

/**
 * pall - prints the value of all items on the stack
 * @node: linked list
 * @line: line count
 * Return: void
 */
void pall(stack_t **node, unsigned int line)
{
	stack_t *new = *node;
	(void)line;

	if (node == NULL || *node == NULL)
	{
		return;
	}
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
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

/**
 * pop -  removes the top element of the stack.
 * @node: linked list.
 * @line: line count.
 * Return: void.
 */
void pop(stack_t **node, unsigned int line)
{
	stack_t *new = *node;

	if (*node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	new = new->next;
	free(*node);
	*node = new;
}

/**
 * swap - swaps the top two elements of the stack.
 * @node: linked list.
 * @line: line count.
 * Return: void
 */
void swap(stack_t **node, unsigned int line)
{
	int new;

	if (*node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		freedom(node);
		exit(EXIT_FAILURE);
	}
	else
	{
		new = (*node)->n;
		(*node)->n = (*node)->next->n;
		(*node)->next->n = new;
	}
}
