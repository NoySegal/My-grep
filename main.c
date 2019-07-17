#include "init.h"
#include "match.h"

line read_line(FILE *file_ptr, line this_line) {
	this_line.content = NULL;
	size_t number_bytes = 0;
	this_line.is_eof = getline(&(this_line.content), &number_bytes, file_ptr);
	return this_line;
}

void print(line curr_line, switches switch_arg) {
	if (switch_arg.n == true) {
		printf("%d%c", curr_line.number, curr_line.match ? ':' : '-');
	}
	if (switch_arg.b == true) {
		printf("%d%c", curr_line.offset, curr_line.match ? ':' : '-');
	} 
	printf("%s", curr_line.content);
}

void free_resources(line curr_line, FILE *file_ptr) {
	if (curr_line.content) {
		free(curr_line.content);
	}
	fclose(file_ptr);
}

line update_line(line curr_line, switches switch_arg, char *pattern) {
	curr_line.number++;
	curr_line.offset += strlen(curr_line.content);
	if (switch_arg.A == true) {
		if (curr_line.match == true) {
			curr_line.A_count = switch_arg.A_num;
		} else {
			curr_line.A_count--;
		}
	}
	return curr_line;
}

int main(int argc, char *argv[]) {
	switches switch_arg;
	int match_count = 0;
	line present_line = init_line();
	switch_arg = set_switch_args(argv);
	char *pattern = argv[switch_arg.count + 1];
	FILE *stream = fopen(argv[switch_arg.count + 2], "r");
	if (stream == NULL && argv[switch_arg.count + 2] == NULL) {
		stream = stdin;
	}
	while (feof(stream) == 0) {
		present_line = read_line(stream, present_line);
		if (present_line.is_eof == -1) {
			break;
		}
		present_line.match = is_match(present_line.content, switch_arg, pattern);
		if (present_line.match == true) {
			if (switch_arg.c == false) {
				print(present_line, switch_arg);
			}
			match_count++;
		} else if (present_line.A_count > 0) {
			print(present_line, switch_arg);
		}
		present_line = update_line(present_line, switch_arg, pattern);
	}
	if (switch_arg.c == true) {
		printf("%d\n", match_count);
	}
	return 0;
}
