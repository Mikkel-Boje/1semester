#include <stdio.h>
#include <math.h>

void run_calculator(void);
char scan_data(double *);
double do_next_op(double *);
int isBinary(char);
void Setup();

/* Laver variabel til at færdiggøre run_calculator */
int run = 1;

int main(void)
{
    Setup();
    run_calculator();

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
    case 'h':
        Setup();
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
    double akkumulator = 0;

    while(run != 0)
    {
        printf("Currently the result is: %lf \n", akkumulator);

        do_next_op(&akkumulator);
    }
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

void Setup()
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
    printf("Write h to get this message again \n");
}