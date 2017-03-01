#include <stdio.h>
#include <stdint.h>

volatile int gIter = 0;

int iteration() { return gIter++; }

static inline void run_cpuid(int code, uint32_t* a, uint32_t* d) {
    asm volatile ( "cpuid" : "=a"(*a), "=d"(*d) : "0"(code) : "ebx", "ecx" );
}

int main() {
	uint32_t a = 0, d = 0;
	run_cpuid(228, &a, &d);
	printf("0x%x 0x%x\n", a, d);

	/* while (1) {
		iteration();
	} */

	return 0;
}
