#include "output.h"

void output(int count, int rc)
{
    if (rc == OK)
    {
        printf("Ближайшее к среднему число: %d \n", count);
    }
    else
    {
        if (rc == ERROR_INPUT)
        {
            printf("Error! Последовательность должна состоять из одного или более элемента. \n");
        }
        else if (rc == ERROR_PARAM)
        {
            printf("Error! Невалидные параметры. \n");
        }
        else if (rc == ERROR_FILE_NOT_FOUND)
        {
            printf("Error! Файл не найден. \n");
        }
    }
}
