#include "comp_bin.h"

int open_file(FILE **, char *);
int open_bin_files(FILE **, char *, FILE **, char *);
int comp_files(FILE *, FILE *, int *);

int main(void)
{
    FILE *f_1 = NULL, *f_2 = NULL;
    char f_1_name[MAX_FILE_NAME], f_2_name[MAX_FILE_NAME];
    int result, rc;
    rc = open_bin_files(&f_1, f_1_name, &f_2, f_2_name);
    if (rc == OK)
    {
        rc = comp_files(f_1, f_2, &result);
    }
    return rc;
}

int comp_files(FILE *f_1, FILE *f_2, int *result)
{
    int rc = OK;
    unsigned char *buf_1, *buf_2;
    if (f_1 == NULL || f_2 == NULL)
    {
        rc = ERROR_ARGUMENTS;
    }
    else
    {
        fread(buf_1, sizeof(buf_1), 1, f_1);
        fread(buf_2, sizeof(buf_2), 1, f_2);
        if (buf_1 == buf_2)
        {
            *result = 1;
        }
        else
        {
            *result = 0;
        }
    }
    return  rc;
}

int open_file(FILE **f, char name[MAX_FILE_NAME])
{
    int rc;
    if (name == NULL)
    {
        rc = ERROR_ARGUMENTS;
    }
    else
    {
        *f = fopen(name, "rb");
        if (*f == NULL)
        {
            rc = ERROR_FILE_NOT_FOUND;
        }
    }
    return rc;
}

int open_bin_files(FILE **f_1, char f_1_name[MAX_FILE_NAME], FILE **f_2, char f_2_name[MAX_FILE_NAME])
{
    int rc;
    char w[MAX_FILE_NAME];
    if (f_1 == NULL || f_2 == NULL || f_1_name == NULL || f_2_name == NULL)
    {
        rc = ERROR_ARGUMENTS;
    }
    else if (scanf("%s", f_1_name) == 0)
    {
        rc = ERROR_ARGUMENTS;
    }
    else if (scanf("%s", f_2_name) == 0)
    {
        rc = ERROR_ARGUMENTS;
    }
    else 
    {
        rc = open_file(f_1, f_1_name);
        fscanf(*f_1, "%s", w);
        printf("%s", w);
        if (rc == OK)
        {
            rc = open_file(f_2, f_2_name);
        }
    }
    return rc;
}
