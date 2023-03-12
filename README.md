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
```C
void strlib_concat(char *_Dest, const char **_arrStrings, size_t _arrSize)
```
- String_lib's **strlib_concat** is an improved version of string.h's *strconcat* as it can concatenate
multiple strings, instead of only two.

- **Letter Case**
```C
void strlib_capitalize(char *_Dest, const char *_Source)
```
- A simple function that capitalizes the source string variable's first character, it may come in handy depending on what project you are currently working on.


```C
void strlib_touppercase(char *_Dest, const char *_Source)
```
- Converts all the source string variable's characters to uppercase.


```C
void strlib_tolowercase(char *_Dest, const char *_Source)
```
- Converts all the source string variable's characters to lowercase.


```C
void strlib_swapcase(char *_Dest, char *_Source) 
```
- Swaps the letter case of every character in the source string variable.


```C
int strlib_ntouppercase(char *_Dest, const char *_Source, int _Range)
```
- Converts the first *_Range* characters of the source string variable to uppercase


```C
int strlib_ntolowercase(char *_Dest, const char *_Source, int _Range)
```
- Converts the first *_Range* characters of the source string variable to lowercase


- ```C
    int strlib_startswith(const char *_Source, const char _CompareChar)
    ```
    - Checks if the string is starting with the *_CompareChar*


```C
int strlib_endswith(const char *_Source, const char _CompareChar)
```
- Checks if the string is ending with the *_CompareChar*

**Todo:**

- [ ] replace
- [ ] tochararray
- [ ] compare
- [ ] equals
- [ ] matches (regex)
- [ ] isalpha
- [ ] isdigit
- [ ] isspace
- [ ] isupper
- [ ] islower
- [ ] find
- [ ] index
- [ ] count
- [ ] contains
- [ ] split
- [ ] trim
