#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if (remove("test.txt") != 0) {
		fprintf(stderr, "cannot remove file\n");
		exit(EXIT_FAILURE);
	}

	printf("success..\n");
}