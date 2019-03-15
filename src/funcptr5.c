#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func1(void) {
	printf("Yay1\n");
}
void func2(void) {
	printf("Yay2\n");
}
void func3(void) {
	printf("Yay4\n");
}
void func4(void) {
	printf("Yay4\n");
}
void func5(void) {
	printf("Yay5\n");
}

void (*fa)(void);
void (*fb)(void);

void bof(char *a) {
	char buffer[8];

	strcpy(buffer, a);
	(*fa)();
	(*fb)();
}

void init(int x, int y) {
	switch(x) {
		case 1: fa = &func1;
			break;
		case 2: fa = &func3;
			break;
		case 3: fa = &func5;
			break;
		default: fa = NULL;
	}
	switch(y) {
		case 1: fb = &func2;
			break;
		case 2: fb = &func4;
			break;
		case 3: fb = &func5;
			break;
		default: fb = NULL;
	}
}

int main(int argc, char **argv) {
	if (argc != 4) {
		printf("Usage: %s <integer> <integer> <string>", argv[0]);
		return 1;
	}

	printf("A: %s\n", argv[3]);
	init(atoi(argv[1]), atoi(argv[2]));
	bof(argv[3]);

	return 0;
}
