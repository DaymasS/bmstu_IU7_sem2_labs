#include <stdio.h>
#include <stdint.h>
#define OK 0
#define INCORRECT_INPUT 1
#define OUT_OF_BOUNDS 2
#define MAX_BYTE_VAL 255
#define BYTE_LENGTH 8

int input(uint8_t *, uint8_t *, uint8_t *, uint8_t *);
uint32_t pack(uint8_t, uint8_t, uint8_t, uint8_t);
void unpack(uint8_t *, uint8_t *, uint8_t *, uint8_t *, uint32_t);
void output(int, uint32_t, uint8_t, uint8_t, uint8_t, uint8_t);

int main(void)
{
    int return_code;
    uint8_t a, b, c, d;
    uint32_t packed;
    return_code = input(&a, &b, &c, &d);
    packed = pack(a, b, c, d);
    unpack(&a, &b, &c, &d, packed);
    output(return_code, packed, a, b, c, d);
    return return_code;
}

int input(uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d)
{
    int num_of_var, return_code;
    long long a1, b1, c1, d1;
    printf("Enter four bytes: ");
    num_of_var = scanf("%lld %lld %lld %lld", &a1, &b1, &c1, &d1);
    if (num_of_var != 4)
    {
        return_code = INCORRECT_INPUT;
    }
    else
    {
        if (a1 > MAX_BYTE_VAL || b1 > MAX_BYTE_VAL || c1 > MAX_BYTE_VAL || d1 > MAX_BYTE_VAL)
        {
            return_code = OUT_OF_BOUNDS;
        }
        else
        {
            return_code = OK;
            *a = a1;
            *b = b1;
            *c = c1;
            *d = d1;
        }
    }
    return return_code;
}

uint32_t pack(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    uint32_t packed = 0;
    packed |= a << BYTE_LENGTH * 3;
    packed |= b << BYTE_LENGTH * 2;
    packed |= c << BYTE_LENGTH;
    packed |= d;
    return packed;
}

void unpack(uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d, uint32_t packed)
{
    *a = (packed >> BYTE_LENGTH * 3);
    *b = (packed >> BYTE_LENGTH * 2);
    *c = (packed >> BYTE_LENGTH);
    *d = (packed);
}

void output(int return_code, uint32_t packed, uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    if (return_code == OK)
    {
        printf("Result: ");
        for (int i = 31; i >= 0; i--)
        {
            printf("%d", (packed >> i) & 0x01);
        }
        printf(" %hhu %hhu %hhu %hhu", a, b, c, d);
    }
    else
    {
        printf("Error: ");
        if (return_code == INCORRECT_INPUT)
        {
            printf("incorrect input.");
        }
        else
        {
            printf("out of bounds.");
        }
    }
}