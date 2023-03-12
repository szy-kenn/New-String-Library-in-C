#ifndef string_lib      // include guards to prevent duplicate definitions
#define string_lib

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

size_t strlib_len(const char *_Source);
void strlib_copy(char *_Dest, const char *_Source);
void strlib_concat(char *_Dest, const char **_arrStrings, size_t _arrSize);
void strlib_capitalize(char *_Dest, const char *_Source);
void strlib_touppercase(char *_Dest, const char *_Source);
int strlib_ntouppercase(char *_Dest, const char *_Source, int _Range);

size_t strlib_len(const char *_Source) {

    /**
     * Returns the size of a string from a character pointer excluding the null character,
     * 
     * It will first store the pointer, then store the initial memory location of it
     * before iterating through the string until it reaches the null terminator.
     * 
     * Once it reaches the null character, it will then return the difference between
     * the temp's final and initial location.
    */

    const char *tmp = _Source;

    intptr_t initialMemoryLocation = (intptr_t)tmp;

    while (*tmp != '\0') { 
        tmp++;
    }

    return (size_t) (tmp - initialMemoryLocation) + 1;
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

void strlib_concat(char *_Dest, const char **_arrStrings, size_t _arrSize) {

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

char _upper(const char c) {

    if ((int) c <= 122 && (int) c >= 97) {
        /*
            if in the first character of the string, 
            check if the ASCII value of the character is in range of
            the values of lowercase characters (97 - 122),
        */
        return (char) ((int)c - 32);

    } else 
        return c;
}

char _lower(const char c) {

    if ((int) c <= 90 && (int) c >= 65) {
        return (char) ((int)c + 32);
    } else 
        return c;
}

char _swapcase(const char c) {

    if ((int) c <= 90 && (int) c >= 65) {
        return _lower(c);
    } else if ((int) c <= 122 && (int) c >= 97) {
        return _upper(c);
    } else
        return c;
}

void strlib_capitalize(char *_Dest, const char *_Source) {

    int pos = 0;

    const char *tmp = _Source;

    while (*tmp != '\0') {
        if (pos == 0) { 
            _Dest[pos] = _upper(*tmp);
        } else {
            _Dest[pos] = *tmp;
        }

        pos++;
        tmp++;
    }

    _Dest[pos] = '\0';

}

void strlib_touppercase(char *_Dest, const char *_Source) {
    /*
        Converts all characters of _Source char array to uppercase
    */

   const char *tmp = _Source;

   int pos = 0;

   while (*tmp != '\0') {
        _Dest[pos] = _upper(*tmp);
        pos++;
        tmp++;
   } 

   _Dest[pos] = '\0';

}

void strlib_tolowercase(char *_Dest, const char *_Source) {
    /*
        Converts all characters of _Source char array to lowercase
    */

   const char *tmp = _Source;

   int pos = 0;

   while (*tmp != '\0') {
        _Dest[pos] = _lower(*tmp);
        pos++;
        tmp++;
   } 

   _Dest[pos] = '\0';  
}

int strlib_ntouppercase(char *_Dest, const char *_Source, int _Range) {

    /*
        Converts the first _Range characters of _Source char array to uppercase and
        pass it to _Dest char array, including the remaining characters while maintaining 
        its case
    */

    if (strlib_len(_Source) < _Range) {
        return -1;  // error
    }

    const char *tmp = _Source;
    int i = 0;

    for (i = 0; i < _Range; i++) {
        _Dest[i] = _upper(*tmp);
        tmp++;
    }

    int pos = i;

    while (*tmp != '\0') {        
        _Dest[pos] = *tmp;
        pos++;
        tmp++;
    }

    _Dest[pos] = '\0';

    return 0;
}

int strlib_ntolowercase(char *_Dest, const char *_Source, int _Range) {

    /*
        Converts the first _Range characters of _Source char array to lowercase and
        pass it to _Dest char array, including the remaining characters while maintaining 
        its case
    */

    if (strlib_len(_Source) < _Range) {
        return -1;  // error
    }

    const char *tmp = _Source;
    int i = 0;

    for (i = 0; i < _Range; i++) {
        _Dest[i] = _lower(*tmp);
        tmp++;
    }

    int pos = i;

    while (*tmp != '\0') {        
        _Dest[pos] = *tmp;
        pos++;
        tmp++;
    }

    _Dest[pos] = '\0';

    return 0;
}

void strlib_swapcase(char *_Dest, char *_Source) {

    char *tmp = _Source;
    int pos = 0;

    while (*tmp != '\0') {
        _Dest[pos] = _swapcase(*tmp);
        pos++;
        tmp++;
    }

    _Dest[pos] = '\0';
}

#endif