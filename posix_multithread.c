#include<stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
	printf("error\n");
	return 1;
    }

    printf("argc(num) is %d\n", argc);
    printf("argv string is %s\n", argv[1]);

    return 0;
}
