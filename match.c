#include "match.h"

void string_lower(char *str) {
	for (int i = 0; str[i]; i++) {
		str[i] = tolower((unsigned char)str[i]);
	}
}

bool is_match(char *content, char *pattern) {
	return strstr(content, pattern);
}

bool match_by_criteria(char *content, grep_option options, char *pattern) {
	char *content_dup = strdup(content);
	if (options.i == true) {
		string_lower(content_dup);
		string_lower(pattern);
	}
	return is_match(content_dup, pattern);
}

bool print_by_criteria(line curr_line, print_param settings, grep_option options) {
	if (options.v == true) {
		curr_line.match = !(curr_line.match);
	}
	if (curr_line.match == true) {
		return true;
	}
	return false;
}
