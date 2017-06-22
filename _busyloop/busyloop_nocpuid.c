#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <sys/time.h>

volatile int gIter = 0;

static inline void run_cpuid(int code, uint32_t* a, uint32_t* d) {
    asm volatile ( "cpuid" : "=a"(*a), "=d"(*d) : "0"(code) : "ebx", "ecx" );
}

int iteration() { 
	uint32_t a = 0, d = 0;
//	run_cpuid(0xdeadbeef, &a, &d);
	// printf("0x%x 0x%x\n", a, d);
	return gIter++; 
}

int main(int argc, char** argv) {
	uint32_t end;
	struct timeval tv1, tv2;

    if (argc == 2) {
        end = strtol(argv[1], NULL, 10);
        printf("%d\n", end);
    } else {
        end = 100;
    }

	gettimeofday(&tv1, NULL);
	while (iteration() < end);
	gettimeofday(&tv2, NULL);

	printf ("Total time = %f seconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));

	return 0;
}
