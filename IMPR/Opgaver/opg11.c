#include <stdio.h>
#include <math.h>

int main(void) 
{
int m = 0;
int n = 0;
int side1 = 0;

scanf(" %d", &m);
scanf(" %d", &n);
printf("\n");

if(m > n)
{
    side1 = m * m - n * n;
}
else
{
    side1 = n * n - m * m;
}

int side2 = 2 * m * n;
int hyp = m * m + n * n;

printf("%d \n", side1);
printf("%d \n", side2);
printf("%d \n", hyp);

return 0;
}