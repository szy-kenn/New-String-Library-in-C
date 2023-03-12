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

```C
void strlib_concat(char *_Dest, const char **_arrStrings, size_t _arrSize)
```
String_lib's **strlib_concat** is an improved version of string.h's *strconcat* as it can concatenate
multiple strings, instead of only two.

```C
void strlib_capitalize(char *_Dest, const char *_Source)
```
A simple function that capitalizes the source string variable's first character, it may come in handy depending
on what project you are currently working on.

Todo:

- replace
- tochararray
- compare, equals, matches (regex)
- capitalize ✅
- touppercase ✅, ntouppercase ✅
- tolowercase ✅, ntolowercase ✅
- swapcase ✅
- isalpha, isdigit, isspace
- isupper, islower
- find, index, count, contains
- startswith ✅, endswith ✅
- split, trim
