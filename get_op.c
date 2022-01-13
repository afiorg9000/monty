#include "monty.h"
/**
 * get_op - struct to compare input to a list of opcode function.
 * @opstring: opcode input
 * @stack: linked list
 * @line: line count of instruction
 *
 * Return: 0 for success, 1 otherwise
 */
int get_op(char *opstring, stack_t **stack, unsigned int line)
{
	int idx = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	for (idx = 0; opcodes[idx].opcode; idx++)
	{
		if (strcmp(opstring, opcodes[idx].opcode) == 0)
		{
			(opcodes[idx].f)(stack, line);
			return (EXIT_SUCCESS);
		}
	}
	freedom(stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opstring);
	exit(EXIT_FAILURE);
}
