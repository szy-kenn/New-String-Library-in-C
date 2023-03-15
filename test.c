#include <stdio.h>
#include <stdlib.h>
#include "string_lib/string_lib.h"

#define BUFFERSIZE 100

int main () {

    char str1[] = "john#ken#haha#hehe";
    char str3[10][BUFFERSIZE];

    char str2[BUFFERSIZE];

    strlib_split(str3, str1, '#', 0);

    printf("%s", str3[0]);
    printf("\n%s", str3[1]);

    return 0;
}