#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_grid(int size);


int main (void)
{
    //Create a function that gives me n when prompted
    int n = get_size();

    //Print the pyramid grid
    print_grid(n);
}


int get_size(void)
{
    int n;
    do
    {
       n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_grid(int size)
{
    for (int row = 1; row <= size; row++)
    {
        for (int space = 1; space <= size - row; space++)
        {
            printf(" ");
        }
        for (int freq = 1; freq <= row; freq++)
        {
            printf("#");
        }
        printf("\n");
    }
}