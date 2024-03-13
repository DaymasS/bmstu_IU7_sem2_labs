/*
Для работы с числами используется тип int,
файл упорядочивается по возрастанию,
сортировка пузырьком
*/

#include "main.h"

int main(int argc, char **argv)
{
    int rc;
    if (argc == 3 || argc == 4)
    {
        rc = controller(argc, argv);
    }
    else
    {
        rc = ERROR_ARGUMENTS;
    }
    return rc;
}
