#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void user_input(char input[], int size) {
    printf("\nEnter the message: ");
    if (fgets(input, size, stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
    }
}

void check(char input[])
{
    char *start=input, *end = input +strlen(input)-1;

    while(start < end)
    {
        while (!(*start >= 'A' && *start <= 'Z' || *start >= 'a' && *start <= 'z'))
        {
            start++;
        }
        if (*start>='a' && *start<='z')
        {
            *start -= 32;
        }

        while (!(*end >= 'A' && *end <= 'Z' || *end >= 'a' && *end <= 'z'))
        {
            end--;
        }
        if (*end>='a' && *end<='z')
        {
            *end -= 32;
        }
        
        if (*start != *end)
        {
            printf("\nNot a palindrome");
            exit(1);
        }


        start++; end--;
    }
    printf("\nIt is a palindrome");
}

int main() {
    char message[100];
    user_input(message, sizeof(message));
    printf("You entered: %s\n", message);
    check(message);
    

    return 0;
}
