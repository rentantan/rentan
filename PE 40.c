#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char v[1000010] = {0};
	int a = 1;
    int b = 1;
	int c = 1;
	int d = 10;
    int e;
	while (b <= 1000000) {
		e = a;
		for (int i = 1; i <= c; ++i) {
            //v[i]は小数点以下i番目の数
			v[b + (c - i)] = e % 10;
			e /= 10;
		}
		b += c;
		a++;
		if (a == d) {
			++c;
			d *= 10;
		}
	}

	printf("%d\n",v[1]*v[10]*v[100]*v[1000]*v[10000]*v[100000]*v[1000000]);

	return 0;
}