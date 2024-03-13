#include "main.h"

int main(int argc, char **argv)
{
    int rc;
    if (argc == 3 || argc == 5)
    {
        rc = controller(argc, argv);
    }
    else
    {
        rc = ERROR_ARGUMENTS;
    }
    return rc;
}
