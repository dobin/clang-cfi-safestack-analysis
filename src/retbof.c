#include <stdio.h>
#include <string.h>

void bof(char *a) {

	char buf[8];

	strcpy(buf, a);
	printf("buf: %s\n", buf);
}

int main(int argc, char **argv) {
	bof(argv[1]);

	return 0;
}
