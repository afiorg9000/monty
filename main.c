#include "monty.h"

globalvar_t global = {NULL, 1, NULL, NULL};

/**
 * main - monty bytecode interpreter.
 * Reads monty file and runs opcodes
 * @argc: number of arguments passed.
 * @argv: double pointer array which points to each argument passed to the program
 * Return: exit success
 */
/*If no arguments are supplied, argc will be one, and if you pass one argument 
 * then argc is set at 2.*/

int main(int argc, char **argv)
{
	if (argc != 2)
		/*If the user does not give any file or more than one argument to your program,
		 * print the error message USAGE: monty file, followed by a new line,
		 * and exit with the status EXIT_FAILURE*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_sweep(argv[1]);
	return (0);
}

/**
 * file_sweep - sweeps the monty file line by line.
 */

void file_sweep(char *mfile)
{
	char *opcodes = NULL;
	size_t len = 0;
	unsigned int count = 1;
	/*If, for any reason, it’s not possible to open the file, 
	 * print the error message Error: Can't open file <file>, 
	 * followed by a new line, and exit with the status EXIT_FAILURE
	 * where <file> is the name of the file*/
	global.file = fopen(mfile, "r");
	if (global.file == NULL)/*Opens the monty file passed by the user*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", mfile);
		exit(EXIT_FAILURE);
	}

	while (getline(&global.string, &len, global.file) != -1)
	{
		opcodes = strtok(global.string, "\t\n");
		if (opcodes == NULL)
		{
			count++;
			continue;
		}
		if (global.string[0] != '#')
		{
			if (strncmp(opcodes, "push", 4) == 0)
			{
				opcodes = strtok(NULL," \t\n");
			}
			else
			{
				global.line = count;
				(*get_op(opcodes))(&global.stack, count);
			}
		}
		count++;
	}
	freedom();
}

/**
 * get_op - struct to compare input to a list of cmds and then execute if validalls the corresponding opcode function to their string.						 * @opcode: the opcode to run.
 * @stack:our linked list.
 * @line: line count of instruction.
 */

void (*get_op(char *opstring))(stack_t **stack, unsigned int line)
{
	int tmp;

	instruction_t opcodes[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	for (tmp = 0; opcodes[tmp].opcode; tmp++)
	{
		if (strcmp(opstring, opcodes[tmp].opcode)== 0)
			return(opcodes[tmp].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", global.line, global.string);
	freedom();
	return (NULL);
}

/**
 * free - frees stack
 */

void freedom(void)
{
	stack_t *tmp = NULL;

	while (global.stack)
	{
		tmp = global.stack;
		global.stack = (global.stack)->next;
		free(tmp);/*frees a dlistint_t list.*/
		
		free(global.string);
		fclose(global.file);
	}
}
