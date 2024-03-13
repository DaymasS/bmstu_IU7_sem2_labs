#include <stdio.h>
#include <math.h>
#include <limits.h>
#define OK 0
#define ERROR_CODE 1

int input(double *, double *);
double func_f(double);
double func_s(double, double);
double calc_relative_error(double, double);
double calc_absolut_error(double, double);
void output(double, double, double, double, int);

int main(void)
{
    double x, eps, f_x, s_x, rel_err, abs_err;
    int return_code;
    return_code = input(&x, &eps);
    if (return_code == OK)
    {
        f_x = func_f(x);
        s_x = func_s(x, eps);
        abs_err = calc_absolut_error(f_x, s_x);
        rel_err = calc_relative_error(abs_err, f_x);
    }
    output(s_x, f_x, abs_err, rel_err, return_code);
    return return_code;
}

int input(double *x, double *eps)
{
    int return_code, num_of_var;
    printf("Enter value X and EPS: ");
    num_of_var = scanf("%lf %lf", x, eps);
    if (num_of_var == 2 && fabs(*x) < 1 && *eps > 0 && *eps <= 1)
    {
        return_code = OK;
    }
    else
    {
        return_code = ERROR_CODE;
    }

    return return_code;
}

double func_f(double x)
{
    return 1 / sqrt(1 - x * x);
}

double func_s(double x, double eps)
{
    double result, current_value, current_coef;
    current_value = x * x / 2;
    current_coef = 2;
    result = 1;
    while (fabs(current_value) > eps)
    {
        result += current_value;
        current_coef += 2;
        current_value *= (current_coef - 1) * x * x / current_coef;
    }
    return result;
}

double calc_absolut_error(double f_x, double s_x)
{
    return fabs(f_x - s_x);
}

double calc_relative_error(double abs_err, double f_x)
{
    return abs_err / fabs(f_x);
}

void output(double s_x, double f_x, double abs_err, double rel_err, int return_code)
{
    if (return_code == OK)
    {
        printf("S(x) = %lf , F(x) = %lf , absolut error: %lf , relative error: %lf ", s_x, f_x, abs_err, rel_err);
    }
    else
    {
        printf("Incorrect input.");
    }
}