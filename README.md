# New-String-Library-in-C

An attempt to make an improved string library in C.

## Improvements / Changes

This repository is created mainly with the reason of learning **string manipulation** and **pointers** in C, but
I will still try to offer more functionalities that can provide a much more beginner-friendly and an easier 
and broader way to manipulate strings in C.

### Preexisting Functions:

```C
void strlib_copy(char *_Dest, const char *_Source) // similar to string.h's strcpy
``` 
```C
size_t strlib_len(const char *_Source) // similar to string.h's strlen
``` 

### Additional Functions:

- **Multiple String Concatenation**
    - ```C
        void strlib_concat(char *_Dest, const char **_arrStrings, size_t _arrSize)
        ```
        - String_lib's **strlib_concat** is an improved version of string.h's *strconcat* as it can concatenate
        multiple strings, instead of only two.

- **Letter Case Manipulation**
    - ```C
        void strlib_capitalize(char *_Dest, const char *_Source)
        ```
        - A simple function that capitalizes the source string variable's first character, it may come in handy depending on what project you are currently working on.


    - ```C
        void strlib_touppercase(char *_Dest, const char *_Source)
        ```
        - Converts all the source string variable's characters to uppercase.


    - ```C
        void strlib_tolowercase(char *_Dest, const char *_Source)
        ```
        - Converts all the source string variable's characters to lowercase.


    - ```C
        void strlib_swapcase(char *_Dest, char *_Source) 
        ```
        - Swaps the letter case of every character in the source string variable.


    - ```C
        int strlib_ntouppercase(char *_Dest, const char *_Source, int _Range)
        ```
        - Converts the first *_Range* characters of the source string variable to uppercase


    - ```C
        int strlib_ntolowercase(char *_Dest, const char *_Source, int _Range)
        ```
        - Converts the first *_Range* characters of the source string variable to lowercase


    - ```C
        int strlib_startswith(const char *_Source, int _CompareChar)
        ```
        - Checks if the string is starting with the *_CompareChar*


    - ```C
        int strlib_endswith(const char *_Source, int _CompareChar)
        ```
        - Checks if the string is ending with the *_CompareChar*

- **Comparisons**
    - ```C
        int strlib_equals(const char *_FirstString, const char *_SecondString)
        ```
        - Checks if the two passed strings are equal

    - ```C
        int strlib_equalsignorecase(const char *_FirstString, const char *_SecondString)
        ```
        - Checks if the two passed strings are equal (ignoring the case)

    - ```C
        int strlib_index(const char *_Source, int c)
        ```
        - Returns the index of the char *c*, returns -1 if character is not found

    - ```C
        int strlib_contains(const char *_Source, int c)
        ```
        - Checks if the string contains the char *c*, returns 0 if found, else -1

- **Char Functions**
    - ```C
        int strlib_countchar(const char *_Source, int _CompareChar, int _IgnoreCase)
        ```
        - Counts all the present *_CompareChar* in the *_Source* variable, 
        Ignore case is also added in the parameter to choose between 0 (do not ignore case)
        and 1 (ignore case) when checking

    - ```C
        void strlib_replace(char _Source[], char _ChrRemove, char _ChrReplace)
        ```
        - Replaces every char *_ChrRemove* with char *_ChrReplace*, *_Source* must be a char array, not a char pointer


**Todo:**

- [x] copy
- [x] len
- [x] concat
- [x] capitalize
- [x] touppercase
- [x] tolowercase
- [x] swapcase
- [x] ntouppercase
- [x] ntolowercase
- [x] startswith
- [x] endswith
- [x] countchar
- [x] replace
- [ ] compare
- [x] equals
- [ ] matches (regex)
- [ ] isalpha
- [ ] isdigit
- [ ] isspace
- [ ] isupper
- [ ] islower
- [ ] find
- [x] index
- [x] contains
- [ ] split
- [ ] trim
- [ ] ciphers, encryption, decryption
