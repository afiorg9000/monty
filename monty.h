#ifndef _GNU_SOURCE
#define _GNU_SOURCE/*getline*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> /*isdigit*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globalvar_s - container for globally used variables
 * @file: The monty file being read
 * @lineNum: The current line number being read
 * @stack: The stack being used
 * @line: The current line being read
 */

typedef struct globalvar_s
{
	FILE *file;
	unsigned int line;
	stack_t *stack;
	char *string;
} globalvar_t;

extern globalvar_t global;
/*main protoypes*/
int main(int argc, char **argv);
void file_sweep(char *file);
void (*get_op(char *opstring))(stack_t **stack, unsigned int line);
void freedom(void);
/*opcode protoypes*/
void push(stack_t **node, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
