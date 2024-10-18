#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#define MAX_DIGITS 10

const char segments [10][7] = {"-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ", "-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"};
char digits [5][MAX_DIGITS *6];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);
void user_input(void);

int main()
{
    clear_digits_array();
    user_input();
    print_digits_array();

    return 0;
}

void clear_digits_array(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < MAX_DIGITS * 6; j++) {
            digits[i][j] = ' ';
        }
    }
}

void print_digits_array(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < MAX_DIGITS * 6; j++) {
            putchar(digits[i][j]);
        }
        putchar('\n');
    }
}

void process_digit(int digit, int position)
{
    int col=position*6;
    const char* seg = segments[digit];
    //top segment
    digits[0][col+1]=seg[0];
    digits[0][col+2]=seg[0];
    //top left
    digits[1][col]=seg[1];
    //top right
    digits[1][col+3]=seg[2];
    //middle
    digits[2][col+1]=seg[3];
    digits[2][col+2]=seg[3];
    //bottom left
    digits[3][col]=seg[4];
    //bottom right
    digits[3][col+3]=seg[5];
    //bottom segment
    digits[4][col+1]=seg[6];
    digits[4][col+2]=seg[6];
}

void user_input()
{
    printf("Hey enter the %d digit number: ", MAX_DIGITS);
    char input[MAX_DIGITS+5];
    scanf("%s", input);
    int size = strlen(input);

    for (int i=0, ndigits=0; ndigits < MAX_DIGITS && i < size; i++)
    {
        if(isdigit(input[i]))
        {
            process_digit(input[i]-'0', ndigits);
            ndigits++;
        }
    }

}