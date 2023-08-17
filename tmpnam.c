#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define	MAX_LINE	8192


int issharp(const char *line);

int main(int argc, char *argv[])
{
	FILE* f, * ftemp;
	char line[MAX_LINE];
	char* path;
	
	

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!...\n");
		exit(EXIT_FAILURE);
	}

	if ((path = tmpnam(NULL)) == NULL) {
		fprintf(stderr, "cannot get temporary file...\n");
		exit(EXIT_FAILURE);
	}

	if ((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "cannot open file.....\n");
		exit(EXIT_FAILURE);
	}


	if ((ftemp = fopen(path, "w")) == NULL) {
		fprintf(stderr, "cannot open file...\n");
		exit(EXIT_FAILURE);
	}

	
	while (fgets(line, MAX_LINE, f) != NULL) {
		if (!issharp(line))
			if (fputs(line, ftemp) == EOF) {
				fprintf(stderr, "cannot write file temporary file...\n");
				goto FAILURE;
			}
	}

	if (ferror(f)) {
		fprintf(stderr, "cannot read file: %s\n", argv[1]);
		goto FAILURE;
	}


	fclose(f);
	fclose(ftemp);

	if (remove(argv[1]) != 0) {
		fprintf(stderr, "cannot remove file...\n");
		goto FAILURE;
	}

	if (rename(path, argv[1]) != 0) 
		fprintf(stderr, "cannot rename file...\n");
		
	return EXIT_FAILURE;
	

	printf("success..\n");

	if (remove(path) != 0)
		fprintf(stderr, "cannot remove file...\n");

	exit(EXIT_SUCCESS);

FAILURE:
	fclose(f);
	if (remove(path) != 0)
		fprintf(stderr, "cannot remove file...\n");

	exit(EXIT_FAILURE);
	
	
}

int issharp(const char* line)
{
	while (isspace(*line))
		++line;

	return *line == '#';
}