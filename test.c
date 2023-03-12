#include <stdio.h>
#include <stdlib.h>
#include "string_lib/string_lib.h"

#define BUFFERSIZE 100

int main () {

    char *str1 = "hHh123";
    
    char str2[BUFFERSIZE];
    strlib_swapcase(str2, str1);

    int ret = strlib_countchar(str1, 'H', 1);

    printf("%d", ret);

    return 0;
}