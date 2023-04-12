#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>


long get_cardnumber(void);
bool valid(long number);
int card_length(long n);
int totalsum(long number);
void print_brand(long ccn);


int main(void)
{
    //Prompt for input
    long number = get_cardnumber();

    if(valid(number) == true)
    {
        print_brand(number);
    }
    else
    {
        printf("INVALID\n");
    }
}



long get_cardnumber(void) //prompt user for card number
{
    long number;
    do
    {
        number = get_long("Card Number: ");
    }
    while (number < 0);
    return number;
}


bool valid(long number)
{
    long length = card_length(number);
    return ((length == 13 || length == 15 || length == 16) && totalsum(number));

}


int card_length(long n)
{
    int length = 0;
    while (n > 0)
    {
        n = n / 10;
        length++;
    }
    return length;
}

int totalsum(long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += (ccn % 10); //4003600000000014
        }
        else
        {
            int digit = 2 * (ccn % 10);
            sum += (digit / 10) + (digit % 10);
        }
    }
    return (sum % 10) == 0;
}

void print_brand(long ccn)
{
    if(ccn>= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }

    else if(ccn >= 34e13 && ccn < 38e13)
    {
        printf("AMEX\n");
    }
    else if((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

