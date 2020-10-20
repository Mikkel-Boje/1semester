#include <stdio.h>
#include <math.h>

double round_f(double n)
{
    double result;

    result = roundf(n * 100) / 100;

    return result;
}

int main(void)
{
double r = 0;
double x = 0;
double y = 0;
double l = 0;

printf("I will tell you if a point is either, in/out or on the periphery\n");
printf("Press a button to continue\n");
getchar();

printf("Chose a radius for the cirkle: ");
scanf("%lf", &r);

printf("Chose x coordinate: ");
scanf("%lf", &x);

printf("Chose y coordinate: ");
scanf("%lf", &y);

l = sqrt( x * x + y * y);

r = round_f(r);
l = round_f(l);

printf( l > r ? "Outside" : l < r ? "Inside" : "On");
printf("\n");

return(0);
}