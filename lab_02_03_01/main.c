#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_LENGTH 10
#define MIN_ARRAY_LENGTH 1
#define OK 0
#define ERROR 1

int input(int *, int *);
int add_fib(int *, int *);
int shift_array(int *, int *);
void output(int *, int, int);

int main(void)
{
    int length, arr[MAX_ARRAY_LENGTH * 2], return_code;
    return_code = input(arr, &length);
    if (return_code == OK)
    {
        return_code = add_fib(arr, &length);
    }
    output(arr, length, return_code);
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

int add_fib(int *beg_arr, int *length)
{
    int fib_next = 1, fib_cur = 0, fib_temp, return_code = OK, *end_arr = beg_arr + *length;
    for (int *cur_arr = beg_arr; cur_arr < end_arr; cur_arr++)
    {
        if (*cur_arr % 3 == 0)
        {
            shift_array(cur_arr + 1, end_arr);
            end_arr++;
            ++*length;
            *(cur_arr + 1) = fib_cur;
            fib_temp = fib_next;
            fib_next += fib_cur;
            fib_cur = fib_temp;
            cur_arr++;
        }
    }
    return return_code;
}

int shift_array(int *beg_arr, int *end_arr)
{
    for (int *cur_arr = end_arr; cur_arr > beg_arr; cur_arr--)
    {
        *cur_arr = *(cur_arr - 1);
    }
    return OK;
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
