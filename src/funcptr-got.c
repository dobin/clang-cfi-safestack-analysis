#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bof(long a, long loc) {
	long *ptr = (void*) (long) loc;
	*ptr = a;
}

int main(int argc, char **argv) {
	system("echo bla"); // load system system-call
	printf("Start\n");
	bof( (long)strtol(argv[1], NULL, 16), (long)strtol(argv[2], NULL, 16));

	printf("ls");
	return 0;
}
