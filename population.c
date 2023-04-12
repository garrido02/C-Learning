#include <cs50.h>
#include <stdio.h>


int get_size_start(void);
int get_size_end(int start);
int pop_rate(int start, int end);
void print_years(int y);


int main(void)
{
    // TODO: Prompt for start size
    int n1 = get_size_start();

    // TODO: Prompt for end size
    int n2 = get_size_end(n1);

    // TODO: Calculate number of years until we reach threshold
    int years = pop_rate(n1, n2);

    // TODO: Print number of years
        print_years (years);
}



int get_size_start(void) //get starting size
{
    int start;
    do
    {
        start = get_int("Starting Size?: ");
    }
    while (start < 9);
    return start;
}


int get_size_end(int start) //get ending size
{
    int end;
    do
    {
        end = get_int("Ending Size?: ");
    }
    while (end < start);
    return end;
}


int pop_rate(int start, int end)
{
    int anos = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        anos++;
    }
    return anos;
}

void print_years(int y)
{
    printf("Years: %i\n", y);
}