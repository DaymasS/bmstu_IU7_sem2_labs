#include <stdio.h>

#define MAX_ARRAY_LENGTH 10
#define MIN_ARRAY_LENGTH 1
#define OK 0
#define ERROR 1

int input(int *, int **);
void max_func(int *, int *, int *);
void output(int, int);

int main(void)
{
    int arr[MAX_ARRAY_LENGTH], *arr_end, return_code, max_elem = 0;
    return_code = input(arr, &arr_end);
    if (return_code != ERROR)
    {
        max_func(arr, arr_end, &max_elem);
    }
    output(max_elem, return_code);
    return return_code;
}

int input(int *arr, int **end)
{
    int *cur = arr, return_code = OK, length;
    printf("Enter length of array: ");
    if (scanf("%d", &length) != 1)
    {
        return_code = ERROR;
    }
    else if (length > MAX_ARRAY_LENGTH || length < MIN_ARRAY_LENGTH)
    {
        return_code = ERROR;
    }
    else
    {
        printf("Enter elements of array: ");
        for (int i = 0; i < length && return_code != ERROR; i++)
        {
            if (scanf("%d", cur++) != 1)
            {
                return_code = ERROR;
            }
        }
    }
    if (return_code == OK)
    {
        *end = arr + length;
    }
    else
    {
        *end = arr;
    }
    return return_code;
}

void max_func(int *arr_beg, int *arr_end, int *max_elem)
{
    int cur_sum;
    *max_elem = *arr_beg + *(arr_end - 1);
    for (int *arr_cur_b = arr_beg + 1, *arr_cur_e = arr_end - 2; arr_cur_b <= arr_cur_e; arr_cur_b++, arr_cur_e--)
    {
        cur_sum = *arr_cur_b + *arr_cur_e;
        if (cur_sum > *max_elem)
        {
            *max_elem = cur_sum;
        }
    }
}

void output(int max_elem, int return_code)
{
    if (return_code != ERROR)
    {
        printf("Max sum: %d ", max_elem);
    }
    else
    {
        printf("Incorrect input");
    }
}
