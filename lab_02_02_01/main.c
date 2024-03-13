#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_LENGTH 10
#define MIN_ARRAY_LENGTH 1
#define OK 0
#define ERROR 1

int input(int *, int *);
int is_num_prime(int);
int is_prime(int *, int, int *, int *);
void output(int *, int, int);

int main(void)
{
    int length, arr_in[MAX_ARRAY_LENGTH], arr_res[MAX_ARRAY_LENGTH], return_code, num_of_prime = 0;
    return_code = input(arr_in, &length);
    if (return_code == OK)
    {
        return_code = is_prime(arr_in, length, arr_res, &num_of_prime);
    }
    output(arr_res, num_of_prime, return_code);
    return return_code;
}

int input(int *beg, int *length)
{
    int *cur = beg, return_code = OK;
    printf("Enter length of array: ");
    if (scanf("%d", length) != 1)
    {
        return_code = ERROR;
    }
    else if (*length > MAX_ARRAY_LENGTH || *length < MIN_ARRAY_LENGTH)
    {
        return_code = ERROR;
    }
    else
    {
        printf("Enter elements of array: ");
        for (int i = 0; i < *length && return_code != ERROR; i++)
        {
            if (scanf("%d", cur++) != 1)
            {
                return_code = ERROR;
            }
        }
    }
    return return_code;
}

int is_prime(int *beg_in, int length, int *beg_res, int *num_of_prime)
{
    int *cur_in = beg_in, *cur_res = beg_res, return_code, *end_in = beg_in + length;
    for (; cur_in < end_in; cur_in++)
    {
        if (is_num_prime(*cur_in))
        {
            *cur_res = *cur_in;
            cur_res++;
        }
    }
    *num_of_prime = cur_res - beg_res;
    if (*num_of_prime == 0)
    {
        return_code = ERROR;
    }
    else
    {
        return_code = OK;
    }
    return return_code;
}

int is_num_prime(int num)
{
    int is_prime = 1;
    if (num <= 1)
    {
        is_prime = 0;
    }
    for (int devider = 2; devider * devider <= num && is_prime; devider++)
    {
        if (num % devider == 0)
        {
            is_prime = 0;
        }
    }
    return is_prime;
}

void output(int *arr_beg, int length, int return_code)
{
    int *arr_end = arr_beg + length;
    if (return_code == OK)
    {
        printf("Result: ");
        for (int *cur_arr = arr_beg; cur_arr < arr_end; cur_arr++)
        {
            printf("%d ", *cur_arr);
        }
    }
    else
    {
        printf("Incorrect input");
    }
}
