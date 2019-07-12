#include "init.h"

grep_option reset() {
	grep_option todo;
	todo.i = 0;
	todo.A = 0;
	todo.A_num = 0;
	todo.b = 0;
	todo.c = 0;
	todo.V = 0;
	todo.n = 0;
	todo.x = 0;
	todo.E = 0;
	todo.count = 0;
	return todo;
}

grep_option set_options(char *argv[]) {
	grep_option my_options = reset();
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
		} else if (strcmp(argv[i], "-V") == 0) {
			my_options.V = true;
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
	printf("%d\n", my_options.count);
	return my_options;
}
