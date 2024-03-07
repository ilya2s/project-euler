#include <stdio.h>

int multiples_sum(int a, int limit) {
    int n;
    n = (limit - 1) / a;

    return n * (a + (n * a)) / 2;
}

int main(void) {
    int sum;
    
    sum = multiples_sum(3, 1000) +
        multiples_sum(5, 1000) -
        multiples_sum(3 * 5, 1000);

    printf("Sum: %d\n", sum);

    return 0;
}
