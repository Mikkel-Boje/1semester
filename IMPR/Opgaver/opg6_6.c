#include <stdio.h>

double convert(double, double *, double *, double *, double *);

int main(void)
{
    double euro, dkk, yen, rubler, dollars;
    
    for (double dollars = 1; dollars <= 100; dollars++)
    {
        convert(dollars, &euro, &dkk, &rubler, &yen);
        printf("%lf dollars is equal to: %lf Euro, %lf DKK, %lf Rubler, %lf Yen \n", dollars, euro, dkk, rubler, yen);
    }
    
    return 0;
}

double convert(double dollars, double *pointer_euro, double *pointer_dkk, double *pointer_rubler, double *pointer_yen)
{
    double dollars_per_euro = 0.89;
    double dollars_per_dkk = 6.66;
    double dollars_per_yen = 119.9;
    double dollars_per_rubler = 66.43;

    *pointer_euro = dollars * dollars_per_euro;
    *pointer_dkk = dollars * dollars_per_dkk;
    *pointer_yen = dollars * dollars_per_yen;
    *pointer_rubler = dollars * dollars_per_rubler;    
}