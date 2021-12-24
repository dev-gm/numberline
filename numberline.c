#include <stdio.h>
#include <stdlib.h>

#define unsigned int uint

uint _log10(uint x) {
	uint out = 0;
	while (x >= 10) {
		x /= 10;
		++out;
	};
	return out;
}

// nums must be sorted
void display_numberline(uint *nums, size_t len) {
	size_t i, j;
	putchar('|'); // 0
	for (j = 0; j < nums[0]; ++j)
		putchar('-');
	for (i = nums[0] == 0; i < len-1; ++i) {
		putchar('|');
		for (j = nums[i]; j < nums[i+1]; ++j)
			putchar('-');
	}
	printf("|\n0");
	for (j = 0; j < nums[0]; ++j)
		putchar(' ');
	for (i = nums[0] == 0; i < len-1; ++i) {
		printf("%d", nums[i]);
		for (j = nums[i]; j < nums[i+1] - _log10(nums[i]); ++j)
			putchar(' ');
	}
	printf("%d", nums[len-1]);
	putchar('\n');
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		perror("Args are not valid");
		return 1;
	}
	uint *nums = malloc((argc-1) * sizeof(uint));
	for (int i = 1; i < argc; ++i)
		nums[i-1] = (uint) atoi(argv[i]);
	display_numberline(nums, (size_t) argc-1);
	return 0;
}
