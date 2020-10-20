#include <stdio.h>

int main(void)
{
    int i, k, a, b, result = 0;

    printf("Chose lowerbound of the interval: ");
    scanf("%d", &a);
    printf("Chose upperbound of the interval: ");
    scanf("%d", &b);
    printf("Chose divisor: ");
    scanf("%d", &k);

    /* m vil hermed være det mindste tal*/
    int m = a <= b ? a : b;
    int n = a >= b ? a : b;

    for (i = m + 1; i <= n + 1; i++)
    {
        if(i % k == 0)
            result += i;
    }
    
    printf("The sum of the divisable numbers of k in interval a to b is equal to: %d\n", result);

    return 0;
}