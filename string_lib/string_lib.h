#ifndef string_lib      // include guards to prevent duplicate definitions
#define string_lib

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

size_t strlib_len(char *_Source) {

    /**
     * Returns the size of a string from a character pointer excluding the null character,
     * 
     * It will first store the pointer, then store the initial memory location of it
     * before iterating through the string until it reaches the null terminator.
     * 
     * Once it reaches the null character, it will then return the difference between
     * the temp's final and initial location.
    */

    char *temp = _Source;

    intptr_t initialMemoryLocation = (intptr_t)temp;

    while (*temp != '\0') { 
        temp++;
    }

    return (size_t) (temp - initialMemoryLocation) + 1;
}

void strlib_copy(char *_Dest, const char *_Source) {
    /**
     * 
     * iterate through the passed char pointer and copy the character to the result variable 
     * that points to another location with an allocated memory equal to the size of the source 
     * including the null terminator.
     * 
     */

    const char *tmp = _Source;

    int pos = 0;

    while (*tmp != '\0') {
        _Dest[pos] = *tmp;
        pos++;
        tmp++;
    }

    _Dest[pos] = '\0';
}

void strlib_concat(char *_Dest, char **_arrStrings, size_t _arrSize) {

    int res_pos = 0;

    for (int i = 0; i < _arrSize; i++) {
        
        int arr_pos = 0;
        char c = _arrStrings[i][arr_pos];
        while (c != '\0') {
            _Dest[res_pos] = c;
            res_pos++;
            arr_pos++;
            c = _arrStrings[i][arr_pos];
        }

    }

    _Dest[res_pos] = '\0';
}

void strlib_capitalize(char *_Dest, char *_Source) {

    int pos = 0;

    char *tmp = _Source;

    while (*tmp != '\0') {
        if (pos == 0) { 
            if ((int)*tmp <= 122 && (int)*tmp >= 97) {
                
                /*
                    if in the first character of the string, 
                    check if the ASCII value of the character is in range of
                    the values of lowercase characters (97 - 122),
                */

               // if true, then subtract by 32 (its corresponding uppercase character),
                _Dest[pos] = (char)((int)(*tmp - 32));      

            } else {   
                // else, just copy the character.                         
                _Dest[pos] = *tmp;      
            }

        } else {
            _Dest[pos] = *tmp;
        }

        pos++;
        tmp++;
    }

    _Dest[pos] = '\0';

}

#endif