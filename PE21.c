#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//約数の和を求める関数を定義
int calculation(int num) {
	int sum = 1; 
	for (int i = 2; i * i <= num; ++i) {
		if ((num % i) == 0) {
			if (i * i != num) {
				sum += i;
				sum += num / i;
			} else {
				sum += i;
			}
		}
	}

	return sum;
}

int main() {
	int answer = 0;
	for (int a = 2; a <= 100000; ++a) {
		int b = calculation(a);
		if ((a == calculation(b))&&(a != b)) {
			answer += a;
		}
	}

	printf("%d\n", answer);

	return 0;
}