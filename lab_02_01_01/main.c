#include <stdio.h>

#define MAX_ARRAY_LENGTH 10
#define MIN_ARRAY_LENGTH 1
#define OK 0
#define ERROR 1

int input(int *, int *);
int calc_mult(int *, int, int *);
void output(int, int);

int main(void)
{
    int length, arr[MAX_ARRAY_LENGTH], result = 0, return_code;
    return_code = input(arr, &length);
    if (return_code == OK)
    {
        return_code = calc_mult(arr, length, &result);
    }
    output(result, return_code);
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

int calc_mult(int *beg_arr, int length, int *result)
{
    int *cur_arr = beg_arr, has_odd = 0, return_code, *end_arr = beg_arr + length;
    *result = 1;
    for (; cur_arr < end_arr; cur_arr++)
    {
        if (*cur_arr % 2)
        {
            has_odd = 1;
            *result *= *cur_arr;
        }
    }
    if (has_odd)
    {
        return_code = OK;
    }
    else
    {
        return_code = ERROR;
    }
    return return_code;
}

void output(int result, int return_code)
{
    if (return_code == OK)
    {
        printf("Result: %d", result);
    }
    else
    {
        printf("Incorrect input");
    }
}
