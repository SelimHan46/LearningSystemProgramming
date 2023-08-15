#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* mystork(char* str, const char* delim)
{
	static char* pos;
	char* beg;

	if (str != NULL)
		pos = str;

	while (*pos != '\0' && strchr(delim, *pos) != NULL)
		++pos;

	if (*pos == '\0')
		return NULL;

	beg = pos;

	while (*pos != '\0' && strchr(delim, *pos) == NULL)
		++pos;

	if (*pos != '\0')
		*pos++ = '\0';

	return beg;

}

int main() 
{
    char s[] = ",,,,,Ali,,,,,,Veli,,,,,,Selami,,,,,,";
	char* pstr;

	for (pstr = mystork(s, ","); pstr != NULL; pstr = mystork(NULL, ","))
		puts(pstr);

	

	return 0;

}