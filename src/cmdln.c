#include <ciphers.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAESARSCIPHER "cc"

int main (int argc, char **argv) {
  if (argc < 4) {
    perror ("Invalid number of arguments ");
    exit (EXIT_FAILURE);
  }

  char *ci_selection = argv[1];

  if (strncmp (CAESARSCIPHER, ci_selection, 3) == 0) {
    char *endptr;
    int uin_key = strtol (argv[3], &endptr, 10);

    if (endptr[0] != '\0') {
      perror ("Invalid key.");
      exit (EXIT_FAILURE);
    }
    char *ciphertext = cc_encrypt (argv[2], uin_key);
    char *decipheredtext = cc_decrypt (argv[2], uin_key);
    printf ("Encrypted: %s\n", ciphertext);
    printf ("Decrypted: %s\n", decipheredtext);
    free (ciphertext);
    free (decipheredtext);
  }
  else {
    perror ("Invalid option.");
    exit (EXIT_FAILURE);
  }

  return 0;
}
