#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

/**
 * push - Pushes an element onto the stack.
 * @value: The value to be pushed onto the stack.
 */
void push(int value)
{
	if (top == STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: Stack overflow\n", __LINE__);
		exit(EXIT_FAILURE);
	}
	stack[++top] = value;
}

/**
 * pall - Prints all the values on the stack.
 */
void pall()
{
	int i;
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	char opcode[10];
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", __LINE__);
				exit(EXIT_FAILURE);
			}
			push(value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall();
		}
		else
		{
			fprintf(stderr, "L%d: Unknown opcode %s\n", __LINE__, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}

