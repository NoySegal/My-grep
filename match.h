#ifndef MATCH_H
#define MATCH_H

#include "init.h"
#include <ctype.h>

bool match_by_criteria(char *content, grep_option options, char *pattern);
bool print_by_criteria(line curr_line, print_param settings, grep_option options);

#endif
