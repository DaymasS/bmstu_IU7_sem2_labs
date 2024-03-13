#include "output.h"

void output(int count, int rc)
{
    if (rc == OK)
    {
        printf("Наибольшее кол-во одинаковых эл-тов подряд: %d \n", count);
    }
    else
    {
        if (rc == ERROR_INPUT)
        {
            printf("Error! Последовательность должна состоять из одного или более элемента. \n");
        }
        else if (rc == ERROR_PARAM)
        {
            printf("Error! Невалидные параметры функции. \n");
        }
    }
}
