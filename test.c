#include <stdio.h>
#include <stdlib.h>
#include "string_lib/string_lib.h"

#define BUFFERSIZE 100
int main () {

    char *str1 = "hElloSqwkd";
    
    char str2[BUFFERSIZE];

    strlib_swapcase(str2, str1);

    printf("%s", str2);
    return 0;
}