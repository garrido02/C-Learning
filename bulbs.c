#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);


int main(void)
{

    //ask for prompt
    string input = get_string("Message: ");
    int n = strlen(input);

    // Convert text to decimal numbers and then to binary
    int bits[n];
    char binary;
    int rem[n];
    int total = 8;
    for (int i = 0; i < n; i++) //loop to get every char value
    {
        int conversion = input[i];


        for (int j = 0; j < total; j++) //convert every char to an array of 0 and 1
        {
            rem[j] = (conversion % 2);
            conversion = (conversion / 2);

        }

        for (int k = 1; k <= total; k++) //calculate binary in reverse
        {
            binary = rem[total - k];
            print_bulb(binary);
        }
        printf("\n");
    }

}






//new variable called bits


void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}


