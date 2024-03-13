#include "file_manip.h"

int calc_file_size(FILE *, int *);
int get_student_by_pos(FILE *, int, student *);
int put_student_by_pos(FILE *, int, student *);
int calc_avg_student_mark(student *, double *);
int calc_avg_all_students_mark(FILE *, double *);
int ftruncate(int fd, off_t length);
int fileno(FILE *stream);

int create_file(FILE *f, student *st)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        rc = OK;
        while (scanf("%s %s %u %u %u %u", st->s_name, st->f_name, &st->marks[0], &st->marks[1], &st->marks[2], &st->marks[3]) > 2)
        {
            fwrite(st, sizeof(student), 1, f);
        }
    }
    return rc;
}

int read_file(FILE *in_f, FILE *out_f, char sub[MAX_S_NAME_LENGTH], student *st)
{
    int rc;
    if (in_f == NULL || out_f == NULL || sub == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        int f_size, num = 0;
        rc = calc_file_size(in_f, &f_size);
        if (rc == OK)
        {
            if (fseek(in_f, 0L, SEEK_SET) || fseek(out_f, 0L, SEEK_SET))
            {
                rc = ERROR_INPUT_OUTPUT;
            }
            for (int i = 0; rc == OK && i < f_size; i++)
            {
                if (fread(st, sizeof(student), 1, in_f) == 1)
                {
                    if (strncmp(st->s_name, sub, strlen(sub)) == 0)
                    {
                        if (fwrite(st, sizeof(student), 1, out_f))
                        {
                            num++;
                        }
                        else
                        {
                            rc = ERROR_INPUT_OUTPUT;
                        }
                    }
                }
                else
                {
                    rc = ERROR_FILE_STRUCTURE;
                }
            }
            if (num == 0)
            {
                rc = ERROR_FILE_EMPTY;
            }
        }
    }
    return rc;
}

int cut_file(FILE *f, student *st)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        int size;
        double g_avg, l_avg = 0;
        rc = calc_file_size(f, &size);
        if (rc == OK)
        {
            rc = calc_avg_all_students_mark(f, &g_avg);
            for (int i = 0; i < size && rc == OK; i++)
            {
                rc = get_student_by_pos(f, i, st);
                if (rc == OK)
                {
                    rc = calc_avg_student_mark(st, &l_avg);
                    if (l_avg < g_avg)
                    {
                        for (int j = i + 1; j < size && rc == OK; j++)
                        {
                            rc = get_student_by_pos(f, j, st);
                            if (rc == OK)
                            {
                                rc = put_student_by_pos(f, j - 1, st);
                            }
                        }
                        i--;
                        size--;
                    }
                }
            }
            if (rc == OK)
            {
                if (ftruncate(fileno(f), size * sizeof(student)) != 0)
                {
                    rc = ERROR_TRUNCATE;
                }
            }
        }
    }
    return rc;
}

int sort_file(FILE *f, student *st_1, student *st_2)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        int size, comp_res;
        rc = calc_file_size(f, &size);
        if (rc == OK)
        {
            for (int i = 0; i < size - 1 && rc == OK; i++)
            {
                for (int j = i + 1; j < size && rc == OK; j++)
                {
                    if (get_student_by_pos(f, i, st_1) != OK ||
                        get_student_by_pos(f, j, st_2) != OK)
                    {
                        rc = ERROR_INPUT_OUTPUT;
                    }
                    else
                    {
                        comp_res = strcmp(st_1->s_name, st_2->s_name);
                        if (comp_res == 0)
                        {
                            comp_res = strcmp(st_1->f_name, st_2->f_name);
                            if (comp_res > 0)
                            {
                                if (put_student_by_pos(f, i, st_2) != OK ||
                                    put_student_by_pos(f, j, st_1) != OK)
                                {
                                    rc = ERROR_INPUT_OUTPUT;
                                }
                            }
                        }
                        else if (comp_res > 0)
                        {
                            if (put_student_by_pos(f, i, st_2) != OK ||
                                put_student_by_pos(f, j, st_1) != OK)
                            {
                                rc = ERROR_INPUT_OUTPUT;
                            }
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
            else if (byte_size % sizeof(student) != 0)
            {
                rc = ERROR_FILE_STRUCTURE;
            }
            else
            {
                *size = byte_size / sizeof(student);
                rc = OK;
            }
        }
    }
    return rc;
}

int get_student_by_pos(FILE *f, int index, student *st)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        if (fseek(f, index * sizeof(student), SEEK_SET) == 0)
        {
            if (fread(st, sizeof(student), 1, f) != 1)
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

int put_student_by_pos(FILE *f, int index, student *st)
{
    int rc;
    if (f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        if (fseek(f, index * sizeof(student), SEEK_SET) == 0)
        {
            if (fwrite(st, sizeof(student), 1, f) != 1)
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

int calc_avg_student_mark(student *st, double *avg)
{
    int rc;
    if (st == NULL || avg == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        rc = OK;
        *avg = 0;
        for (int i = 0; i < MAX_MARK_ARR_LENGTH; i++)
        {
            *avg += st->marks[i];
        }
        *avg /= MAX_MARK_ARR_LENGTH;
    }
    return rc;
}

int calc_avg_all_students_mark(FILE *f, double *avg)
{
    int rc;
    if (f == NULL || avg == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        int size = 0;
        double cur_val;
        student st;
        rc = calc_file_size(f, &size);
        *avg = 0;
        for (int i = 0; i < size && rc == OK; i++)
        {
            rc = get_student_by_pos(f, i, &st);
            if (rc == OK)
            {
                rc = calc_avg_student_mark(&st, &cur_val);
                if (rc == OK)
                {
                    *avg += cur_val;
                }
            }
        }
        if (size != 0)
        {
            *avg /= size;
        }
    }
    return rc;
}

int print_st_data(FILE *f, student *st)
{
    int rc, size;
    if (st == NULL || f == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        rc = calc_file_size(f, &size);
        for (int i = 0; i < size && rc == OK; i++)
        {
            if (get_student_by_pos(f, i, st) != OK)
            {
                rc = ERROR_INPUT_OUTPUT;
            }
            else
            {
                printf("%s\n%s\n%d\n%d\n%d\n%d\n", st->s_name, st->f_name, st->marks[0], st->marks[1], st->marks[2], st->marks[3]);
            }
        }
    }
    return rc;
}
