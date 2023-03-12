#include <stdio.h>
#include <stdlib.h>
#include "string_lib/string_lib.h"

#define BUFFERSIZE 100
int main () {

    char *str1 = "hElloSqwkd";
    
    char str2[BUFFERSIZE];

    strlib_swapcase(str2, str1);

    printf("%s\n", str2);

    printf("%d", strlib_startswith(str1, 'h'));
    printf("\n%d", strlib_endswith(str1, 'd'));

    return 0;
}