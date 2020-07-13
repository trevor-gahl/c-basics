#include <stdio.h>
#include <stdlib.h>

int main()
{
#ifdef DEBUG
    printf("a");
#else
    printf("b");
#endif
}
