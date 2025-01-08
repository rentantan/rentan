#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int com(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

int check(const char *s) {
  size_t l;
  char t[10];
  size_t i;

  l = strlen(s);

  if (l != 9) {
    return 0;
  }
  strncpy(t, s, sizeof t);
  qsort(t, l, sizeof *t, com);
  for (i = 0; i < l; i++) {
    if (t[i] != i+'1') {
      return 0;
    }
  }
  return 1;
}

int main() {
  int max = 0;
  int i;

  for (i = 1; i < 10000; i++) {
    char s[10] = {0};
    int j;

    snprintf(s, sizeof s, "%u", i);
    for (j = 2; ; j++) {
      char t[10] = {0};

      snprintf(t, sizeof t, "%u", i*j);
      if (strlen(s) + strlen(t) > 9) {
        break;
      }
      strncat(s, t, sizeof s - strlen(s));
    }
    if (check(s)) {
      int l = strtoul(s, NULL, 10);
      if (l > max) {
        max = l;
      }
    }
  }
  printf("%u\n", max);

  return 0;
}