#include <ciphers.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAESARSCIPHER "-cc"

int
main (int argc, char **argv)
{
  if (argc < 3)
    {
      perror ("Invalid number of arguments ");
      exit (EXIT_FAILURE);
    }

  char *ci_option = argv[1];

  if (strncmp (CAESARSCIPHER, ci_option, 3) == 0)
    {
      char *ciphertext = cc_encrypt ("test", 1);
      printf ("%s\n", ciphertext);
      free (ciphertext);
    }
  else
    {
      perror ("Invalid option.");
      exit (EXIT_FAILURE);
    }

  return 0;
}
