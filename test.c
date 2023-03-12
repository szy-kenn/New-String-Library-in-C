#include <stdio.h>
#include <stdlib.h>
#include "string_lib/string_lib.h"

#define BUFFERSIZE 100

int main () {

    char *str1 = "john";
    char *str3 = "JOHN";

    char str2[BUFFERSIZE];

    int ret = strlib_equalsignorecase(str1, str3);

    printf("%d", ret);

    return 0;
}