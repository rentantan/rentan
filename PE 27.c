#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


int is_prime(int n) {
  int i;
  if (n <= 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  for (i = 2; i < sqrt((double)n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}



int main() {
  int a, b, n;
  int nmax = 0, amax = 0, bmax = 0;
  for (a = -999; a < 1000; a++) {
    for (b = -1000; b <= 1000; b++) {
      n = 0;
      while(is_prime(n*n + a*n + b) == 1) n++;
      n--;
      if (n > nmax) {
        nmax = n;
        amax = a;
        bmax = b;
      }
    }
  }
  printf("%d\n", amax * bmax);
  return 0;
}
