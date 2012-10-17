#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int x = 42;
    const char *s = "this is some static data!";

    printf("location of code        0x%016llx\n", (unsigned long long)(void *) main); 
    printf("location of heap        0x%016llx\n", (unsigned long long)(void *) sbrk(0)); 
    printf("location of stack       0x%016llx\n", (unsigned long long)(void *) &x);
    printf("location of static data 0x%016llx\n", (unsigned long long)(void *) &s[0]);

    return 0;
}
