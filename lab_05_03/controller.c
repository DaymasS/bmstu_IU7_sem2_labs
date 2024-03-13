#include "controller.h"

int controller(int argc, char **argv)
{
    int rc;
    if (argc == 3)
    {
        if (strcmp(argv[1], "p") == 0)
        {
            FILE *read_f = fopen(argv[2], "rb");
            if (read_f == NULL)
            {
                rc = ERROR_FILE_NOT_FOUND;
            }
            else
            {
                rc = read_file(read_f);
                fclose(read_f);
            }
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            FILE *sort_f = fopen(argv[2], "r+b");
            if (sort_f == NULL)
            {
                rc = ERROR_FILE_NOT_FOUND;
            }
            else
            {
                rc = sort_file(sort_f);
                fclose(sort_f);
            }
        }
        else
        {
            rc = ERROR_ARGUMENTS;
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "c") == 0)
        {
            FILE *new_f = fopen(argv[3], "wb");
            if (new_f == NULL)
            {
                rc = ERROR_FILE_NOT_FOUND;
            }
            else
            {
                int size = atoi(argv[2]);
                if (size == 0)
                {
                    rc = ERROR_ARGUMENTS;
                }
                else
                {
                    rc = gen_file(new_f, atoi(argv[2]));
                }
                fclose(new_f);
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
