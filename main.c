#include "init.h"

line read_line(FILE *file_ptr) {
	line this_line;
	this_line.content = NULL;
	size_t number_bytes = 0;
	this_line.is_eof = getline(&(this_line.content), &number_bytes, file_ptr);
	this_line.length = strlen(this_line.content);
	return this_line;
}

int main(int argc, char *argv[]) {
	grep_option options;
	line present_line;
	options = set_options(argv);
	char *expression = argv[options.count +1];
	FILE *stream = fopen(argv[options.count +2], "r");
	if (stream == NULL && argv[options.count +2] == NULL) {
		stream = stdin;
	}
	if (stream == NULL) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(1);
	}
	while (feof(stream) == 0) {
		present_line = read_line(stream);
		if (present_line.is_eof == -1) {
			break;
		}
	}
	fclose(stream);
	return 0;
}
