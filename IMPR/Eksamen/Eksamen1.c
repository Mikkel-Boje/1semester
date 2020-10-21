#include <stdio.h>

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

    if(isBinary(operator) = 1)
    {
        scanf(" %lf", &operand);
    }
    else
    {
        operand = 0.0;
    }
}

void do_next_op(operator, operand)
{


}

double run_calculator()
{

}

int isBinary(operator)
{
    if()


}