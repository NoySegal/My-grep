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
	bool v;
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
	bool prev_print;
	int b_byte_count;
	int c_match_count;
	int A_count;
} print_param;

grep_option set_options(char *argv[]);
print_param init_parameters();

#endif
