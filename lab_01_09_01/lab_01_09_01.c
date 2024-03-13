#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR_CODE 1
#define EPS 1e-6

double input_element();
double calc_sum(int *);
void output(int, double);

int main(void)
{
    int return_code;
    double sum, g_x;
    sum = calc_sum(&return_code);
    g_x = sin(sum);
    output(return_code, g_x);
    return return_code;
}

double calc_sum(int *return_code)
{
    double sum = 0, element;
    int num_of_var = 0;
    element = input_element();
    while (element > 0 || fabs(element) < EPS)
    {
        num_of_var += 1;
        sum += sqrt(element / num_of_var);
        element = input_element();
    }
    if (num_of_var == 0 || fabs(element + 2) < EPS)
    {
        *return_code = ERROR_CODE;
    }
    else
    {
        *return_code = OK;
    }
    return sum;
}

double input_element()
{
    int num_of_var;
    double element;
    printf("Enter element (neg to stop): ");
    num_of_var = scanf("%lf", &element);
    if (num_of_var != 1)
    {
        element = -2;
    }
    else if (element < 0)
    {
        element = -1;
    }
    return element;
}

void output(int return_code, double g_x)
{
    if (return_code == OK)
    {
        printf("%lf", g_x);
    }
    else
    {
        printf("Incorrect input.");
    }
}