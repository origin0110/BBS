test: bbs.c bbs.h test.c
	gcc *.c -Ofast -flto -pipe -static -march=native -mtune=native -fopt-info -fopenmp -lgmp