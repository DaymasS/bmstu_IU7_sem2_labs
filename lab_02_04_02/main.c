#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_LENGTH 10
#define MIN_ARRAY_LENGTH 1
#define OK 0
#define ERROR 1
#define OUT_OF_BOUNDS 100

int input(int *, int *);
void sort(int *, int);
void shift(int *, int *);
void output(int *, int, int);

int main(void)
{
    int length, arr[MAX_ARRAY_LENGTH + 1], return_code;
    return_code = input(arr, &length);
    if (return_code != ERROR)
    {
        sort(arr, length);
    }
    output(arr, length, return_code);
    return return_code;
}

int input(int *beg, int *length)
{
    int *cur = beg, return_code = OK;
    printf("Enter elements of array: ");
    for (*length = 0; *length < MAX_ARRAY_LENGTH + 1 && return_code == OK; ++*length)
    {
        if (scanf("%d", cur++) != 1)
        {
            return_code = ERROR;
            --*length;
        }
    }
    if (*length == MAX_ARRAY_LENGTH + 1)
    {
        *length = MAX_ARRAY_LENGTH;
        return_code = OUT_OF_BOUNDS;
    }
    else if (*length != 0)
    {
        return_code = OK;
    }
    return return_code;
}

void sort(int *arr_beg, int length)
{
    int *arr_flag = NULL, temp, *arr_end = arr_beg + length;
    for (int *arr_cur = arr_beg + 1; arr_cur < arr_end; arr_cur++)
    {
        temp = *arr_cur;
        if (*arr_cur < *arr_beg)
        {
            shift(arr_beg, arr_cur);
            *arr_beg = temp;
        }
        else
        {
            for (arr_flag = arr_cur - 1; *arr_flag > *arr_cur;)
                arr_flag--;
            arr_flag++;
            shift(arr_flag, arr_cur);
            *arr_flag = temp;
        }
    }
}

void shift(int *sh_beg, int *sh_end)
{
    for (int *sh_cur = sh_end; sh_cur > sh_beg; sh_cur--)
    {
        *sh_cur = *(sh_cur - 1);
    }
}

void output(int *arr_beg, int length, int return_code)
{
    int *arr_end = arr_beg + length;
    if (return_code != ERROR)
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
