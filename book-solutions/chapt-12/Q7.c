#include <stdio.h>

#define MAX_SIZE 10

void max_min (int*, int, int*, int*);
void user_input(int*, int);
void print_result(int, int);

int main ()
{
    int numbers[MAX_SIZE], maximum, minimum;
    user_input(numbers, MAX_SIZE);
    max_min(numbers, MAX_SIZE, &maximum, &minimum);
    print_result(maximum, minimum);

    return 0;
}

void user_input(int *input, int size)
{
    int *ptr = input;
    printf("\nEnter the numbers: ");
    for (int i=0; i<size; i++, ptr++)
    {
        scanf("%d", ptr);
    }
}

void print_result(int max, int min)
{
    printf("\nThe maximum number is: %d", max);
    printf("\nThe minimum number is: %d", min);
}

void max_min (int *input, int size, int *max, int *min)
{
    *max = *min = *input;
    int *ptr = input;
    for (int i=0; i<size; i++)
    {
        if(*ptr > *max)
        {
            *max = *ptr;
        }
        else if (*ptr < *min)
        {
            *min = *ptr;
        }
        ptr++;
    }
}