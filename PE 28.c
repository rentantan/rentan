#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(){
	long long int sum =1;
	int next = 1;
	int diff = 2;
	while (diff <= 1000) {
		for (int i = 0; i < 4; ++i) {
			next += diff;
			sum += next;
		}
		diff += 2;
	}
	printf("%lld\n", sum);
	return 0;
}