#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

grep_option reset();
grep_option set_options(char *argv[]);

#endif
