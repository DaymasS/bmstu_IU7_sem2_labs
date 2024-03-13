#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR_CODE 1
# define PI 3.141592

void output(double);
void input(double *, double *, double *);
double calc_square(double, double, double);

int main(void)
{
	int return_code = OK;
	double a, b, q, s;
	input(&a, &b, &q);
	s = calc_square(a, b, q);
	output(s);
	return return_code;
}

void output(double s)
{
	printf("Square of trapezoid eq: %.6lf \n", s);
}

void input(double *a, double *b, double *q)
{
	printf("Enter trapesoid bases and it's angle: ");
	scanf("%lf %lf %lf", a, b, q);
}

double calc_square(double a, double b, double q)
{
	double s;
	s = (a + b) / 2 * (tan(q * PI / 180) * fabs(a - b) / 2);
	return s;
}