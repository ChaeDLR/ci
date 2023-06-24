#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/errno.h>

/*
* File to binary
*/
int ftob (char *ftrpath, char *ftwpath)
{
    FILE *infile;
    FILE *outfile;
    char *filetext;
    long filelen;

    infile = fopen (ftrpath, "rb");

    fseek (infile, 0, SEEK_END);
    filelen = ftell (infile);
    fseek (infile, 0, SEEK_SET);

    filetext = malloc (sizeof (char) * filelen);
    fread (filetext, sizeof (char), filelen, infile);

    outfile = fopen (ftwpath, "w");
    fwrite (filetext, sizeof (char), filelen, outfile);

    free (filetext);

    fclose (infile);
    fclose (outfile);
    if (errno == 5) {
        return -1;
    }
    return 0;
}