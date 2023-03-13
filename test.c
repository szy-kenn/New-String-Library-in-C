#include <stdio.h>
#include <stdlib.h>
#include "string_lib/string_lib.h"

#define BUFFERSIZE 100

int main () {

    char str1[] = "john";
    char *str3 = "JOHN";

    char str2[BUFFERSIZE];
    
    strlib_replace(str1, 'o', 'l');
    printf("%s", str1);


    return 0;
}