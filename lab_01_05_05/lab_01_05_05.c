#include <stdio.h>
#define OK 0
#define ERROR_CODE 1

int input(int *);
void output(int, int);
void digit_out(int);

int main(void)
{
    int n, return_code;
    return_code = input(&n);
    output(n, return_code);
    return return_code;
}

int input(int *n)
{
    int return_code = OK;
    printf("Enter the number: ");
    int num_of_var = scanf("%d", n);
    if (num_of_var != 1)
    {
        return_code = ERROR_CODE;
    }
    else if (*n <= 0)
    {
        return_code = ERROR_CODE;
    }

    return return_code;
}

void output(int n, int return_code)
{
    if (return_code == OK)
    {
        printf("The number is: ");
        digit_out(n);
    }
    else
    {
        printf("Incorrect input.");
    }
}

void digit_out(int n)
{
    if (n < 10)
    {
        printf("%d", n);
    }
    else
    {
        digit_out(n / 10);
        printf("%d", n % 10);
    }
}