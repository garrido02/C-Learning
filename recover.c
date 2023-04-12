#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //size of each blocks
    int BLOCK_SIZE = 512;

    //acept only one command line
    if (argc != 2)
    {
        printf("Usage: ./recover NAME\n");
        return 1;
    }

    //open file
    char *infile = argv[1];
    FILE *input = fopen(infile, "r");

    //if file is null give error
    if (input == NULL)
    {
        printf("Could not open %s\n", infile);
        return 1;
    }


    //create buffer, allocate outfile, inicialize that file and counter
    uint8_t buffer[BLOCK_SIZE];

    char *outfile = malloc(sizeof(infile));
    FILE *img = NULL;
    int jpeg_counter = 0;

    //read through file and store it in buffer (512 bytes at a time)
    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        //check for jpeg header and open file (if first time)
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0) && (jpeg_counter == 0))
        {
            //print to the oufile the current jpeg number
            sprintf(outfile, "%03i.jpg", jpeg_counter);

            //open outfile, write add 1 to counter
            img = fopen(outfile, "w");
            if (img == NULL)
            {
                printf("Could not open %s\n", outfile);
                free(outfile);
                return 1;
            }
            fwrite(buffer, 1, BLOCK_SIZE, img);
            jpeg_counter++;
            continue;
        }

        //check for jpeg header and open file (for subsequent images)
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0) && (jpeg_counter != 0))
        {
            //close file first
            fclose(img);

            //print to the outfile the current jpeg name based on counter
            sprintf(outfile, "%03i.jpg", jpeg_counter);

            //open file again
            img = fopen(outfile, "w");
            if (img == NULL)
            {
                printf("Could not open %s\n", outfile);
                free(outfile);
                return 1;
            }
            fwrite(buffer, 1, BLOCK_SIZE, img);
            jpeg_counter++;
            continue;
        }

        //if image is not null that means its already open then we want to keep adding information until we find a new one
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
            continue;
        }
    }
    free(outfile);
    fclose(input);
    fclose(img);
    return 0;
}


