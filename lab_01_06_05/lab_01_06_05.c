#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR_CODE 1
#define EPS 0.000001

int input(double *, double *, double *, double *, double *, double *, double *, double *);
void output(int, int);
int eq(double, double);
int check_intersection_vectors(double, double, double, double, double, double, double, double);
double calc_k_vectors(double, double, double, double);

int main(void)
{
    int return_code, is_intersect;
    double xp, yp, xq, yq, xr, yr, xs, ys;
    return_code = input(&xp, &yp, &xq, &yq, &xr, &yr, &xs, &ys);
    if (return_code == OK)
    {
        is_intersect = check_intersection_vectors(xp, yp, xq, yq, xr, yr, xs, ys);
    }
    else
    {
        is_intersect = 0;
    }
    output(is_intersect, return_code);
    return return_code;
}


int check_intersection_vectors(double xp, double yp, double xq, double yq, double xr, double yr, double xs, double ys)
{
    int is_inter;
    double k_pq_1, k_pq_2, k_rs_1, k_rs_2;
    k_pq_1 = calc_k_vectors(xq - xp, yq - yp, xr - xp, yr - yp);
    k_pq_2 = calc_k_vectors(xq - xp, yq - yp, xs - xp, ys - yp);
    k_rs_1 = calc_k_vectors(xs - xr, ys - yr, xp - xr, yp - yr);
    k_rs_2 = calc_k_vectors(xs - xr, ys - yr, xq - xr, yq - yr);

    if (k_pq_1 * k_pq_2 < 0 && k_rs_1 * k_rs_2 < 0)
    {
        is_inter = 1;
    }
    else
    {
        is_inter = 0;
    }
    return is_inter;
}

double calc_k_vectors(double xa, double ya, double xb, double yb)
{
    return xa * yb - ya * xb;
}

int input(double *x1, double *y1, double *x2, double *y2, double *x3, double *y3, double *x4, double *y4)
{
    int return_code = OK, num_of_var;
    printf("Enter four pairs of coords. (x, y): ");
    num_of_var = scanf("%lf %lf %lf %lf %lf %lf %lf %lf", x1, y1, x2, y2, x3, y3, x4, y4);
    if ((num_of_var != 8))
    {
        return_code = ERROR_CODE;
    }
    else
    {
        if (eq(*x1, *x2) && eq(*y1, *y2))
        {
            return_code = ERROR_CODE;
        }
        if (eq(*x3, *x4) && eq(*y3, *y4))
        {
            return_code = ERROR_CODE;
        }
    }

    return return_code;
}

void output(int is_inter, int return_code)
{
    if (return_code == OK)
    {
        printf("Result: %d ", is_inter);
    }
    else
    {
        printf("Incorrect input.");
    }
}

int eq(double a, double b)
{
    int result;
    if (fabs(a - b) < EPS)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}