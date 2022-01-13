#include "monty.h"
/**
 * exec_op - called by main to execute opcode.
 * @node: pointer to linked list
 * @tmp: temp of user input
 * @len: len of temp
 * @file: pointer to file to read from
 *
 * Return: void
 */
void exec_op(stack_t *node, char *tmp, size_t len, FILE *file)
{
	unsigned int line = 0;
	char *temp = NULL, *str = NULL;

	while (getline(&tmp, &len, file) != -1)
	{
		line++;
		temp = strtok(tmp, SEPARATOR);
		if (temp == NULL || strncmp(temp, "#", TRUE) == 0)
			continue;
		if (strcmp(temp, "push") == 0)
		{
			str = strtok(NULL, SEPARATOR);
			push(&node, line, str);
		}
		else
			get_op(temp, &node, line);
	}
	fclose(file);
	freedom(&node);
	free(tmp);
}
