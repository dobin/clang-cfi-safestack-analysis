#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func_v1(void) {
        printf("Yay v1\n");
}
void func_v2(void) {
        printf("Yay v2\n");
}
void func_v3(void) {
        printf("Yay v4\n");
}
void func_i1(int a) {  // int argument
        printf("Yay i1 %i\n", a);
}
void func_i2(int a) {  // int argument
        printf("Yay i2 %i\n", a);
}

void (*fa)(void);
void (*fb)(int); // int argument

void bof(void) {
        (*fa)();
        (*fb)(2);
}

void init(int x, int y) {
        switch(x) {
                case 1: fa = &func_v1;
                        break;
                case 2: fa = &func_v2;
                        break;
                case 3: fa = &func_v3;
                        break;
                default: fa = NULL;
        }
        switch(y) {
                case 1: fb = &func_i1;
                        break;
                case 2: fb = &func_i2;
                        break;
                default: fb = NULL;
        }
}

int main(int argc, char **argv) {
        if (argc != 3) {
                printf("Usage: %s <integer> <integer>", argv[0]);
                return 1;
        }

        init(atoi(argv[1]), atoi(argv[2]));
        bof();

        return 0;
}


