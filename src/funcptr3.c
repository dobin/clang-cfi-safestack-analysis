#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func1(void) {
	printf("Yay1\n");
}

void func2(void) {
	printf("Yay2\n");
}

void bof(int idx) {
	void (*fa[2])(void);
	void (*f)(void);
	char buffer[8];

	fa[0] = &func1;
	fa[1] = &func2;

	f = fa[idx];

	(*f)();
}

int main(int argc, char **argv) {
	printf("A: %s\n", argv[1]);
	bof(atoi(argv[1]));

	return 0;
}
