#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

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
	if (is_full()) printf("Stack overflow\n");
	contents[top++]=i;
}

int pop (void)
{
	if(is_empty()) printf("Stack underflow\n");
	return contents[--top];
}

void add()      {top>=2 ? push(pop() + pop()) : printf("\nNot enough operands!");}
void multiply() {top>=2 ? push(pop() * pop()) : printf("\nNot enough operands!");}

void subtract() {
    if (top >= 2) {
        int s = pop();
        push(pop() - s);
    } else {
        printf("\nNot enough operands!\n");
    }
}


void divide() {
    if (top >= 2) {
        int d = pop();
        push(pop() / d);
    } else {
        printf("\nNot enough operands!\n");
    }
}


int main()
{
	char input[100], c;
	printf("Kindly enter the RPN expression: ");
	scanf("%s", input); //the %s doesnot limit the input to a specific number of characters, therefore we must limit using %9s or something
	printf("\n %s", input);

	make_empty();

	for(int i=0; input[i] != '\0'; i++)
	{
		c=input[i];
		if (isdigit(c))
		{
			push(c - '0');
		}
		else if (c == '=')
		{
			printf("\nThe result is: %d", pop());
		}
		else
		{
			switch(c)
			{
				case '+': add(); break;
				case '-': subtract(); break;
				case '/': divide(); break;
				case '*': multiply(); break;
				default : printf("\n What the fuck man??");
			}
		}
	}
	
	return 0;
}

