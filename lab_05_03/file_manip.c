#include "file_manip.h"

int calc_file_size(FILE *, int *);
int get_number_by_pos(FILE *, int, int *);
int put_number_by_pos(FILE *, int, int);

int gen_file(FILE *f, int size)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        rc = OK;
        srand(time(NULL));
        int tmp;
        for (int i = 0; i < size; i++)
        {
            tmp = rand();
            fwrite(&tmp, sizeof(int), 1, f);
        }
    }
    return rc;
}

int read_file(FILE *f)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        int f_size, tmp_val;
        rc = calc_file_size(f, &f_size);
        if (rc == OK)
        {
            for (int i = 0; rc == OK && i < f_size; i++)
            {
                if (fread(&tmp_val, sizeof(int), 1, f))
                {
                    printf("%d ", tmp_val);
                }
                else
                {
                    rc = ERROR_FILE_STRUCTURE;
                }
            }
            printf("\n");
        }
    }
    return rc;
}

int sort_file(FILE *f)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        int size, val_1, val_2;
        rc = calc_file_size(f, &size);
        if (rc == OK)
        {
            for (int i = 0; i < size - 1 && rc == OK; i++)
            {
                for (int j = i + 1; j < size && rc == OK; j++)
                {
                    if (get_number_by_pos(f, i, &val_1) != OK ||
                        get_number_by_pos(f, j, &val_2) != OK)
                    {
                        rc = ERROR_INPUT_OUTPUT;
                    }
                    if (val_1 > val_2)
                    {
                        if (put_number_by_pos(f, i, val_2) != OK ||
                            put_number_by_pos(f, j, val_1) != OK)
                        {
                            rc = ERROR_INPUT_OUTPUT;
                        }
                    }
                }
            }
        }
    }
    return rc;
}

int calc_file_size(FILE *f, int *size)
{
    int rc;
    if (f == NULL || size == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        if (fseek(f, 0L, SEEK_END))
        {
            rc = ERROR_FILE_EMPTY;
        }
        else
        {
            long byte_size = ftell(f);
            if (byte_size <= 0)
            {
                rc = ERROR_FILE_EMPTY;
            }
            else if (fseek(f, 0L, SEEK_SET))
            {
                rc = ERROR_INPUT_OUTPUT;
            }
            else if (byte_size % sizeof(int) != 0)
            {
                rc = ERROR_FILE_STRUCTURE;
            }
            else
            {
                *size = byte_size / sizeof(int);
                rc = OK;
            }
        }
    }
    return rc;
}

int get_number_by_pos(FILE *f, int index, int *val)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        if (fseek(f, index * sizeof(int), SEEK_SET) == 0)
        {
            if (fread(val, sizeof(int), 1, f) != 1)
            {
                rc = ERROR_INPUT_OUTPUT;
            }
            else
            {
                rc = OK;
            }
        }
        else
        {
            rc = ERROR_INPUT_OUTPUT;
        }
    }
    return rc;
}

int put_number_by_pos(FILE *f, int index, int val)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        if (fseek(f, index * sizeof(int), SEEK_SET) == 0)
        {
            if (fwrite(&val, sizeof(int), 1, f) != 1)
            {
                rc = ERROR_INPUT_OUTPUT;
            }
            else
            {
                rc = OK;
            }
        }
        else
        {
            rc = ERROR_INPUT_OUTPUT;
        }
    }
    return rc;
}
