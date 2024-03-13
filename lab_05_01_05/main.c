#include "main.h"

int main(void)
{
    int rc, count;
    printf("Введите последовательность эл-тов (для окончания ввода - символ отличный от цыфры): ");
    rc = process(stdin, &count);
    output(count, rc);
    return rc;
}
