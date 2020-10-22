#include <stdio.h>
#include <math.h>

void run_calculator(void);
char scan_data(double *);
double do_next_op(double *);
int isBinary(char);

int run = 1;

int main(void)
{
    printf("This is a calculator. \n");
    printf("The following input needs to be in format operator and then a space if you want an operator as well and then wrtie a operand. \n");
    printf("Format example: + 2\n");
    printf("The operators are as following: \n");
    printf(" +, -, *, /, ^, #, %%, !, q \n");
    printf("Here # is square root of previous result.\n");
    printf("Here %% is negating the previous result.\n");
    printf("Here ! is the reciproc of the previous result.\n");
    printf("When you want to EXIT the program write q as an operator\n");

    while(run != 0)
    {
        run_calculator();
    }

    return 0;
}

char scan_data(double *operand)
{
    char operator;
    double temp;

    scanf(" %c", &operator);

    if(isBinary(operator))
    {
        scanf(" %lf", &temp);
    }
    else
    {
        temp = 0.0;
    }

    *operand = temp;

    return operator;
}

double do_next_op(double *akkumulator)
{
    double operand;
    char operator = scan_data(&operand);

    switch (operator)
    {
    case '+':
        *akkumulator += operand; 
        break;
    case '-':
        *akkumulator -= operand; 
        break;
    case '*':
        *akkumulator *= operand; 
        break;
    case '/':
        *akkumulator /= operand; 
        break;
    case '^':
        *akkumulator = pow(*akkumulator, operand); 
        break;
    case '#':
        *akkumulator = sqrt(*akkumulator); 
        break;
    case '%':
        *akkumulator *= -1; 
        break;
    case '!':
        *akkumulator = 1 / *akkumulator; 
        break;
    case 'q':
        run = 0;
        break;

    default:
        break;
    }

}

void run_calculator(void)
{
    double akkumulator;

    do_next_op(&akkumulator);

    printf("The result of the computation is: %lf \n", akkumulator);
}

int isBinary(char operator)
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