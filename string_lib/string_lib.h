#ifndef string_lib      // include guards to prevent duplicate definitions
#define string_lib

#include <stdlib.h>
#include <stdint.h>

// available functions
size_t strlength(char *_Source);

char* strcopy(char *_Source);

size_t strlength(char *_Source) {

    /**
     * Returns the size of a string from a character pointer including the null character,
     * 
     * It will first store the pointer, then store the initial memory location of it
     * before iterating through the string until it reaches the null terminator.
     * 
     * Once it reaches the null character, it will then return the difference between
     * the temp's final and initial location, incremented by 1 to give space to the null character.
    */

    char *temp = _Source;

    intptr_t initialMemoryLocation = (intptr_t)temp;

    while (*temp != '\0') { 
        temp++;
    }

    return (size_t) (temp - initialMemoryLocation) + 1;
}

char* strcopy(char *_Source) {

    /**
     * 
     * iterate through the passed char pointer and copy the character to the result variable 
     * that points to another location with an allocated memory equal to the size of the source 
     * including the null terminator.
     * 
     */
    
    char *temp = _Source;

    char *result = malloc(sizeof(char) * strlength(_Source));

    int pos = 0;

    while (*temp != '\0') {
        
        result[pos] = *temp;
        pos++;
        temp++;
    }

    result[pos] = '\0';
    return result;
}

#endif
