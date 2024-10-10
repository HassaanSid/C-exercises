#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// ranks 2,3,4,5,6,7,8,9,t,j,q,k,a
// suits s,d,h,c


#define NUM_RANK 13
#define NUM_SUIT 4
#define NUM_CARDS 5


int num_in_rank[NUM_RANK], num_in_suit[NUM_SUIT];
bool flush, straight, four, three;
int pairs;


void user_input();
void analyse();
void print();


int main()
{
    while(true)
    {
        user_input();
        analyse();
        print();
    }
    return 0;
}


void user_input()
{
    char rank_ch, suit_ch;
    char input, c;
    bool bad_input = false;
    int rank, suit;
    int card_reads = 0;
    bool repeat[NUM_RANK][NUM_SUIT]={false};


    for(rank = 0; rank < NUM_RANK; rank++)
    {
        num_in_rank[rank] = 0;
    }


    for (suit = 0; suit < NUM_SUIT; suit++)
    {
        num_in_suit[suit]=0;
    }


    while (card_reads < NUM_CARDS)
    {
        bad_input=false;


        printf("Enter the card: ");
        scanf("%c%c", &rank_ch, &suit_ch);


        //rank_ch = getchar();
        switch(rank_ch)
        {
            case '0' : exit(1);
            case '2' : rank = 0; break;
            case '3' : rank = 1; break;
            case '4' : rank = 2; break;
            case '5' : rank = 3; break;
            case '6' : rank = 4; break;
            case '7' : rank = 5; break;
            case '8' : rank = 6; break;
            case '9' : rank = 7; break;
            case 't' : case 'T' : rank = 8; break;
            case 'j' : case 'J' : rank = 9; break;
            case 'q' : case 'Q' : rank = 10; break;
            case 'k' : case 'K' : rank = 11; break;
            case 'a' : case 'A' : rank = 12; break;
            default : bad_input = true;
        }


        //suit_ch = getchar();
        switch(suit_ch)
        {
            case 's' : case 'S' : suit = 0; break;
            case 'd' : case 'D' : suit = 1; break;
            case 'h' : case 'H' : suit = 2; break;
            case 'c' : case 'C' : suit = 3; break;
            default : bad_input = true;
        }


        while ((c=getchar()) != '\n' && c != EOF)
        {
            if (c!= ' ') bad_input = true;
        }


        if (bad_input) printf("\nBad input!");
        else if (repeat[rank][suit]) printf("\nDuplicate card!");
        else
        {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            repeat[rank][suit]=true;
            card_reads++;
        }
    }
}


void analyse()
{
    flush=false; straight=false; four=false; three=false; pairs=0;
    int rank, suit, consec=0;


    // flush
    for (suit=0; suit < NUM_SUIT; suit++)
    {
        if (num_in_suit[suit] == NUM_CARDS) flush=true;
    }


    //straight
    rank=0;
    while(num_in_rank[rank] == 0) rank++;

    for(rank; rank < NUM_RANK && num_in_rank[rank]>0; rank++) consec++;
    if(consec == NUM_CARDS) straight=true;


    for(rank=0; rank<NUM_RANK; rank++)
    {
        if(num_in_rank[rank]==4) four=true;
        else if (num_in_rank[rank]==3) three=true;
        else if (num_in_rank[rank]==2) pairs++;
    }
}


void print()
{
    if(straight && flush) printf("\nStraight Flush");
    else if(straight) printf("\nStraight");
    else if(flush) printf("\nFlush");
    else if(four) printf("\nFour of a kind");
    else if(three && pairs==1) printf("\nFull House");
    else if(three) printf("\nThree of a kind");
    else if(pairs==2) printf("\nTwo Pairs");
    else if(pairs==1) printf("\nPair");
    else printf("\nHigh Card");


    printf("\n");
}
