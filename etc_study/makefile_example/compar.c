#include<stdio.h>
void print_number_compar(int n1, int n2)
{
    if (n1==n2) {
	printf("same number\n");
    } else {
	(n1>n2)?printf("n1 > n2\n"):
	    printf("n2 > n1\n");
    }
}
