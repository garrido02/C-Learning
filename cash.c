#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25; // 68 - quarters * 25 same as saying how much is taken

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // We need to create a loop so that a promped is asked
    int cents;
    do
    {
        cents = get_int("What is the change?: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // Calc how many quarters we should give for x number of cents;
    int quarters = 0;
    while (cents >= 25) // 68 > 25 - yes - then 68 - 25 and add 1 quarter and so on until is not > 25
    {
        cents = cents - 25;
        quarters++;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calc how many dimes we should give for x number of cents
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calc how many nickels we should give for x number of cents
    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calc how many pennies we should give for x number of cents
    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}