#include "init.h"

switches reset_options() {
	switches todo;
	todo.i = 0;
	todo.A = 0;
	todo.A_num = 0;
	todo.b = 0;
	todo.c = 0;
	todo.v = 0;
	todo.n = 0;
	todo.x = 0;
	todo.E = 0;
	todo.count = 0;
	return todo;
}

switches set_switch_args(char *argv[]) {
	switches my_options = reset_options();
	int i = 1;
	while(argv[i] != NULL) {
		if (strcmp(argv[i], "-i") == 0) {
			my_options.i = true;
		} else if (strcmp(argv[i], "-A") == 0) {
			my_options.A = true;
			my_options.A_num = atoi(argv[i+1]);
			my_options.count++;
			i++;
		} else if (strcmp(argv[i], "-b") == 0) {
			my_options.b = true;
		} else if (strcmp(argv[i], "-c") == 0) {
			my_options.c = true;
		} else if (strcmp(argv[i], "-v") == 0) {
			my_options.v = true;
		} else if (strcmp(argv[i], "-n") == 0) {
			my_options.n = true;
		} else if (strcmp(argv[i], "-x") == 0) {
			my_options.x = true;
		} else if (strcmp(argv[i], "-E") == 0) {
			my_options.E = true;
		} else {
			break;
		}
		my_options.count++;
		i++;
	}
	if (strchr(argv[my_options.count +1], '\\') != NULL) {
		my_options.E = true;
	}
	return my_options;
}

line init_line() {
	line new_line;
	new_line.content = NULL;
	new_line.number = 1;
	new_line.offset = 0;
	new_line.match = false;
	new_line.A_count = 0;
	new_line.is_eof = -1;
	return new_line;
}
