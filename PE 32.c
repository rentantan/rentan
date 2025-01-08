#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define d(x) (lround(floor(log10((double)x))))

int com(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

int check(char *buf) {
  qsort(buf, 9, 1, com);
  return memcmp(buf, "123456789", 9) == 0;
}

int main() {
  int x, y, z, w;
  int ans = 0;
  char buf[10];

  for (x = 2; x < 10000; x++) {
    for (z = 2; z*z < x; z++) {
      w = x % z;
      if (w != 0) {
        continue;
      }
      y = x / z;
      if (d(z) + d(y) + d(x) != 6) {
        continue;
      }

      snprintf(buf, sizeof buf, "%d%d%d", z, y, x);
      if (check(buf)) {
        ans += x;
        break;
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}

