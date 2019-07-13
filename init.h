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

typedef struct line_info {
	char *content;
	int number;
	int offset;
	int length;
	bool match;
	bool is_print;
	ssize_t is_eof;
} line;

typedef struct print_parameters {
	int line_num;
	int c_count;
	int b_byteCount;
	int A_count;
	bool previous_is_print;
} print_param;

grep_option reset_options();
grep_option set_options(char *argv[]);
print_param init_parameters(print_param parameter);

#endif
