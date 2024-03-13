#include <stdio.h>

void input(double *, double *, double *, double *);
double calc_temp(double, double, double, double);
double calc_vol(double, double);
void output(double, double);

int main(void)
{
    double v1, t1, v2, t2, v, t;
    input(&v1, &t1, &v2, &t2);
    t = calc_temp(v1, t1, v2, t2);
    v = calc_vol(v1, v2);
    output(v, t);
    return 0;
}

void input(double *v1, double *t1, double *v2, double *t2)
{
    printf("Enter two pairs: volume tepmreture: ");
    scanf("%lf %lf %lf %lf", v1, t1, v2, t2);
}

double calc_temp(double v1, double t1, double v2, double t2)
{
    double t = (v1 * t1 + v2 * t2) / (v1 + v2);
    return t;
}

double calc_vol(double v1, double v2)
{
    double v = v1 + v2;
    return v;
}

void output(double v, double t)
{
    printf("The resulting volume eq: %.6lf and tepreture: %.6lf \n", v, t);
}