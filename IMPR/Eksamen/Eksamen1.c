#include <stdio.h>
#include <math.h>

void scan_data(operator, operand);
void do_next_op(operator, operand);
double run_calculator();
int isBinary(operator);

int main(void)
{
    double akkumulator, operand;
    char operator;


    akkumulator = 0.0;



}

void scan_data(operator, operand)
{
    scanf(" %c", &operator);

    if(isBinary(operator))
    {
        scanf(" %lf", &operand);
    }
    else
    {
        operand = 0.0;
    }
}

void do_next_op(operator, operand, *akkumulator)
{
    switch (operator)
    {
    case '+':
        *akkumulator =  
        break;

    default:
        break;
    }

}

double run_calculator()
{

}

int isBinary(operator)
{
    if(operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}