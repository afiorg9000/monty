#ifndef _GNU_SOURCE
#define _GNU_SOURCE/*getline*/
#define TRUE 1
#define FALSE 0
#define SEPARATOR "\n\t\r " /*spaces*/
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
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main prototypes */
int main(int argc, char **argv);
int get_op(char *tmp, stack_t **stack, unsigned int line);
void exec_op(stack_t *node, char *tmp, size_t len, FILE *file);
void freedom(stack_t **node);

/* opcode prototypes */
void push(stack_t **node, unsigned int line, char *str);
void pall(stack_t **node, unsigned int line);
void pint(stack_t **node, unsigned int line);
void pop(stack_t **node, unsigned int line);
void swap(stack_t **node, unsigned int line);
void add(stack_t **node, unsigned int line);
void nop(stack_t **node, unsigned int line);

#endif

