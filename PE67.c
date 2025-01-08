#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int max(int a,int b) {
  if(a < b) a = b;
  return a;
}

int main() {
int v[100][100] = {0};
FILE *fp;
    int i,j;
	fp = fopen("p067_triangle.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "Cannot open \"p067_triangle.txt\".\n");
		return 1;
	}
	for (i = 0; i < 100; ++i) {
		for (j = 0; j < 100; ++j) {
			if(i >= j)fscanf(fp, "%d", &(v[i][j]));
		}
	}
	fclose(fp);
  int dp[100][100] = {0};
  dp[0][0] = v[0][0];
  for(int i = 0;i < 99;i++){
    for(int j = 0;j < 100;j++){
    //もらうｄｐ
    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + v[i+1][j]);
    if(j >= 1) dp[i+1][j] = max(dp[i+1][j], dp[i][j-1] + v[i+1][j]);
    }
  }
  int M = 0;
  for(int j = 0;j < 100;j++) M = max(M,dp[99][j]);
  printf("%d\n",M);
  return 0;
}
