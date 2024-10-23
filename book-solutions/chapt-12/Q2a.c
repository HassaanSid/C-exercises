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
    int start=0, end=strlen(input)-1;

    while(start < end)
    {
        while (!(input[start] >= 'A' && input[start] <= 'Z' || input[start] >= 'a' && input[start] <= 'z'))
        {
            start++;
        }
        if (input[start]>='a' && input[start]<='z')
        {
            input[start] -= 32;
        }

        while (!(input[end] >= 'A' && input[end] <= 'Z' || input[end] >= 'a' && input[end] <= 'z'))
        {
            end--;
        }
        if (input[end]>='a' && input[end]<='z')
        {
            input[end] -= 32;
        }
        
        if (input[start] != input [end])
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
