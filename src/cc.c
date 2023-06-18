#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 0xffff
#define TEXTKEY "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .,?!"


char *cc_encrypt (char *text, size_t key) {

  size_t tklen = strlen (TEXTKEY);
  size_t txtlen = strnlen (text, MAXSTRLEN);

  char *ci_text = malloc (sizeof (char) * (txtlen + 1));
  ci_text[txtlen] = 0;

  size_t shiftloc;
  size_t i, j;
  for (i = 0, j = 0; i < txtlen; ++i) {
    shiftloc = i;
    look:
    if (text[i] == TEXTKEY[j]) {
      shiftloc = j + key;
      j = 0;
      while (shiftloc >= tklen) shiftloc -= tklen;
    }
    else if (j < tklen) {
      ++j;
      goto look;
    }
    ci_text[i] = TEXTKEY[shiftloc];
  }

  return ci_text;
}

char *cc_decrypt (char *text, size_t key) {

  size_t tklen = strlen (TEXTKEY);
  size_t txtlen = strnlen (text, MAXSTRLEN);

  char *deci_text = malloc (sizeof (char) * (txtlen + 1));
  deci_text[txtlen] = 0;

  int shiftloc;
  size_t i, j;
  for (i = 0, j = 0; i < txtlen; ++i) {
    shiftloc = i;
    look:
    if (text[i] == TEXTKEY[j]) {
      shiftloc = j - key;
      j = 0;
      while (shiftloc < 0) shiftloc += tklen;
    }
    else if (j < tklen) {
      ++j;
      goto look;
    }
    deci_text[i] = TEXTKEY[shiftloc];
  }

  return deci_text;
}
