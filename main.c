#include "init.h"
#include "match.h"

line read_line(FILE *file_ptr) {
	line this_line;
	this_line.content = NULL;
	size_t number_bytes = 0;
	this_line.is_eof = getline(&(this_line.content), &number_bytes, file_ptr);
	return this_line;
}

void print(line sentence) {
	if (sentence.is_print && sentence.is_eof != -1) {
		printf("%s", sentence.content);
	}
}

void free_resources(line curr_line, FILE *file_ptr) {
	if (curr_line.content) {
		free(curr_line.content);
	}
	fclose(file_ptr);
}

line update_line(line curr_line, grep_option options, print_param settings, char *pattern) {
	curr_line.number = settings.line_num;
	curr_line.offset = settings.b_byte_count;
	curr_line.length = strlen(curr_line.content);
	curr_line.match = match_by_criteria(curr_line.content, options, pattern);
	curr_line.is_print = print_by_criteria(curr_line, settings, options);
	print(curr_line);
	return curr_line;
}

int main(int argc, char *argv[]) {
	grep_option options;
	line present_line;
	print_param print_settings = init_parameters();
	options = set_options(argv);
	char *expression = argv[options.count + 1];
	FILE *stream = fopen(argv[options.count + 2], "r");
	if (stream == NULL && argv[options.count + 2] == NULL) {
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
		present_line = update_line(present_line, options, print_settings, expression);
	}
	return 0;
}
