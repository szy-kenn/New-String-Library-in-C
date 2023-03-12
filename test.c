#include <stdio.h>
#include <stdlib.h>
#include "string_lib/string_lib.h"

#define BUFFERSIZE 100
int main () {

    char *str1 = "HELLOW";
    
    char str2[BUFFERSIZE];

    strlib_ntolowercase(str2, str1, 5);

    printf("%s", str2);
    return 0;
}