
#include <stdio.h>


void pay_amount(int, int *, int*, int*, int*);

int main()
{
    int input=0, twenties, tens, fives, ones;
    //int *p_20s=&twenties, *p_10s=&tens, *p_5s=&fives, *p_ones=&ones;

    printf("\nEnter the bill: $");
    scanf("%d", &input);

    pay_amount(input, &twenties, &tens, &fives, &ones);

    printf("\n20$ bills: $%d", twenties);
    printf("\n10$ bills: $%d", tens);
    printf("\n5$ bills: $%d", fives);
    printf("\n1$ bills: $%d", ones);


    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars/20;
    *tens = (dollars - (*twenties)*(20) )/10;
    *fives = (dollars - (*twenties)*(20) - (*tens)*(10) )/5;
    *ones = dollars - (*twenties)*(20) - (*tens)*(10) - (*fives)*(5);

}