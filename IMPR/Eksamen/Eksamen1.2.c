/* Lavet af Mikkel Boje Larsen */

#include <stdio.h>
#include <math.h>

char scan_data(double *);
int isBinary(char);
void do_next_op(double *, char, double *);
void run_calculator(void);
void Setup();

/* Laver variabel til at færdiggøre run_calculator */
int run = 1;

int main(void)
{
    Setup();
    run_calculator();

    return 0;
}

/* Denne funktion indlæser data for både operator og operand */
char scan_data(double *operand)
{
    char operator;
    double temp;

    scanf(" %c", &operator);

/* Her findes der ud af om der skal indlæses en operand vha. IsBinary funktionen */
    if(isBinary(operator) == 1)
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

/* Denne funktion finder ud af hvad der skal beregnes for de forskellige valg af operatorer */
void do_next_op(double *operand, char operator, double *akkumulator)
{
    switch (operator)
    {
    case '+':
        *akkumulator += *operand; 
        break;
    case '-':
        *akkumulator -= *operand; 
        break;
    case '*':
        *akkumulator *= *operand; 
        break;
    case '/':
        *akkumulator /= *operand; 
        break;
    case '^':
        *akkumulator = pow(*akkumulator, *operand); 
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

/* Her er funktionen som sørger for at inteagere med brugeren og holder programmet igang så længde inputet ikke er 0.
Her findes også ud af om brugeren har indtastet noget der ikke var forventet */
void run_calculator(void)
{
    double akkumulator = 0;
    double operand = 0;
    char operator;

    while(run != 0)
    {
        operator = scan_data(&operand);
        do_next_op(&operand, operator, &akkumulator);
        
        if(isBinary(operator) == 0 || isBinary(operator) == 1)
        {
            printf("Result so far is: %f \n", akkumulator);
        }
        else if(isBinary(operator) == 2)
        {
            printf("The final result is: %f \n", akkumulator);
        }
    }
}

/* Denne funktion bruges til at finde ud af om der skal indlæses en operand */
int isBinary(char operator)
{
    if(operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^')
    {
        return 1;
    }
    else if(operator == '#' || operator == '%' || operator == '!')
    {
        return 0;
    }
    else if(operator == 'q')
    {
        return 2;
    }
    else
    {
        /* returner f for false input */
        return 'f';
    }
}

/* Laver denne funktion så jeg kan lave et input h som skriver denne beskred igen for at hjælpe brugeren med at huske de mulige inputs */
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