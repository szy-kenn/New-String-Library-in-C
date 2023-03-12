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
```C
void strlib_concat(char *_Dest, const char **_arrStrings, size_t _arrSize) // similar to string.h's strcat
```

### Additional Functions:
```
- capitalize ()
```

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
