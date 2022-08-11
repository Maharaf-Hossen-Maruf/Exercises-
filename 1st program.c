#include <stdio.h>

void fun()

{
    return 1;
}

void main()

{
    int x = 0;

    x = fun();

    printf("%d", x);
}
