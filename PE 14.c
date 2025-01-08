#include <stdio.h>
int length(long x) {
    if(x == 1) return 1;
    if(x % 2 == 0) return length(x / 2) + 1;
    else  return length(3 * x + 1) + 1;
    }
 int main(){
    int ans = 0;
    int ans_length = 0;
    for(int i = 1; i <= 1000000; i++) {
        int tmp = length(i);
        if ( tmp > ans_length) {
            ans_length = tmp;
            ans = i;
        }
    }
    printf("%d %d\n",ans, ans_length);
    return 0;
}