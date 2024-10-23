#include <stdio.h>
#include <string.h>

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

void reverse_string(char input[])
{
    int start=0, end=strlen(input)-1;
    char temp;

    while(start < end)
    {
        temp = input[start];
        input[start]=input[end];
        input[end]=temp;


        start++; end--;
    }
}

int main() {
    char message[100];
    user_input(message, sizeof(message));
    printf("You entered: %s\n", message);
    reverse_string(message);
    printf("Reverse: %s\n", message);

    return 0;
}
