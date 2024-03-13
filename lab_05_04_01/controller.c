#include "controller.h"

int controller(int argc, char **argv)
{
    int rc;
    student st_1, st_2;
    if (argc == 3)
    {
        if (strcmp(argv[1], "db") == 0)
        {
            FILE *cut_f = fopen(argv[2], "r+b");
            if (cut_f == NULL)
            {
                rc = ERROR_FILE_NOT_FOUND;
            }
            else
            {
                rc = cut_file(cut_f, &st_1);
                fclose(cut_f);
            }
        }
        else if (strcmp(argv[1], "sb") == 0)
        {
            FILE *sort_f = fopen(argv[2], "r+b");
            if (sort_f == NULL)
            {
                rc = ERROR_FILE_NOT_FOUND;
            }
            else
            {
                rc = sort_file(sort_f, &st_1, &st_2);
                if (rc == OK)
                {
                    rc = print_st_data(sort_f, &st_1);
                }
                fclose(sort_f);
            }
        }
        else if (strcmp(argv[1], "cb") == 0)
        {
            FILE *new_f = fopen(argv[2], "wb");
            if (new_f == NULL)
            {
                rc = ERROR_FILE_NOT_FOUND;
            }
            else
            {
                rc = create_file(new_f, &st_1);
                fclose(new_f);
            }
        }
        else
        {
            rc = ERROR_ARGUMENTS;
        }
    }
    else if (argc == 5)
    {
        if (strcmp(argv[1], "fb") == 0)
        {
            if (strcmp(argv[2], argv[3]) == 0)
            {
                rc = ERROR_PARAM;
            }
            else
            {
                FILE *read_f = fopen(argv[2], "rb");
                FILE *new_f = fopen(argv[3], "wb");
                if (new_f == NULL || read_f == NULL)
                {
                    rc = ERROR_FILE_NOT_FOUND;
                }
                else
                {
                    if (strlen(argv[4]) > MAX_S_NAME_LENGTH)
                    {
                        rc = ERROR_ARGUMENTS;
                    }
                    else
                    {
                        rc = read_file(read_f, new_f, argv[4], &st_1);
                    }
                    fclose(new_f);
                    fclose(read_f);
                }
            }
        }
        else
        {
            rc = ERROR_ARGUMENTS;
        }
    }
    else
    {
        rc = ERROR_ARGUMENTS;
    }
    return rc;
}
