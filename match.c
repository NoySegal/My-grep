#include "match.h"

void string_lower(char *str) {
	for (int i = 0; str[i]; i++) {
		str[i] = tolower((unsigned char)str[i]);
	}
}

bool is_match(char *content, switches switch_arg, char *pattern) {
	bool match = false;
	char *content_dup = strdup(content);
	if (switch_arg.i == true) {
		string_lower(content_dup);
		string_lower(pattern);
	}
	if (switch_arg.x == true) {
		*strchr(content_dup, '\n') = '\0';
		if (strcmp(content_dup, pattern) == 0) {
			match = true;
		}
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
