#include <stdio.h>
#include <string.h>


void func(void) {
	printf("Yay\n");
}

void bof(char *a) {
	void (*f)(void) = &func;
	char buffer[8];

	strcpy(buffer, a);
	(*f)();
}

int main(int argc, char **argv) {
	printf("A: %s\n", argv[1]);
	bof(argv[1]);

	return 0;
}
