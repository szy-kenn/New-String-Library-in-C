#ifndef string_lib      // include guards to prevent duplicate definitions
#define string_lib

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

size_t strlib_len(const char *_Source);
void strlib_copy(char *_Dest, const char *_Source);
void strlib_concat(char *_Dest, const char **_arrStrings, size_t _arrSize);
void strlib_capitalize(char *_Dest, const char *_Source);
void strlib_touppercase(char *_Dest, const char *_Source);
int strlib_ntouppercase(char *_Dest, const char *_Source, int _Range);


int _isupper(int c) {
    if (c <= 90 && c >= 65) {
        return 0;
    }

    return -1;
}

int _islower(int c) {
    if (c <= 122 && c >= 97) {
        return 0;
    }

    return -1;
}

char _upper(int c) {

    if (_islower(c) == 0) {
        /*
            if in the first character of the string, 
            check if the ASCII value of the character is in range of
            the values of lowercase characters (97 - 122),
        */
        return (char) (c - 32);

    } else 
        return c;
}

char _lower(int c) {

    if (_isupper(c) == 0) {
        return (char) (c + 32);
    } else 
        return c;
}

char _swapcase(int c) {

    if (_isupper(c) == 0) {
        return _lower(c);
    } else if (_islower(c) == 0) {
        return _upper(c);
    } else
        return c;
}

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

    return (size_t) (tmp - initialMemoryLocation);
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

int strlib_startswith(const char *_Source, int _CmpChar) {

    if ((int)_Source[0] == _CmpChar) {
        return 0;
    }

    return -1;
}

int strlib_endswith(const char *_Source, int _CmpChar) {

    if ((int)_Source[strlib_len(_Source) - 1] == _CmpChar) {
        return 0;
    }

    return -1;
}

int strlib_equals(const char *_FirstString, const char *_SecondString) {
    
    /*
        Compares each character of the two passsed strings,
        Returns 0 if true, else returns a non-zero
    */

    const int srcSize = strlib_len(_FirstString);
    const int cmpSize = strlib_len(_SecondString);

    int diff = 0;

    if (srcSize != cmpSize) {
        return -1;
    }

    for (int i = 0; i < srcSize; i++) {

        diff = (int)_FirstString[i] - (int)_SecondString[i];

        if (diff != 0) {
            return diff;
        }
    }

    return diff;
}

int strlib_equalsignorecase(const char *_FirstString, const char *_SecondString) {
    /*
        Compares each character of the two passsed strings ignoring the case,
        Returns 0 if true, else returns a non-zero
    */

    const int srcSize = strlib_len(_FirstString);
    const int cmpSize = strlib_len(_SecondString);

    int diff = 0;

    if (srcSize != cmpSize) {
        return -1;
    }

    for (int i = 0; i < srcSize; i++) {

        diff = (int)_lower(_FirstString[i]) - (int)_lower(_SecondString[i]);

        if (diff != 0) {
            return diff;
        }
    }

    return diff;   
}

int strlib_countchar(const char *_Source, int _CmpChar, int _IgnoreCase) {
    
    if (_IgnoreCase != 0 && _IgnoreCase != 1) {
        return -1;  // error
    }

    int count = 0;
    const char *tmp = _Source;

    while (*tmp != '\0') {
        
        if (_IgnoreCase == 0) {
            if ((int)*tmp == _CmpChar) {
                count++;
            }

        } else {
            if ((int)_lower(*tmp) == (int)_lower(_CmpChar)) {
                count++;
            }
        }

        tmp++;
    }
    return count;

}

int strlib_countstr(const char *_Source, const char *_CompareStr, int _IgnoreCase) {

    const char *tmpSrc = _Source;
    const char *tmpCmp = _CompareStr;

    const int srcSize = strlib_len(tmpSrc); 
    const int cmpSize = strlib_len(tmpCmp);

    //TODO: create substring functions and equals first
    return 0;

}

int strlib_index(const char *_Source, int c) {

    const char *tmp = _Source;
    intptr_t _initmempos = (intptr_t) tmp;

    while (*tmp != '\0') {
        if ((int) *tmp == c) {
            return (int) (tmp - _initmempos);
        }
        tmp++;
    }

    return -1;  // none
}

int strlib_contains(const char *_Source, int c) {

    if (strlib_index(_Source, c) == -1)
        return -1;  // false
    else
        return 0;   // true
}

void strlib_replace(char _Source[], char _ChrRemove, char _ChrReplace) {
    /*
        _Source must be a character array, not a char pointer
        c1 is the char to be replaced by c2
    */
   
   char *tmp = _Source;
   
   int idx = strlib_index(tmp, _ChrRemove);
   
   while (idx != -1) {
        tmp[idx] = _ChrReplace;
        idx = strlib_index(tmp, _ChrRemove);
   }

}

#endif