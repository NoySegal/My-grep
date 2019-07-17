#ifndef MATCH_H
#define MATCH_H

#include "init.h"
#include <ctype.h>

bool is_match(char *content, switches options, char *pattern);
bool regex_match(char *regexp, char *text);
bool match_backslash(char *regexp, char *text);

#endif
