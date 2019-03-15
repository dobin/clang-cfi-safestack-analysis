#include <stdio.h>

void func_i1(int a) {  // int argument
        printf("Yay i1 %i\n", a);
}
void func_i2(int a) {  // int argument
        printf("Yay i2 %i\n", a);
}

void (*fb)(int); // int argument

void init_lib(int y) {
        switch(y) {
                case 1: fb = &func_i1;
                        break;
                case 2: fb = &func_i2;
                        break;
                default: fb = NULL;
        }
}


void exec_lib() {
	(*fb)(2);
}
