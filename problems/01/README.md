# Multiples of 3 or 5

## Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

## My Solution
Let's try to find the sum of the multiples of 3 and 5 that are below 100.

1. Let's try with 5:\
$s = 5 + 10 + 15 + ... + 85 + 90 + 95$\
$s = 5 + (5 + 5) + (5 + 10) + ... + (95 - 10) + (95 - 5) + 95$\
$s = 5 + (5 + 5) + (5 + 2 \times 5) + ... + (95 - 2 \times 5) + (95 - 5) + 95$

2. We can generalize it to:\
$s = a + (a + d) + (a + 2d) + ... + (l - 2d) + (l - d) + l$\
Where:
    - $a$ is the first term
    - $d$ is the difference between each term
    - $l$ is the last term

3. We can use the reverse trick:\
$s = l + (l - d) + (l - 2d) + ... + (a + 2d) + (a + d) + a$

4. we then have two sums:\
$s = a + (a + d) + (a + 2d) + ... + (l - 2d) + (l - d) + l$\
$s = l + (l - d) + (l - 2d) + ... + (a + 2d) + (a + d) + a$

5. We can add them together:\
$2s = (a + l) + (a + l) + (a + l) + ... + (a + l) + (a + l) + (a + l)$

6. We have $n$ (number of terms) times $(a + l)$:\
$2s = n (a + l)$\
$s = n (a + l) / 2$

7. To find variables:
    - $a$ is the first term which is the divisor (in our example 5)
    - $n$ is the number of terms that we can calculate by limit - 1 / a (integer division will round it to the smallest int) (in our example 19)
    - $l$ is $n \times a$ (in our example 19 * 5 = 95)

8. This formula gives us the sum of multiples of a that are under a certain limit:\
$s(5) = 950$$\
$s(3) = 1683$\
$s(5) + s(3) = 2633$ (Which is above the right answer)

9. We need to subtract the multiples of 5 AND 3 that are counted twice! (Like 15, 30, 45, ...) to do so we can calculate the sum of the multiples of 15 (3 * 5) and subtract it from the total sum:\
$s(15) = 315$

10. So finally we have:\
$s(5) + s(3) - s(3 * 5) = 2318$

My solution in C:
```C
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
```

