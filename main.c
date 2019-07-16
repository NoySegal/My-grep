#include "init.h"
#include "match.h"

line read_line(FILE *file_ptr) {
	line this_line;
	this_line.content = NULL;
	size_t number_bytes = 0;
	this_line.is_eof = getline(&(this_line.content), &number_bytes, file_ptr);
	return this_line;
}

int byte_count (FILE *file_ptr, char *pattern) {
	int byte_count = 0;
	for (int i = 0; pattern[i] != '\n' && feof(file_ptr) == 0; i++) {
		byte_count++;
	}
	byte_count++;
	return byte_count;
}

void print(line sentence, switches options, print_param *print_parameters) {
	if (options.n == true && options.b == true) {
		printf("%d:%d:%s", print_parameters->line_num, print_parameters->b_byte_count, sentence.content);
	} else if (options.n == true) {
		printf("%d:%s", print_parameters->line_num, sentence.content);
	} else if (options.b == true) {
		printf("%d:%s", print_parameters->b_byte_count, sentence.content);
	} else {
		printf("%s", sentence.content);
	}
}

void free_resources(line curr_line, FILE *file_ptr) {
	if (curr_line.content) {
		free(curr_line.content);
	}
	fclose(file_ptr);
}

line update_line(line curr_line, switches options, print_param *print_parameters, char *pattern) {
	curr_line.number = print_parameters->line_num;
	curr_line.offset = print_parameters->b_byte_count;
	curr_line.length = strlen(curr_line.content);
	curr_line.match = match_by_criteria(curr_line.content, options, pattern);
	//curr_line.is_print = 
	return curr_line;
}

print_param update_print_parameters(switches options, line curr_line, print_param print_parameters, FILE* file_ptr) {
	print_parameters.line_num++;
	print_parameters.prev_print = curr_line.is_print;
	print_parameters.b_byte_count += byte_count(file_ptr ,curr_line.content);
	return print_parameters;
}

int main(int argc, char *argv[]) {
	switches options;
	line present_line;
	print_param print_parameters = init_parameters();
	options = set_options(argv);
	char *pattern = argv[options.count + 1];
	FILE *stream = fopen(argv[options.count + 2], "r");
	if (stream == NULL && argv[options.count + 2] == NULL) {
		stream = stdin;
	}
	while (feof(stream) == 0) {
		present_line = read_line(stream);
		if (present_line.is_eof == -1) {
			break;
		}
		present_line = update_line(present_line, options, &print_parameters, pattern);
		if (present_line.match == true) {
			if (options.c == false) {
				print(present_line, options, &print_parameters);
			}
			print_parameters.c_match_count++;
		}
		print_parameters = update_print_parameters(options, present_line, print_parameters, stream);
	}
	if (options.c == true) {
		printf("%d\n", print_parameters.c_match_count);
	}
	return 0;
}
