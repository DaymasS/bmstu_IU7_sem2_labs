#include "process.h"

int process(FILE *f, int *max_count)
{
    *max_count = 0;
    int rc = OK, cur, prev, cur_count = 1;
    if (f == NULL || max_count == NULL)
    {
        rc = ERROR_PARAM;
    }
    else
    {
        if (fscanf(f, "%d", &prev) != 1)
        {
            rc = ERROR_INPUT;
        }
        while (fscanf(f, "%d", &cur) == 1)
        {
            if (cur == prev)
            {
                cur_count++;
            }
            else
            {
                if (cur_count > *max_count)
                {
                    *max_count = cur_count;
                }
                cur_count = 1;
            }
            prev = cur;
        }
        if (cur_count > *max_count)
        {
            *max_count = cur_count;
        }
    }
    return rc;
}
