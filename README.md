# gcc-defer
go like defer in c, but only works with gcc


example:
```c
#include <stdio.h>
#include <stdlib.h>
#include "defer.h"

int main( void )
{
    int* arr = malloc( sizeof (int) * 10 );
    defer
    (
        free(arr);
    );
    defer
    (
        printf( "world\n" );
    );
    printf( "Hello " );

    return 0;
}
```
