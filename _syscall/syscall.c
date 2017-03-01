#include <unistd.h>
#include <fcntl.h>

int main() {
	open("/dev/null", O_RDONLY);
	return 0;
}
