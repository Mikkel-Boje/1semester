#include <stdio.h>

int GCD(int, int);

int main(void) 
{
    int a, b, divider;

    do
    {
    printf("Chose a value for a: ");
    scanf("%d", &a);
    if(a < 0)
        break;

    printf("\nChose a value for b: ");
    scanf("%d", &b);
    if(b < 0)
        break;

    divider = GCD(a,b);

    printf("\n The greatest common divider for a and b is %d \n", divider);
    } while (a > 0 && b > 0);

    return 0;
}

int GCD(int a, int b)
    {
        int min = a <= b ? a : b;
        int result;
        int i;

        for (i = min; i >= 1; i--)
        {
            if(a % i == 0 && b % i == 0)
                return i;
        }
        
        if(a == 0 && b == 0)
            i = 0;
        
        if(a == 0)
        {
            i = b;
        }
        else if(b == 0)
        {
            i = a;
        }
        
        return i;
    }