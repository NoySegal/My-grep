#include "match.h"

void string_lower(char *str) {
	for (int i = 0; str[i]; i++) {
		str[i] = tolower((unsigned char)str[i]);
	}
}

bool regex_match(char *regexp, char *text) {
	if (regexp[0] == '\0') {
		return true;
	}
	if (regexp[0] == '\\' && *text != '\0') {
		return match_backslash(regexp+1, text);
	}
	if (*text != '\0' && regexp[0] == '(') {
		return regex_match(regexp+1, text) || regex_match(strstr(regexp, "|")+1, text);
	}
	if (*text != '\0' && (regexp[0] == '|' || regexp[0] == ')')) {
		//add here
	}
	return false;
}

bool match_backslash(char *regexp, char *text) {
	if (regexp[0] == '\0') {
		return true;
	}
	if (*text != '\0' && regexp[0] == *text) {
		return regex_match(regexp+1, text+1);
	}
	return false;
}

bool is_match(char *content, switches switch_arg, char *pattern) {
	bool match = false;
	char *content_dup = strdup(content);
	char *text = content_dup;
	if (switch_arg.i == true) {
		string_lower(content_dup);
		string_lower(pattern);
	}
	if (switch_arg.x == true) {
		*strchr(content_dup, '\n') = '\0';
		if (strcmp(content_dup, pattern) == 0) {
			match = true;
		}
	} else if (switch_arg.E == true) {
		do {
		match = regex_match(pattern, text);
		} while(*text++ != '\0' && match != true);
	} else {
		if (strstr(content_dup, pattern) != NULL) {
			match = true;
		}
	}
	free(content_dup);
	if (switch_arg.v == true) {
		return !match;
	}
	return match;
}
