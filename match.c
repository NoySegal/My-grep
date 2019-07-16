#include "match.h"

void string_lower(char *str) {
	for (int i = 0; str[i]; i++) {
		str[i] = tolower((unsigned char)str[i]);
	}
}

bool match_by_criteria(char *content, switches options, char *pattern) {
	bool match = false;
	char *content_dup = strdup(content);
	if (options.i == true) {
		string_lower(content_dup);
		string_lower(pattern);
	}
	if (options.x == true) {
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
	if (options.v == true) {
		return !match;
	}
	return match;
}
