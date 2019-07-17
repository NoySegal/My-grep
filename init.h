#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct switches {
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
} switches;

typedef struct line_info {
	char *content;
	int number;
	int offset;
	bool match;
	int A_count;
	ssize_t is_eof;
} line;

line init_line();
switches set_switch_args(char *argv[]);

#endif
