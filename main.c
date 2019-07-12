#include "init.h"


int main(int argc, char *argv[]) {
	grep_option options;
	options = set_options(argv);
	printf("%d\n", options.count);
	char *expression = argv[options.count +1];
	FILE *stream = fopen(argv[options.count +2], "r");
	if (stream == NULL && argv[options.count +2] == NULL) {
		stream = stdin;
	}
	if (stream == NULL) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(1);
	}
	return 0;
}
