#include "main.h"

int main(void)
{
    printf("strpbrk failed %d times\n", test_strpbrk());
    printf("strspn failed %d times\n", test_strspn());
    printf("strcspn failed %d times\n", test_strcspn());
    printf("strchr failed %d times\n", test_strchr());
    printf("strrchr failed %d times\n", test_strrchr());
}
