#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
void user_input(char*, int, char*);
void reverse(char*, char*);

int main()
{
    char terminate;
    char array[SIZE];
    user_input(array, SIZE, &terminate);
    reverse(array, &terminate);
    return 0;
}

void user_input(char *array, int size, char *terminate) //without size, cant use pointer for taking input unless dynamic memory allocation
{
    char *ptr=array;
    *terminate ='F'; // just initializing
    printf("Enter a sentence: ");
    fgets (array, size, stdin); 
    array[strlen(array)-1] = '\0'; //remove the newline character assuming input doesn't exceed SIZE 100
    
    //printf("\nThe array now: %s", array);

    while (*ptr != '\0')
    {
        if(*ptr == '?' || *ptr == '.' || *ptr == '!') 
        {
            *terminate = *ptr;
            *ptr = '\0'; 
        }
        ptr++;
    }

    //printf("\nThe array after: %s", array);
}


void reverse(char *array, char *terminate) {
    char *end = array + strlen(array) - 1;
    char *start;

    while (end >= array) {
        // Skip trailing spaces
        while (end >= array && *end == ' ') {
            end--;
        }
        if (end < array) break;

        // Find the start of the word
        start = end;
        while (start >= array && *start != ' ') {
            start--;
        }

        // Print the word
        char *ptr = start + 1;
        while (ptr <= end) {
            putchar(*ptr);
            ptr++;
        }
        putchar(' ');

        // Move to the next word
        end = start - 1;
    }
    putchar(*terminate);
}