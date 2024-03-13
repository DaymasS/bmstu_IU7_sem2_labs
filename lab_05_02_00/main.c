#include "main.h"

int main(int argc, char **argv)
{
    int rc, avg_num = 0;
    FILE *f;
    if (argc != 2)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            rc = ERROR_FILE_NOT_FOUND;
        }
        else
        {
            rc = process(f, &avg_num);
            fclose(f);
        }
    }
    output(avg_num, rc);
    return rc;
}
