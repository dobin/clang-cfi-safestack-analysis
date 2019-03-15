#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "funcptr8lib.h"

void func_v1(void) {
        printf("Yay v1\n");
}
void func_v2(void) {
        printf("Yay v2\n");
}
void func_v3(void) {
        printf("Yay v4\n");
}

void (*fa)(void);

void exec(void) {
        (*fa)();
}

void init(int x) {
        switch(x) {
                case 1: fa = &func_v1;
                        break;
                case 2: fa = &func_v2;
                        break;
                case 3: fa = &func_v3;
                        break;
                default: fa = NULL;
        }
}

int main(int argc, char **argv) {
        if (argc != 3) {
                printf("Usage: %s <integer> <integer>", argv[0]);
                return 1;
        }

        init(atoi(argv[1]));
	init_lib(atoi(argv[2]));
        
	exec();
	exec_lib();

        return 0;
}


