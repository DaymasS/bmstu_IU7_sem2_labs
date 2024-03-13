#include "process.h"

int process(FILE *f, int *avg_num)
{
    int rc = OK, cur, sum = 0, amount = 0;
    double avg, min_delta;
    if (f == NULL)
    {
        rc = ERROR_FILE_NOT_FOUND;
    }
    else
    {
        while (fscanf(f, "%d", &cur) == 1)
        {
            amount++;
            sum += cur;
        }
        if (amount == 0)
        {
            rc = ERROR_INPUT;
        }
        else
        {
            avg = sum / amount;
            rewind(f);
            if (fscanf(f, "%d", &cur) == 1)
            {
                min_delta = fabs(cur - avg);
                *avg_num = cur;
                while (fscanf(f, "%d", &cur) == 1)
                {
                    if (fabs(cur - avg) < min_delta)
                    {
                        min_delta = fabs(cur - avg);
                        *avg_num = cur;
                    }
                }
            }
        }
    }
    return rc;
}
