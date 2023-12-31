#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int result;
    int a_flag, b_flag, c_flag;
    char* b_arg;
    int i;

    a_flag = b_flag = c_flag = 0;

    while ((result = getopt(argc, argv, "ab:c")) != -1)
    {
        switch (result) {
        case 'a':
            a_flag = 1;
            break;
        case 'b':
            b_flag = 1;
            b_arg = optarg;
            break;
        case 'c':
            c_flag = 1;
            break;
        }
    }

    if (a_flag)
        printf("-a option used....\n");
    if (b_flag)
        printf("-b option used with argument \"%s\"\n", b_arg);
    if (c_flag)
        printf("-c option used....\n");

    printf("seceneksiz normal argumanlar:");
    for (i = optind; i < argc; ++i) {
        printf("%s\n", argv[i]);

    }


    return 0;
}