#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100

int main(int argc, char **argv)
{
    int filenum = 0, monnum = 0, index = 0;
    FILE *entry, *output;
    char filename[25], ch;
    const char *outputfile = "checkitout\\output.txt";

    if (argc != 1) // the simple error handling part
    {
        fprintf(stderr, "This sorts the text files generated by genmonareadexdata and split accordingly.\n");
        return 1;
    }

    output = fopen(outputfile, "w");

    _workaround:

    filenum = (index * 0x1EF) + monnum;

    sprintf(filename, "checkitout\\xx%04d.txt", filenum);

    entry = fopen(filename, "r");

    printf("%s\n", filename);

    if (!entry)
    {
        fprintf(stderr, "index+1");
        return 1;
    }

    while ((ch = fgetc(entry)) != EOF)
    {
        fputc(ch, output);
    }

    filenum++;

    fclose(entry);

    if (monnum <= 0x1EE)
    {
        if (index < 7)
            index++;
        else
        {
            index = 0;
            monnum++;
        }
        goto _workaround;
    }

    return 0;
}
