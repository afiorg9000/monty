#include "monty.h"
/**
 * main - monty bytecode interpreter that reads monty file and runs opcodes.
 * @argc: number of arguments passed.
 * @argv: double pointer array that points to arguments passed.
 * Return: exit success
 */
int main(int argc, char **argv)
{
	char *tmp = NULL;
	stack_t *node = NULL;
	size_t len = 0;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r"); /*opens monty file*/
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
		exec_op(node, tmp, len, file);
	return (EXIT_SUCCESS);
}

/**
 * freedom - free stack
 * @node: linked list
 *
 *
 * Return - void
 */
void freedom(stack_t **node)
{
	stack_t *tmp = NULL;

	while (*node)
	{
		tmp = *node;
		*node = (*node)->next;
		free(tmp);
	}
}
