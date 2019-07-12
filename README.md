# My-grep
Custom implementation for the Unix [grep](https://en.wikipedia.org/wiki/Grep) command 

## The data structures
#### grep\_options holds the user choice for the grep execution, the idea is to count all these options in the input and derive the expression and file name which are at the end-of-line
```C
typedef struct grep_options {
        bool i;
        bool A;
        int A_num;
        bool b;
        bool c;
        bool V;
        bool n;
        bool x;
        bool E;
        int count;
} grep_option;
```

work in progress..
