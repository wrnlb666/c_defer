# gcc-defer
go like defer in c, but only works with gcc or clang

# Caution
gcc support is done via gcc nested function, when compiling, you might need to add `-z execstack` to have a executable stack. 
clang support is done via clang blocks, when compiling, you need to add `-fblocks` and for some platform, `-lBlocksRuntime`. 


# example:
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
    ({
        printf( "world\n" );
    });
    printf( "Hello " );

    return 0;
}
```
