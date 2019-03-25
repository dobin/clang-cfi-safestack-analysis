CC=clang
CFIFLAGS=-fsanitize=cfi -flto -fvisibility=hidden
SAFESTACKFLAGS=-fsanitize=safe-stack

all: funcptr2 funcptr3 funcptr4 funcptr5 funcptr7 funcptr8 retbof funcptr-got

clean:
	rm funcptr8 funcptr8.o funcptr8lib.o
	rm funcptr2 funcptr2-nocfi
	rm funcptr3 funcptr3-nocfi
	rm funcptr4 funcptr4-nocfi
	rm funcptr5 funcptr5-nocfi
	rm funcptr7 funcptr7-nocfi
	rm retbof retbof-nosafestack
	rm funcptr-got funcptr-got-all funcptr-got-all-pie

funcptr2: funcptr2.c
	clang funcptr2.c $(CFIFLAGS) -o funcptr2
	clang funcptr2.c -o funcptr2-nocfi

funcptr3: funcptr3.c
	clang funcptr3.c $(CFIFLAGS) -o funcptr3
	clang funcptr3.c -o funcptr3-nocfi

funcptr4: funcptr4.c
	clang funcptr4.c $(CFIFLAGS) -o funcptr4
	clang funcptr4.c -o funcptr4-nocfi

funcptr5: funcptr5.c
	clang funcptr5.c $(CFIFLAGS) -o funcptr5
	clang funcptr5.c -o funcptr5-nocfi

funcptr7: funcptr7.c
	clang funcptr7.c $(CFIFLAGS) -o funcptr7
	clang funcptr7.c -o funcptr7-nocfi


funcptr8: funcptr8.c funcptr8lib.c
	clang -c $(CFIFLAGS) funcptr8.c 
	clang -c funcptr8lib.c 
	clang -o funcptr8 funcptr8.o funcptr8lib.o

funcptr-got: funcptr-got.c
	clang  -fsanitize=cfi -flto -fvisibility=hidden funcptr-got.c  -o funcptr-got
	clang  -fsanitize=cfi -flto -fvisibility=hidden funcptr-got.c  -Wl,-z,now -Wl,-z,relro  -o funcptr-got-all
	clang  -fpie -pie -fsanitize=cfi -flto -fvisibility=hidden funcptr-got.c  -Wl,-z,now -Wl,-z,relro  -o funcptr-got-all-pie


retbof: retbof.c
	clang $(SAFESTACKFLAGS) retbof.c -o retbof
	clang retbof.c -o retbof-nosafestack
