#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

int top = 0;
int contents[STACK_SIZE];

void make_empty ()
{
	top = 0;
}

bool is_empty ()
{
	return top == 0;
}

bool is_full()
{
	return top == STACK_SIZE;
}

void push (int i)
{
	if (is_full) printf("Stack overflow\n");
	contents[top++]=i;
}

int pop (void)
{
	if(is_empty) printf("Stack underflow\n");
	return contents[--top];
}

int main()
{

	return 0;
}