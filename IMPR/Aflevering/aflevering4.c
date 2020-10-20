#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(double a, double b, double c);
double computeDiscriminant(double a, double b, double c);
double findRoot1(double a, double b, double discriminant);
double findRoot2(double a, double b, double discriminant);

int main(void) 
{
double a, b, c;

int looping = 1;

while(looping)
{
    printf("Enter coeficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    looping = !(a == 0 && b == 0 && c == 0);

    if (looping) 
    {
        solveQuadraticEquation(a, b, c); 
    }
}

  return 0;
} 

void solveQuadraticEquation(double a, double b, double c){
  double discriminant, root1, root2;

discriminant = computeDiscriminant(a, b, c);
  if (discriminant < 0)
    printf("No roots\n");
  else if (discriminant == 0){
    root1 = -b/(2*a);
    printf("One root: %f\n", root1);
  }
  else {
    root1 = (-b + sqrt(discriminant))/(2*a);
    root2 = (-b - sqrt(discriminant))/(2*a);
    printf("Two roots: %f and %f\n", root1, root2);
  }
}   

double computeDiscriminant(double a, double b, double c)
{
    double result;

    result = b * b - 4 * a * c;

    return result;
}

double findRoot1(double a, double b, double discriminant)
{
    return (-b + sqrt(discriminant))/(2*a);
}

double findRoot2(double a, double b, double discriminant)
{
    return (-b - sqrt(discriminant))/(2*a);
}