#include <stdio.h>
#include <math.h>

static int is_triangle(int c);

int main(){
  FILE *fp;
  int cnt = 0;
  char buf[32];

  fp = fopen("words.txt", "r");
  if (!fp) {
    perror("words.txt");
    return 1;
  }

  while (fscanf(fp, "\"%[^\"]\",", buf) != EOF) {
    int i, sum = 0;
    for (i = 0; buf[i] != '\0'; i++) {
      sum += buf[i]-'A'+1;
    }
    cnt += is_triangle(sum);
  }
  fclose(fp);

  printf("%d\n", cnt);

  return 0;
}

int is_triangle(int c){
  int sq = sqrt(1+8*c);
  return (sq*sq == 1+8*c && (sq & 1) == 1);
}