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

void (*f)(void);

void bof(char *a) {
	char buffer[8];

	strcpy(buffer, a);
	(*f)();
}

void init(int x) {
	switch(x) {
		case 1: f = &func1;
			break;
		case 2: f = &func2;
			break;
		case 3: f = &func3;
			break;
		case 4: f = &func4;
			break;
		case 5: f = &func5;
			break;
		default: f = NULL;
	}
}

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Usage: %s <integer> <string>", argv[0]);
		return 1;
	}

	printf("A: %s\n", argv[2]);
	init(atoi(argv[1]));
	bof(argv[2]);

	return 0;
}
